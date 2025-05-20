#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_SPEED 100
#define MAX_ANGLE 90
#define MIN_ANGLE -90

int main() {
    int speed = 0, angle = 0;

    while (1) {
        printf("Enter joystick state (speed 1-100, angle -90 to 90): ");
        scanf("%d %d", &speed, &angle);

        if (speed < 0 || speed > MAX_SPEED) {
            printf("Speed must be between 0 and %d.\n", MAX_SPEED);
            continue;
        }

        if (angle < MIN_ANGLE || angle > MAX_ANGLE) {
            printf("Angle must be between %d and %d.\n", MIN_ANGLE, MAX_ANGLE);
            continue;
        }

        printf("Vehicle speed: %d, angle: %d\n", speed, angle);
    }

    return 0;
}
