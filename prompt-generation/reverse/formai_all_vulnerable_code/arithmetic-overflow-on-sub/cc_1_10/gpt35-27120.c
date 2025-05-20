//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Global variables
int altitude = 0;
int speed = 0;
int x_pos = 0;
int y_pos = 0;

// Function to take off the drone
void takeOff() {
    printf("Drone taking off...\n");
    altitude = 50;
}

// Function to move the drone forward
void moveForward(int distance) {
    printf("Drone moving forward %d meters...\n", distance);
    x_pos += distance;
}

// Function to move the drone backward
void moveBackward(int distance) {
    printf("Drone moving backward %d meters...\n", distance);
    x_pos -= distance;
}

// Function to move the drone left
void moveLeft(int distance) {
    printf("Drone moving left %d meters...\n", distance);
    y_pos -= distance;
}

// Function to move the drone right
void moveRight(int distance) {
    printf("Drone moving right %d meters...\n", distance);
    y_pos += distance;
}

// Function to increase speed of the drone
void increaseSpeed(int amount) {
    printf("Increasing drone speed by %d km/h...\n", amount);
    speed += amount;
}

// Function to decrease speed of the drone
void decreaseSpeed(int amount) {
    printf("Decreasing drone speed by %d km/h...\n", amount);
    speed -= amount;
}

// Function to land the drone
void land() {
    printf("Drone landing...\n");
    altitude = 0;
}

// Main function
int main() {
    char choice;
    int distance, amount;

    printf("Welcome to the C Drone Remote Control Program!\n\n");

    do {
        printf("Altitude: %d m, Speed: %d km/h, Position: (%d, %d)\n\n", altitude, speed, x_pos, y_pos);
        printf("Enter a choice:\n");
        printf("1. Take off the drone\n");
        printf("2. Move the drone forward\n");
        printf("3. Move the drone backward\n");
        printf("4. Move the drone left\n");
        printf("5. Move the drone right\n");
        printf("6. Increase drone speed\n");
        printf("7. Decrease drone speed\n");
        printf("8. Land the drone\n");
        printf("9. Quit the program\n\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (altitude == 0) {
                    takeOff();
                } else {
                    printf("Drone is already in the air.\n\n");
                }
                break;
            case '2':
                if (altitude == 0) {
                    printf("Drone is on the ground.\n\n");
                } else {
                    printf("Enter distance to move forward: ");
                    scanf("%d", &distance);
                    moveForward(distance);
                }
                break;
            case '3':
                if (altitude == 0) {
                    printf("Drone is on the ground.\n\n");
                } else {
                    printf("Enter distance to move backward: ");
                    scanf("%d", &distance);
                    moveBackward(distance);
                }
                break;
            case '4':
                if (altitude == 0) {
                    printf("Drone is on the ground.\n\n");
                } else {
                    printf("Enter distance to move left: ");
                    scanf("%d", &distance);
                    moveLeft(distance);
                }
                break;
            case '5':
                if (altitude == 0) {
                    printf("Drone is on the ground.\n\n");
                } else {
                    printf("Enter distance to move right: ");
                    scanf("%d", &distance);
                    moveRight(distance);
                }
                break;
            case '6':
                printf("Enter amount to increase speed: ");
                scanf("%d", &amount);
                increaseSpeed(amount);
                break;
            case '7':
                printf("Enter amount to decrease speed: ");
                scanf("%d", &amount);
                decreaseSpeed(amount);
                break;
            case '8':
                if (altitude == 0) {
                    printf("Drone is already on the ground.\n\n");
                } else {
                    land();
                }
                break;
            case '9':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while (choice != '9');

    return 0;
}