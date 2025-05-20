//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

void move(Vector* v, double distance, double direction) {
    Vector new_v;
    new_v.x = v->x + distance * cos(direction);
    new_v.y = v->y + distance * sin(direction);
    v->theta += direction;
    v->x = new_v.x;
    v->y = new_v.y;
}

void turn(Vector* v, double angle) {
    v->theta += angle;
}

void remote_control(Vector* v) {
    printf("Enter command (forward, backward, left, right, turn left, turn right): ");
    char command[10];
    scanf("%s", command);

    if (strcmp(command, "forward") == 0) {
        move(v, 0.1, 0);
    } else if (strcmp(command, "backward") == 0) {
        move(v, -0.1, 180);
    } else if (strcmp(command, "left") == 0) {
        turn(v, -0.1);
    } else if (strcmp(command, "right") == 0) {
        turn(v, 0.1);
    } else if (strcmp(command, "turn left") == 0) {
        turn(v, -0.1);
    } else if (strcmp(command, "turn right") == 0) {
        turn(v, 0.1);
    } else {
        printf("Invalid command\n");
    }
}

int main() {
    Vector v;
    v.x = 0;
    v.y = 0;
    v.theta = 0;

    remote_control(&v);

    return 0;
}