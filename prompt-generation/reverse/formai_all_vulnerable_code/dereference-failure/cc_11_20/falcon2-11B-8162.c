//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];
    int index = 0;

    while (1) {
        printf("Enter your command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcmp(buffer, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        }

        char *command = strtok(buffer, " ");

        if (strcmp(command, "up") == 0) {
            printf("Moving up...\n");
            system("./c_drone -u");
        } else if (strcmp(command, "down") == 0) {
            printf("Moving down...\n");
            system("./c_drone -d");
        } else if (strcmp(command, "left") == 0) {
            printf("Moving left...\n");
            system("./c_drone -l");
        } else if (strcmp(command, "right") == 0) {
            printf("Moving right...\n");
            system("./c_drone -r");
        } else if (strcmp(command, "forward") == 0) {
            printf("Moving forward...\n");
            system("./c_drone -f");
        } else if (strcmp(command, "backward") == 0) {
            printf("Moving backward...\n");
            system("./c_drone -b");
        } else if (strcmp(command, "rotate_clockwise") == 0) {
            printf("Rotating clockwise...\n");
            system("./c_drone -c");
        } else if (strcmp(command, "rotate_counter_clockwise") == 0) {
            printf("Rotating counter-clockwise...\n");
            system("./c_drone -cc");
        } else {
            printf("Invalid command!\n");
        }

        index++;
    }

    return 0;
}