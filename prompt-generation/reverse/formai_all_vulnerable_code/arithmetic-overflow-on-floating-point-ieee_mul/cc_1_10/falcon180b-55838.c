//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Vector;

Vector forward(Vector v, double distance) {
    Vector result;
    result.x = v.x + distance * cos(v.theta);
    result.y = v.y + distance * sin(v.theta);
    result.theta = v.theta;
    return result;
}

Vector turn_left(Vector v, double angle) {
    Vector result;
    result.x = v.x;
    result.y = v.y;
    result.theta = v.theta - angle;
    if (result.theta < 0) {
        result.theta += 2 * PI;
    }
    return result;
}

Vector turn_right(Vector v, double angle) {
    Vector result;
    result.x = v.x;
    result.y = v.y;
    result.theta = v.theta + angle;
    if (result.theta > 2 * PI) {
        result.theta -= 2 * PI;
    }
    return result;
}

void move(Vector start, Vector end, double speed) {
    Vector current = start;
    double distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    double steps = distance / speed;

    for (int i = 0; i <= steps; i++) {
        current = forward(current, speed);
        printf("%.2f %.2f %.2f\n", current.x, current.y, current.theta);
        usleep(100000);
    }
}

int main() {
    Vector start, end;
    start.x = 0;
    start.y = 0;
    start.theta = 0;
    end.x = 10;
    end.y = 10;
    end.theta = PI / 4;

    move(start, end, 1);

    return 0;
}