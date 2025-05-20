//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100

void calculate_statistics(int numbers[], int count, double *mean, double *median, double *variance, double *stddev, int *mode, int *mode_count) {
    int i, j, sum = 0, frequency[MAX_NUMBERS] = {0};
    
    // Calculate Mean
    for (i = 0; i < count; i++) {
        sum += numbers[i];
    }
    *mean = (double) sum / count;

    // Sort numbers for Median and Mode calculations
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Calculate Median
    if (count % 2 == 0) {
        *median = (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    } else {
        *median = numbers[count / 2];
    }

    // Calculate Mode
    for (i = 0; i < count; i++) {
        frequency[numbers[i]]++;
    }
    *mode_count = 0;
    *mode = numbers[0];
    for (i = 0; i < count; i++) {
        if (frequency[numbers[i]] > *mode_count) {
            *mode_count = frequency[numbers[i]];
            *mode = numbers[i];
        }
    }

    // Calculate Variance and Standard Deviation
    double sum_squared_diff = 0.0;
    for (i = 0; i < count; i++) {
        sum_squared_diff += (numbers[i] - *mean) * (numbers[i] - *mean);
    }
    *variance = sum_squared_diff / count;
    *stddev = sqrt(*variance);
}

int main() {
    int numbers[MAX_NUMBERS], count = 0;
    double mean, median, variance, stddev;
    int mode, mode_count;

    printf("Enter numbers (terminate with -1): \n");
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        if (count < MAX_NUMBERS) {
            numbers[count++] = num;
        } else {
            printf("Exceeded maximum limit of %d numbers.\n", MAX_NUMBERS);
            break;
        }
    }

    if (count == 0) {
        printf("No numbers were entered.\n");
        return 1;
    }

    calculate_statistics(numbers, count, &mean, &median, &variance, &stddev, &mode, &mode_count);

    printf("\nStatistics:\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d (occurs %d times)\n", mode, mode_count);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);

    return 0;
}