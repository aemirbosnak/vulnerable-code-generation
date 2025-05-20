//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

Vector forward(Vector v, double d) {
    Vector result;
    result.x = v.x + d * cos(v.theta);
    result.y = v.y + d * sin(v.theta);
    result.theta = v.theta;
    return result;
}

Vector turnLeft(Vector v, double d) {
    Vector result;
    result.x = v.x + d * cos(v.theta - PI / 2);
    result.y = v.y + d * sin(v.theta - PI / 2);
    result.theta = v.theta - PI / 2;
    return result;
}

Vector turnRight(Vector v, double d) {
    Vector result;
    result.x = v.x + d * cos(v.theta + PI / 2);
    result.y = v.y + d * sin(v.theta + PI / 2);
    result.theta = v.theta + PI / 2;
    return result;
}

int main() {
    Vector robot;
    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    Vector target;
    target.x = 10;
    target.y = 5;
    target.theta = PI / 4;

    Vector path[100];
    int pathIndex = 0;
    path[pathIndex++] = robot;

    while (pathIndex < 100 && sqrt(pow(robot.x - target.x, 2) + pow(robot.y - target.y, 2)) > 0.1) {
        Vector next = forward(robot, 1);
        if (next.x > target.x) {
            path[pathIndex++] = turnLeft(robot, 1);
        } else if (next.x < target.x) {
            path[pathIndex++] = turnRight(robot, 1);
        } else if (next.y > target.y) {
            path[pathIndex++] = turnLeft(robot, 1);
        } else if (next.y < target.y) {
            path[pathIndex++] = turnRight(robot, 1);
        } else {
            path[pathIndex++] = next;
        }
        robot = next;
    }

    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("(%f, %f, %f)\n", path[i].x, path[i].y, path[i].theta);
    }

    return 0;
}