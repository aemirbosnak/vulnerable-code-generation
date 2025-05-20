//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void moveForward(int *distance, int *battery);
void moveBackward(int *distance);
void turnLeft(int *orientation);
void turnRight(int *orientation);
void status(int distance, int battery, int orientation);

// Main function
int main() {
    srand(time(0));
    int distance = 0;
    int battery = 100;
    int orientation = rand() % 360;
    displayMenu();
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveForward(&distance, &battery);
                break;
            case 2:
                moveBackward(&distance);
                break;
            case 3:
                turnLeft(&orientation);
                break;
            case 4:
                turnRight(&orientation);
                break;
            case 5:
                status(distance, battery, orientation);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
                displayMenu();
                continue;
        }
        if (distance >= 100) {
            printf("Congratulations! You have reached the target distance.\n");
            exit(0);
        }
        if (battery <= 0) {
            printf("Your battery has run out! Game over.\n");
            exit(0);
        }
    }
    return 0;
}

// Display the menu
void displayMenu() {
    printf("Remote Control Vehicle Simulation\n\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Status\n");
    printf("6. Quit program\n\n");
}

// Move forward
void moveForward(int *distance, int *battery) {
    int steps = rand() % 20 + 1;
    int energy = steps * 2;
    if (energy > *battery) {
        printf("Sorry, not enough battery remaining.\n");
        return;
    }
    printf("Moving forward %d steps...\n", steps);
    *distance += steps;
    *battery -= energy;
}

// Move backward
void moveBackward(int *distance) {
    int steps = rand() % 10 + 1;
    printf("Moving backward %d steps...\n", steps);
    *distance -= steps;
}

// Turn left
void turnLeft(int *orientation) {
    int degrees = rand() % 45 + 1;
    printf("Turning left %d degrees...\n", degrees);
    *orientation -= degrees;
    if (*orientation < 0) {
        *orientation += 360;
    }
}

// Turn right
void turnRight(int *orientation) {
    int degrees = rand() % 45 + 1;
    printf("Turning right %d degrees...\n", degrees);
    *orientation += degrees;
    if (*orientation >= 360) {
        *orientation -= 360;
    }
}

// Check status
void status(int distance, int battery, int orientation) {
    printf("Distance traveled: %d steps\n", distance);
    printf("Battery remaining: %d%%\n", battery);
    printf("Orientation: %d degrees\n", orientation);
}