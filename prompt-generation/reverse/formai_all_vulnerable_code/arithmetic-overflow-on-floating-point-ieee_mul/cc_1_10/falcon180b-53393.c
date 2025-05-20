//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    double x, y, theta;
} Vector;

Vector forward(Vector v, double distance) {
    Vector result;
    result.x = v.x + cos(v.theta) * distance;
    result.y = v.y + sin(v.theta) * distance;
    result.theta = v.theta;
    return result;
}

Vector turn_left(Vector v, double angle) {
    Vector result;
    result.x = v.x;
    result.y = v.y;
    result.theta = v.theta - angle;
    if (result.theta < 0) {
        result.theta += 2 * M_PI;
    }
    return result;
}

Vector turn_right(Vector v, double angle) {
    Vector result;
    result.x = v.x;
    result.y = v.y;
    result.theta = v.theta + angle;
    if (result.theta > 2 * M_PI) {
        result.theta -= 2 * M_PI;
    }
    return result;
}

void move(Vector current, double distance, double angle) {
    Vector next = forward(current, distance);
    current = turn_left(current, angle);
    printf("%.2f %.2f %.2f\n", current.x, current.y, current.theta * 180 / M_PI);
    current = next;
}

int main() {
    Vector start;
    printf("Enter starting position (x y theta): ");
    scanf("%lf %lf %lf", &start.x, &start.y, &start.theta);
    double distance, angle;
    while (true) {
        printf("Enter distance and angle: ");
        scanf("%lf %lf", &distance, &angle);
        move(start, distance, angle);
    }
    return 0;
}