#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void display_messages(char **messages, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s\n", messages[i]);
    }
}

int main(int argc, char **argv) {
    char buffer[BUFFER_SIZE];
    char **messages = malloc(BUFFER_SIZE * sizeof(char *));
    int message_count = 0;

    while (1) {
        printf("Enter a chat message (or type 'quit' to exit): ");
        gets(buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        messages[message_count] = malloc(strlen(buffer) + 1);
        strcpy(messages[message_count], buffer);
        message_count++;

        if (message_count == BUFFER_SIZE) {
            printf("Buffer is full. Cannot accept more messages.\n");
        }
    }

    printf("\nMessages:\n");
    display_messages(messages, message_count);

    for (int i = 0; i < message_count; ++i) {
        free(messages[i]);
    }
    free(messages);

    return 0;
}
