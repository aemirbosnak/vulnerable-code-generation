//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_DATA_POINTS 1000000

typedef struct {
    double x;
    double y;
} DataPoint;

void calculate_mean(double* data, int num_data_points, double* mean) {
    int i;
    double sum = 0;

    for (i = 0; i < num_data_points; i++) {
        sum += data[i];
    }

    *mean = sum / num_data_points;
}

void calculate_standard_deviation(double* data, int num_data_points, double* std_dev) {
    int i;
    double mean, variance = 0;

    calculate_mean(data, num_data_points, &mean);

    for (i = 0; i < num_data_points; i++) {
        variance += pow(data[i] - mean, 2);
    }

    *std_dev = sqrt(variance / num_data_points);
}

int main() {
    int i;
    DataPoint data[MAX_NUM_DATA_POINTS];
    double mean, std_dev;

    printf("Enter data points (x, y):\n");

    for (i = 0; i < MAX_NUM_DATA_POINTS; i++) {
        scanf("%lf %lf", &data[i].x, &data[i].y);
    }

    calculate_mean(data, MAX_NUM_DATA_POINTS, &mean);
    calculate_standard_deviation(data, MAX_NUM_DATA_POINTS, &std_dev);

    printf("Mean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", std_dev);

    return 0;
}