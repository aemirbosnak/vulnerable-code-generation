//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define DIMENSIONS 2

typedef struct {
    int id;
    double x, y;
} Point;

void initializeCentroids(Point centroids[], int k, Point points[], int n) {
    for (int i = 0; i < k; i++) {
        int index = rand() % n;
        centroids[i].x = points[index].x;
        centroids[i].y = points[index].y;
    }
}

int euclideanDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void kMeans(Point points[], int n, int k, Point centroids[]) {
    int iterations = 0;
    while (iterations < 100) {
        iterations++;
        int changed = 0;
        for (int i = 0; i < n; i++) {
            int minIndex = -1;
            double minDistance = INFINITY;
            for (int j = 0; j < k; j++) {
                double distance = euclideanDistance(points[i], centroids[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = j;
                }
            }
            if (minIndex!= points[i].id) {
                points[i].id = minIndex;
                changed = 1;
            }
        }
        if (!changed) {
            break;
        }
        initializeCentroids(centroids, k, points, n);
    }
}

void printPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%f, %f)\n", points[i].id, points[i].x, points[i].y);
    }
}

int main() {
    Point points[MAX_POINTS];
    int n = 0;
    while (n < MAX_POINTS) {
        printf("Enter point (x y): ");
        scanf("%lf %lf", &points[n].x, &points[n].y);
        n++;
    }
    Point centroids[3];
    kMeans(points, n, 3, centroids);
    printf("Centroids:\n");
    printPoints(centroids, 3);
    return 0;
}