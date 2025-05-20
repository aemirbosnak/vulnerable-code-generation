#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct ChatMessage {
    char content[1];
} ChatMessage;

int main() {
    ChatMessage *buffer = (ChatMessage *) malloc(sizeof(ChatMessage) * 1000);
    int index = 0;

    printf("Welcome to the Unsafe Chat Message Buffer Manager\n");

    while (1) {
        printf("Enter message content or type 'quit' to exit: ");
        char message[256];
        scanf("%255s", message);

        if (!strcmp(message, "quit")) {
            break;
        }

        buffer[index].content[0] = message[0];
        buffer[index].content[1] = '\0'; // Just for aesthetic reasons, this is not necessary
        index = (index + 1) % 1000;
        printf("Message [%d]: %s\n", index, buffer[index].content);
    }

    free(buffer);
    return 0;
}
