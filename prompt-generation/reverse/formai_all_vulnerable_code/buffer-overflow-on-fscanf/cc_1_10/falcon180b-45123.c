//Falcon-180B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 100

struct DataPoint {
    int x;
    int y;
};

struct DataPoint data[MAX_DATA_POINTS];
int numDataPoints;

void readData(FILE *fp) {
    int x, y;
    while (fscanf(fp, "%d %d", &x, &y) == 2) {
        data[numDataPoints].x = x;
        data[numDataPoints].y = y;
        numDataPoints++;
    }
}

void calculateMean(int *array, int size, double *mean) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    *mean = (double)sum / size;
}

void calculateVariance(int *array, int size, double *variance) {
    int mean = 0;
    calculateMean(array, size, &mean);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(array[i] - mean, 2);
    }
    *variance = (double)sum / size;
}

void calculateCorrelation(int *x, int *y, int size, double *correlation) {
    int meanX = 0, meanY = 0;
    calculateMean(x, size, &meanX);
    calculateMean(y, size, &meanY);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (x[i] - meanX) * (y[i] - meanY);
    }
    *correlation = (double)sum / (size - 1);
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    readData(fp);
    fclose(fp);

    double meanX, meanY, variance, correlation;
    calculateMean(data, numDataPoints, &meanX);
    calculateMean(data, numDataPoints, &meanY);
    calculateVariance(data, numDataPoints, &variance);
    calculateCorrelation(data, data, numDataPoints, &correlation);

    printf("Mean X: %lf\n", meanX);
    printf("Mean Y: %lf\n", meanY);
    printf("Variance: %lf\n", variance);
    printf("Correlation: %lf\n", correlation);

    return 0;
}