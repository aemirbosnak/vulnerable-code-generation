//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 9.81

typedef struct {
    double x, y, z;
} Vector3;

typedef struct {
    double roll, pitch, yaw;
} Orientation;

Vector3 position;
Orientation orientation;

void update_position(double vx, double vy, double vz, double dt) {
    position.x += vx * dt;
    position.y += vy * dt;
    position.z += vz * dt;
}

void update_orientation(double roll_rate, double pitch_rate, double yaw_rate, double dt) {
    orientation.roll += roll_rate * dt;
    orientation.pitch += pitch_rate * dt;
    orientation.yaw += yaw_rate * dt;
}

void print_position() {
    printf("Position: (%g, %g, %g)\n", position.x, position.y, position.z);
}

void print_orientation() {
    printf("Orientation: (%g, %g, %g)\n", orientation.roll, orientation.pitch, orientation.yaw);
}

int main() {
    srand(time(NULL));

    position.x = 0;
    position.y = 0;
    position.z = 0;

    orientation.roll = 0;
    orientation.pitch = 0;
    orientation.yaw = 0;

    double dt = 0.01;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double roll_rate = 0;
    double pitch_rate = 0;
    double yaw_rate = 0;
    double thrust = 0;
    int quit = 0;

    while (!quit) {
        printf("Enter commands (vx vy vz roll pitch yaw thrust quit):\n");
        scanf("%lg %lg %lg %lg %lg %lg %lg", &vx, &vy, &vz, &roll_rate, &pitch_rate, &yaw_rate, &thrust);

        if (thrust > 0) {
            update_position(vx, vy, vz, dt);
            update_orientation(roll_rate, pitch_rate, yaw_rate, dt);
        }

        print_position();
        print_orientation();

        if (quit) {
            break;
        }
    }

    return 0;
}