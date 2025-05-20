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

void readPoints(Point points[], int *numPoints, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%lf %lf", &points[*numPoints].x, &points[*numPoints].y) != EOF && *numPoints < MAX_POINTS) {
        (*numPoints)++;
    }
    fclose(file);
}

void writePoints(const Point points[], int numPoints, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numPoints; i++) {
        fprintf(file, "%.2f %.2f\n", points[i].x, points[i].y);
    }
    fclose(file);
}

int main() {
    Point points[MAX_POINTS];
    int numPoints = 0;
    readPoints(points, &numPoints, "input.txt");
    // K-means clustering algorithm implementation here
    writePoints(points, numPoints, "output.txt");
    return 0;
}
