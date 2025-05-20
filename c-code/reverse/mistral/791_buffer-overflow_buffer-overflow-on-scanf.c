#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_SPEED 100
#define MAX_ANGLE 90
#define MIN_SPEED 0
#define MIN_ANGLE 0

typedef struct {
    int speed;
    int angle;
} Vehicle;

int main() {
    Vehicle vehicle = {0, 0};

    while (1) {
        int input;
        printf("Enter joystick input (1-4): 1(up), 2(down), 3(left), 4(right): ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                if (vehicle.speed < MAX_SPEED)
                    vehicle.speed++;
                if (vehicle.angle < MAX_ANGLE)
                    vehicle.angle++;
                break;
            case 2:
                if (vehicle.speed > MIN_SPEED)
                    vehicle.speed--;
                break;
            case 3:
                if (vehicle.angle > MIN_ANGLE)
                    vehicle.angle--;
                if (vehicle.angle < 0)
                    vehicle.angle = 0;
                break;
            case 4:
                if (vehicle.angle < MAX_ANGLE)
                    vehicle.angle++;
                break;
            default:
                printf("Invalid input. Please enter a valid joystick input (1-4).\n");
        }

        printf("Speed: %d, Angle: %d\n", vehicle.speed, vehicle.angle);
    }

    return 0;
}
