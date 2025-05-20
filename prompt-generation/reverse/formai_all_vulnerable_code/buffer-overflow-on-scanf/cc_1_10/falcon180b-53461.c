//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define ACCELERATION 1
#define DECELERATION 1
#define TURN_RADIUS 5
#define TURN_SPEED 2

/* Define the structure for our vehicle */
typedef struct {
    int x, y;
    int speed;
    int direction;
} Vehicle;

/* Function to initialize the vehicle */
void init_vehicle(Vehicle *v) {
    v->x = 0;
    v->y = 0;
    v->speed = MIN_SPEED;
    v->direction = 0;
}

/* Function to move the vehicle forward */
void move_forward(Vehicle *v) {
    v->x += v->speed * cos(v->direction);
    v->y += v->speed * sin(v->direction);
}

/* Function to turn the vehicle left or right */
void turn_vehicle(Vehicle *v, int turn) {
    v->direction += turn * TURN_SPEED;
    if (v->direction > 360) {
        v->direction -= 360;
    } else if (v->direction < 0) {
        v->direction += 360;
    }
}

/* Function to accelerate the vehicle */
void accelerate(Vehicle *v) {
    if (v->speed < MAX_SPEED) {
        v->speed += ACCELERATION;
    }
}

/* Function to decelerate the vehicle */
void decelerate(Vehicle *v) {
    if (v->speed > MIN_SPEED) {
        v->speed -= DECELERATION;
    }
}

/* Function to update the vehicle's position */
void update_vehicle(Vehicle *v) {
    move_forward(v);
}

/* Function to print the vehicle's position */
void print_vehicle(Vehicle *v) {
    printf("Vehicle at (%d, %d) facing %d degrees\n", v->x, v->y, v->direction);
}

/* Function to simulate the vehicle's movement */
void simulate_vehicle(Vehicle *v, int duration) {
    int i;
    for (i = 0; i < duration; i++) {
        update_vehicle(v);
        printf("Vehicle at (%d, %d)\n", v->x, v->y);
        fflush(stdout);
        usleep(100000); /* Sleep for 100ms */
    }
}

int main() {
    Vehicle v;
    int choice, duration;

    init_vehicle(&v);

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Accelerate\n");
        printf("5. Decelerate\n");
        printf("6. Print vehicle position\n");
        printf("7. Simulate vehicle movement\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_forward(&v);
                break;
            case 2:
                turn_vehicle(&v, -1);
                break;
            case 3:
                turn_vehicle(&v, 1);
                break;
            case 4:
                accelerate(&v);
                break;
            case 5:
                decelerate(&v);
                break;
            case 6:
                print_vehicle(&v);
                break;
            case 7:
                printf("Enter the duration of the simulation in seconds: ");
                scanf("%d", &duration);
                simulate_vehicle(&v, duration);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}