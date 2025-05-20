//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean of an array
float calculateMean(int data[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return (float) sum / n;
}

// Function to calculate standard deviation of an array
float calculateStdDeviation(int data[], int n) {
    float mean = calculateMean(data, n);
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / n);
}

// Function to print the data array
void printData(int data[], int n) {
    printf("Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// Function to print the statistics of the data array
void printStats(int data[], int n) {
    printf("Statistics: \n");
    printf("Mean: %f\n", calculateMean(data, n));
    printf("Standard deviation: %f\n", calculateStdDeviation(data, n));
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    int *data = (int*) malloc(n * sizeof(int));

    printf("Enter the data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    printData(data, n);
    printStats(data, n);

    free(data);
    return 0;
}