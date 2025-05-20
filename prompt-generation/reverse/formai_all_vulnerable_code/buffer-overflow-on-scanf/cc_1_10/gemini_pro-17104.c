//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEERING_ANGLE 45
#define MIN_STEERING_ANGLE -45

typedef struct {
    int speed;
    int steering_angle;
} car_state;

void initialize_car_state(car_state *car) {
    car->speed = MIN_SPEED;
    car->steering_angle = 0;
}

void update_car_state(car_state *car, int acceleration, int steering) {
    // Update speed
    car->speed += acceleration;
    if (car->speed > MAX_SPEED) {
        car->speed = MAX_SPEED;
    } else if (car->speed < MIN_SPEED) {
        car->speed = MIN_SPEED;
    }

    // Update steering angle
    car->steering_angle += steering;
    if (car->steering_angle > MAX_STEERING_ANGLE) {
        car->steering_angle = MAX_STEERING_ANGLE;
    } else if (car->steering_angle < MIN_STEERING_ANGLE) {
        car->steering_angle = MIN_STEERING_ANGLE;
    }
}

void print_car_state(car_state car) {
    printf("Speed: %d km/h\n", car.speed);
    printf("Steering angle: %d degrees\n", car.steering_angle);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize car state
    car_state car;
    initialize_car_state(&car);

    // Main loop
    while (1) {
        // Get user input
        int acceleration = 0;
        int steering = 0;
        printf("Enter acceleration (-100 to 100): ");
        scanf("%d", &acceleration);
        printf("Enter steering (-45 to 45): ");
        scanf("%d", &steering);

        // Update car state
        update_car_state(&car, acceleration, steering);

        // Print car state
        print_car_state(car);

        // Check for exit condition
        if (car.speed == 0 && car.steering_angle == 0) {
            break;
        }
    }

    return 0;
}