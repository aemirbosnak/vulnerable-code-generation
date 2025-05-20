#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void control_light(char *input) {
    char command[10];
    char state[3];

    strcpy(command, strtok(input, " "));
    strcpy(state, strtok(NULL, " "));

    if (strcmp(command, "turn") == 0) {
        if (strcmp(state, "on") == 0) {
            printf("Light is turned on.\n");
        } else if (strcmp(state, "off") == 0) {
            printf("Light is turned off.\n");
        } else {
            printf("Invalid state provided.\n");
        }
    } else {
        printf("Invalid command provided.\n");
    }

    char buffer[256];
    sscanf(input, "turn %s %s %s", command, state, buffer);
}

int main() {
    char input[512];

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    control_light(input);

    return 0;
}
