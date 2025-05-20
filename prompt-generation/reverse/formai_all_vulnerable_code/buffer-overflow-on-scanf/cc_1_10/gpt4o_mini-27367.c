//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256
#define SPAM_THRESHOLD 3

const char *spam_keywords[] = {
    "free",
    "winner",
    "money",
    "cash",
    "urgent",
    "click here",
    "limited time",
    "risk free",
    "special promotion",
    "guaranteed"
};

int is_spam(const char *message) {
    int spam_score = 0;
    char message_copy[MAX_LENGTH];
    strcpy(message_copy, message);
    
    // Convert the message to lowercase for case-insensitive comparison
    for (int i = 0; message_copy[i]; i++) {
        message_copy[i] = tolower(message_copy[i]);
    }

    // Check for spam keywords
    for (int i = 0; i < sizeof(spam_keywords) / sizeof(spam_keywords[0]); i++) {
        if (strstr(message_copy, spam_keywords[i]) != NULL) {
            spam_score++;
        }
    }

    return spam_score >= SPAM_THRESHOLD;
}

void classify_messages(const char messages[MAX_MESSAGES][MAX_LENGTH], int message_count) {
    for (int i = 0; i < message_count; i++) {
        if (is_spam(messages[i])) {
            printf("Message %d: SPAM\n", i + 1);
        } else {
            printf("Message %d: NOT SPAM\n", i + 1);
        }
    }
}

int main() {
    int message_count;
    char messages[MAX_MESSAGES][MAX_LENGTH];

    printf("Enter the number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", &message_count);
    
    // Validate message count
    if (message_count < 1 || message_count > MAX_MESSAGES) {
        printf("Invalid number of messages. Please enter a number between 1 and %d.\n", MAX_MESSAGES);
        return 1;
    }

    // Clear input buffer
    while (getchar() != '\n');

    // Input messages
    for (int i = 0; i < message_count; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i], MAX_LENGTH, stdin);
        
        // Remove newline character if present
        size_t len = strlen(messages[i]);
        if (len > 0 && messages[i][len - 1] == '\n') {
            messages[i][len - 1] = '\0';
        }
    }

    // Classify messages as spam or not
    classify_messages(messages, message_count);
    
    return 0;
}