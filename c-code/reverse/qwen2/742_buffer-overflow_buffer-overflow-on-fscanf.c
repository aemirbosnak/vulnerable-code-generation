#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 1000
#define DIMENSION 2

typedef struct {
    double x;
    double y;
} Point;

void readPoints(Point points[], int *numPoints) {
    FILE *file = fopen("points.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (!feof(file)) {
        fscanf(file, "%lf %lf", &points[*numPoints].x, &points[*numPoints].y);
        (*numPoints)++;
    }
    fclose(file);
}

int main() {
    Point points[MAX_POINTS];
    int numPoints = 0;

    readPoints(points, &numPoints);

    // Intentionally omitting bounds checking for demonstration purposes
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i, points[i].x, points[i].y);
    }

    return 0;
}
