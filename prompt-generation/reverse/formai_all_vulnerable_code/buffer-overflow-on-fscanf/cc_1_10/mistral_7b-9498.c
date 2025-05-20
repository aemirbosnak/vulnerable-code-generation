//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    double x;
    double y;
} DataPoint;

typedef struct {
    double sum_x;
    double sum_y;
    double sum_xx;
    double sum_xy;
} Sums;

void read_data(const char *filename, DataPoint *data, int *size) {
    FILE *file = fopen(filename, "r");
    fscanf(file, "%d", size);
    data = malloc(*size * sizeof(DataPoint));
    for (int i = 0; i < *size; ++i) {
        fscanf(file, "%lf %lf", &data[i].x, &data[i].y);
    }
    fclose(file);
}

void calculate_sums(const DataPoint *data, Sums *sums, int size) {
    sums->sum_x = 0.0;
    sums->sum_y = 0.0;
    sums->sum_xx = 0.0;
    sums->sum_xy = 0.0;
    for (int i = 0; i < size; ++i) {
        sums->sum_x += data[i].x;
        sums->sum_y += data[i].y;
        sums->sum_xx += data[i].x * data[i].x;
        sums->sum_xy += data[i].x * data[i].y;
    }
}

double linear_regression(const DataPoint *data, int size) {
    Sums sums;
    calculate_sums(data, &sums, size);
    double x_mean = sums.sum_x / size;
    double y_mean = sums.sum_y / size;
    double slope = (sums.sum_xy - size * x_mean * y_mean) / (sums.sum_xx - size * x_mean * x_mean);
    return slope;
}

int main() {
    const char *filename = "data.txt";
    int size;
    DataPoint *data;
    double slope;

    read_data(filename, data, &size);
    slope = linear_regression(data, size);
    printf("Slope: %.2f\n", slope);

    free(data);
    return 0;
}