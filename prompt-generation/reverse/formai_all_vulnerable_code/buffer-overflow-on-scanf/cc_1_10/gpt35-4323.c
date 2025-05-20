//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN_ANGLE 45
#define MIN_TURN_ANGLE -45
#define MAX_DISTANCE 1000
#define MIN_DISTANCE 0

struct remote_control_car {
    char brand[20];
    int speed;
    int turn_angle;
    int fuel_level;
    int distance_travelled;
    bool is_on;
};

void display_menu() {
    printf("\n");
    printf("====== Remote Control Car Simulator ======\n");
    printf("1. Turn on/off the car\n");
    printf("2. Change the speed\n");
    printf("3. Turn the car left/right\n");
    printf("4. Check fuel level\n");
    printf("5. Check distance travelled\n");
    printf("6. Quit\n");
    printf("=========================================\n");
    printf("Enter your choice: ");
}

void turn_on_off(struct remote_control_car *car) {
    if (car->is_on) {
        printf("Turning off the car...\n");
        car->is_on = false;
        car->speed = 0;
        car->turn_angle = 0;
    } else {
        printf("Turning on the car...\n");
        car->is_on = true;
    }
}

void change_speed(struct remote_control_car *car) {
    int new_speed;
    printf("Enter the new speed (%d-%d): ", MIN_SPEED, MAX_SPEED);
    scanf("%d", &new_speed);
    if (new_speed < MIN_SPEED || new_speed > MAX_SPEED) {
        printf("Invalid speed entered. The speed remains unchanged.\n");
    } else if (!car->is_on) {
        printf("The car is turned off. Turn on the car before changing the speed.\n");
    } else {
        printf("Changing the speed to %d...\n", new_speed);
        car->speed = new_speed;
    }
}

void turn_car(struct remote_control_car *car) {
    int angle;
    printf("Enter the angle of turn (%d-%d): ", MIN_TURN_ANGLE, MAX_TURN_ANGLE);
    scanf("%d", &angle);
    if (angle < MIN_TURN_ANGLE || angle > MAX_TURN_ANGLE) {
        printf("Invalid turn angle entered. The turn angle remains unchanged.\n");
    } else if (!car->is_on) {
        printf("The car is turned off. Turn on the car before turning it.\n");
    } else {
        printf("Turning the car %s...\n", angle < 0 ? "left" : "right");
        car->turn_angle = angle;
    }
}

void check_fuel_level(struct remote_control_car *car) {
    printf("The fuel level is %d.\n", car->fuel_level);
}

void check_distance_travelled(struct remote_control_car *car) {
    printf("The distance travelled so far is %d.\n", car->distance_travelled);
}

int main() {
    struct remote_control_car car = {"BMW", 0, 0, 100, 0, false};
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: turn_on_off(&car); break;
            case 2: change_speed(&car); break;
            case 3: turn_car(&car); break;
            case 4: check_fuel_level(&car); break;
            case 5: check_distance_travelled(&car); break;
            case 6: printf("Quitting the program...\n"); break;
            default: printf("Invalid choice entered. Please try again.\n"); break;
        }
    } while (choice != 6);
    return 0;
}