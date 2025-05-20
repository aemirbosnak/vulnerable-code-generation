//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a spam message
#define MAX_SPAM_LENGTH 1024

// Define the list of spam keywords
const char *spam_keywords[] = {
    "free",
    "money",
    "win",
    "prize",
    "cash",
    "click here",
    "urgent",
    "important",
    "limited time offer",
    "don't miss out"
};

// Define the number of spam keywords
const int num_spam_keywords = sizeof(spam_keywords) / sizeof(char *);

// Function to check if a message is spam
int is_spam(char *message) {
    // Check if the message contains any of the spam keywords
    for (int i = 0; i < num_spam_keywords; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return 1;
        }
    }

    // If the message does not contain any spam keywords, return 0
    return 0;
}

// Main function
int main() {
    // Get the message from the user
    char message[MAX_SPAM_LENGTH];
    printf("Enter the message: ");
    gets(message);

    // Check if the message is spam
    int is_spam_result = is_spam(message);

    // Print the result
    if (is_spam_result) {
        printf("**SPAM DETECTED!!**\n");
        printf("Do not open this message or click on any links. It is a phishing or scam attempt.");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}