//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    float x;
    float y;
} Point;

Point points[MAX_POINTS];
int pointCount = 0;

Point pivot;

// Function to read points from a file
void readPointsFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%f %f", &points[pointCount].x, &points[pointCount].y) != EOF) {
        pointCount++;
        if (pointCount >= MAX_POINTS) {
            break;
        }
    }
    fclose(file);
}

// Function to find the pivot point (with the lowest y, and leftmost x if tied)
void findPivot() {
    pivot = points[0];
    for (int i = 1; i < pointCount; i++) {
        if (points[i].y < pivot.y || (points[i].y == pivot.y && points[i].x < pivot.x)) {
            pivot = points[i];
        }
    }
}

// Function to calculate the orientation of the triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Comparison function for sorting points based on polar angle with respect to the pivot
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(pivot, *p1, *p2);
    if (o == 0) {
        return (hypot(pivot.x - p2->x, pivot.y - p2->y) <= hypot(pivot.x - p1->x, pivot.y - p1->y)) ? -1 : 1;
    }
    return (o == 2) ? -1 : 1; // -1 if p1 is further than p2
}

// Function to find the convex hull
void computeConvexHull(Point *hull) {
    // Sort points by polar angle with respect to the pivot
    qsort(points, pointCount, sizeof(Point), compare);

    // Create an empty stack to store the points of the convex hull
    int hullPointCount = 0;
    for (int i = 0; i < pointCount; i++) {
        while (hullPointCount >= 2 && orientation(hull[hullPointCount - 2], hull[hullPointCount - 1], points[i]) != 2) {
            hullPointCount--;
        }
        hull[hullPointCount++] = points[i];
    }
    printf("Convex Hull Points:\n");
    for (int i = 0; i < hullPointCount; i++) {
        printf("(%0.2f, %0.2f)\n", hull[i].x, hull[i].y);
    }
}

// Main function
int main() {
    readPointsFromFile("points.txt");
    
    if (pointCount < 3) {
        printf("At least 3 points are required to form a convex hull.\n");
        return 0;
    }
    
    findPivot();
    
    Point hull[MAX_POINTS];
    computeConvexHull(hull);

    return 0;
}