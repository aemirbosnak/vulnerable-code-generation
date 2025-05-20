//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NUMBERS 100

void calculate_statistics(double numbers[], int count, double *mean, double *median, double *mode, double *stddev) {
    double sum = 0.0;
    double sum_squared = 0.0;
    int frequency[MAX_NUMBERS] = {0};
    int max_freq = 0;

    // Calculate mean and frequency for mode
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        sum_squared += numbers[i] * numbers[i];
        frequency[(int)numbers[i]]++;
        if (frequency[(int)numbers[i]] > max_freq) {
            max_freq = frequency[(int)numbers[i]];
            *mode = numbers[i];
        }
    }
    
    *mean = sum / (double)count;
    *stddev = sqrt((sum_squared / (double)count) - (*mean * *mean));

    // Calculate median
    double temp[MAX_NUMBERS];
    memcpy(temp, numbers, sizeof(double) * count);
    // Simple bubble sort for median calculation
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                double t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    if (count % 2 == 0) {
        *median = (temp[count / 2 - 1] + temp[count / 2]) / 2.0;
    } else {
        *median = temp[count / 2];
    }
}

int main() {
    double numbers[MAX_NUMBERS];
    int count = 0;
    double mean = 0.0, median = 0.0, mode = 0.0, stddev = 0.0;

    printf("Welcome to the Statistical Analysis Tool!\n");
    printf("Enter up to %d numbers (enter -1 to finish):\n", MAX_NUMBERS);

    while (count < MAX_NUMBERS) {
        double num;
        scanf("%lf", &num);
        if (num == -1) {
            break;
        }
        numbers[count] = num;
        count++;
    }

    if (count > 0) {
        calculate_statistics(numbers, count, &mean, &median, &mode, &stddev);
        printf("\nStatistics:\n");
        printf("Mean: %.2lf\n", mean);
        printf("Median: %.2lf\n", median);
        printf("Mode: %.2lf\n", mode);
        printf("Standard Deviation: %.2lf\n", stddev);
    } else {
        printf("No valid numbers entered.\n");
    }

    return 0;
}