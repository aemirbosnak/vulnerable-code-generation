//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to hold a point in 2D space
typedef struct {
    float x;
    float y;
} Point;

// Function to calculate the area of a triangle given three points
float calculateTriangleArea(Point a, Point b, Point c) {
    return 0.5f * fabs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

// Function to check if a point is inside a polygon
int isPointInPolygon(Point *polygon, int n, Point p) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if ((polygon[i].y > p.y) != (polygon[j].y > p.y) &&
            (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            count++;
        }
    }
    return count % 2; // Inside if odd, outside if even
}

// Function to calculate the distance between two points
float calculateDistance(Point a, Point b) {
    return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Function to print a point
void printPoint(Point p) {
    printf("Point(%f, %f)\n", p.x, p.y);
}

int main() {
    // Example usage of geometry algorithms

    // 1. Calculate the area of a triangle given three points
    Point A = {0.0f, 0.0f};
    Point B = {5.0f, 0.0f};
    Point C = {0.0f, 5.0f};

    float area = calculateTriangleArea(A, B, C);
    printf("Area of triangle ABC: %f\n", area);

    // 2. Check if a point is inside a polygon
    int n;
    printf("Enter number of vertices in polygon: ");
    scanf("%d", &n);

    Point *polygon = (Point *)malloc(n * sizeof(Point));
    printf("Enter coordinates of polygon vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &polygon[i].x, &polygon[i].y);
    }

    Point p;
    printf("Enter point coordinates (x y) to check if it's inside the polygon: ");
    scanf("%f %f", &p.x, &p.y);

    if (isPointInPolygon(polygon, n, p)) {
        printf("Point ");
        printPoint(p);
        printf("is inside the polygon.\n");
    } else {
        printf("Point ");
        printPoint(p);
        printf("is outside the polygon.\n");
    }

    free(polygon); // Free allocated memory

    // 3. Calculate distance between two points
    Point D, E;
    printf("Enter coordinates of point D (x y): ");
    scanf("%f %f", &D.x, &D.y);
    printf("Enter coordinates of point E (x y): ");
    scanf("%f %f", &E.x, &E.y);

    float distance = calculateDistance(D, E);
    printf("Distance between D and E: %f\n", distance);

    return 0;
}