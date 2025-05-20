//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

typedef struct {
    char message[MAX_LENGTH];
    int spamScore;
} Message;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int calculateSpamScore(const char *message) {
    char *spamKeywords[] = {"free", "win", "winner", "urgent", "click", "offer", "buy now", "limited", "cash", "prize"};
    int score = 0;
    
    // Convert message to lowercase to make the check case-insensitive
    char tempMessage[MAX_LENGTH];
    strncpy(tempMessage, message, MAX_LENGTH);
    toLowerCase(tempMessage);

    for (int i = 0; i < sizeof(spamKeywords) / sizeof(spamKeywords[0]); i++) {
        if (strstr(tempMessage, spamKeywords[i]) != NULL) {
            score++;
        }
    }
    
    // Increase score for excessive punctuation
    for (int i = 0; tempMessage[i]; i++) {
        if (ispunct(tempMessage[i])) {
            score++;
        }
    }

    return score;
}

void analyzeMessages(Message *messages, int count) {
    for (int i = 0; i < count; i++) {
        messages[i].spamScore = calculateSpamScore(messages[i].message);
        if (messages[i].spamScore > 0) {
            printf("Message: \"%s\" | Spam Score: %d\n", messages[i].message, messages[i].spamScore);
        }
    }
}

void getMessages(Message *messages, int *count) {
    printf("Enter the number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", count);
    getchar(); // clear newline from buffer

    if (*count > MAX_MESSAGES) {
        *count = MAX_MESSAGES;
    }

    for (int i = 0; i < *count; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i].message, MAX_LENGTH, stdin);
        messages[i].message[strcspn(messages[i].message, "\n")] = 0; // Remove newline character
    }
}

void displaySpamWarnings(const Message *messages, int count) {
    printf("\nSpam Warnings:\n---------------------\n");
    for (int i = 0; i < count; i++) {
        if (messages[i].spamScore > 3) {
            printf("Warning: Message \"%s\" has a high Spam Score of %d\n", messages[i].message, messages[i].spamScore);
        }
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int messageCount = 0;

    getMessages(messages, &messageCount);
    analyzeMessages(messages, messageCount);
    displaySpamWarnings(messages, messageCount);

    return 0;
}