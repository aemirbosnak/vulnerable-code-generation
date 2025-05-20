#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct ChatMessage {
    char message[BUFFER_SIZE];
    struct ChatMessage *next;
} ChatMessage;

ChatMessage *messages = NULL;

void append_message(const char *message) {
    ChatMessage *new_message = malloc(sizeof(ChatMessage));
    if (!new_message) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    strcpy(new_message->message, message);
    new_message->next = messages;
    messages = new_message;
}

void free_messages() {
    ChatMessage *current = messages;
    messages = NULL;
    while (current) {
        ChatMessage *temp = current;
        current = current->next;
        free(temp);
    }
}

void display_messages() {
    ChatMessage *current = messages;
    while (current) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

int main() {
    append_message("Hello, World!");
    append_message("This is a chat message buffer manager tool.");
    append_message("It's not secure and deliberately contains a use after free vulnerability.");

    display_messages();

    free_messages();

    // Use the freed memory after freeing it.
    append_message("Oops, I just leaked and used this memory again.");

    display_messages();

    return 0;
}
