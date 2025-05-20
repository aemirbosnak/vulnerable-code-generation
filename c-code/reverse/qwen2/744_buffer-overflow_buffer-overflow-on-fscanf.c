#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 1000
#define DIMENSION 3

typedef struct {
    double coords[DIMENSION];
} Point;

void readPoints(Point points[], int *numPoints) {
    FILE *file = fopen("points.txt", "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%lf %lf %lf", &points[*numPoints].coords[0], &points[*numPoints].coords[1], &points[*numPoints].coords[2]) == DIMENSION) {
        (*numPoints)++;
    }
    fclose(file);
}

int main() {
    Point points[MAX_POINTS];
    int numPoints = 0;
    readPoints(points, &numPoints);

    // Intentional buffer overflow vulnerability
    char buffer[10];
    fscanf(stdin, "%s", buffer); // Vulnerable line

    printf("Number of points: %d\n", numPoints);
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%.2f, %.2f, %.2f)\n", i + 1, points[i].coords[0], points[i].coords[1], points[i].coords[2]);
    }

    return 0;
}
