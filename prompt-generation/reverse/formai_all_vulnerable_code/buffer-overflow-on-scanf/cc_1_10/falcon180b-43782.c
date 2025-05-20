//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359
#define MAX_POINTS 1000

typedef struct {
    double x;
    double y;
} Point;

Point generateRandomPoint() {
    Point point;
    point.x = rand() % 1000;
    point.y = rand() % 1000;
    return point;
}

int isInsideCircle(Point center, double radius, Point point) {
    double dx = point.x - center.x;
    double dy = point.y - center.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= radius;
}

double estimatePi(int numPoints) {
    int insideCircleCount = 0;
    srand(time(NULL));

    for (int i = 0; i < numPoints; i++) {
        Point center = {.x = rand() % 1000,.y = rand() % 1000};
        Point point = generateRandomPoint();

        if (isInsideCircle(center, 500, point)) {
            insideCircleCount++;
        }
    }

    double pi = 4.0 * insideCircleCount / numPoints;
    return pi;
}

int main() {
    int numPoints;

    printf("Enter the number of points to generate: ");
    scanf("%d", &numPoints);

    if (numPoints > MAX_POINTS) {
        printf("Error: Too many points.\n");
        return 1;
    }

    double pi = estimatePi(numPoints);

    printf("Estimated value of pi with %d points: %.4f\n", numPoints, pi);

    return 0;
}