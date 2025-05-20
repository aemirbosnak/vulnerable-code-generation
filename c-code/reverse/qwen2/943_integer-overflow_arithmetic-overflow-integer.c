#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100

typedef struct {
    int speed;
    int direction; // 0: forward, 1: backward
} Vehicle;

void update_speed(Vehicle *v, int change) {
    v->speed += change;
    if (v->speed > MAX_SPEED) v->speed = MAX_SPEED;
    if (v->speed < 0) v->speed = 0;
}

void turn_direction(Vehicle *v, int new_direction) {
    v->direction = new_direction;
}

int main() {
    Vehicle car = {0, 0};
    clock_t start_time = clock();
    double distance = 0.0;

    while (1) {
        printf("Speed: %d km/h, Direction: %s\n", car.speed, car.direction ? "Backward" : "Forward");
        printf("Enter command (a/d to accelerate/decelerate, l/r to turn left/right, q to quit): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                update_speed(&car, 5);
                break;
            case 'd':
                update_speed(&car, -5);
                break;
            case 'l':
                turn_direction(&car, 0);
                break;
            case 'r':
                turn_direction(&car, 1);
                break;
            case 'q':
                goto end;
            default:
                printf("Invalid command.\n");
        }

        double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
        distance = car.speed * elapsed_time / 3600.0;
        printf("Distance traveled: %.2f km\n", distance);
    }

end:
    return 0;
}
