//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

void generateRandomPoints(Point *points, int numPoints) {
    int i;
    srand(time(NULL));
    for (i = 0; i < numPoints; i++) {
        points[i].x = rand() % MAX_SIZE;
        points[i].y = rand() % MAX_SIZE;
    }
}

double distance(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double perimeter(Point *points, int numPoints) {
    int i;
    double perimeter = 0;
    for (i = 0; i < numPoints; i++) {
        if (i == numPoints - 1) {
            perimeter += distance(points[i], points[0]);
        } else {
            perimeter += distance(points[i], points[i + 1]);
        }
    }
    return perimeter;
}

double area(Point *points, int numPoints) {
    int i, j;
    double area = 0;
    for (i = 0; i < numPoints; i++) {
        j = (i + 1) % numPoints;
        area += distance(points[i], points[j]) * distance(points[(i + 1) % numPoints], points[(j + 1) % numPoints]);
    }
    return area / 2;
}

void printPoints(Point *points, int numPoints) {
    int i;
    for (i = 0; i < numPoints; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

int main() {
    int numPoints;
    Point points[MAX_SIZE];
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);
    generateRandomPoints(points, numPoints);
    printf("Perimeter: %.2lf\n", perimeter(points, numPoints));
    printf("Area: %.2lf\n", area(points, numPoints));
    printf("Points: ");
    printPoints(points, numPoints);
    return 0;
}