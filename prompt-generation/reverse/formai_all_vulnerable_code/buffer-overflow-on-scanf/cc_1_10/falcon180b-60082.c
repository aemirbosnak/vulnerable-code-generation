//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_SPEED 1000
#define MIN_SPEED 500
#define MAX_RADIUS 100
#define MIN_RADIUS 10
#define MAX_ANGLE 180
#define MIN_ANGLE 0
#define MAX_DISTANCE 100
#define MIN_DISTANCE 0

void move(int speed, int radius, double angle, int distance) {
    int x = radius * cos(angle * PI / 180) + distance * cos(angle * PI / 180);
    int y = radius * sin(angle * PI / 180) + distance * sin(angle * PI / 180);
    printf("Moving %d units at %d degrees with a radius of %d units.\n", distance, angle, radius);
    printf("Current position: (%d, %d)\n", x, y);
}

void turn(int speed, double angle) {
    printf("Turning %d degrees at %d units per second.\n", angle, speed);
}

int main() {
    int choice;
    int speed = MAX_SPEED;
    int radius = MAX_RADIUS;
    double angle = 0;
    int distance = 0;

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Move backward\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("How far do you want to move? ");
            scanf("%d", &distance);
            move(speed, radius, angle, distance);
            break;
        case 2:
            printf("How many degrees do you want to turn? ");
            scanf("%lf", &angle);
            turn(speed, angle);
            break;
        case 3:
            printf("How many degrees do you want to turn? ");
            scanf("%lf", &angle);
            turn(speed, angle);
            break;
        case 4:
            printf("How far do you want to move? ");
            scanf("%d", &distance);
            move(speed, radius, angle, distance);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}