//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Drone control simulation functions
void takeOff() {
    printf("Drone is taking off...\n");
}

void land() {
    printf("Drone is landing...\n");
}

void moveForward() {
    printf("Drone is moving forward...\n");
}

void moveBackward() {
    printf("Drone is moving backward...\n");
}

void moveLeft() {
    printf("Drone is moving left...\n");
}

void moveRight() {
    printf("Drone is moving right...\n");
}

void hover() {
    printf("Drone is hovering in place...\n");
}

int main() {
    int choice;
    char droneName[50];

    printf("Welcome to Drone Remote Control\n");
    printf("Please enter your drone's name: ");
    fgets(droneName, sizeof(droneName), stdin);
    // Remove trailing newline character from name
    droneName[strcspn(droneName, "\n")] = 0;

    while (1) {
        printf("\n--- %s Control Menu ---\n", droneName);
        printf("1. Take Off\n");
        printf("2. Land\n");
        printf("3. Move Forward\n");
        printf("4. Move Backward\n");
        printf("5. Move Left\n");
        printf("6. Move Right\n");
        printf("7. Hover\n");
        printf("8. Exit\n");
        printf("Please choose an option (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3:
                moveForward();
                break;
            case 4:
                moveBackward();
                break;
            case 5:
                moveLeft();
                break;
            case 6:
                moveRight();
                break;
            case 7:
                hover();
                break;
            case 8:
                printf("Exiting control for %s\n", droneName);
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }

        // Simulate a delay to prevent too fast commands
        sleep(1);
    }

    return 0;
}