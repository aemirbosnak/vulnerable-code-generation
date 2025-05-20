//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

// List of spam keywords
const char *spam_keywords[] = {
    "win", "prize", "money", "free", "winner",
    "click", "urgent", "act now", "risk free", "limited time"
};

// Function to check each message for spam keywords
bool is_spam(char *message, int keyword_index, int keyword_count) {
    if (keyword_index >= keyword_count) {
        return false; // No more keywords to check
    }
    
    // Check if the current keyword is present in the message
    if (strstr(message, spam_keywords[keyword_index]) != NULL) {
        return true; // Found a spam keyword
    }

    // Recursive case: check the next keyword
    return is_spam(message, keyword_index + 1, keyword_count);
}

// Function to analyze messages for spam
void analyze_messages(char messages[][MAX_LENGTH], int count, int index) {
    if (index >= count) {
        return; // No more messages to analyze
    }
    
    // Check if the current message is spam
    if (is_spam(messages[index], 0, sizeof(spam_keywords) / sizeof(spam_keywords[0]))) {
        printf("Message %d: Spam detected - \"%s\"\n", index + 1, messages[index]);
    } else {
        printf("Message %d: No spam - \"%s\"\n", index + 1, messages[index]);
    }

    // Recursive case: analyze the next message
    analyze_messages(messages, count, index + 1);
}

int main() {
    int message_count;
    char messages[MAX_MESSAGES][MAX_LENGTH];

    printf("Enter the number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", &message_count);

    // Input validation for message count
    if (message_count > MAX_MESSAGES || message_count <= 0) {
        printf("Invalid number of messages!\n");
        return 1;
    }

    // Input each message
    printf("Enter the messages:\n");
    getchar(); // Consume newline character left by previous input
    for (int i = 0; i < message_count; i++) {
        printf("Message %d: ", i + 1);
        fgets(messages[i], MAX_LENGTH, stdin);
        messages[i][strcspn(messages[i], "\n")] = 0; // Remove trailing newline
    }

    // Analyze all messages for spam
    printf("\nAnalyzing messages for spam...\n");
    analyze_messages(messages, message_count, 0);
    
    return 0;
}