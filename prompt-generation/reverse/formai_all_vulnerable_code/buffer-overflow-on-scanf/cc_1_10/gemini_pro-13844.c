//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} position;

typedef struct {
    double left;
    double right;
} velocity;

void update_position(position *pos, velocity *vel, double dt) {
    pos->x += vel->left * cos(pos->theta) * dt + vel->right * cos(pos->theta + PI / 2) * dt;
    pos->y += vel->left * sin(pos->theta) * dt + vel->right * sin(pos->theta + PI / 2) * dt;
    pos->theta += (vel->left - vel->right) / 100.0 * dt;
}

void print_position(position *pos) {
    printf("Position: (%.2f, %.2f, %.2f)\n", pos->x, pos->y, pos->theta);
}

int main() {
    position pos = {0.0, 0.0, 0.0};
    velocity vel = {0.0, 0.0};

    double dt = 0.1;

    while (1) {
        char command;
        scanf(" %c ", &command);

        switch (command) {
            case 'w':
                vel.left += 10.0;
                vel.right += 10.0;
                break;
            case 's':
                vel.left -= 10.0;
                vel.right -= 10.0;
                break;
            case 'a':
                vel.left -= 10.0;
                vel.right += 10.0;
                break;
            case 'd':
                vel.left += 10.0;
                vel.right -= 10.0;
                break;
            case 'q':
                return 0;
        }

        update_position(&pos, &vel, dt);
        print_position(&pos);
    }

    return 0;
}