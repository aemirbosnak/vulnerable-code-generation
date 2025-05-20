//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAX_OBJECTS = 100;
const int MAX_STEPS = 10000;

struct Object {
    double x;
    double y;
    double vx;
    double vy;
};

double calculateGravity(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt(dx * dx + dy * dy);
    double g = -9.8;
    double f = g * distance;
    return f;
}

void moveObjects(struct Object objects[], int numObjects, int steps) {
    for (int i = 0; i < numObjects; i++) {
        for (int j = 0; j < numObjects; j++) {
            double gravity = calculateGravity(objects[i].x, objects[i].y, objects[j].x, objects[j].y);
            objects[i].vx += gravity * objects[j].x;
            objects[i].vy += gravity * objects[j].y;
        }
    }
    for (int i = 0; i < numObjects; i++) {
        objects[i].x += objects[i].vx * steps;
        objects[i].y += objects[i].vy * steps;
    }
}

int main() {
    struct Object objects[MAX_OBJECTS];
    int numObjects = 0;
    printf("Enter the number of objects: ");
    scanf("%d", &numObjects);
    while (numObjects > MAX_OBJECTS) {
        printf("Number of objects must be less than %d. Enter the number of objects: ", MAX_OBJECTS);
        scanf("%d", &numObjects);
    }
    for (int i = 0; i < numObjects; i++) {
        printf("Enter the x and y coordinates for object %d: ", i + 1);
        scanf("%lf %lf", &objects[i].x, &objects[i].y);
    }
    printf("Enter the initial velocity for object 1: ");
    scanf("%lf %lf", &objects[0].vx, &objects[0].vy);
    for (int i = 1; i < numObjects; i++) {
        printf("Enter the initial velocity for object %d: ", i + 1);
        scanf("%lf %lf", &objects[i].vx, &objects[i].vy);
    }
    for (int steps = 0; steps < MAX_STEPS; steps++) {
        moveObjects(objects, numObjects, steps);
        printf("Step %d:\n", steps + 1);
        for (int i = 0; i < numObjects; i++) {
            printf("Object %d: (%lf, %lf), (%lf, %lf)\n", i + 1, objects[i].x, objects[i].y, objects[i].vx, objects[i].vy);
        }
    }
    return 0;
}