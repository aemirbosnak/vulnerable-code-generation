//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of steps robot can take
#define MAX_STEPS 100

// Define robot's initial position and direction
int x_pos = 0;
int y_pos = 0;
char direction = 'N';

// Define function to move robot forward by one step
void move_forward() {
    printf("Robot moves forward.\n");
    if (direction == 'N') {
        y_pos += 1;
    } else if (direction == 'E') {
        x_pos += 1;
    } else if (direction == 'S') {
        y_pos -= 1;
    } else if (direction == 'W') {
        x_pos -= 1;
    }
}

// Define function to turn robot to the right one step
void turn_right() {
    printf("Robot turns right.\n");
    if (direction == 'N') {
        direction = 'E';
    } else if (direction == 'E') {
        direction = 'S';
    } else if (direction == 'S') {
        direction = 'W';
    } else if (direction == 'W') {
        direction = 'N';
    }
}

// Define function to turn robot to the left one step
void turn_left() {
    printf("Robot turns left.\n");
    if (direction == 'N') {
        direction = 'W';
    } else if (direction == 'W') {
        direction = 'S';
    } else if (direction == 'S') {
        direction = 'E';
    } else if (direction == 'E') {
        direction = 'N';
    }
}

int main() {
    // Define array to store robot's movement commands
    char commands[MAX_STEPS];

    // Get user input for movement commands
    printf("Enter robot movement commands (F for forward, R for right, L for left):\n");
    scanf("%s", commands);

    // Loop through movement commands and perform corresponding actions
    for (int i = 0; commands[i] != '\0'; i++) {
        if (commands[i] == 'F') {
            move_forward();
        } else if (commands[i] == 'R') {
            turn_right();
        } else if (commands[i] == 'L') {
            turn_left();
        } else {
            printf("Invalid command: %c\n", commands[i]);
        }
    }

    // Print final position and direction of robot
    printf("Final position: (%d, %d)\n", x_pos, y_pos);
    printf("Final direction: %c\n", direction);

    return 0;
}