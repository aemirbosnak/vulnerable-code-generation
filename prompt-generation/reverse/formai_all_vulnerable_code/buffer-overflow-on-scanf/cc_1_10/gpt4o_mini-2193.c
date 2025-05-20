//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256
#define SPAM_KEYWORD_COUNT 5

// Function to check if the message contains any spam keywords
bool isSpam(const char *message, const char spamKeywords[][MAX_LENGTH], int keywordCount) {
    for (int i = 0; i < keywordCount; i++) {
        if (strstr(message, spamKeywords[i]) != NULL) {
            return true; // Found a spam keyword
        }
    }
    return false; // No spam keywords found
}

int main() {
    char messages[MAX_MESSAGES][MAX_LENGTH];
    char spamKeywords[SPAM_KEYWORD_COUNT][MAX_LENGTH] = {
        "win", "free", "credit", "offer", "winner"
    };
    
    int messageCount, spamCount = 0;

    // Input number of messages
    printf("Enter number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", &messageCount);
    
    // Ensuring we don't exceed the maximum defined messages
    if (messageCount > MAX_MESSAGES) {
        messageCount = MAX_MESSAGES;
    }

    // Clear the input buffer
    while (getchar() != '\n');

    // Input messages
    for (int i = 0; i < messageCount; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i], MAX_LENGTH, stdin);
        // Remove newline character from string
        messages[i][strcspn(messages[i], "\n")] = 0;
    }

    // Check for spam messages
    for (int i = 0; i < messageCount; i++) {
        if (isSpam(messages[i], spamKeywords, SPAM_KEYWORD_COUNT)) {
            printf("Message %d: SPAM\n", i + 1);
            spamCount++;
        } else {
            printf("Message %d: NOT SPAM\n", i + 1);
        }
    }

    // Final report
    printf("\nTotal messages: %d\n", messageCount);
    printf("Total spam messages detected: %d\n", spamCount);

    return 0;
}