//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the robot's position and orientation
typedef struct {
    double x;
    double y;
    double theta;
} Robot;

// Define the robot's movement parameters
typedef struct {
    double v; // linear velocity
    double w; // angular velocity
} Movement;

// Define the robot's sensor readings
typedef struct {
    double r; // distance to obstacle
    double phi; // angle to obstacle
} Sensor;

// Define the robot's control functions
void move(Robot* r, Movement* m) {
    r->x += m->v * cos(r->theta);
    r->y += m->v * sin(r->theta);
    r->theta += m->w;
}

Sensor* sense(Robot* r) {
    double d = sqrt(pow(r->x - 5, 2) + pow(r->y - 3, 2));
    double phi = atan2(r->y - 3, r->x - 5);
    return (Sensor*) malloc(sizeof(Sensor));
}

// Define the robot's main control loop
int main() {
    Robot r = {0, 0, 0};
    Movement m = {1, 0};
    Sensor s;

    while (1) {
        sense(&r);
        printf("Distance to obstacle: %f, Angle to obstacle: %f\n", s.r, s.phi);
        move(&r, &m);
        sleep(1);
    }

    return 0;
}