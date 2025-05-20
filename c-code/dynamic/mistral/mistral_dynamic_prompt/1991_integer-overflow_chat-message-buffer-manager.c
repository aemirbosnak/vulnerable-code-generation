#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char message[1024];
    char sender[32];
} ChatMessage;

void receiveMessage(ChatMessage *message) {
    printf("Enter your message: ");
    fgets(message->message, sizeof(message->message), stdin);
    strcpy(message->sender, "Anonymous");
}

void printMessage(const ChatMessage *message) {
    printf("%s: %s\n", message->sender, message->message);
}

int main() {
    ChatMessage messages[1000];
    char input[32];
    int i = 0;

    while (1) {
        printf("Type 'quit' to exit.\n");
        receiveMessage(&messages[i]);
        if (!strncmp(messages[i].message, "quit", 4)) break;

        i = (i + 1) % 1000;
        strcpy(input, messages[i].message);
        strcat(input, "\0");
        strcat(input, messages[i].sender);

        if (strlen(input) > sizeof(messages[i].message) - sizeof(messages[i].sender)) {
            printf("Message from %s was truncated due to size constraints.\n", messages[i].sender);
        } else {
            strcpy(messages[i].message, input);
        }

        printMessage(&messages[i]);
    }

    return 0;
}
