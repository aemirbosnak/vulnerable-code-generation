#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char input[2];
    int speed = 0;
    int direction = 0;

    printf("Enter joystick input (e.g., 'F' for forward, 'B' for backward): ");
    scanf("%s", input);

    switch(input[0]) {
        case 'F':
            speed = 100;
            direction = 0;
            break;
        case 'B':
            speed = -100;
            direction = 0;
            break;
        case 'L':
            speed = 50;
            direction = -90;
            break;
        case 'R':
            speed = 50;
            direction = 90;
            break;
        case 'U':
            speed = 75;
            direction = 45;
            break;
        case 'D':
            speed = -75;
            direction = -45;
            break;
        case 'S':
            speed = 0;
            direction = 0;
            break;
        case 'A':
            speed = 30;
            direction = 0;
            break;
        case 'Z':
            speed = -30;
            direction = 0;
            break;
        default:
            printf("Invalid input\n");
            return 1;
    }

    printf("Speed: %d, Direction: %d\n", speed, direction);
    return 0;
}
