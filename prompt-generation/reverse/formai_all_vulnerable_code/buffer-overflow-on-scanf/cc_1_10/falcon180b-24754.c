//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function prototypes
void generate_points(int n, double *x, double *y);
double distance(double x1, double y1, double x2, double y2);
int find_closest_pair(int n, double *x, double *y, double *d);

int main() {
    int n;
    double *x, *y;
    double *d;
    int k;
    srand(time(NULL));
    printf("Enter the number of points: ");
    scanf("%d", &n);
    x = (double *)malloc(n * sizeof(double));
    y = (double *)malloc(n * sizeof(double));
    d = (double *)malloc(n * sizeof(double));
    generate_points(n, x, y);
    printf("Input points:\n");
    for (k = 0; k < n; k++) {
        printf("(%lf, %lf)\n", x[k], y[k]);
    }
    k = find_closest_pair(n, x, y, d);
    printf("The closest pair of points is (%lf, %lf) and (%lf, %lf) with a distance of %lf\n", x[k], y[k], x[k+1], y[k+1], d[k]);
    free(x);
    free(y);
    free(d);
    return 0;
}

void generate_points(int n, double *x, double *y) {
    int i;
    for (i = 0; i < n; i++) {
        x[i] = rand() % 100;
        y[i] = rand() % 100;
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int find_closest_pair(int n, double *x, double *y, double *d) {
    int i, j, k;
    double min_dist = 1000;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            double dist = distance(x[i], y[i], x[j], y[j]);
            if (dist < min_dist) {
                min_dist = dist;
                k = i;
            }
        }
    }
    d[k] = min_dist;
    return k;
}