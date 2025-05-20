//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50
#define MIN_SPEED 10
#define TURN_RADIUS 20
#define FORWARD_SPEED 30
#define BACKWARD_SPEED -30

#define LEFT_TURN 1
#define RIGHT_TURN 2
#define FORWARD_MOVE 3
#define BACKWARD_MOVE 4
#define STOP_MOVE 5

void move(int direction, int speed) {
    printf("Vehicle is moving %d at a speed of %d\n", direction, speed);
}

void turn(int direction, int radius) {
    printf("Vehicle is turning %d with a radius of %d\n", direction, radius);
}

void remote_control_vehicle() {
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move(FORWARD_MOVE, FORWARD_SPEED);
                break;
            case 2:
                move(BACKWARD_MOVE, BACKWARD_SPEED);
                break;
            case 3:
                turn(LEFT_TURN, TURN_RADIUS);
                break;
            case 4:
                turn(RIGHT_TURN, TURN_RADIUS);
                break;
            case 5:
                printf("Vehicle stopped.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);
}

int main() {
    srand(time(NULL));
    int max_speed = MAX_SPEED - MIN_SPEED + 1;
    int min_speed = MIN_SPEED;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Your vehicle has a maximum speed of %d and a minimum speed of %d.\n", MAX_SPEED, MIN_SPEED);

    remote_control_vehicle();

    return 0;
}