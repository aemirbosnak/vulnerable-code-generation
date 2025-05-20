//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// function to move the car forward
void moveForward(int *x, int *y, char orientation) {
    if(orientation == 'N') {
        (*y)++;
    } else if(orientation == 'S') {
        (*y)--;
    } else if(orientation == 'E') {
        (*x)++;
    } else if(orientation == 'W') {
        (*x)--;
    }  
}

// function to move the car backward
void moveBackward(int *x, int *y, char orientation) {
    if(orientation == 'N') {
        (*y)--;
    } else if(orientation == 'S') {
        (*y)++;
    } else if(orientation == 'E') {
        (*x)--;
    } else if(orientation == 'W') {
        (*x)++;
    }  
}

// function to change the direction of the car
void turn(char *orientation, char direction) {
    if(direction == 'L') {
        if((*orientation) == 'N') {
            (*orientation) = 'W';
        } else if((*orientation) == 'S') {
            (*orientation) = 'E';
        } else if((*orientation) == 'E') {
            (*orientation) = 'N';
        } else if((*orientation) == 'W') {
            (*orientation) = 'S';
        } 
    } else if(direction == 'R') {
         if((*orientation) == 'N') {
            (*orientation) = 'E';
        } else if((*orientation) == 'S') {
            (*orientation) = 'W';
        } else if((*orientation) == 'E') {
            (*orientation) = 'S';
        } else if((*orientation) == 'W') {
            (*orientation) = 'N';
        } 
    }
}

// function to print the current position of the car
void printPosition(int x, int y, char orientation) {
    printf("Current Position: (%d,%d) (%c)\n", x, y, orientation);
}

// main function
int main() {
    int x = 0;
    int y = 0;
    char orientation = 'N';

    printf("Initial Position: (%d,%d) (%c)\n", x, y, orientation);

    // simulate moving the car based on input commands
    char cmd;
    while(1) {
        printf("Enter command (F=move forward, B=move backward, L=turn left, R=turn right, Q=quit): ");
        scanf(" %c", &cmd);

        if(cmd == 'F') {
            moveForward(&x, &y, orientation);
        } else if(cmd == 'B') {
            moveBackward(&x, &y, orientation);
        } else if(cmd == 'L' || cmd == 'R') {
            turn(&orientation, cmd);
        } else if(cmd == 'Q') {
            break;
        }

        printPosition(x, y, orientation);
    }

    return 0;
}