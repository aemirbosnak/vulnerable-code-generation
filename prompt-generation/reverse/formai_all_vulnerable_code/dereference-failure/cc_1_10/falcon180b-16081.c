//Falcon-180B DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum size of the array
#define MAX_VALUE 1000 // maximum value of each element

int main() {
    int size;
    int *array;
    int sum = 0;
    float average;
    int max = 0;
    int min = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // generate random array of integers
    array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }

    // find the sum, average, maximum, and minimum values
    for (int i = 0; i < size; i++) {
        sum += array[i];
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    average = (float)sum / size;

    // sort the array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // print the array and its statistics
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    // free the memory allocated for the array
    free(array);

    return 0;
}