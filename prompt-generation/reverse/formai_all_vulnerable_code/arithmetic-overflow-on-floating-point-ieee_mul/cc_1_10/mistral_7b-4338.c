//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DATA_POINTS 100
#define MAX_COLUMNS 2

typedef struct {
    float x;
    float y;
} DataPoint;

typedef struct {
    float x_sum;
    float y_sum;
    float x_sq_sum;
} Sums;

void linear_regression(DataPoint data_points[], float *slope, float *intercept) {
    Sums sums;
    int num_points = 0;

    // Initialize sums to zero
    sums.x_sum = 0.0;
    sums.y_sum = 0.0;
    sums.x_sq_sum = 0.0;

    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        if (data_points[i].x != 0) {
            num_points++;

            sums.x_sum += data_points[i].x;
            sums.y_sum += data_points[i].y;
            sums.x_sq_sum += pow(data_points[i].x, 2);
        }
    }

    *slope = (sums.y_sum / num_points) - (sums.x_sum * (sums.y_sum / num_points) / num_points);
    *intercept = (sums.y_sum / num_points) - (*slope * sums.x_sum / num_points);
}

int main() {
    DataPoint data_points[MAX_DATA_POINTS];
    float slope, intercept;

    // Input data points
    for (int i = 0; i < MAX_DATA_POINTS / 2; i++) {
        data_points[i].x = i + 1;
        data_points[i].y = pow(i + 1, 2);
    }

    for (int i = MAX_DATA_POINTS / 2; i < MAX_DATA_POINTS; i++) {
        data_points[i].x = i + 1;
        data_points[i].y = sqrt(pow(i + 1, 2) + 1);
    }

    linear_regression(data_points, &slope, &intercept);

    // Output results
    printf("Slope: %.2f\n", slope);
    printf("Intercept: %.2f\n", intercept);

    return 0;
}