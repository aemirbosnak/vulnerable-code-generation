//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the structure for the remote control vehicle
typedef struct {
    char name[20];
    int battery_level;
    int speed;
    int position; // 0 to 100 for simplicity
    int is_running; // 1 for running, 0 for stopped
} Vehicle;

// Function declarations
void initializeVehicle(Vehicle *v, const char *name);
void displayStatus(Vehicle *v);
void moveVehicle(Vehicle *v, int distance);
void recharge(Vehicle *v);
void performOperation(Vehicle *v);

int main() {
    Vehicle survivorVehicle;
    initializeVehicle(&survivorVehicle, "Rover-X");

    while (1) {
        performOperation(&survivorVehicle);
    }

    return 0;
}

// Initialize vehicle with starting values
void initializeVehicle(Vehicle *v, const char *name) {
    strncpy(v->name, name, sizeof(v->name) - 1);
    v->battery_level = 100;
    v->speed = 0;
    v->position = 0;
    v->is_running = 0;
}

// Display the current status of the vehicle
void displayStatus(Vehicle *v) {
    printf("\n===== Vehicle Status =====\n");
    printf("Name: %s\n", v->name);
    printf("Battery Level: %d%%\n", v->battery_level);
    printf("Speed: %d km/h\n", v->speed);
    printf("Position: %d\n", v->position);
    printf("Status: %s\n", v->is_running ? "Running" : "Stopped");
    printf("==========================\n");
}

// Move the vehicle a certain distance if possible
void moveVehicle(Vehicle *v, int distance) {
    if (v->is_running) {
        if (v->battery_level > 0) {
            v->position += distance;
            v->battery_level -= distance / 10; // Drain battery based on distance
            if (v->battery_level < 0) {
                v->battery_level = 0;
            }
            printf("Moving %d units. New position: %d\n", distance, v->position);
        } else {
            printf("Battery is dead! Must recharge.\n");
            v->is_running = 0;
            v->speed = 0;
        }
    } else {
        printf("Vehicle is not running. Start the vehicle first.\n");
    }
}

// Recharge the vehicle's battery
void recharge(Vehicle *v) {
    if (v->battery_level < 100) {
        v->battery_level += 20; // Recharge 20%
        if (v->battery_level > 100) {
            v->battery_level = 100;
        }
        printf("Recharging... Battery level: %d%%\n", v->battery_level);
    } else {
        printf("Battery is already full!\n");
    }
}

// Perform user operations
void performOperation(Vehicle *v) {
    int choice, distance;

    displayStatus(v);
    
    printf("Choose an operation:\n");
    printf("1. Start Vehicle\n");
    printf("2. Stop Vehicle\n");
    printf("3. Move Vehicle\n");
    printf("4. Recharge Battery\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (!v->is_running) {
                v->is_running = 1;
                v->speed = 10; // Set default speed
                printf("Vehicle started!\n");
            } else {
                printf("Vehicle is already running.\n");
            }
            break;

        case 2:
            if (v->is_running) {
                v->is_running = 0;
                printf("Vehicle stopped!\n");
            } else {
                printf("Vehicle is not running.\n");
            }
            break;

        case 3:
            printf("Enter distance to move: ");
            scanf("%d", &distance);
            moveVehicle(v, distance);
            break;

        case 4:
            recharge(v);
            break;

        case 5:
            printf("Exiting simulation...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
    }
}