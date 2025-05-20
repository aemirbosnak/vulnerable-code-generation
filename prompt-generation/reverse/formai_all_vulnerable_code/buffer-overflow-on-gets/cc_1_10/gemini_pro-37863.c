//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a spam message
#define MAX_SPAM_SIZE 1024

// Define the threshold for spam detection
#define SPAM_THRESHOLD 0.5

// Define the list of spam words
char *spam_words[] = {
    "free",
    "money",
    "win",
    "prize",
    "offer",
    "click",
    "subscribe",
    "unsubscribe",
    "remove",
    "delete",
    "stop"
};

// Calculate the spam score of a message
float calculate_spam_score(char *message) {
    // Initialize the spam score
    float spam_score = 0.0;

    // Tokenize the message
    char *token = strtok(message, " ");

    // Iterate over the tokens
    while (token != NULL) {
        // Check if the token is a spam word
        for (int i = 0; i < sizeof(spam_words) / sizeof(char *); i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                // Increment the spam score
                spam_score += 1.0;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the spam score
    return spam_score;
}

// Detect if a message is spam
int detect_spam(char *message) {
    // Calculate the spam score
    float spam_score = calculate_spam_score(message);

    // Check if the spam score is above the threshold
    if (spam_score > SPAM_THRESHOLD) {
        // The message is spam
        return 1;
    } else {
        // The message is not spam
        return 0;
    }
}

// Main function
int main() {
    // Get the message from the user
    char message[MAX_SPAM_SIZE];
    printf("Enter a message: ");
    gets(message);

    // Detect if the message is spam
    int is_spam = detect_spam(message);

    // Print the result
    if (is_spam) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}