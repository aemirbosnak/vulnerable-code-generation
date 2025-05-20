//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void move_forward(int *x, int *y, int direction);
void move_backward(int *x, int *y, int direction);
void turn_left(int *direction);
void turn_right(int *direction);

int main() {
    int x = 0, y = 0, direction = 0; // starting position and direction
    char input; // user input

    // seed random number generator
    srand(time(NULL));

    printf("Welcome to Retro Remote Control Vehicle Simulation!\n");

    while(1) {
        printf("Current position: (%d, %d)  Direction: %d\n", x, y, direction);

        // prompt user for input
        printf("Enter a command (F/B/L/R/Q): ");
        scanf(" %c", &input);

        // process user input
        switch(input) {
            case 'F':
                move_forward(&x, &y, direction);
                break;
            case 'B':
                move_backward(&x, &y, direction);
                break;
            case 'L':
                turn_left(&direction);
                break;
            case 'R':
                turn_right(&direction);
                break;
            case 'Q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command, please try again.\n");
        }
    }

    return 0;
}

// moves the vehicle forward one unit in the current direction
void move_forward(int *x, int *y, int direction) {
    switch(direction) {
        case 0: // up
            (*y)++;
            break;
        case 1: // right
            (*x)++;
            break;
        case 2: // down
            (*y)--;
            break;
        case 3: // left
            (*x)--;
            break;
    }

    // simulate random obstacle avoidance
    int obstacle = rand() % 10; // generate random number from 0-9
    if(obstacle == 0) {
        printf("Obstacle detected! Vehicle halted.\n");
        move_backward(x, y, direction); // move back to previous position
    }
}

// moves the vehicle backward one unit in the current direction
void move_backward(int *x, int *y, int direction) {
    switch(direction) {
        case 0: // up
            (*y)--;
            break;
        case 1: // right
            (*x)--;
            break;
        case 2: // down
            (*y)++;
            break;
        case 3: // left
            (*x)++;
            break;
    }
}

// turns the vehicle 90 degrees to the left
void turn_left(int *direction) {
    (*direction)--;
    if(*direction < 0) {
        *direction = 3; // wrap around to face left
    }
}

// turns the vehicle 90 degrees to the right
void turn_right(int *direction) {
    (*direction)++;
    if(*direction > 3) {
        *direction = 0; // wrap around to face up
    }
}