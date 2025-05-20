//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Welcome to the CDRone Remote Control Program!\n");
    printf("Enter 'help' for a list of commands.\n\n");

    while (1) {
        printf(">> ");
        fgets(input, 100, stdin); // read user input
        
        // remove newline character from input
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(input, "help") == 0) {
            printf("Available Commands:\n");
            printf("takeoff         - Take off the drone.\n");
            printf("land            - Land the drone.\n");
            printf("forward <speed> - Move the drone forward at the specified speed (0-100).\n");
            printf("backward <speed>- Move the drone backward at the specified speed (0-100).\n");
            printf("left <speed>    - Move the drone left at the specified speed (0-100).\n");
            printf("right <speed>   - Move the drone right at the specified speed (0-100).\n");
            printf("up <speed>      - Move the drone up at the specified speed (0-100).\n");
            printf("down <speed>    - Move the drone down at the specified speed (0-100).\n");
            printf("rotate <angle>  - Rotate the drone clockwise by the specified angle (0-360).\n");
            printf("quit            - Exit the program.\n");
        }
        else if (strcmp(input, "takeoff") == 0) {
            printf("Taking off the drone!\n");
            // code to activate the drone's takeoff sequence
        }
        else if (strcmp(input, "land") == 0) {
            printf("Landing the drone!\n");
            // code to activate the drone's landing sequence
        }
        else if (strncmp(input, "forward", 7) == 0) {
            int speed = atoi(input + 8);
            printf("Moving the drone forward at speed %d.\n", speed);
            // code to move the drone forward at the specified speed
        }
        else if (strncmp(input, "backward", 8) == 0) {
            int speed = atoi(input + 9);
            printf("Moving the drone backward at speed %d.\n", speed);
            // code to move the drone backward at the specified speed
        }
        else if (strncmp(input, "left", 4) == 0) {
            int speed = atoi(input + 5);
            printf("Moving the drone left at speed %d.\n", speed);
            // code to move the drone left at the specified speed
        }
        else if (strncmp(input, "right", 5) == 0) {
            int speed = atoi(input + 6);
            printf("Moving the drone right at speed %d.\n", speed);
            // code to move the drone right at the specified speed
        }
        else if (strncmp(input, "up", 2) == 0) {
            int speed = atoi(input + 3);
            printf("Moving the drone up at speed %d.\n", speed);
            // code to move the drone up at the specified speed
        }
        else if (strncmp(input, "down", 4) == 0) {
            int speed = atoi(input + 5);
            printf("Moving the drone down at speed %d.\n", speed);
            // code to move the drone down at the specified speed
        }
        else if (strncmp(input, "rotate", 6) == 0) {
            int angle = atoi(input + 7);
            printf("Rotating the drone clockwise by %d degrees.\n", angle);
            // code to rotate the drone clockwise by the specified angle
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command. Enter 'help' to see a list of available commands.\n");
        }

        printf("\n"); // add a newline character after each command is executed
    }

    return 0;
}