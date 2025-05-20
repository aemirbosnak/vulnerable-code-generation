//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define ROTATION_SPEED 0.1
#define MOVEMENT_SPEED 0.05
#define TIME_STEP 0.01

typedef struct {
    double x, y, z, theta;
} Vector;

void rotate(Vector *v, double theta) {
    v->x = v->x * cos(theta) - v->y * sin(theta);
    v->y = v->x * sin(theta) + v->y * cos(theta);
}

void move(Vector *v, double dtheta) {
    double dx = MOVEMENT_SPEED * sin(v->theta);
    double dy = MOVEMENT_SPEED * cos(v->theta);
    v->x += dx * cos(v->theta + dtheta) - dy * sin(v->theta + dtheta);
    v->y += dx * sin(v->theta + dtheta) + dy * cos(v->theta + dtheta);
}

void draw(Vector v) {
    int x = (int) (v.x * 10);
    int y = (int) (v.y * 10);
    printf("(%d, %d)\n", x, y);
}

int main() {
    Vector v = {0, 0, 0, 0};
    srand(time(NULL));
    int x, y;
    while (1) {
        system("clear");
        printf("Enter x and y coordinates: ");
        scanf("%d %d", &x, &y);
        v.x = x / 10.0;
        v.y = y / 10.0;
        v.theta = 0;
        while (1) {
            draw(v);
            rotate(&v, ROTATION_SPEED);
            move(&v, ROTATION_SPEED);
            usleep(TIME_STEP * 1000);
        }
    }
    return 0;
}