//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateArea(Point *points, int n) {
    float area = 0.0;
    for (int i = 0; i < n; i++) {
        area += (points[i].x * points[(i + 1) % n].y) - (points[(i + 1) % n].x * points[i].y);
    }
    return fabs(area) / 2.0;
}

void getInput(Point **points, int *n) {
    printf("Enter the number of vertices (3 or more): ");
    scanf("%d", n);
    
    if (*n < 3) {
        fprintf(stderr, "A polygon must have at least 3 vertices.\n");
        exit(1);
    }

    *points = (Point *)malloc(*n * sizeof(Point));
    if (*points == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        if (scanf("%f %f", &(*points)[i].x, &(*points)[i].y) != 2) {
            fprintf(stderr, "Invalid input. Please enter floating point numbers for x and y.\n");
            free(*points);
            exit(1);
        }
    }
}

void freeMemory(Point *points) {
    free(points);
}

int main() {
    Point *points = NULL;
    int n = 0;

    getInput(&points, &n);
    
    float area = calculateArea(points, n);
    printf("The area of the polygon is: %.2f\n", area);

    freeMemory(points);
    return 0;
}