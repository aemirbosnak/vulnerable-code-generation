//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Define various states for the remote control vehicle
typedef struct {
    int speed;
    char color[20];
    int x, y; // Vehicle's position
} RC_Vehicle;

// Function prototypes
void displayMenu();
void changeSpeed(RC_Vehicle *vehicle);
void changeColor(RC_Vehicle *vehicle);
void moveVehicle(RC_Vehicle *vehicle);
void displayStatus(RC_Vehicle *vehicle);

int main() {
    RC_Vehicle vehicle = {0, "Red", 0, 0}; // Initialize vehicle properties
    int choice;

    printf("Welcome to the RC Vehicle Simulator!\n");
    printf("Get ready for some excitement!\n");
    
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                changeSpeed(&vehicle);
                break;
            case 2:
                changeColor(&vehicle);
                break;
            case 3:
                moveVehicle(&vehicle);
                break;
            case 4:
                displayStatus(&vehicle);
                break;
            case 5:
                printf("Thanks for playing! Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
        usleep(500000); // Pause for a moment to make it manageable
    }
    
    return 0;
}

// Display the menu options
void displayMenu() {
    printf("\n---- RC Vehicle Control Menu ----\n");
    printf("1. Change Speed\n");
    printf("2. Change Color\n");
    printf("3. Move Vehicle\n");
    printf("4. Display Status\n");
    printf("5. Exit\n");
}

// Function to change the speed of the RC vehicle
void changeSpeed(RC_Vehicle *vehicle) {
    int newSpeed;
    printf("Enter new speed (0-100): ");
    scanf("%d", &newSpeed);
    
    if (newSpeed < 0 || newSpeed > 100) {
        printf("Invalid speed! Must be between 0 and 100.\n");
    } else {
        vehicle->speed = newSpeed;
        printf("Speed changed to %d!\n", vehicle->speed);
    }
}

// Function to change the color of the RC vehicle
void changeColor(RC_Vehicle *vehicle) {
    char newColor[20];
    printf("Enter new color: ");
    scanf("%s", newColor);
    strcpy(vehicle->color, newColor);
    printf("Color changed to %s!\n", vehicle->color);
}

// Function to move the vehicle
void moveVehicle(RC_Vehicle *vehicle) {
    int distance;
    printf("Enter distance to move (in units): ");
    scanf("%d", &distance);
    
    vehicle->x += distance;
    vehicle->y += distance; // Move diagonally for simplicity
    printf("Vehicle moved! New position: (%d, %d)\n", vehicle->x, vehicle->y);
}

// Function to display the vehicle's current status
void displayStatus(RC_Vehicle *vehicle) {
    printf("\n---- Vehicle Status ----\n");
    printf("Speed: %d\n", vehicle->speed);
    printf("Color: %s\n", vehicle->color);
    printf("Position: (%d, %d)\n", vehicle->x, vehicle->y);
    printf("-------------------------\n");
}