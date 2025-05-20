//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SPEED 100
#define MAX_TURN_RATE 30

typedef struct {
    int speed;
    int turn_rate;
} car_state;

car_state car;

void init_car() {
    car.speed = 0;
    car.turn_rate = 0;
}

void update_car(char *command) {
    if (strcmp(command, "forward") == 0) {
        car.speed += 10;
        if (car.speed > MAX_SPEED) {
            car.speed = MAX_SPEED;
        }
    } else if (strcmp(command, "backward") == 0) {
        car.speed -= 10;
        if (car.speed < -MAX_SPEED) {
            car.speed = -MAX_SPEED;
        }
    } else if (strcmp(command, "left") == 0) {
        car.turn_rate -= 10;
        if (car.turn_rate < -MAX_TURN_RATE) {
            car.turn_rate = -MAX_TURN_RATE;
        }
    } else if (strcmp(command, "right") == 0) {
        car.turn_rate += 10;
        if (car.turn_rate > MAX_TURN_RATE) {
            car.turn_rate = MAX_TURN_RATE;
        }
    } else if (strcmp(command, "stop") == 0) {
        car.speed = 0;
        car.turn_rate = 0;
    }
}

void print_car_state() {
    printf("Speed: %d\n", car.speed);
    printf("Turn rate: %d\n", car.turn_rate);
}

int main() {
    init_car();

    while (1) {
        char command[100];
        scanf("%s", command);

        update_car(command);
        print_car_state();

        usleep(100000);
    }

    return 0;
}