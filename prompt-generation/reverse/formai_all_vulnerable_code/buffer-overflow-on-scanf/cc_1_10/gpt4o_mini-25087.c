//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256
#define SPAM_KEYWORDS 5

typedef struct {
    char message[MAX_LENGTH];
    int is_spam;
} Message;

const char *spam_keywords[SPAM_KEYWORDS] = {
    "free",
    "win",
    "click here",
    "buy now",
    "subscribe"
};

int is_spam_message(const char *message) {
    for (int i = 0; i < SPAM_KEYWORDS; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return 1; // Message considered spam
        }
    }
    return 0; // Not spam
}

void process_messages(Message *messages, int count) {
    for (int i = 0; i < count; i++) {
        messages[i].is_spam = is_spam_message(messages[i].message);
    }
}

void print_results(Message *messages, int count) {
    printf("Spam Detection Results:\n");
    for (int i = 0; i < count; i++) {
        printf("Message: \"%s\"\n", messages[i].message);
        if (messages[i].is_spam) {
            printf("Status: SPAM\n");
        } else {
            printf("Status: NOT SPAM\n");
        }
        printf("\n");
    }
}

void input_messages(Message *messages, int *count) {
    printf("Enter the number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", count);
    getchar(); // Clear newline left in buffer

    if (*count > MAX_MESSAGES) {
        *count = MAX_MESSAGES;
        printf("Limiting input to maximum %d messages.\n", MAX_MESSAGES);
    }

    for (int i = 0; i < *count; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i].message, MAX_LENGTH, stdin);
        messages[i].message[strcspn(messages[i].message, "\n")] = 0; // Remove newline
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int message_count = 0;

    input_messages(messages, &message_count);
    process_messages(messages, message_count);
    print_results(messages, message_count);

    return 0;
}