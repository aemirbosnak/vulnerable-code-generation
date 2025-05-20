//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the Vehicle structure
typedef struct {
    char name[20];
    int speed;
    char direction[10];
    int position; // Position on a 1D line
} Vehicle;

// Function prototypes
void initializeVehicle(Vehicle *v, const char *name);
void moveForward(Vehicle *v);
void moveBackward(Vehicle *v);
void turnLeft(Vehicle *v);
void turnRight(Vehicle *v);
void stopVehicle(Vehicle *v);
void displayStatus(const Vehicle *v);

int main() {
    Vehicle myVehicle;
    initializeVehicle(&myVehicle, "RC Car");

    while (1) {
        printf("\nRemote Control Vehicle Simulation:\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Stop\n");
        printf("6. Display Status\n");
        printf("7. Exit\n");
        printf("Choose an option (1-7): ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                moveForward(&myVehicle);
                break;
            case 2:
                moveBackward(&myVehicle);
                break;
            case 3:
                turnLeft(&myVehicle);
                break;
            case 4:
                turnRight(&myVehicle);
                break;
            case 5:
                stopVehicle(&myVehicle);
                break;
            case 6:
                displayStatus(&myVehicle);
                break;
            case 7:
                printf("Exiting simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
        usleep(500000);  // Sleep for 0.5 seconds
    }
    return 0;
}

void initializeVehicle(Vehicle *v, const char *name) {
    strncpy(v->name, name, sizeof(v->name) - 1);
    v->speed = 0;
    strcpy(v->direction, "None");
    v->position = 0;
    printf("%s initialized.\n", v->name);
}

void moveForward(Vehicle *v) {
    v->speed = 5;  // define a speed value
    v->position += v->speed;
    strcpy(v->direction, "Forward");
    printf("%s moving forward at speed %d.\n", v->name, v->speed);
}

void moveBackward(Vehicle *v) {
    v->speed = 5;  // define speed value
    v->position -= v->speed;
    strcpy(v->direction, "Backward");
    printf("%s moving backward at speed %d.\n", v->name, v->speed);
}

void turnLeft(Vehicle *v) {
    strcpy(v->direction, "Left");
    printf("%s turning left.\n", v->name);
}

void turnRight(Vehicle *v) {
    strcpy(v->direction, "Right");
    printf("%s turning right.\n", v->name);
}

void stopVehicle(Vehicle *v) {
    v->speed = 0;
    strcpy(v->direction, "Stopped");
    printf("%s has stopped.\n", v->name);
}

void displayStatus(const Vehicle *v) {
    printf("\nVehicle Status:\n");
    printf("Name: %s\n", v->name);
    printf("Speed: %d\n", v->speed);
    printf("Direction: %s\n", v->direction);
    printf("Position: %d\n", v->position);
    printf("--------------------\n");
}