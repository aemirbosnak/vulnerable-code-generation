#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 1000

typedef struct {
    double x;
    double y;
} Point;

void readPoints(Point *points, int *numPoints) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%lf %lf", &points[*numPoints].x, &points[*numPoints].y) != EOF) {
        (*numPoints)++;
    }
    fclose(file);
}

int main() {
    Point points[MAX_POINTS];
    int numPoints = 0;
    readPoints(points, &numPoints);

    // Intentionally left unallocated to induce buffer overflow
    // Point centroids[3];

    return 0;
}
