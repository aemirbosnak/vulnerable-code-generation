#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define MSG_LENGTH 256

char chat_buffer[BUFFER_SIZE][MSG_LENGTH];
int buffer_len = 0;

void receive_message(char *message) {
    if (buffer_len >= BUFFER_SIZE) {
        printf("Chat buffer is full. Cannot accept message.\n");
        return;
    }

    strcpy(chat_buffer[buffer_len], message);
    buffer_len++;
}

void display_messages() {
    int i;
    for (i = 0; i < buffer_len; i++) {
        printf("Message %d: %s\n", i+1, chat_buffer[i]);
    }
}

void main() {
    int i;

    // Sample chat messages
    char messages[][MSG_LENGTH] = {
        "Hi there! How are you today?",
        "Fine, and you?",
        "Can't complain. How about you?",
        "I'm good.",
        "Excellent!",
        "Let's continue this conversation later.",
        "Agreed, talk soon.",
    };

    for (i = 0; i < 7; i++) {
        receive_message(messages[i]);
        usleep(100000); // Sleep for 100ms to simulate network delay
    }

    receive_message(&messages[BUFFER_SIZE][0]); // Attempt to exceed buffer size

    display_messages();
}
