//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulation variables
int carX = 0;
int carY = 0;
char direction = 'N';

// Function declarations
void moveForward();
void turnRight();
void turnLeft();
void printLocation();

int main() {
    char input[10];

    // Main program loop
    while(1) {
        printf("Enter a command: ");
        scanf("%s", input);

        // Check user input and execute corresponding function
        if(strcmp(input, "F") == 0) {
            moveForward();
        } else if(strcmp(input, "R") == 0) {
            turnRight();
        } else if(strcmp(input, "L") == 0) {
            turnLeft();
        } else if(strcmp(input, "Q") == 0) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid command, please try again.\n");
            continue;
        }

        printLocation();
    }

    return 0;
}

// Function to move the car forward
void moveForward() {
    switch(direction) {
        case 'N':
            carY++;
            break;
        case 'E':
            carX++;
            break;
        case 'S':
            carY--;
            break;
        case 'W':
            carX--;
            break;
    }
}

// Function to turn the car right
void turnRight() {
    switch(direction) {
        case 'N':
            direction = 'E';
            break;
        case 'E':
            direction = 'S';
            break;
        case 'S':
            direction = 'W';
            break;
        case 'W':
            direction = 'N';
            break;
    }
}

// Function to turn the car left
void turnLeft() {
    switch(direction) {
        case 'N':
            direction = 'W';
            break;
        case 'E':
            direction = 'N';
            break;
        case 'S':
            direction = 'E';
            break;
        case 'W':
            direction = 'S';
            break;
    }
}

// Function to print the current location of the car
void printLocation() {
    printf("Current location: (%d, %d) facing %c\n", carX, carY, direction);
}