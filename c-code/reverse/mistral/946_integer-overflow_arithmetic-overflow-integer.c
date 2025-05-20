#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 255
#define MAX_DISTANCE 65535

void move(int speed, int direction, int *distance) {
    *distance += speed * direction;
    if (*distance > MAX_DISTANCE) *distance -= MAX_DISTANCE;
}

int main() {
    int speed, direction, distance = 0;
    scanf("%d %d", &speed, &direction);
    while (speed || direction) {
        move(speed, direction, &distance);
        printf("Distance: %d\n", distance);
        scanf("%d %d", &speed, &direction);
    }
    return 0;
}
