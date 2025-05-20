//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the speed and direction of the vehicle
#define SPEED 10
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

// Define the structure of the vehicle
typedef struct {
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

// Initialize the vehicle
void init_vehicle(Vehicle *v) {
    v->x = 0;
    v->y = 0;
    v->direction = FORWARD;
    v->speed = SPEED;
}

// Move the vehicle forward
void move_forward(Vehicle *v) {
    v->y += v->speed;
}

// Move the vehicle backward
void move_backward(Vehicle *v) {
    v->y -= v->speed;
}

// Turn the vehicle left
void turn_left(Vehicle *v) {
    v->direction = (v->direction + 3) % 4;
}

// Turn the vehicle right
void turn_right(Vehicle *v) {
    v->direction = (v->direction + 1) % 4;
}

// Print the current state of the vehicle
void print_vehicle(Vehicle *v) {
    printf("Vehicle: (%d, %d) Direction: %d Speed: %d\n", v->x, v->y, v->direction, v->speed);
}

// Main function
int main() {
    srand(time(NULL));
    int choice;
    Vehicle v;
    init_vehicle(&v);

    while (1) {
        system("clear");
        printf("Remote Control Vehicle Simulation\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_forward(&v);
                break;
            case 2:
                move_backward(&v);
                break;
            case 3:
                turn_left(&v);
                break;
            case 4:
                turn_right(&v);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        print_vehicle(&v);
        usleep(100000);
    }

    return 0;
}