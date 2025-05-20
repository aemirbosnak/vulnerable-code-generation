#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 10

void execute_command(char *command) {
    if (strlen(command) > MAX_COMMAND_LENGTH - 1) {
        printf("Error: Command too long.\n");
        return;
    }
    // Simulate command execution
    printf("Executing command: %s\n", command);
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter light control command (or 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "exit", 4) == 0) {
            break;
        }

        // Remove newline character if present
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        execute_command(command);
    }

    return 0;
}
