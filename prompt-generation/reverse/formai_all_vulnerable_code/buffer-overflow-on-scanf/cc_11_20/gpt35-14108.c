//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   int speed = 0;
   char direction = 'N';

   printf("Welcome to C Drone Remote Control\n");
   printf("Please enter a speed (0-10): ");
   scanf("%d", &speed);

    while (speed < 0 || speed > 10) {
        printf("Invalid speed, please enter a value between 0 and 10: ");
        scanf("%d", &speed);
    }

    printf("Please enter the drone's initial direction (N, E, S, W): ");
    scanf(" %c", &direction);

    while (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W') {
        printf("Invalid direction, please enter a value of N, E, S, or W: ");
        scanf(" %c", &direction);
    }

    printf("The drone is now flying at a speed of %d and heading %c\n", speed, direction);

    char input[10];

    printf("Enter command (e.g. 'forward 3', 'up 5', 'turn left') or 'exit' to quit: ");

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "forward") == 0) {
            int distance;
            scanf("%d", &distance);
            printf("Moving forward %d units\n", distance);
        } else if (strcmp(input, "backward") == 0) {
            int distance;
            scanf("%d", &distance);
            printf("Moving backward %d units\n", distance);
        } else if (strcmp(input, "left") == 0) {
            printf("Turning left\n");
        } else if (strcmp(input, "right") == 0) {
            printf("Turning right\n");
        } else if (strcmp(input, "up") == 0) {
            int altitude;
            scanf("%d", &altitude);
            printf("Ascending to altitude of %d units\n", altitude);
        } else if (strcmp(input, "down") == 0) {
            int altitude;
            scanf("%d", &altitude);
            printf("Descending to altitude of %d units\n", altitude);
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting the program\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}