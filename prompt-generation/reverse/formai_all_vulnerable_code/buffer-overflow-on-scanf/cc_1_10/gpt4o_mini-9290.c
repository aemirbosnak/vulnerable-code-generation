//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MESSAGE_LENGTH 256
#define SPAM_KEYWORDS 5

// Function prototypes
void toLowerCase(char *str);
int isSpam(char *message, char spamKeywords[][MESSAGE_LENGTH], int spamCount);
void processMessages(char messages[MAX_MESSAGES][MESSAGE_LENGTH], int messageCount, char spamKeywords[][MESSAGE_LENGTH], int spamCount);
void getSpamKeywords(char spamKeywords[][MESSAGE_LENGTH], int *spamCount);

int main() {
    char messages[MAX_MESSAGES][MESSAGE_LENGTH];
    char spamKeywords[SPAM_KEYWORDS][MESSAGE_LENGTH] = { "win", "free", "click", "buy", "limited" };
    int messageCount = 0;
    char continueInput;

    printf("Welcome to the Spam Detection System!\n");
    
    // Collect messages from the user
    do {
        printf("Enter message (%d/%d): ", messageCount + 1, MAX_MESSAGES);
        fgets(messages[messageCount], MESSAGE_LENGTH, stdin);
        
        // Remove newline character from the end of the string
        size_t len = strlen(messages[messageCount]);
        if (len > 0 && messages[messageCount][len - 1] == '\n') {
            messages[messageCount][len - 1] = '\0';
        }
        
        messageCount++;
        
        if (messageCount >= MAX_MESSAGES) {
            printf("Maximum message limit reached.\n");
            break;
        }

        // Ask to continue
        printf("Do you want to enter another message? (y/n): ");
        scanf(" %c", &continueInput);
        getchar(); // Clear the newline character from input buffer
        
    } while (continueInput == 'y' || continueInput == 'Y');

    // Process the messages for spam detection
    processMessages(messages, messageCount, spamKeywords, SPAM_KEYWORDS);
    
    return 0;
}

// Convert a string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Check if the message contains spam keywords
int isSpam(char *message, char spamKeywords[][MESSAGE_LENGTH], int spamCount) {
    toLowerCase(message); // Convert message to lowercase for case-insensitive comparison
    
    for (int i = 0; i < spamCount; i++) {
        if (strstr(message, spamKeywords[i]) != NULL) {
            return 1; // Message is deemed spam
        }
    }
    return 0; // Message is not spam
}

// Function to process each message and determine if it's spam
void processMessages(char messages[MAX_MESSAGES][MESSAGE_LENGTH], int messageCount, char spamKeywords[][MESSAGE_LENGTH], int spamCount) {
    printf("\nSpam Detection Results:\n");
    for (int i = 0; i < messageCount; i++) {
        if (isSpam(messages[i], spamKeywords, spamCount)) {
            printf("Message %d: [SPAM] - '%s'\n", i + 1, messages[i]);
        } else {
            printf("Message %d: [NOT SPAM] - '%s'\n", i + 1, messages[i]);
        }
    }
}