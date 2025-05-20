//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum speed of the vehicle
#define MAX_SPEED 100

// Define the structure for the vehicle
typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Vehicle;

// Function to initialize the vehicle
void init_vehicle(Vehicle *v) {
    v->x = 0;
    v->y = 0;
    v->speed = 0;
    v->direction = 0;
}

// Function to move the vehicle
void move_vehicle(Vehicle *v) {
    if (v->speed > 0) {
        v->x += v->speed * cos(v->direction);
        v->y += v->speed * sin(v->direction);
    }
}

// Function to turn the vehicle
void turn_vehicle(Vehicle *v, int angle) {
    v->direction += angle;
}

// Function to print the current position of the vehicle
void print_position(Vehicle v) {
    printf("Current position: (%d, %d)\n", v.x, v.y);
}

// Function to simulate the remote control vehicle
void simulate_vehicle(Vehicle *v) {
    int choice;
    int speed = 0;
    int turn_angle = 0;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                speed = MAX_SPEED;
                break;
            case 2:
                turn_angle = -10;
                break;
            case 3:
                turn_angle = 10;
                break;
            case 4:
                speed = 0;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        if (speed!= 0) {
            v->speed = speed;
        } else {
            v->speed = 0;
        }

        if (turn_angle!= 0) {
            turn_vehicle(v, turn_angle);
        }

        move_vehicle(v);
        print_position(*v);

        usleep(100000);
    }
}

int main() {
    Vehicle v;
    init_vehicle(&v);

    simulate_vehicle(&v);

    return 0;
}