//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef struct {
    Point start;
    Point end;
} Line;

void generateRandomPoints(Point points[], int numPoints) {
    srand(time(NULL));
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % MAX_SIZE;
        points[i].y = rand() % MAX_SIZE;
    }
}

int countPointsInsideCircle(Circle circle, Point points[], int numPoints) {
    int count = 0;
    for (int i = 0; i < numPoints; i++) {
        double distance = sqrt(pow(points[i].x - circle.center.x, 2) + pow(points[i].y - circle.center.y, 2));
        if (distance <= circle.radius) {
            count++;
        }
    }
    return count;
}

double calculatePi(int numPoints) {
    Circle circle;
    Point points[MAX_SIZE];
    generateRandomPoints(points, numPoints);
    int count = countPointsInsideCircle(circle, points, numPoints);
    double pi = 4.0 * count / numPoints;
    return pi;
}

int main() {
    int numPoints;
    printf("Enter the number of points to generate: ");
    scanf("%d", &numPoints);

    double pi = calculatePi(numPoints);

    printf("The value of pi is: %.6f\n", pi);

    return 0;
}