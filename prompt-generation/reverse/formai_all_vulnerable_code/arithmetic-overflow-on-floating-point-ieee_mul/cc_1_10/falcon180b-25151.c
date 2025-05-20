//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846

struct Point {
    double x, y;
};

struct Route {
    int numPoints;
    struct Point *points;
};

void generateRandomRoute(struct Route *route, double startX, double startY, double endX, double endY) {
    srand(time(NULL));
    int numPoints = rand() % 10 + 2;
    route->numPoints = numPoints;
    route->points = malloc(numPoints * sizeof(struct Point));

    double dx = endX - startX;
    double dy = endY - startY;
    double distance = sqrt(dx * dx + dy * dy);
    double step = distance / (numPoints - 1);

    struct Point *currentPoint = route->points;
    for (int i = 0; i < numPoints; i++) {
        currentPoint->x = startX + i * step * cos(2 * PI * rand() / RAND_MAX);
        currentPoint->y = startY + i * step * sin(2 * PI * rand() / RAND_MAX);
        currentPoint++;
    }
}

void printRoute(struct Route *route) {
    struct Point *currentPoint = route->points;
    printf("Route: ");
    for (int i = 0; i < route->numPoints; i++) {
        printf("(%f, %f) -> ", currentPoint->x, currentPoint->y);
        currentPoint++;
    }
    printf("Destination\n");
}

int main() {
    double startX, startY, endX, endY;
    printf("Enter starting coordinates (latitude, longitude): ");
    scanf("%lf %lf", &startX, &startY);
    printf("Enter destination coordinates (latitude, longitude): ");
    scanf("%lf %lf", &endX, &endY);

    struct Route route;
    generateRandomRoute(&route, startX, startY, endX, endY);
    printRoute(&route);

    return 0;
}