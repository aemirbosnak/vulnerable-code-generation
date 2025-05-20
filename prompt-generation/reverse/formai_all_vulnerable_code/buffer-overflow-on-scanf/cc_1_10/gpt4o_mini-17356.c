//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1024
#define SPAM_KEYWORDS 5

// List of keywords that indicate a spam message
const char *spam_keywords[SPAM_KEYWORDS] = {
    "win",
    "free",
    "cash",
    "prize",
    "click"
};

// Function to check if a message contains spam keywords
int contains_spam(const char *message) {
    for (int i = 0; i < SPAM_KEYWORDS; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return 1; // Spam keyword found
        }
    }
    return 0; // No spam keywords found
}

// Function to clean the message by removing punctuation
void clean_message(char *cleaned_message, const char *original_message) {
    int j = 0;
    for (int i = 0; original_message[i] != '\0'; i++) {
        if (isalnum(original_message[i]) || isspace(original_message[i])) {
            cleaned_message[j++] = original_message[i];
        }
    }
    cleaned_message[j] = '\0'; // Null-terminate the cleaned message
}

// Function to detect spam messages
void detect_spam() {
    char message[MAX_MESSAGE_LENGTH];
    char cleaned_message[MAX_MESSAGE_LENGTH];

    printf("Enter the message to check for spam:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    // Clean the message input
    clean_message(cleaned_message, message);
    
    // Check for spam
    if (contains_spam(cleaned_message)) {
        printf("Alert: This message is identified as spam!\n");
    } else {
        printf("This message is NOT identified as spam.\n");
    }
}

int main() {
    while (1) {
        detect_spam();
        
        char choice;
        printf("Do you want to check another message? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop if user does not want to continue
        }

        // Clear the input buffer for the next iteration
        while (getchar() != '\n'); 
    }
    
    printf("Thank you for using the Spam Detection System!\n");
    return 0;
}