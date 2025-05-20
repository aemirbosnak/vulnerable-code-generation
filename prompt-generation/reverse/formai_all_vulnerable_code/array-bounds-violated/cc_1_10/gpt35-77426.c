//FormAI DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MSG_LENGTH 1024
#define SPAM_THRESHOLD 0.8

/* Data structure to hold message information */
typedef struct Message {
    char content[MAX_MSG_LENGTH];
    int length;
} Message;

/* Function to check if a message is spam or not */
bool isSpam(Message* msg) {
    /* Count number of uppercase letters */
    int uppercase_count = 0;
    for (int i = 0; i < msg->length; i++) {
        if (isupper(msg->content[i]))
            uppercase_count++;
    }

    /* Calculate uppercase letter ratio */
    float uppercase_ratio = (float) uppercase_count / (float) msg->length;

    /* If uppercase ratio exceeds threshold, message is spam */
    if (uppercase_ratio > SPAM_THRESHOLD)
        return true;
    else
        return false;
}

int main() {
    /* Read message input from user */
    Message msg;
    printf("Enter message content: ");
    fgets(msg.content, MAX_MSG_LENGTH, stdin);

    /* Remove newline character from input */
    msg.length = strlen(msg.content);
    if (msg.content[msg.length-1] == '\n')
        msg.content[msg.length-1] = '\0';
    msg.length--;

    /* Check if message is spam or not */
    if (isSpam(&msg))
        printf("Message is spam.\n");
    else
        printf("Message is not spam.\n");

    return 0;
}