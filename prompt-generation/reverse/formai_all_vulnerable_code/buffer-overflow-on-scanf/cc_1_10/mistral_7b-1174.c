//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define FORWARD 1
#define REVERSE 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

typedef struct {
    int direction;
    int speed;
} vehicle_t;

void signal_handler(int signum) {
    vehicle_t *vehicle = (vehicle_t *) malloc(sizeof(vehicle_t));
    vehicle->direction = STOP;
    vehicle->speed = 0;
    free(vehicle);
    exit(0);
}

void forward(vehicle_t *vehicle) {
    printf("Vehicle moving forward\n");
    vehicle->speed = 10;
}

void reverse(vehicle_t *vehicle) {
    printf("Vehicle moving reverse\n");
    vehicle->speed = -10;
}

void left(vehicle_t *vehicle) {
    printf("Vehicle turning left\n");
    vehicle->direction = LEFT;
}

void right(vehicle_t *vehicle) {
    printf("Vehicle turning right\n");
    vehicle->direction = RIGHT;
}

int main() {
    signal(SIGINT, signal_handler);
    vehicle_t vehicle;
    int command;

    while (1) {
        scanf("%d", &command);
        switch (command) {
            case FORWARD:
                forward(&vehicle);
                break;
            case REVERSE:
                reverse(&vehicle);
                break;
            case LEFT:
                left(&vehicle);
                break;
            case RIGHT:
                right(&vehicle);
                break;
            case STOP:
                vehicle.direction = STOP;
                vehicle.speed = 0;
                break;
            default:
                printf("Invalid command\n");
        }

        struct timeval tv = {0, 50000};
        nanosleep(&tv, NULL);

        switch (vehicle.direction) {
            case FORWARD:
                printf("Vehicle moving with speed %d\n", vehicle.speed);
                break;
            case REVERSE:
                printf("Vehicle moving with speed %d in reverse\n", vehicle.speed);
                break;
            case LEFT:
                printf("Vehicle turning left\n");
                break;
            case RIGHT:
                printf("Vehicle turning right\n");
                break;
            case STOP:
                printf("Vehicle stopped\n");
                break;
        }
    }

    return 0;
}