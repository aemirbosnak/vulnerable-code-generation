#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_CHAT_MESSAGES 10
#define MAX_MESSAGE_LENGTH 200

typedef struct ChatMessage {
    char message[MAX_MESSAGE_LENGTH];
    char sender[50];
} ChatMessage;

ChatMessage chat_messages[MAX_CHAT_MESSAGES];
int num_messages = 0;

void add_message(const char* sender, const char* message) {
    if (num_messages >= MAX_CHAT_MESSAGES) {
        printf("Error: Max number of chat messages reached.\n");
        return;
    }
    strcpy(chat_messages[num_messages].sender, sender);
    strcpy(chat_messages[num_messages].message, message);
    num_messages++;
}

void print_messages() {
    for (int i = 0; i < num_messages; i++) {
        printf("%s: %s\n", chat_messages[i].sender, chat_messages[i].message);
    }
}

int main() {
    char input_message[MAX_MESSAGE_LENGTH];
    char input_sender[50];

    while (1) {
        printf("\nEnter your message: ");
        fgets(input_message, sizeof(input_message), stdin);
        printf("Enter your username: ");
        fgets(input_sender, sizeof(input_sender), stdin);

        // Intentionally exploiting the buffer overflow vulnerability
        // The number of characters read is smaller than the buffer size, but when concatenating the sender and message, it exceeds the buffer
        strcpy(chat_messages[num_messages].message, input_message);
        strcat(chat_messages[num_messages].message, input_sender);

        add_message(input_sender, input_message);

        print_messages();
    }

    return 0;
}
