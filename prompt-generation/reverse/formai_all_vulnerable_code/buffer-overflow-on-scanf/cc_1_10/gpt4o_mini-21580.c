//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the area of the polygon using the Shoelace formula
double calculateArea(Point* points, int n) {
    double area = 0.0;
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // Wrap around to the first point
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }

    return fabs(area) / 2.0; // Return the absolute value of area divided by 2
}

int main() {
    int n;

    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("A polygon must have at least 3 vertices.\n");
        return 1;
    }

    Point* points = (Point*)malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the vertices of the polygon
    printf("Enter the vertices of the polygon (x y) format:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double area = calculateArea(points, n);
    
    printf("The area of the polygon is: %.2f\n", area);

    // Clean up dynamic memory
    free(points);
    
    return 0;
}