//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000
#define PI 3.14159265358979323846

double rand_double(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    double x[MAX_SIZE], y[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        x[i] = rand_double(0, 1);
        y[i] = rand_double(0, 1);
    }

    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }

    double mean_x = sum_x / n, mean_y = sum_y / n;
    double var_x = 0, var_y = 0, cov = 0;

    for (int i = 0; i < n; i++) {
        var_x += pow(x[i] - mean_x, 2);
        var_y += pow(y[i] - mean_y, 2);
        cov += (x[i] - mean_x) * (y[i] - mean_y);
    }

    double corr = cov / (var_x * var_y);
    double slope = corr * var_y / var_x;
    double intercept = mean_y - slope * mean_x;

    printf("Correlation coefficient: %.2f\n", corr);
    printf("Slope: %.2f\n", slope);
    printf("Intercept: %.2f\n", intercept);

    return 0;
}