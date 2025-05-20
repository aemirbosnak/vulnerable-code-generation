//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define vehicle structure
typedef struct {
    int x, y; // Position
    int speed; // Speed
} Vehicle;

// Function to update vehicle position
void update_vehicle(Vehicle* v) {
    v->x += v->speed;
}

// Function to draw vehicle
void draw_vehicle(Vehicle* v) {
    printf("Vehicle at (%d,%d)\n", v->x, v->y);
}

// Function to move vehicle forward
void move_forward(Vehicle* v) {
    v->speed = 5;
    update_vehicle(v);
}

// Function to turn vehicle left
void turn_left(Vehicle* v) {
    v->speed = -5;
    update_vehicle(v);
}

// Function to turn vehicle right
void turn_right(Vehicle* v) {
    v->speed = 5;
    update_vehicle(v);
}

// Function to stop vehicle
void stop_vehicle(Vehicle* v) {
    v->speed = 0;
}

// Function to simulate vehicle movement
void simulate_vehicle(Vehicle* v, int duration) {
    int elapsed_time = 0;
    while (elapsed_time < duration) {
        update_vehicle(v);
        draw_vehicle(v);
        elapsed_time += 50; // Assume each iteration takes 50 milliseconds
        usleep(50*1000); // Sleep for 50 milliseconds
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    Vehicle v = {0, 0, 0}; // Initialize vehicle at position (0,0) with speed 0
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            move_forward(&v);
            break;
        case 2:
            turn_left(&v);
            break;
        case 3:
            turn_right(&v);
            break;
        case 4:
            stop_vehicle(&v);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        simulate_vehicle(&v, 5000); // Simulate vehicle movement for 5 seconds
    } while (1); // Loop indefinitely
    return 0;
}