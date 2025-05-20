#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10
#define MESSAGE_SIZE 140

struct ChatMessage {
    char buffer[BUFFER_SIZE];
    size_t length;
};

void append_message(struct ChatMessage *message, const char *str) {
    if (message->length + strlen(str) >= BUFFER_SIZE) {
        printf("Error: Message buffer overflow\n");
        return;
    }
    strcpy(message->buffer + message->length, str);
    message->length += strlen(str);
}

int main() {
    struct ChatMessage chat_message;
    char input[MESSAGE_SIZE];
    int i;

    chat_message.length = 0;

    printf("Enter chat messages (Type 'exit' to quit):\n");
    for (i = 0; i < 100; ++i) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        append_message(&chat_message, input);
    }

    printf("Chat messages:\n");
    printf("%s\n", chat_message.buffer);

    // Dereference failure vulnerability intentionally added
    printf("%c", chat_message.buffer[chat_message.length]);

    return 0;
}
