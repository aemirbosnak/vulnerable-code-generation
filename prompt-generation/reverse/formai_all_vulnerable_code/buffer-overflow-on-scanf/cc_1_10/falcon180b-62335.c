//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 100

typedef struct {
    int x;
    int y;
} Point;

void generatePoints(int n, Point* points) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
    }
}

int convexHull(int n, Point* points, Point* hull) {
    int hullSize = 0;
    for (int i = 0; i < n; i++) {
        if (hullSize == 0 || points[i].x < hull[hullSize - 1].x) {
            hull[hullSize++] = points[i];
        }
        else if (hullSize > 1 && points[i].x < hull[0].x) {
            hull[0] = points[i];
        }
        else if (hullSize > 1 && points[i].x < hull[hullSize - 1].x) {
            for (int j = hullSize - 1; j > 0; j--) {
                hull[j] = hull[j - 1];
            }
            hull[0] = points[i];
            hullSize++;
        }
    }
    return hullSize;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point points[MAX_POINTS];
    generatePoints(n, points);
    printf("Enter the number of points to generate convex hull: ");
    scanf("%d", &n);
    Point hull[MAX_POINTS];
    int hullSize = convexHull(n, points, hull);
    printf("The convex hull has %d points:\n", hullSize);
    for (int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
    return 0;
}