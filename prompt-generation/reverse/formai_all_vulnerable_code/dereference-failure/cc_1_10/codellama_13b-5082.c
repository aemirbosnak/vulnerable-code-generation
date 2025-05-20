//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: complete
/*
 * C Spam Detection System
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_SPAM_THRESHOLD 5

typedef struct {
    char *message;
    int score;
} Message;

void read_message(Message *message) {
    char buffer[MAX_MESSAGE_LENGTH];
    fgets(buffer, MAX_MESSAGE_LENGTH, stdin);
    message->message = strdup(buffer);
    message->score = 0;
}

void check_spam(Message *message) {
    char *ptr;
    ptr = strstr(message->message, "viagra");
    if (ptr != NULL) {
        message->score += 5;
    }
    ptr = strstr(message->message, "pills");
    if (ptr != NULL) {
        message->score += 5;
    }
    ptr = strstr(message->message, "pharmacy");
    if (ptr != NULL) {
        message->score += 5;
    }
    ptr = strstr(message->message, "prescription");
    if (ptr != NULL) {
        message->score += 5;
    }
    ptr = strstr(message->message, "online");
    if (ptr != NULL) {
        message->score += 2;
    }
    ptr = strstr(message->message, "sale");
    if (ptr != NULL) {
        message->score += 2;
    }
    ptr = strstr(message->message, "discount");
    if (ptr != NULL) {
        message->score += 2;
    }
    ptr = strstr(message->message, "free");
    if (ptr != NULL) {
        message->score += 2;
    }
}

void print_result(Message *message) {
    if (message->score >= MAX_SPAM_THRESHOLD) {
        printf("SPAM\n");
    } else {
        printf("HAM\n");
    }
}

int main() {
    Message message;
    read_message(&message);
    check_spam(&message);
    print_result(&message);
    return 0;
}