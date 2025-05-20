//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000000
#define M 1000
#define PI 3.14159265358979323846

typedef struct {
    int id;
    double x, y, z;
} Point;

void calculate_distance(Point p1, Point p2, double *distance) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;

    *distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
}

int main() {
    Point *points;
    double *distances;
    int i, j;
    clock_t start, end;
    double total_distance = 0.0;

    // Allocate memory for arrays
    points = (Point *)malloc(N * sizeof(Point));
    distances = (double *)calloc(N * (N - 1) / 2, sizeof(double));

    // Initialize points with random values
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        points[i].id = i;
        points[i].x = (double)rand() / RAND_MAX * 10;
        points[i].y = (double)rand() / RAND_MAX * 10;
        points[i].z = (double)rand() / RAND_MAX * 10;
    }

    // Calculate distances between all pairs of points
    start = clock();
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            calculate_distance(points[i], points[j], &distances[i * (N - i - 1) / 2]);
            total_distance += distances[i * (N - i - 1) / 2];
        }
    }
    end = clock();

    // Free memory
    free(points);
    free(distances);

    // Print results and calculate execution time
    printf("Total distance: %.16f\n", total_distance);
    printf("Execution time: %.16f ms\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}