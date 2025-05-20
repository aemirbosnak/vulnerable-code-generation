//FormAI DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_numbers(int arr[], int n) {
    srand(time(0)); // set the seed for random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // generate a random number between 0 and 100
    }
}

float calculate_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float) sum / n;
}

float calculate_standard_deviation(int arr[], int n, float mean) {
    float sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += (arr[i] - mean) * (arr[i] - mean);
    }
    float variance = sum_of_squares / n;
    return sqrt(variance);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generate_numbers(arr, n);

    printf("Generated numbers: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    float mean = calculate_mean(arr, n);
    printf("Mean: %.2f\n", mean);

    float standard_deviation = calculate_standard_deviation(arr, n, mean);
    printf("Standard deviation: %.2f\n", standard_deviation);

    return 0;
}