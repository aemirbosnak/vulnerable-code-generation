//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000

// Function prototypes
void inputNumbers(int *data, int *num);
float calculateMean(int *data, int num);
float calculateMedian(int *data, int num);
int calculateMode(int *data, int num);
float calculateVariance(int *data, int num, float mean);
float calculateStandardDeviation(float variance);
void sort(int *data, int num);

int main() {
    int data[MAX_NUMBERS];
    int num = 0;
    char choice;

    do {
        inputNumbers(data, &num);
        
        float mean = calculateMean(data, num);
        float median = calculateMedian(data, num);
        int mode = calculateMode(data, num);
        float variance = calculateVariance(data, num, mean);
        float stddev = calculateStandardDeviation(variance);

        printf("\nStatistical Analysis of the Input Data:\n");
        printf("Mean: %.2f\n", mean);
        printf("Median: %.2f\n", median);
        printf("Mode: %d\n", mode);
        printf("Variance: %.2f\n", variance);
        printf("Standard Deviation: %.2f\n", stddev);

        printf("\nDo you want to analyze another set of numbers? (y/n): ");
        getchar();  // To consume leftover newline
        choice = getchar();
    } while (choice == 'y');

    return 0;
}

// Function to input numbers
void inputNumbers(int *data, int *num) {
    printf("Enter the number of data points (max %d): ", MAX_NUMBERS);
    scanf("%d", num);

    if (*num > MAX_NUMBERS) {
        printf("Exceeds maximum number of allowed inputs. Setting to %d.\n", MAX_NUMBERS);
        *num = MAX_NUMBERS;
    }

    printf("Enter %d data points:\n", *num);
    for (int i = 0; i < *num; i++) {
        scanf("%d", &data[i]);
    }
}

// Function to calculate mean
float calculateMean(int *data, int num) {
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += data[i];
    }
    return (float)sum / num;
}

// Function to calculate median
float calculateMedian(int *data, int num) {
    sort(data, num);
    if (num % 2 == 0) {
        return (data[num / 2 - 1] + data[num / 2]) / 2.0;
    } else {
        return data[num / 2];
    }
}

// Function to calculate mode
int calculateMode(int *data, int num) {
    int maxValue = data[0], maxCount = 0, i, j;

    for (i = 0; i < num; ++i) {
        int count = 0;
        for (j = 0; j < num; ++j) {
            if (data[j] == data[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            maxValue = data[i];
        }
    }

    return maxValue;
}

// Function to calculate variance
float calculateVariance(int *data, int num, float mean) {
    float variance = 0.0;
    for (int i = 0; i < num; i++) {
        variance += (data[i] - mean) * (data[i] - mean);
    }
    return variance / num;
}

// Function to calculate standard deviation
float calculateStandardDeviation(float variance) {
    return sqrt(variance);
}

// Function to sort an array
void sort(int *data, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}