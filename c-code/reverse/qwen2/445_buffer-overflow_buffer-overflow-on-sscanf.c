#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void control_light(char *command) {
    int light_id;
    char action[20];

    if (sscanf(command, "%d %s", &light_id, action) != 2) {
        printf("Invalid command format. Usage: <light_id> <action>\n");
        return;
    }

    if (strlen(action) > 9 || strlen(action) == 0) {
        printf("Action must be 'on' or 'off'.\n");
        return;
    }

    if (light_id < 1 || light_id > 10) {
        printf("Light ID must be between 1 and 10.\n");
        return;
    }

    if (strcmp(action, "on") == 0) {
        printf("Turning light %d on.\n", light_id);
    } else if (strcmp(action, "off") == 0) {
        printf("Turning light %d off.\n", light_id);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command (or 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "exit", 4) == 0) {
            break;
        }

        // Remove newline character if present
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        control_light(command);
    }

    return 0;
}
