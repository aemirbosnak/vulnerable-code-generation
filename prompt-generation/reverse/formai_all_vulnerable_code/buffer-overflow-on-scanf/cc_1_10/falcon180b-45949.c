//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

int main() {
    int size;
    int *array;
    double mean, median, mode;
    int frequency[MAX_SIZE] = {0};
    int i, j, k;
    int max_frequency = 0;
    int mode_index = -1;

    srand(time(NULL));

    // Get input size from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Initialize array with random integers
    array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // Sort the array in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Calculate mean
    mean = 0;
    for (i = 0; i < size; i++) {
        mean += array[i];
    }
    mean /= size;

    // Calculate median
    if (size % 2 == 0) {
        median = (array[size / 2] + array[size / 2 - 1]) / 2;
    } else {
        median = array[size / 2];
    }

    // Calculate mode
    for (i = 0; i < size; i++) {
        frequency[array[i]]++;
        if (frequency[array[i]] > max_frequency) {
            max_frequency = frequency[array[i]];
            mode_index = array[i];
        }
    }

    // Print results
    printf("The array is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("The mean is: %.2lf\n", mean);

    printf("The median is: %d\n", median);

    printf("The mode is: %d\n", mode_index);

    free(array);
    return 0;
}