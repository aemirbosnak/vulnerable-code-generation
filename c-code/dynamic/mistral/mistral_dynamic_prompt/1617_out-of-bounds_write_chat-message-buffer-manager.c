#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 140

struct Message {
    char username[MAX_USERNAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

void receive_message(struct Message *message) {
    printf("Enter username: ");
    fgets(message->username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter message: ");
    fgets(message->message, MAX_MESSAGE_LENGTH, stdin);
}

void send_message(struct Message *message) {
    printf("\n%s: %s", message->username, message->message);
}

int main() {
    struct Message messages[100];
    int num_messages = 0;

    while (1) {
        receive_message(&messages[num_messages]);
        num_messages++;

        if (num_messages >= 100) {
            printf("Chat buffer is full!\n");
            break;
        }

        send_message(&messages[num_messages - 1]);
    }

    return 0;
}
