//FormAI DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>

// Define constants for movement commands
#define FORWARD 1
#define RIGHT 2
#define LEFT 3
#define BACKWARD 4

// Function to execute movement commands
void move(int command, int steps) {
    switch(command) {
        case FORWARD:
            printf("Moving forward %d steps...", steps);
            break;
        case RIGHT:
            printf("Turning right and moving %d steps...", steps);
            break;
        case LEFT:
            printf("Turning left and moving %d steps...", steps);
            break;
        case BACKWARD:
            printf("Moving backward %d steps...", steps);
            break;
        default:
            printf("Invalid command!");
            break;
    }
}

int main() {
    int command, steps, i;

    // Introduce yourself
    printf("Hello! I am an invasive robot.\n");

    // Ask user for commands
    printf("\nPlease enter the number of steps to move forward: ");
    scanf("%d", &steps);

    // Execute forward movement command
    move(FORWARD, steps);

    // Ask user for more commands
    printf("\n\nWhat's next?\nEnter 1 to turn right, 2 to turn left, or 3 to move backward: ");
    scanf("%d", &command);

    // Execute next movement command
    switch(command) {
        case RIGHT:
            move(RIGHT, steps);
            break;
        case LEFT:
            move(LEFT, steps);
            break;
        case BACKWARD:
            move(BACKWARD, steps);
            break;
        default:
            printf("Invalid command!");
            break;
    }

    // Ask user for more commands
    printf("\n\nWhat's next?\nEnter 1 to turn right, 2 to turn left, or 4 to move forward again: ");
    scanf("%d", &command);

    // Execute final movement command
    if(command == FORWARD) {
        move(FORWARD, steps);
    } else if(command == RIGHT) {
        move(RIGHT, steps);
    } else if(command == LEFT) {
        move(LEFT, steps);
    } else {
        printf("Invalid command!");
    }

    return 0;
}