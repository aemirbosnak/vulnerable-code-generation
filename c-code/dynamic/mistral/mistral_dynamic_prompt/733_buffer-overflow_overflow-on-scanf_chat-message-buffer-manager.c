#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

typedef struct ChatMessage {
    char message[BUFFER_SIZE];
    struct ChatMessage *next;
} ChatMessage;

ChatMessage *messages = NULL;

void addMessage(char *message) {
    ChatMessage *newMessage = (ChatMessage *)malloc(sizeof(ChatMessage));
    strcpy(newMessage->message, message);
    newMessage->next = messages;
    messages = newMessage;
}

int main() {
    char buffer[BUFFER_SIZE];
    char *message;

    printf("Enter messages (type 'END' to quit):\n");

    while (1) {
        scanf("%100s", buffer);
        if (!strcmp(buffer, "END"))
            break;
        message = (char *)realloc(message, strlen(buffer) + 1);
        strcpy(message, buffer);
        addMessage(message);
        message = NULL;
    }

    ChatMessage *current = messages;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }

    return 0;
}
