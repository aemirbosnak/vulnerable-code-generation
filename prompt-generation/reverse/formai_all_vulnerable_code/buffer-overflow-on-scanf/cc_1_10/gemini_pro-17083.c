//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <signal.h>

#define PI 3.14159265358979323846
#define MAX_SPEED 10
#define MAX_ANGLE 45

typedef struct {
    double x;
    double y;
    double angle;
} Drone;

Drone drone;

void initDrone() {
    drone.x = 0;
    drone.y = 0;
    drone.angle = 0;
}

void moveDrone(double speed, double angle) {
    drone.x += speed * cos(angle * PI / 180);
    drone.y += speed * sin(angle * PI / 180);
    drone.angle = fmod(drone.angle + angle, 360);
}

void printDrone() {
    printf("Drone position: (%f, %f)\n", drone.x, drone.y);
    printf("Drone angle: %f\n", drone.angle);
}

int main() {
    initDrone();

    while (1) {
        double speed, angle;
        printf("Enter speed: ");
        scanf("%lf", &speed);
        printf("Enter angle: ");
        scanf("%lf", &angle);

        if (speed > MAX_SPEED) {
            printf("Speed too high! Maximum speed is %d.\n", MAX_SPEED);
            continue;
        }
        if (angle > MAX_ANGLE) {
            printf("Angle too large! Maximum angle is %d.\n", MAX_ANGLE);
            continue;
        }

        moveDrone(speed, angle);
        printDrone();
    }

    return 0;
}