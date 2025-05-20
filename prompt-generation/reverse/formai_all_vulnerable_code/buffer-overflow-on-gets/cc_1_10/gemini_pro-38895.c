//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEERING 30
#define MIN_STEERING -30

typedef struct {
    int speed;
    int steering;
} Car;

void init_car(Car *car) {
    car->speed = 0;
    car->steering = 0;
}

void accelerate(Car *car, int amount) {
    car->speed += amount;
    if (car->speed > MAX_SPEED) {
        car->speed = MAX_SPEED;
    } else if (car->speed < MIN_SPEED) {
        car->speed = MIN_SPEED;
    }
}

void decelerate(Car *car, int amount) {
    car->speed -= amount;
    if (car->speed > MAX_SPEED) {
        car->speed = MAX_SPEED;
    } else if (car->speed < MIN_SPEED) {
        car->speed = MIN_SPEED;
    }
}

void turn_left(Car *car, int amount) {
    car->steering -= amount;
    if (car->steering > MAX_STEERING) {
        car->steering = MAX_STEERING;
    } else if (car->steering < MIN_STEERING) {
        car->steering = MIN_STEERING;
    }
}

void turn_right(Car *car, int amount) {
    car->steering += amount;
    if (car->steering > MAX_STEERING) {
        car->steering = MAX_STEERING;
    } else if (car->steering < MIN_STEERING) {
        car->steering = MIN_STEERING;
    }
}

void print_car_status(Car *car) {
    printf("Speed: %d\n", car->speed);
    printf("Steering: %d\n", car->steering);
}

int main(int argc, char *argv[]) {
    Car car;
    init_car(&car);

    // Get input from the user
    char input[100];
    while (1) {
        printf("Enter a command (accelerate, decelerate, turn left, turn right, or quit): ");
        gets(input);

        // Parse the input
        if (strcmp(input, "accelerate") == 0) {
            int amount;
            printf("Enter an amount to accelerate (0-100): ");
            scanf("%d", &amount);
            accelerate(&car, amount);
        }
        else if (strcmp(input, "decelerate") == 0) {
            int amount;
            printf("Enter an amount to decelerate (0-100): ");
            scanf("%d", &amount);
            decelerate(&car, amount);
        }
        else if (strcmp(input, "turn left") == 0) {
            int amount;
            printf("Enter an amount to turn left (0-30): ");
            scanf("%d", &amount);
            turn_left(&car, amount);
        }
        else if (strcmp(input, "turn right") == 0) {
            int amount;
            printf("Enter an amount to turn right (0-30): ");
            scanf("%d", &amount);
            turn_right(&car, amount);
        }
        else if (strcmp(input, "quit") == 0) {
            break;
        }
        else {
            // handle error
            printf("Invalid command.\n");
        }
        //print_car_status(&car);
    }

    return 0;
}