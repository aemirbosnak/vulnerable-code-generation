//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define THRESHOLD 5

// Function to read input from the user
void read_input(char *input) {
    printf("Enter a message: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
}

// Function to check for spam keywords
bool is_spam(const char *input) {
    const char *spam_words[] = {
        "win", "free", "money", "urgent", "click", "buy now", "limited", "offer", "risk-free", "guarantee"
    };
    int spam_count = 0;
    char *token;
    char *input_copy = strdup(input); // Duplicate input to avoid modifying the original

    token = strtok(input_copy, " "); // Tokenize the input by spaces
    while (token != NULL) {
        for (int i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
            if (strcasecmp(token, spam_words[i]) == 0) {
                spam_count++;
                break; // Stop checking after finding a match
            }
        }
        token = strtok(NULL, " ");
    }

    free(input_copy); // Free the duplicated string
    return spam_count >= THRESHOLD; // Return true if spam threshold is met
}

// Function to log the result to a file
void log_result(const char *input, bool spam) {
    FILE *file = fopen("spam_log.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open spam_log.txt for writing.\n");
        return;
    }
    
    fprintf(file, "Message: \"%s\" - %s\n", input, spam ? "SPAM" : "NOT SPAM");
    fclose(file);
}

// Main function to execute the spam detection system
int main() {
    char input[MAX_SIZE];
    char choice;

    printf("Welcome to the C Spam Detection System!\n");

    do {
        read_input(input); // Read input from the user

        if (is_spam(input)) {
            printf("This message is classified as SPAM.\n");
        } else {
            printf("This message is classified as NOT SPAM.\n");
        }

        log_result(input, is_spam(input)); // Log the result to the file

        printf("Do you want to check another message? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear the input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Spam Detection System. Goodbye!\n");
    return 0;
}