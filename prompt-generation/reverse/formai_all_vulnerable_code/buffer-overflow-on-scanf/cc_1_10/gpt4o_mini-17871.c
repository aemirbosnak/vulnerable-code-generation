//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void displayMenu();
void takeOff();
void land();
void moveForward(int distance);
void moveBackward(int distance);
void rotate(int degrees);
void hover(int seconds);

// Main function
int main() {
    int choice = 0;
    
    while (choice != 6) {
        displayMenu();
        printf("Choose your action (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3: {
                int distance;
                printf("Enter distance to move forward (meters): ");
                scanf("%d", &distance);
                moveForward(distance);
                break;
            }
            case 4: {
                int distance;
                printf("Enter distance to move backward (meters): ");
                scanf("%d", &distance);
                moveBackward(distance);
                break;
            }
            case 5: {
                int degrees;
                printf("Enter degrees to rotate (clockwise): ");
                scanf("%d", &degrees);
                rotate(degrees);
                break;
            }
            case 6:
                printf("Exiting the drone control program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nDrone Remote Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Rotate\n");
    printf("6. Exit\n");
}

// Function to simulate take off
void takeOff() {
    printf("The drone is taking off...\n");
    sleep(2);
    printf("The drone has taken off successfully!\n");
}

// Function to simulate landing
void land() {
    printf("The drone is landing...\n");
    sleep(2);
    printf("The drone has landed successfully!\n");
}

// Function to simulate moving forward
void moveForward(int distance) {
    printf("The drone is moving forward %d meters...\n", distance);
    sleep(1);
    printf("The drone has moved forward %d meters!\n", distance);
}

// Function to simulate moving backward
void moveBackward(int distance) {
    printf("The drone is moving backward %d meters...\n", distance);
    sleep(1);
    printf("The drone has moved backward %d meters!\n", distance);
}

// Function to simulate rotating
void rotate(int degrees) {
    printf("The drone is rotating %d degrees clockwise...\n", degrees);
    sleep(1);
    printf("The drone has rotated %d degrees!\n", degrees);
}

// Function to simulate hovering
void hover(int seconds) {
    printf("The drone is hovering for %d seconds...\n", seconds);
    sleep(seconds);
    printf("The drone has finished hovering!\n");
}