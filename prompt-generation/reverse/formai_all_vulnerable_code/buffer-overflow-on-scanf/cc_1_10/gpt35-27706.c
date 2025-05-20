//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

/* Define constants for the drone's movement */
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main() {
    /* Initialize variables for the drone's movement */
    int direction;
    int speed;

    /* Prompt user for desired direction and speed */
    printf("Welcome to the drone control program.\n");
    printf("Please enter the direction you want to move (1 - forward, 2 - backward, 3 - left, 4 - right): ");
    scanf("%d", &direction);

    printf("Please enter the speed (1 - slow, 2 - medium, 3 - fast): ");
    scanf("%d", &speed);

    /* Send command to the drone based on user input */
    switch (direction) {
        case FORWARD:
            printf("Moving drone forward with speed ");
            break;
        case BACKWARD:
            printf("Moving drone backward with speed ");
            break;
        case LEFT:
            printf("Moving drone left with speed ");
            break;
        case RIGHT:
            printf("Moving drone right with speed ");
            break;
        default:
            printf("Invalid direction input. Please try again.\n");
            exit(0);
    }

    /* Set speed based on user input */
    switch (speed) {
        case 1:
            printf("slow.\n");
            break;
        case 2:
            printf("medium.\n");
            break;
        case 3:
            printf("fast.\n");
            break;
        default:
            printf("Invalid speed input. Please try again.\n");
            exit(0);
    }

    /* Exit program */
    return 0;
}