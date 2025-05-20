#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command) {
    char buffer[32];
    if (sscanf(command, "%s", buffer) == 1) {
        printf("Executing: %s\n", buffer);
        // Simulate some actions based on the command
        if (strcmp(buffer, "on") == 0) {
            printf("Lighting turned ON.\n");
        } else if (strcmp(buffer, "off") == 0) {
            printf("Lighting turned OFF.\n");
        } else if (strcmp(buffer, "dim") == 0) {
            printf("Lighting dimmed.\n");
        } else {
            printf("Unknown command.\n");
        }
    } else {
        printf("Invalid command format.\n");
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command ('exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        // Remove newline character from input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        execute_command(input);
    }

    return 0;
}
