#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_SPEED 100
#define MIN_SPEED -100

int main() {
    int up = 0, down = 0, left = 0, right = 0;
    int speed = 0, direction = 0;

    while (1) {
        printf("Enter joystick inputs (up, down, left, right): ");
        scanf("%d %d %d %d", &up, &down, &left, &right);

        speed += up - down;
        direction += left - right;

        if (speed > MAX_SPEED) speed = MAX_SPEED;
        if (speed < MIN_SPEED) speed = MIN_SPEED;

        if (direction > 360) direction -= 360;
        if (direction < 0) direction += 360;

        printf("Speed: %d, Direction: %d\n", speed, direction);
    }

    return 0;
}
