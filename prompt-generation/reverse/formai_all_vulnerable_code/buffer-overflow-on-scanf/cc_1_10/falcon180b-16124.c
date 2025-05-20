//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Drone control functions
void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void hover(int speed);

// Main program
int main() {
    srand(time(NULL));
    int speed = rand() % 11 + 1; // Random speed between 1 and 10
    int choice;

    // Main loop
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Hover\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveForward(speed);
                break;
            case 2:
                moveBackward(speed);
                break;
            case 3:
                turnLeft(speed);
                break;
            case 4:
                turnRight(speed);
                break;
            case 5:
                hover(speed);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Drone control functions
void moveForward(int speed) {
    printf("Drone is moving forward at %d speed.\n", speed);
}

void moveBackward(int speed) {
    printf("Drone is moving backward at %d speed.\n", speed);
}

void turnLeft(int speed) {
    printf("Drone is turning left at %d speed.\n", speed);
}

void turnRight(int speed) {
    printf("Drone is turning right at %d speed.\n", speed);
}

void hover(int speed) {
    printf("Drone is hovering at %d speed.\n", speed);
}