//Falcon-180B DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // Maximum size of the array
#define MAX_VALUE 100 // Maximum value of the array elements

int main() {
    int size, i, j, sum = 0;
    float avg;
    int arr[MAX_SIZE];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate a random array of integers
    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // Print the original array
    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate the sum and average of the array elements
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    avg = (float) sum / size;

    // Print the sum and average of the array elements
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}