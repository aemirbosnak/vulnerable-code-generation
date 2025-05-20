//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Vector2D;

Vector2D robotPos;
Vector2D targetPos;
double wheelBase;
double wheelRadius;

void moveForward(double distance) {
    double deltaTheta = distance * (2 * PI * wheelRadius) / wheelBase;
    robotPos.theta += deltaTheta;
    robotPos.x += distance * cos(robotPos.theta);
    robotPos.y += distance * sin(robotPos.theta);
}

void turn(double angle) {
    double deltaTheta = angle * (2 * PI * wheelRadius) / wheelBase;
    robotPos.theta += deltaTheta;
    robotPos.x += (robotPos.y - targetPos.y) * sin(deltaTheta) - (robotPos.x - targetPos.x) * cos(deltaTheta);
    robotPos.y += (robotPos.x - targetPos.x) * sin(deltaTheta) + (robotPos.y - targetPos.y) * cos(deltaTheta);
}

int main() {
    srand(time(NULL));

    printf("Enter the wheelbase (in meters): ");
    scanf("%lf", &wheelBase);

    printf("Enter the wheel radius (in meters): ");
    scanf("%lf", &wheelRadius);

    robotPos.x = 0;
    robotPos.y = 0;
    robotPos.theta = 0;

    printf("Enter the target position (x y): ");
    scanf("%lf %lf", &targetPos.x, &targetPos.y);

    while (1) {
        system("clear");
        printf("Current position: (%lf, %lf, %lf)\n", robotPos.x, robotPos.y, robotPos.theta * (180 / PI));
        printf("Target position: (%lf, %lf)\n", targetPos.x, targetPos.y);
        printf("Enter movement command (forward distance, turn angle): ");
        double distance, angle;
        scanf("%lf %lf", &distance, &angle);

        moveForward(distance);
        turn(angle);

        if (fabs(robotPos.x - targetPos.x) < 0.1 && fabs(robotPos.y - targetPos.y) < 0.1) {
            printf("Arrived at target position!\n");
            break;
        }
    }

    return 0;
}