//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LENGTH 256
#define PI 3.14159265358979323846

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Circle {
    Point center;
    float radius;
} Circle;

Circle createCircle(int x, int y, float r) {
    Circle circ;
    circ.center.x = x;
    circ.center.y = y;
    circ.radius = r;
    return circ;
}

int isInsideCircle(Point p, Circle circ) {
    float distance = sqrtf((powf(p.x - circ.center.x, 2) + powf(p.y - circ.center.y, 2)));
    if (distance <= circ.radius) {
        return 1;
    } else {
        return 0;
    }
}

void printCircle(Circle circ) {
    printf("Circle with center at (%d, %d) and radius %f\n", circ.center.x, circ.center.y, circ.radius);
}

void generateRandomPoint(Point *p) {
    p->x = rand() % MAX_LENGTH;
    p->y = rand() % MAX_LENGTH;
}

void drawCircle(Circle circ) {
    printf("Drawing circle...\n");
    Point point;
    generateRandomPoint(&point);
    if (isInsideCircle(point, circ)) {
        printf("Point (%d, %d) is inside the circle!\n", point.x, point.y);
    } else {
        printf("Point (%d, %d) is outside the circle.\n", point.x, point.y);
    }
    printCircle(circ);
}

int main() {
    srand(time(NULL));
    Circle myCircle = createCircle(MAX_LENGTH / 2, MAX_LENGTH / 2, 50);
    printf("Generating random points...\n");
    int i;
    for (i = 0; i < 10; i++) {
        drawCircle(myCircle);
    }
    return 0;
}