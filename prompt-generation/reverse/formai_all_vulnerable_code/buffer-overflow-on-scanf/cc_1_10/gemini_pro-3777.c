//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MAX_STEERING_ANGLE 30

typedef struct {
    int speed;
    int steering_angle;
} car_state;

void update_car_state(car_state *car, int throttle, int steering) {
    // Update the car's speed based on the throttle input.
    car->speed += throttle;
    if (car->speed > MAX_SPEED) {
        car->speed = MAX_SPEED;
    } else if (car->speed < 0) {
        car->speed = 0;
    }

    // Update the car's steering angle based on the steering input.
    car->steering_angle += steering;
    if (car->steering_angle > MAX_STEERING_ANGLE) {
        car->steering_angle = MAX_STEERING_ANGLE;
    } else if (car->steering_angle < -MAX_STEERING_ANGLE) {
        car->steering_angle = -MAX_STEERING_ANGLE;
    }
}

void print_car_state(car_state *car) {
    printf("Speed: %d\n", car->speed);
    printf("Steering angle: %d\n", car->steering_angle);
}

int main() {
    // Create a new car state.
    car_state car = {0, 0};

    // Get the user input for throttle and steering.
    int throttle, steering;
    printf("Enter throttle (-100 to 100): ");
    scanf("%d", &throttle);
    printf("Enter steering (-30 to 30): ");
    scanf("%d", &steering);

    // Update the car's state based on the user input.
    update_car_state(&car, throttle, steering);

    // Print the car's state.
    print_car_state(&car);

    return 0;
}