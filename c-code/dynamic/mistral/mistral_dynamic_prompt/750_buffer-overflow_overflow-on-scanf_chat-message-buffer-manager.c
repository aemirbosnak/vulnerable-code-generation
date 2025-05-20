#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_messages(char messages[][BUFFER_SIZE]) {
    for (int i = 0; messages[i][0] != '\0'; ++i) {
        printf("%s\n", messages[i]);
    }
}

int main() {
    char messages[10][BUFFER_SIZE];
    int message_count = 0;

    while (1) {
        printf("Enter a chat message or type 'quit' to exit:\n");

        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);

        strcpy(messages[message_count], input);
        message_count++;

        if (strcmp(input, "quit\n") == 0) {
            break;
        }
    }

    printf("\nMessages:\n");
    display_messages(messages);

    return 0;
}
