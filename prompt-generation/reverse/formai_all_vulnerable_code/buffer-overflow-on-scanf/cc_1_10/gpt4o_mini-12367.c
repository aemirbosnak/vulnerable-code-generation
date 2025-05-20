//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256
#define THRESHOLD 3

typedef struct {
    char *content;
    int spam_score;
} Message;

void initialize_message(Message *msg, const char *text) {
    msg->content = (char *)malloc(strlen(text) + 1);
    strcpy(msg->content, text);
    msg->spam_score = 0;
}

void free_message(Message *msg) {
    free(msg->content);
}

int count_keywords(const char *message, const char *keyword) {
    int count = 0;
    const char *p = message;

    while ((p = strstr(p, keyword)) != NULL) {
        count++;
        p += strlen(keyword);
    }
    return count;
}

int assess_spam(const Message *msg) {
    const char *keywords[] = {
        "free", "money", "win", "prize", "click", "offer", "discount", "buy now", "act fast"
    };
    int total_spam_score = 0;

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        int score = count_keywords(msg->content, keywords[i]);
        total_spam_score += score;
    }
    
    return total_spam_score;
}

void display_spam_messages(const Message messages[], int count) {
    printf("Messages marked as spam:\n");
    for (int i = 0; i < count; i++) {
        if (messages[i].spam_score >= THRESHOLD) {
            printf(" - [SPAM] %s (Score: %d)\n", messages[i].content, messages[i].spam_score);
        }
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int message_count = 0;
    
    printf("Enter the number of messages (up to %d): ", MAX_MESSAGES);
    scanf("%d", &message_count);
    getchar();  // Consume the newline character
    
    if (message_count > MAX_MESSAGES) {
        message_count = MAX_MESSAGES;
    }

    for (int i = 0; i < message_count; i++) {
        char buffer[MAX_LENGTH];
        printf("Enter message %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove the newline character
        
        initialize_message(&messages[i], buffer);
        messages[i].spam_score = assess_spam(&messages[i]);
    }

    display_spam_messages(messages, message_count);
    
    // Free memory
    for (int i = 0; i < message_count; i++) {
        free_message(&messages[i]);
    }

    return 0;
}