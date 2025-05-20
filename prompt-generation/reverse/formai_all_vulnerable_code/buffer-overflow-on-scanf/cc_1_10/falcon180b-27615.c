//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SPEED 100
#define MIN_SPEED 1

// Struct for vehicle
typedef struct {
    int speed;
    int direction;
    int location;
} Vehicle;

// Function prototypes
void init_vehicle(Vehicle* v);
void move_vehicle(Vehicle* v, int speed, int direction);
void print_location(Vehicle* v);

// Main function
int main() {
    srand(time(NULL));

    Vehicle vehicle;
    init_vehicle(&vehicle);

    int choice;
    while (TRUE) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_vehicle(&vehicle, MAX_SPEED, vehicle.direction);
                break;
            case 2:
                move_vehicle(&vehicle, MIN_SPEED, vehicle.direction);
                break;
            case 3:
                vehicle.direction = (vehicle.direction + 3) % 4;
                move_vehicle(&vehicle, vehicle.speed, vehicle.direction);
                break;
            case 4:
                vehicle.direction = (vehicle.direction + 1) % 4;
                move_vehicle(&vehicle, vehicle.speed, vehicle.direction);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        print_location(&vehicle);
    }

    return 0;
}

// Function to initialize vehicle
void init_vehicle(Vehicle* v) {
    v->speed = 0;
    v->direction = 0;
    v->location = 0;
}

// Function to move vehicle
void move_vehicle(Vehicle* v, int speed, int direction) {
    v->speed = speed;
    v->direction = direction;

    int dx = 0;
    int dy = 0;

    switch (direction) {
        case 0: // Up
            dy = -speed;
            break;
        case 1: // Right
            dx = speed;
            break;
        case 2: // Down
            dy = speed;
            break;
        case 3: // Left
            dx = -speed;
            break;
    }

    v->location += dx;
    v->location += dy;
}

// Function to print vehicle location
void print_location(Vehicle* v) {
    printf("Vehicle location: (%d, %d)\n", v->location, v->direction);
}