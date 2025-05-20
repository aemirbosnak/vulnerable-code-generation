//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONE_SPEED 100
#define MIN_DRONE_SPEED 0

// Structure to hold drone information
struct drone {
    int speed;
    int altitude;
    int battery_level;
};

// Function to validate user input for drone speed
int validate_speed_input(int speed) {
    if (speed < MIN_DRONE_SPEED) {
        printf("Invalid speed entered. Setting speed to minimum.\n");
        return MIN_DRONE_SPEED;
    } else if (speed > MAX_DRONE_SPEED) {
        printf("Invalid speed entered. Setting speed to maximum.\n");
        return MAX_DRONE_SPEED;
    } else {
        return speed;
    }
}

// Function to validate user input for drone altitude
int validate_altitude_input(int altitude) {
    if (altitude < 0) {
        printf("Invalid altitude entered. Setting altitude to 0.\n");
        return 0;
    } else {
        return altitude;
    }
}

// Function to validate user input for drone battery level
int validate_battery_input(int battery_level) {
    if (battery_level < 0) {
        printf("Invalid battery level entered. Setting battery level to 0.\n");
        return 0;
    } else {
        return battery_level;
    }
}

// Function to print drone information
void print_drone_info(struct drone *d) {
    printf("Current drone information:\n");
    printf("Speed: %d\n", d->speed);
    printf("Altitude: %d\n", d->altitude);
    printf("Battery Level: %d\n", d->battery_level);
}

int main() {

    struct drone my_drone = {0, 0, 100}; // Speed, altitude, battery level

    char choice;
    int speed_input, altitude_input, battery_input;

    printf("Welcome to C Drone Remote Control!\n");

    do {
        // Display menu
        printf("Choose an action:\n");
        printf("1. Set drone speed\n");
        printf("2. Set drone altitude\n");
        printf("3. Set drone battery level\n");
        printf("4. Print current drone information\n");
        printf("5. Exit\n");

        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter desired speed (0-100): ");
                scanf("%d", &speed_input);
                my_drone.speed = validate_speed_input(speed_input);
                break;
            case '2':
                printf("Enter desired altitude: ");
                scanf("%d", &altitude_input);
                my_drone.altitude = validate_altitude_input(altitude_input);
                break;
            case '3':
                printf("Enter desired battery level: ");
                scanf("%d", &battery_input);
                my_drone.battery_level = validate_battery_input(battery_input);
                break;
            case '4':
                print_drone_info(&my_drone);
                break;
            case '5':
                printf("Exiting C Drone Remote Control.\n");
                break;
            default:
                printf("Invalid choice entered. Please try again.\n");
                break;
        }

    } while (choice != '5');

    return 0;
}