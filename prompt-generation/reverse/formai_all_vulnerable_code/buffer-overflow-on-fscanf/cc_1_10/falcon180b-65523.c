//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 1000000
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} DataPoint;

int main() {
    int i, j;
    DataPoint dataPoints[MAX_DATA_POINTS];
    double sumX = 0.0, sumY = 0.0;
    double meanX, meanY, covariance;
    int numDataPoints = 0;

    // Read data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file data.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%lf %lf", &dataPoints[numDataPoints].x, &dataPoints[numDataPoints].y) == 2) {
        numDataPoints++;
    }

    fclose(fp);

    // Calculate mean
    for (i = 0; i < numDataPoints; i++) {
        sumX += dataPoints[i].x;
        sumY += dataPoints[i].y;
    }

    meanX = sumX / numDataPoints;
    meanY = sumY / numDataPoints;

    // Calculate covariance
    for (i = 0; i < numDataPoints; i++) {
        sumX += (dataPoints[i].x - meanX) * (dataPoints[i].y - meanY);
    }

    covariance = sumX / (numDataPoints - 1);

    // Calculate correlation coefficient
    double correlation = covariance / (sqrt(covariance) * sqrt(covariance));

    // Print results
    printf("Number of data points: %d\n", numDataPoints);
    printf("Mean X: %.4lf\n", meanX);
    printf("Mean Y: %.4lf\n", meanY);
    printf("Covariance: %.4lf\n", covariance);
    printf("Correlation coefficient: %.4lf\n", correlation);

    return 0;
}