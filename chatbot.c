#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Predefined FAQs
const char *questions[] = {
    "what is ai",
    "what is machine learning",
    "what is python"
};

const char *answers[] = {
    "AI stands for Artificial Intelligence.",
    "Machine Learning is a subset of AI that learns from data.",
    "Python is a programming language used in AI."
};

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Chatbot function to match questions and provide answers
void chatbot(char input[]) {
    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(input, questions[i]) == 0) {
            printf("Bot: %s\n", answers[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Bot: Sorry, I don't understand that question.\n");
    }
}

// Main function
int main() {
    char query[100];

    printf("Welcome to the FAQ Chatbot!\n");
    printf("Type your question (e.g., what is ai). Type 'exit' to quit.\n\n");

    while (1) {
        printf("You: ");
        fgets(query, sizeof(query), stdin);

        // Remove newline character
        query[strcspn(query, "\n")] = 0;

        // Convert to lowercase for case-insensitive comparison
        toLowerCase(query);

        // Exit condition
        if (strcmp(query, "exit") == 0) {
            printf("Bot: Goodbye!\n");
            break;
        }

        chatbot(query);
    }

    return 0;
}
