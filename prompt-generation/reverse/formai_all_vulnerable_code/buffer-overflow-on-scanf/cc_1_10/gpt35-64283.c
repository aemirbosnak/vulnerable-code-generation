//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 5
#define MAX_TURN_ANGLE 45

struct remote_control_car {
    int speed;
    int direction;
    int x_position;
    int y_position;
};

void move_forward(struct remote_control_car *car);
void move_backward(struct remote_control_car *car);
void turn_left(struct remote_control_car *car);
void turn_right(struct remote_control_car *car);
void stop_car(struct remote_control_car *car);

int main() {
    struct remote_control_car car;

    car.speed = 0;
    car.direction = 0;
    car.x_position = 0;
    car.y_position = 0;

    bool car_running = true;

    while (car_running) {
        char input;
        printf("Enter command (F/B/L/R/S): ");
        scanf(" %c", &input);

        switch (input) {
            case 'F':
            case 'f':
                move_forward(&car);
                break;
            case 'B':
            case 'b':
                move_backward(&car);
                break;
            case 'L':
            case 'l':
                turn_left(&car);
                break;
            case 'R':
            case 'r':
                turn_right(&car);
                break;
            case 'S':
            case 's':
                stop_car(&car);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        printf("Current Speed: %d\n", car.speed);
        printf("Current Direction: %d\n", car.direction);
        printf("Current Position: (%d, %d)\n", car.x_position, car.y_position);
    }

    return 0;
}

void move_forward(struct remote_control_car *car) {
    if (car->speed < MAX_SPEED) {
        car->speed++;
    }
    car->x_position += car->speed;
}

void move_backward(struct remote_control_car *car) {
    if (car->speed < MAX_SPEED) {
        car->speed++;
    }
    car->x_position -= car->speed;
}

void turn_left(struct remote_control_car *car) {
    if (car->direction < MAX_TURN_ANGLE) {
        car->direction -= MAX_TURN_ANGLE;
    } else {
        car->direction = -MAX_TURN_ANGLE;
    }
}

void turn_right(struct remote_control_car *car) {
    if (car->direction > -MAX_TURN_ANGLE) {
        car->direction += MAX_TURN_ANGLE;
    } else {
        car->direction = MAX_TURN_ANGLE;
    }
}

void stop_car(struct remote_control_car *car) {
    car->speed = 0;
}