//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the remote control vehicle's speed and direction
#define SPEED 5
#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3

// Define the remote control vehicle's position and orientation
struct vehicle {
    int x;
    int y;
    int direction;
};

// Initialize the remote control vehicle's position and orientation
void init_vehicle(struct vehicle *v) {
    v->x = 0;
    v->y = 0;
    v->direction = FORWARD;
}

// Move the remote control vehicle forward
void move_forward(struct vehicle *v) {
    v->x += SPEED;
}

// Move the remote control vehicle backward
void move_backward(struct vehicle *v) {
    v->x -= SPEED;
}

// Turn the remote control vehicle left
void turn_left(struct vehicle *v) {
    v->direction = (v->direction + 1) % 4;
}

// Turn the remote control vehicle right
void turn_right(struct vehicle *v) {
    v->direction = (v->direction + 3) % 4;
}

// Print the remote control vehicle's position and orientation
void print_vehicle(struct vehicle *v) {
    switch (v->direction) {
        case FORWARD:
            printf("^");
            break;
        case BACKWARD:
            printf("v");
            break;
        case LEFT:
            printf("<");
            break;
        case RIGHT:
            printf(">");
            break;
    }
}

// Simulate the remote control vehicle's movement
void simulate_vehicle(struct vehicle *v) {
    int i;
    for (i = 0; i < SPEED; i++) {
        move_forward(v);
        usleep(50000);
    }
}

int main() {
    struct vehicle v;
    init_vehicle(&v);

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
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
                printf("Invalid choice\n");
        }

        print_vehicle(&v);
        printf("\n");

        simulate_vehicle(&v);
    }

    return 0;
}