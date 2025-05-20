//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEERING_ANGLE 30
#define MIN_STEERING_ANGLE -30

typedef struct {
    int speed;
    int steering_angle;
} CarState;

void print_car_state(CarState state) {
    printf("Speed: %d km/h\n", state.speed);
    printf("Steering angle: %d degrees\n", state.steering_angle);
}

int main() {
    CarState car_state = {0, 0};

    char command[100];
    while (strcmp(command, "quit") != 0) {
        printf("Enter command (accelerate, decelerate, turn left, turn right, quit): ");
        scanf("%s", command);

        if (strcmp(command, "accelerate") == 0) {
            car_state.speed += 10;
            if (car_state.speed > MAX_SPEED) {
                car_state.speed = MAX_SPEED;
            }
        } else if (strcmp(command, "decelerate") == 0) {
            car_state.speed -= 10;
            if (car_state.speed < MIN_SPEED) {
                car_state.speed = MIN_SPEED;
            }
        } else if (strcmp(command, "turn left") == 0) {
            car_state.steering_angle -= 5;
            if (car_state.steering_angle < MIN_STEERING_ANGLE) {
                car_state.steering_angle = MIN_STEERING_ANGLE;
            }
        } else if (strcmp(command, "turn right") == 0) {
            car_state.steering_angle += 5;
            if (car_state.steering_angle > MAX_STEERING_ANGLE) {
                car_state.steering_angle = MAX_STEERING_ANGLE;
            }
        }

        print_car_state(car_state);
    }

    return 0;
}