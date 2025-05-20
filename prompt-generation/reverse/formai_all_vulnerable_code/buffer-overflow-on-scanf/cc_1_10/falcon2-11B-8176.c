//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the elevator status
void printStatus(int floor, int direction) {
    printf("Current floor: %d\n", floor);
    printf("Direction: %d\n", direction);
}

// Function to move the elevator up
void moveUp() {
    int floor = rand() % 10 + 1; // Random floor number between 1 and 10
    int direction = 1; // Moving up
    printStatus(floor, direction);
}

// Function to move the elevator down
void moveDown() {
    int floor = rand() % 10 + 1; // Random floor number between 1 and 10
    int direction = -1; // Moving down
    printStatus(floor, direction);
}

// Function to start the elevator simulation
int main() {
    int choice;

    printf("Welcome to the Elevator Simulation!\n");

    do {
        printf("1. Move Up\n");
        printf("2. Move Down\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveUp();
                break;
            case 2:
                moveDown();
                break;
            case 3:
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}