//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for spam detection
#define MAX_MESSAGES 100
#define MAX_LENGTH 256

// List of common spam words/phrases
const char *spamWords[] = {
    "buy now",
    "limited time offer",
    "free",
    "exclusive deal",
    "act now",
    "click here",
    "subscribe",
    "win a prize",
    "urgent",
    "risk-free"
};

int spamWordsCount = sizeof(spamWords) / sizeof(spamWords[0]);

bool isSpam(const char *message) {
    // Check if the message contains any spam words
    for (int i = 0; i < spamWordsCount; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return true;
        }
    }
    return false;
}

void processMessages(const char messages[MAX_MESSAGES][MAX_LENGTH], int messageCount) {
    printf("Processing messages for spam detection...\n\n");
    
    for (int i = 0; i < messageCount; i++) {
        printf("Message %d: %s\n", i + 1, messages[i]);
        if (isSpam(messages[i])) {
            printf("  -> This message is identified as spam!\n");
        } else {
            printf("  -> This message is clean.\n");
        }
    }
}

void readMessages(char messages[MAX_MESSAGES][MAX_LENGTH], int *messageCount) {
    printf("Enter the number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", messageCount);
    
    // Clear the input buffer
    while (getchar() != '\n');

    if (*messageCount > MAX_MESSAGES) {
        printf("Exceeds maximum limit of %d messages. Truncating to %d.\n", MAX_MESSAGES, MAX_MESSAGES);
        *messageCount = MAX_MESSAGES;
    }

    for (int i = 0; i < *messageCount; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i], MAX_LENGTH, stdin);
        // Remove newline character if present
        messages[i][strcspn(messages[i], "\n")] = 0;
    }
}

int main() {
    char messages[MAX_MESSAGES][MAX_LENGTH];
    int messageCount = 0;

    readMessages(messages, &messageCount);
    processMessages(messages, messageCount);

    return 0;
}