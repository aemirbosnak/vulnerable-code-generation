#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *buffer) {
    char command[10];
    strcpy(command, buffer);

    if (strncmp(command, "move ", 5) == 0) {
        int direction = command[5] - '0';
        switch (direction) {
            case 1:
                printf("Moving forward...\n");
                break;
            case 2:
                printf("Moving backward...\n");
                break;
            case 3:
                printf("Moving left...\n");
                break;
            case 4:
                printf("Moving right...\n");
                break;
            default:
                printf("Invalid direction. Please use 1, 2, 3, or 4.\n");
        }
    } else {
        printf("Unrecognized command.\n");
    }
}

int main() {
    char input[1000];

    while (1) {
        printf("Enter your command: ");
        fscanf(stdin, "%s", input);
        process_input(input);
    }

    return 0;
}
