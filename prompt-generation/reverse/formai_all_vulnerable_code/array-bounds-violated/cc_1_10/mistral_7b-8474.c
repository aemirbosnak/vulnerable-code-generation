//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    double x, y, z;
} Point;

Point readPoint() {
    char str[100];
    Point p;
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%lf %lf %lf", &p.x, &p.y, &p.z);
    return p;
}

Point calculateCentroid(Point points[], int n) {
    Point centroid;
    for (int i = 0; i < n; i++) {
        centroid.x += points[i].x;
        centroid.y += points[i].y;
        centroid.z += points[i].z;
    }
    centroid.x /= n;
    centroid.y /= n;
    centroid.z /= n;
    return centroid;
}

double calculateDistance(Point centroid, Point point) {
    double dx = point.x - centroid.x, dy = point.y - centroid.y, dz = point.z - centroid.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    int n;
    fscanf(stdin, "%d", &n);
    Point points[n];

    for (int i = 0; i < n; i++) {
        points[i] = readPoint();
    }

    Point centroid = calculateCentroid(points, n);

    Point farthestPoint = points[0];
    double maxDistance = 0;

    for (int i = 0; i < n; i++) {
        double distance = calculateDistance(centroid, points[i]);
        if (distance > maxDistance) {
            maxDistance = distance;
            farthestPoint = points[i];
        }
    }

    printf("Farthest point: %.2lf %.2lf %.2lf\n", farthestPoint.x, farthestPoint.y, farthestPoint.z);

    return 0;
}