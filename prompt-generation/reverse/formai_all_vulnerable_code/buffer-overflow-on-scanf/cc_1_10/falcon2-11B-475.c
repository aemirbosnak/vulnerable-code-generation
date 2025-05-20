//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANGLE 60
#define MAX_SPEED 20
#define DELAY 500

int main(int argc, char *argv[])
{
    int angle, speed;
    int delay = DELAY;
    srand(time(NULL));

    printf("Drone Remote Control\n");
    printf("Please enter the angle (0-60): ");
    scanf("%d", &angle);

    while (angle > MAX_ANGLE || angle < 0)
    {
        printf("Invalid angle! Please enter the angle (0-60): ");
        scanf("%d", &angle);
    }

    printf("Please enter the speed (0-20): ");
    scanf("%d", &speed);

    while (speed > MAX_SPEED || speed < 0)
    {
        printf("Invalid speed! Please enter the speed (0-20): ");
        scanf("%d", &speed);
    }

    printf("Drone is moving with angle %d and speed %d\n", angle, speed);
    sleep(delay);

    printf("Drone is turning to the right\n");
    angle += 5;

    if (angle > MAX_ANGLE)
        angle = MAX_ANGLE;

    printf("Drone is moving with angle %d and speed %d\n", angle, speed);
    sleep(delay);

    printf("Drone is turning to the left\n");
    angle -= 5;

    if (angle < 0)
        angle = 0;

    printf("Drone is moving with angle %d and speed %d\n", angle, speed);
    sleep(delay);

    printf("Drone is moving straight\n");
    angle = 30;

    printf("Drone is moving with angle %d and speed %d\n", angle, speed);
    sleep(delay);

    printf("Drone is landing\n");
    sleep(delay * 2);

    return 0;
}