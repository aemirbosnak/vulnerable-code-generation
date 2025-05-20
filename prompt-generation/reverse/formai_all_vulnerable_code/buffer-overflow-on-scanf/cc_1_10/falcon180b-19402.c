//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Define the speed of the vehicle
#define SPEED 5

// Define the structure of the vehicle
typedef struct {
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

// Function to initialize the vehicle
void init_vehicle(Vehicle* vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->direction = UP;
    vehicle->speed = SPEED;
}

// Function to move the vehicle
void move_vehicle(Vehicle* vehicle) {
    switch(vehicle->direction) {
        case UP:
            vehicle->y -= vehicle->speed;
            break;
        case DOWN:
            vehicle->y += vehicle->speed;
            break;
        case LEFT:
            vehicle->x -= vehicle->speed;
            break;
        case RIGHT:
            vehicle->x += vehicle->speed;
            break;
    }
}

// Function to turn the vehicle
void turn_vehicle(Vehicle* vehicle, int direction) {
    switch(direction) {
        case UP:
            vehicle->direction = LEFT;
            break;
        case DOWN:
            vehicle->direction = RIGHT;
            break;
        case LEFT:
            vehicle->direction = DOWN;
            break;
        case RIGHT:
            vehicle->direction = UP;
            break;
    }
}

// Function to display the vehicle
void display_vehicle(Vehicle* vehicle) {
    printf("Vehicle is at (%d, %d) facing %d\n", vehicle->x, vehicle->y, vehicle->direction);
}

// Function to simulate the vehicle
void simulate_vehicle(Vehicle* vehicle) {
    // Initialize the vehicle
    init_vehicle(vehicle);

    // Simulate the vehicle
    int choice;
    do {
        system("clear");
        display_vehicle(vehicle);
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Move backward\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_vehicle(vehicle);
                break;
            case 2:
                turn_vehicle(vehicle, LEFT);
                break;
            case 3:
                turn_vehicle(vehicle, RIGHT);
                break;
            case 4:
                turn_vehicle(vehicle, UP);
                break;
            default:
                printf("Invalid choice\n");
        }

        usleep(500000);

    } while(1);
}

int main() {
    Vehicle vehicle;
    simulate_vehicle(&vehicle);
    return 0;
}