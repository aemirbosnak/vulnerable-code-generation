//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct {
    int x, y;
} Point;

Point points[MAX];
int numPoints;

void readPoints() {
    printf("Enter number of points (max %d): ", MAX);
    scanf("%d", &numPoints);

    for (int i = 0; i < numPoints; i++) {
        printf("Enter point %d (x y): ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void printPoints() {
    for (int i = 0; i < numPoints; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void convexHull(int start, int end) {
    int n = end - start + 1;
    Point hull[n];

    for (int i = 0; i < n; i++) {
        int minIndex = start;

        for (int j = start; j <= end; j++) {
            if (distance(points[j], points[minIndex]) > distance(points[j], points[i])) {
                minIndex = j;
            }
        }

        hull[i] = points[minIndex];
    }

    printf("Convex hull:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int main() {
    readPoints();
    convexHull(0, numPoints-1);

    return 0;
}