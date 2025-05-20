//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

Vector forward(Vector v, double dist) {
    Vector result;
    result.x = v.x + dist * cos(v.theta);
    result.y = v.y + dist * sin(v.theta);
    result.theta = v.theta;
    return result;
}

Vector turn_left(Vector v, double angle) {
    Vector result;
    result.x = v.x;
    result.y = v.y;
    result.theta = v.theta - angle;
    if (result.theta < 0) {
        result.theta += 2 * PI;
    }
    return result;
}

Vector turn_right(Vector v, double angle) {
    Vector result;
    result.x = v.x;
    result.y = v.y;
    result.theta = v.theta + angle;
    if (result.theta > 2 * PI) {
        result.theta -= 2 * PI;
    }
    return result;
}

int main() {
    Vector robot;
    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    double dist = 0;
    int choice;

    printf("Enter the initial distance to move forward (in meters): ");
    scanf("%lf", &dist);

    forward(robot, dist);

    while (1) {
        system("clear");
        printf("Current position:\n");
        printf("X: %.2lf\n", robot.x);
        printf("Y: %.2lf\n", robot.y);
        printf("Theta: %.2lf\n", robot.theta * 180 / PI);

        printf("\nChoose an action:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the distance to move forward (in meters): ");
                scanf("%lf", &dist);
                robot = forward(robot, dist);
                break;
            case 2:
                printf("Enter the angle to turn left (in radians): ");
                scanf("%lf", &dist);
                robot = turn_left(robot, dist);
                break;
            case 3:
                printf("Enter the angle to turn right (in radians): ");
                scanf("%lf", &dist);
                robot = turn_right(robot, dist);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}