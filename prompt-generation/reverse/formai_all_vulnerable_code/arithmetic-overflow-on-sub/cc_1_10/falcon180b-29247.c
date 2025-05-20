//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    float sum = 0;
    float avg;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Fill the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate the sum of the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Calculate the average of the array
    avg = sum / n;

    printf("The average of the array is: %.2f\n", avg);

    start = clock();

    // Sort the array using quicksort
    for (int i = 0; i < n; i++) {
        int pivot = arr[i];
        int j = i - 1;
        for (int k = i + 1; k < n; k++) {
            if (arr[k] < pivot) {
                j++;
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
        int temp = arr[j + 1];
        arr[j + 1] = arr[i];
        arr[i] = temp;
    }

    end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The array is sorted in ascending order.\n");
    printf("Time taken to sort the array: %.6f seconds\n", time_taken);

    return 0;
}