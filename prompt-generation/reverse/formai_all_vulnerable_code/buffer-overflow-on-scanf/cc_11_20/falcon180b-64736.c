//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_SPEED 1000
#define MIN_SPEED 0
#define MAX_TURN_RATE 1000
#define MIN_TURN_RATE 0
#define MAX_ACCELERATION 100
#define MIN_ACCELERATION 0

#define MAX_VELOCITY 1000
#define MIN_VELOCITY 0

#define MAX_ANGULAR_VELOCITY 1000
#define MIN_ANGULAR_VELOCITY 0

#define FORWARD 0
#define BACKWARD 1
#define LEFT_TURN 2
#define RIGHT_TURN 3
#define STOP 4

#define PI_2 6.2831853071795864769252

int main() {
    double x = 0.0;
    double y = 0.0;
    double theta = 0.0;
    double v = 0.0;
    double a = 0.0;
    double w = 0.0;
    int mode = STOP;

    while (1) {
        printf("Enter mode (0: Stop, 1: Forward, 2: Backward, 3: Left turn, 4: Right turn): ");
        scanf("%d", &mode);

        if (mode == FORWARD) {
            v = MAX_SPEED;
            a = MAX_ACCELERATION;
        } else if (mode == BACKWARD) {
            v = -MAX_SPEED;
            a = -MAX_ACCELERATION;
        } else if (mode == LEFT_TURN) {
            w = MAX_TURN_RATE;
        } else if (mode == RIGHT_TURN) {
            w = -MAX_TURN_RATE;
        } else if (mode == STOP) {
            v = 0.0;
            a = 0.0;
            w = 0.0;
        }

        if (mode!= STOP) {
            v += a;
            if (v > MAX_VELOCITY) {
                v = MAX_VELOCITY;
            } else if (v < MIN_VELOCITY) {
                v = MIN_VELOCITY;
            }

            w += a / 2.0;
            if (w > MAX_ANGULAR_VELOCITY) {
                w = MAX_ANGULAR_VELOCITY;
            } else if (w < MIN_ANGULAR_VELOCITY) {
                w = MIN_ANGULAR_VELOCITY;
            }

            x += v * cos(theta);
            y += v * sin(theta);
            theta += w;

            printf("Current position: (%lf, %lf)\n", x, y);
        }
    }

    return 0;
}