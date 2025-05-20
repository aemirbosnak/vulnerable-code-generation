//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Vector;

void move(Vector* robot, double distance, double angle) {
    double dx = distance * cos(angle + robot->theta);
    double dy = distance * sin(angle + robot->theta);
    robot->x += dx;
    robot->y += dy;
}

void turn(Vector* robot, double angle) {
    robot->theta += angle;
}

int main() {
    Vector robot = {0, 0, 0};
    int choice;
    double distance, angle;

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Please choose an action:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                printf("Enter the distance to move (in meters): ");
                scanf("%lf", &distance);
                printf("Enter the angle to turn (in degrees): ");
                scanf("%lf", &angle);
                move(&robot, distance, angle);
                break;
            case 2:
                printf("Enter the angle to turn (in degrees): ");
                scanf("%lf", &angle);
                turn(&robot, angle);
                break;
            case 3:
                printf("Enter the angle to turn (in degrees): ");
                scanf("%lf", &angle);
                turn(&robot, -angle);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Current position: (%lf, %lf) facing %lf degrees\n", robot.x, robot.y, robot.theta * 180 / PI);
        printf("Please choose an action:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");

        scanf("%d", &choice);
    }

    printf("Exiting program...\n");

    return 0;
}