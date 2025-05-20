#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MAX_DIRECTION 360

typedef struct {
    int speed;
    int direction;
} Vehicle;

int main() {
    Vehicle vehicle = {0, 0};

    while (1) {
        printf("Enter speed (0-100): ");
        if (scanf("%d", &vehicle.speed) != 1 || vehicle.speed < 0 || vehicle.speed > MAX_SPEED) {
            printf("Invalid speed. Please enter a valid number between 0 and 100.\n");
            continue;
        }

        printf("Enter direction (0-360): ");
        if (scanf("%d", &vehicle.direction) != 1 || vehicle.direction < 0 || vehicle.direction > MAX_DIRECTION) {
            printf("Invalid direction. Please enter a valid number between 0 and 360.\n");
            continue;
        }

        printf("Speed: %d, Direction: %d\n", vehicle.speed, vehicle.direction);
    }

    return 0;
}
