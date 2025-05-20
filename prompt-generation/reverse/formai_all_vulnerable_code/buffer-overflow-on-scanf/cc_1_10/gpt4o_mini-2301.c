//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 280
#define SPAM_KEYWORDS 5

// Structure to hold message data
typedef struct {
    char sender[50];
    char message[MAX_LENGTH];
} Message;

// A simple spam detection function based on keyword matching
int is_spam(const char *message, const char *keywords[], int keyword_count) {
    for (int i = 0; i < keyword_count; i++) {
        if (strstr(message, keywords[i]) != NULL) {
            return 1; // found a keyword, it's spam
        }
    }
    return 0; // no keywords found, not spam
}

// Function to sanitize input
void sanitize_input(char *input) {
    for (int i = 0; input[i]; i++) {
        input[i] = (char)tolower(input[i]);
    }
}

// Function to display spam messages
void display_spam(Message messages[], int count) {
    printf("\nSpam Messages Detected:\n");
    for (int i = 0; i < count; i++) {
        printf("Sender: %s\nMessage: %s\n\n", messages[i].sender, messages[i].message);
    }
}

// Main program function
int main() {
    Message messages[MAX_MESSAGES];
    char *spam_keywords[SPAM_KEYWORDS] = {
        "free money",
        "limited time offer",
        "click here",
        "winner",
        "urgent"
    };
    
    int spam_count = 0;
    
    printf("Enter number of messages to evaluate (max %d): ", MAX_MESSAGES);
    int num_messages;
    scanf("%d", &num_messages);
    
    if (num_messages > MAX_MESSAGES || num_messages < 1) {
        printf("Invalid number of messages.\n");
        return 1;
    }
    
    getchar(); // clear the newline character from buffer

    for (int i = 0; i < num_messages; i++) {
        printf("Enter sender's name: ");
        fgets(messages[i].sender, sizeof(messages[i].sender), stdin);
        messages[i].sender[strcspn(messages[i].sender, "\n")] = 0; // remove newline

        printf("Enter message: ");
        fgets(messages[i].message, sizeof(messages[i].message), stdin);
        messages[i].message[strcspn(messages[i].message, "\n")] = 0; // remove newline
                
        // Sanitize inputs to lowercase
        sanitize_input(messages[i].message);
        
        // Check if the message is spam
        if (is_spam(messages[i].message, spam_keywords, SPAM_KEYWORDS)) {
            spam_count++;
            printf("Spam detected in message from %s\n", messages[i].sender);
        }
    }

    printf("\nTotal spam messages detected: %d\n", spam_count);
    
    // If there are any spam messages, display them
    if (spam_count > 0) {
        display_spam(messages, spam_count);
    } else {
        printf("No spam messages detected.\n");
    }
    
    return 0;
}