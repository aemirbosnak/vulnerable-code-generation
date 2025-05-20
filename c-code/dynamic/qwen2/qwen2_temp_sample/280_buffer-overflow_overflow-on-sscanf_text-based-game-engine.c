#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parse_command(char *command) {
    char buffer[10];
    if (sscanf(command, "%s", buffer) == 1) {
        printf("Command received: %s\n", buffer);
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    char input[20];
    printf("Welcome to the Text-Based Game Engine!\n");
    printf("Enter 'start' to begin the game or 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the game engine.\n");
            break;
        }

        parse_command(input);
    }

    return 0;
}
