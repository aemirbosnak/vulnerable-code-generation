//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000000
#define MIN_SIZE 1

int main(int argc, char *argv[]) {
    int size = 0;
    int i, j;
    int *arr = NULL;
    int sum = 0;
    int count = 0;
    int num;
    double avg;
    double start_time, end_time;

    // Prompt user for array size
    printf("Enter array size: ");
    scanf("%d", &size);

    // Check if size is valid
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid array size. Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Allocate memory for array
    arr = (int *) malloc(size * sizeof(int));

    // Initialize array with random numbers
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort array in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                num = arr[i];
                arr[i] = arr[j];
                arr[j] = num;
            }
        }
    }

    // Calculate sum and average of array
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    avg = (double) sum / size;

    // Print sorted array and average
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nAverage: %.2f\n", avg);

    // Free memory for array
    free(arr);

    return 0;
}