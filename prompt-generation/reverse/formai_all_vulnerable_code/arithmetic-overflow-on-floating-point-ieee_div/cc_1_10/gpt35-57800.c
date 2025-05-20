//FormAI DATASET v1.0 Category: Scientific ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate the standard deviation
float calculateStandardDeviation(float *data, int n) {
    float mean, variance = 0.0, stdDev;
    int i;

    // Calculate the mean
    for(i=0;i<n;i++){
        mean += *(data+i);
    }
    mean /= n;

    // Calculate the variance
    for(i=0;i<n;i++){
        variance += pow(*(data+i) - mean, 2);
    }
    variance /= n;

    // Calculate the standard deviation
    stdDev = sqrt(variance);

    return stdDev;
}

int main(){
    int i, n;
    float *data, stdDev;

    // Get the size of the array
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Allocate memory for the array
    data = (float *)malloc(n * sizeof(float));

    // Get the data points
    printf("Enter the data points: ");
    for(i=0;i<n;i++){
        scanf("%f", (data+i));
    }

    // Calculate the standard deviation
    stdDev = calculateStandardDeviation(data, n);
    printf("The standard deviation is: %0.2f\n", stdDev);

    // Free the memory
    free(data);

    return 0;
}