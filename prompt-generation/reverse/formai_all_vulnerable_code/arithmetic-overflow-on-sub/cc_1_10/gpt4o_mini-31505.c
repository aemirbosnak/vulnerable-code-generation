//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SPEED 10
#define MIN_SPEED 0
#define MAX_BATTERY 100

typedef struct {
    int speed;
    int battery_level;
    char direction[10];
} RC_Vehicle;

void initialize_vehicle(RC_Vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->battery_level = MAX_BATTERY;
    strcpy(vehicle->direction, "stopped");
}

void display_status(const RC_Vehicle *vehicle) {
    printf("RC Vehicle Status:\n");
    printf("Speed: %d\n", vehicle->speed);
    printf("Battery Level: %d%%\n", vehicle->battery_level);
    printf("Direction: %s\n", vehicle->direction);
    printf("------------------------\n");
}

void accelerate(RC_Vehicle *vehicle, int increment) {
    if (vehicle->battery_level <= 0) {
        printf("Battery depleted! Recharge your vehicle.\n");
        return;
    }

    vehicle->speed += increment;
    if (vehicle->speed > MAX_SPEED) {
        vehicle->speed = MAX_SPEED;
    }

    vehicle->battery_level -= increment;
    if (vehicle->battery_level < 0) {
        vehicle->battery_level = 0;
    }

    strcpy(vehicle->direction, "moving");
    printf("Accelerated to speed %d.\n", vehicle->speed);
}

void decelerate(RC_Vehicle *vehicle, int decrement) {
    vehicle->speed -= decrement;
    if (vehicle->speed < MIN_SPEED) {
        vehicle->speed = MIN_SPEED;
    }

    if (vehicle->speed == 0) {
        strcpy(vehicle->direction, "stopped");
    }
    
    printf("Decelerated to speed %d.\n", vehicle->speed);
}

void turn(RC_Vehicle *vehicle, const char *new_direction) {
    if (strcmp(new_direction, "left") == 0 || strcmp(new_direction, "right") == 0) {
        strcpy(vehicle->direction, new_direction);
        printf("Turned %s.\n", new_direction);
    } else {
        printf("Invalid direction. Please specify 'left' or 'right'.\n");
    }
}

void recharge(RC_Vehicle *vehicle) {
    vehicle->battery_level = MAX_BATTERY;
    printf("Vehicle recharged to 100%% battery level.\n");
}

int main() {
    RC_Vehicle vehicle;
    initialize_vehicle(&vehicle);
    
    int choice, value;
    char direction[10];

    while (1) {
        display_status(&vehicle);
        printf("Choose an action:\n");
        printf("1. Accelerate\n");
        printf("2. Decelerate\n");
        printf("3. Turn\n");
        printf("4. Recharge Battery\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter acceleration value (1-10): ");
                scanf("%d", &value);
                accelerate(&vehicle, value);
                break;
            case 2:
                printf("Enter deceleration value (1-10): ");
                scanf("%d", &value);
                decelerate(&vehicle, value);
                break;
            case 3:
                printf("Enter direction (left/right): ");
                scanf("%s", direction);
                turn(&vehicle, direction);
                break;
            case 4:
                recharge(&vehicle);
                break;
            case 5:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        // Sleep to simulate time passing in the vehicle's operation
        sleep(1);
    }

    return 0;
}