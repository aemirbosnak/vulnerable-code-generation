//MISTRAL-7B DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define CARTESIAN_TO_POLAR 1

typedef struct {
    float x, y;
} cartesian_t;

typedef struct {
    float r, theta;
} polar_t;

void cartesian_to_polar(cartesian_t *cartesian, polar_t *polar) {
    if (CARTESIAN_TO_POLAR) {
        polar->r = sqrt(pow(cartesian->x, 2) + pow(cartesian->y, 2));
        polar->theta = atan2(cartesian->y, cartesian->x);

        if (polar->theta < 0) {
            polar->theta += PI;
        }
    }
}

void polar_to_cartesian(polar_t *polar, cartesian_t *cartesian) {
    cartesian->x = polar->r * cos(polar->theta);
    cartesian->y = polar->r * sin(polar->theta);
}

void move_robot(float x_target, float y_target, float speed, float *x, float *y, float *theta) {
    cartesian_t current_position = {*x, *y};
    polar_t target_position, current_position_polar;

    cartesian_to_polar(&current_position, &current_position_polar);

    target_position.r = sqrt(pow(x_target, 2) + pow(y_target, 2));
    target_position.theta = atan2(y_target, x_target);

    if (target_position.theta < 0) {
        target_position.theta += PI;
    }

    float delta_r = fabs(target_position.r - current_position_polar.r);
    float delta_theta = fabs(target_position.theta - current_position_polar.theta);

    float left_rotation = 0;
    float right_rotation = 0;
    float forward_speed = 0;

    if (delta_r > 0.01) {
        forward_speed = speed * delta_r / 0.05; // adjust this value for your robot's capabilities
    }

    if (delta_theta > 0.01) {
        if (target_position.theta > current_position_polar.theta) {
            left_rotation = speed * delta_theta / 0.05;
        } else {
            right_rotation = speed * (-delta_theta) / 0.05;
        }
    }

    *x += forward_speed * cos(current_position_polar.theta);
    *y += forward_speed * sin(current_position_polar.theta);
    *theta += (left_rotation - right_rotation) / 2.0;
}

int main() {
    float x = 0;
    float y = 0;
    float theta = 0;
    float target_x = 5;
    float target_y = 5;
    float speed = 0.1;

    for (int i = 0; i < 100; i++) {
        move_robot(target_x, target_y, speed, &x, &y, &theta);
        printf("Position: (%f, %f), Orientation: %f\n", x, y, theta);
        sleep(1);
    }

    return 0;
}