#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISTANCE 2147483647

struct RemoteControlVehicle {
    int x;
    int y;
    int speed;
    char direction;
};

void move(struct RemoteControlVehicle* vehicle, int distance, char direction) {
    vehicle->x += distance * (direction == 'E' ? 1 : -1);
    vehicle->y += distance * (direction == 'N' ? 1 : -1);
}

int main() {
    struct RemoteControlVehicle car;
    car.x = 0;
    car.y = 0;
    car.speed = 100;
    char direction;
    int distance;

    while (1) {
        scanf("%d %c", &distance, &direction);
        move(&car, distance, direction);
        printf("Current position: (%d, %d)\n", car.x, car.y);

        if (car.x > MAX_DISTANCE || car.y > MAX_DISTANCE) {
            printf("Integer overflow vulnerability detected!\n");
            break;
        }
    }

    return 0;
}
