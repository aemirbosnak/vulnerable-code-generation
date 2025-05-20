//Falcon-180B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 1000

typedef struct {
    double x;
    double y;
} Point;

void read_points(Point *points, int *n_points) {
    FILE *file = fopen("points.txt", "r");
    if (file == NULL) {
        printf("Error: could not open points file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%lf %lf", &points[count].x, &points[count].y) == 2) {
        count++;
    }

    fclose(file);

    *n_points = count;
}

void calculate_distance(Point *points, int n_points, double *total_distance) {
    int i, j;
    double dx, dy;

    for (i = 0; i < n_points - 1; i++) {
        dx = points[i+1].x - points[i].x;
        dy = points[i+1].y - points[i].y;

        *total_distance += sqrt(dx*dx + dy*dy);
    }
}

void write_result(double result) {
    FILE *file = fopen("result.txt", "w");
    fprintf(file, "%.4f\n", result);
    fclose(file);
}

int main() {
    Point points[MAX_POINTS];
    int n_points = 0;

    read_points(points, &n_points);

    double total_distance = 0.0;
    calculate_distance(points, n_points, &total_distance);

    printf("Total distance: %.4f\n", total_distance);

    write_result(total_distance);

    return 0;
}