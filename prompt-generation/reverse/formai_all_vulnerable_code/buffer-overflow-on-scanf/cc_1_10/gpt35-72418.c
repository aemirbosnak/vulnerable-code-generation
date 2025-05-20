//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the remote control vehicle
struct rc_vehicle {
    char name[20];
    int speed;
    int direction;
    int battery_level;
};

// Define the function to update the direction of the remote control vehicle
void update_direction(struct rc_vehicle *vehicle, int new_direction) {
    if (new_direction >= 0 && new_direction <= 360) {
        vehicle->direction = new_direction;
        printf("Direction updated to %d degrees.\n", new_direction);
    } else {
        printf("Error: Invalid direction.\n");
    }
}

// Define the function to update the speed of the remote control vehicle
void update_speed(struct rc_vehicle *vehicle, int new_speed) {
    if (new_speed >= 0 && new_speed <= 100) {
        vehicle->speed = new_speed;
        printf("Speed updated to %d.\n", new_speed);
    } else {
        printf("Error: Invalid speed.\n");
    }
}

// Define the function to update the battery level of the remote control vehicle
void update_battery_level(struct rc_vehicle *vehicle, int new_battery_level) {
    if (new_battery_level >= 0 && new_battery_level <= 100) {
        vehicle->battery_level = new_battery_level;
        printf("Battery level updated to %d%%.\n", new_battery_level);
    } else {
        printf("Error: Invalid battery level.\n");
    }
}

int main() {
    struct rc_vehicle my_vehicle;
    int option, new_value;

    // Initialize the remote control vehicle with default values
    strcpy(my_vehicle.name, "RC Car");
    my_vehicle.speed = 0;
    my_vehicle.direction = 0;
    my_vehicle.battery_level = 100;

    printf("Welcome to the RC vehicle simulation program!\n");

    // Loop until the user chooses to exit the program
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Update the speed\n");
        printf("2. Update the direction\n");
        printf("3. Update the battery level\n");
        printf("4. Quit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a new speed (0-100):\n");
                scanf("%d", &new_value);
                update_speed(&my_vehicle, new_value);
                break;

            case 2:
                printf("Enter a new direction (0-360):\n");
                scanf("%d", &new_value);
                update_direction(&my_vehicle, new_value);
                break;

            case 3:
                printf("Enter a new battery level (0-100):\n");
                scanf("%d", &new_value);
                update_battery_level(&my_vehicle, new_value);
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Error: Invalid option.\n");
                break;
        }
    }

    return 0;
}