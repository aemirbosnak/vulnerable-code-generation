//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAR_MAX_SPEED 100
#define CAR_MIN_SPEED 0
#define CAR_MAX_STEERING_ANGLE 30
#define CAR_MIN_STEERING_ANGLE -30

typedef struct {
    int speed;
    int steering_angle;
} Car;

void init_car(Car *car) {
    car->speed = CAR_MIN_SPEED;
    car->steering_angle = 0;
}

void accelerate(Car *car) {
    if (car->speed < CAR_MAX_SPEED) {
        car->speed++;
    }
}

void decelerate(Car *car) {
    if (car->speed > CAR_MIN_SPEED) {
        car->speed--;
    }
}

void turn_left(Car *car) {
    if (car->steering_angle > CAR_MIN_STEERING_ANGLE) {
        car->steering_angle--;
    }
}

void turn_right(Car *car) {
    if (car->steering_angle < CAR_MAX_STEERING_ANGLE) {
        car->steering_angle++;
    }
}

void print_car_status(Car *car) {
    printf("Speed: %d\n", car->speed);
    printf("Steering Angle: %d\n", car->steering_angle);
}

int main() {
    srand(time(NULL));

    Car car;
    init_car(&car);

    while (1) {
        char command;
        printf("Enter a command (a/d/w/s/q): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                accelerate(&car);
                break;
            case 's':
                decelerate(&car);
                break;
            case 'a':
                turn_left(&car);
                break;
            case 'd':
                turn_right(&car);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command\n");
        }

        print_car_status(&car);
    }

    return 0;
}