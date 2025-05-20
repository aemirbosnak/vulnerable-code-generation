//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 100

struct DataPoint {
    int x;
    int y;
};

void calculateMean(struct DataPoint *dataPoints, int numDataPoints, double *meanX, double *meanY) {
    int i;
    int sumX = 0;
    int sumY = 0;

    for (i = 0; i < numDataPoints; i++) {
        sumX += dataPoints[i].x;
        sumY += dataPoints[i].y;
    }

    *meanX = (double)sumX / numDataPoints;
    *meanY = (double)sumY / numDataPoints;
}

void calculateSlope(struct DataPoint *dataPoints, int numDataPoints, double *slope) {
    int i;
    double sumXY = 0;
    double sumX = 0;
    double sumY = 0;

    for (i = 0; i < numDataPoints; i++) {
        sumXY += dataPoints[i].x * dataPoints[i].y;
        sumX += dataPoints[i].x;
        sumY += dataPoints[i].y;
    }

    *slope = (double)sumXY - (double)(numDataPoints * sumX * sumY / (sumX * sumX));
}

int main() {
    int numDataPoints = 0;
    struct DataPoint dataPoints[MAX_DATA_POINTS];
    int choice;
    double meanX, meanY, slope;

    do {
        printf("Enter the number of data points (1-100): ");
        scanf("%d", &numDataPoints);

        if (numDataPoints < 1 || numDataPoints > MAX_DATA_POINTS) {
            printf("Invalid number of data points.\n");
        }
    } while (numDataPoints < 1 || numDataPoints > MAX_DATA_POINTS);

    printf("Enter the x and y coordinates of each data point:\n");

    for (int i = 0; i < numDataPoints; i++) {
        printf("Data point %d: ", i + 1);
        scanf("%d %d", &dataPoints[i].x, &dataPoints[i].y);
    }

    calculateMean(dataPoints, numDataPoints, &meanX, &meanY);
    calculateSlope(dataPoints, numDataPoints, &slope);

    printf("Mean x: %.2f\n", meanX);
    printf("Mean y: %.2f\n", meanY);
    printf("Slope: %.2f\n", slope);

    return 0;
}