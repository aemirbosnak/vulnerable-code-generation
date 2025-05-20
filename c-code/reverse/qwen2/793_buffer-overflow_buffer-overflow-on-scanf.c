#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_SPEED 100
#define MIN_SPEED -100
#define MAX_DIRECTION 360
#define MIN_DIRECTION 0

int main() {
    int speed = 0;
    int direction = 0;

    while (1) {
        printf("Enter joystick state (speed direction): ");
        scanf("%d %d", &speed, &direction);

        if (speed > MAX_SPEED) speed = MAX_SPEED;
        if (speed < MIN_SPEED) speed = MIN_SPEED;
        if (direction > MAX_DIRECTION) direction = MAX_DIRECTION;
        if (direction < MIN_DIRECTION) direction = MIN_DIRECTION;

        printf("Vehicle Status: Speed=%d, Direction=%d\n", speed, direction);
    }

    return 0;
}
