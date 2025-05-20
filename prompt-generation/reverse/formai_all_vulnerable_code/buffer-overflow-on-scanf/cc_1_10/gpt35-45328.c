//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void drive_forward(int speed);
void drive_backward(int speed);
void steer_right(int degrees);
void steer_left(int degrees);
void honk_horn();

int main()
{
    int speed = 0;
    int degrees = 0;

    printf("Welcome to the Remote Control Vehicle Simulator!\n\n");

    do {
        printf("Please enter a speed between 0 and 100:\n");
        scanf("%d", &speed);
    } while (speed < 0 || speed > 100);

    printf("\nSetting speed to %d...\n", speed);

    do {
        printf("\nPlease enter a degree value between -90 and 90:\n");
        scanf("%d", &degrees);
    } while (degrees < -90 || degrees > 90);

    printf("\nSteering %d degrees...\n", degrees);

    drive_forward(speed);
    steer_right(degrees);
    honk_horn();
    drive_backward(speed);
    steer_left(degrees);

    printf("\nSimulation complete!\n");

    return 0;
}

void drive_forward(int speed)
{
    printf("\nDriving forward at %d mph...\n", speed);
}

void drive_backward(int speed)
{
    printf("\nDriving backward at %d mph...\n", speed);
}

void steer_right(int degrees)
{
    printf("\nSteering right by %d degrees...\n", degrees);
}

void steer_left(int degrees)
{
    printf("\nSteering left by %d degrees...\n", degrees);
}

void honk_horn()
{
    printf("\nHonking horn...\n");
}