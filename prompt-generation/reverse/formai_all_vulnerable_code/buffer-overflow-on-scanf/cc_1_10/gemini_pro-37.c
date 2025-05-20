//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CAR_MAX_SPEED 100.0
#define CAR_MIN_SPEED 0.0
#define CAR_MAX_ANGLE 30.0
#define CAR_MIN_ANGLE -30.0

typedef struct {
    double x;
    double y;
    double angle;
    double speed;
} Car;

void init_car(Car *car) {
    car->x = 0.0;
    car->y = 0.0;
    car->angle = 0.0;
    car->speed = 0.0;
}

void update_car(Car *car, double dt, double throttle, double steering) {
    // Update the car's speed
    car->speed += throttle * dt;
    if (car->speed > CAR_MAX_SPEED) {
        car->speed = CAR_MAX_SPEED;
    } else if (car->speed < CAR_MIN_SPEED) {
        car->speed = CAR_MIN_SPEED;
    }

    // Update the car's angle
    car->angle += steering * dt;
    if (car->angle > CAR_MAX_ANGLE) {
        car->angle = CAR_MAX_ANGLE;
    } else if (car->angle < CAR_MIN_ANGLE) {
        car->angle = CAR_MIN_ANGLE;
    }

    // Update the car's position
    car->x += car->speed * dt * cos(car->angle);
    car->y += car->speed * dt * sin(car->angle);
}

void print_car(Car *car) {
    printf("Car position: (%.2f, %.2f)\n", car->x, car->y);
    printf("Car angle: %.2f degrees\n", car->angle);
    printf("Car speed: %.2f m/s\n", car->speed);
}

int main() {
    // Initialize the car
    Car car;
    init_car(&car);

    // Main loop
    while (1) {
        // Get the user input
        double throttle, steering;
        printf("Enter throttle (-1 to 1): ");
        scanf("%lf", &throttle);
        printf("Enter steering (-1 to 1): ");
        scanf("%lf", &steering);

        // Update the car
        update_car(&car, 0.1, throttle, steering);

        // Print the car
        print_car(&car);
    }

    return 0;
}