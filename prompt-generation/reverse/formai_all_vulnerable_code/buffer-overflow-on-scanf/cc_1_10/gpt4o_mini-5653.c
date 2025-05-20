//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void calculateMean(int arr[], int n);
void calculateMedian(int arr[], int n);
void calculateMode(int arr[], int n);

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int numbers[MAX_SIZE];
    int n = 0;

    printf("Welcome to the C Math Exercise Program!\n");
    printf("You can enter up to %d integers. Enter -1 to finish input.\n", MAX_SIZE);

    while (n < MAX_SIZE) {
        int input;
        printf("Enter an integer (%d/%d): ", n + 1, MAX_SIZE);
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        numbers[n++] = input;
    }

    if (n == 0) {
        printf("No data entered. Exiting the program.\n");
        return 1;
    }

    printf("\nYou entered %d numbers.\n", n);
    
    calculateMean(numbers, n);
    calculateMedian(numbers, n);
    calculateMode(numbers, n);

    return 0;
}

void calculateMean(int arr[], int n) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    double mean = sum / n;
    printf("Mean: %.2f\n", mean);
}

void calculateMedian(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    double median;
    if (n % 2 == 0) {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        median = arr[n / 2];
    }

    printf("Median: %.2f\n", median);
}

void calculateMode(int arr[], int n) {
    int maxValue = 0, maxCount = 0;
    int *count = (int*)calloc(MAX_SIZE, sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
            maxValue = arr[i];
        }
    }

    printf("Mode: ");
    int modeFound = 0;    
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] == maxCount && maxCount > 0) {
            printf("%d ", i);
            modeFound = 1;
        }
    }
    if (!modeFound) {
        printf("No mode found.");
    }
    printf("\n");

    free(count);
}