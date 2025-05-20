#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void executeCommand(char* command) {
    if (strcmp(command, "takeoff") == 0) {
        printf("Drone taking off.\n");
    } else if (strcmp(command, "land") == 0) {
        printf("Drone landing.\n");
    } else if (strcmp(command, "move forward") == 0) {
        printf("Drone moving forward.\n");
    } else if (strcmp(command, "move backward") == 0) {
        printf("Drone moving backward.\n");
    } else if (strcmp(command, "turn left") == 0) {
        printf("Drone turning left.\n");
    } else if (strcmp(command, "turn right") == 0) {
        printf("Drone turning right.\n");
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character if present
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            break;
        }

        executeCommand(command);
    }

    return 0;
}
