//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000 // Maximum size of the array
#define MIN_VALUE -1000 // Minimum value for the random numbers
#define MAX_VALUE 1000 // Maximum value for the random numbers

int main() {
    int size; // Size of the array
    int i; // Loop counter
    int *array; // Pointer to the array
    int sum = 0; // Sum of the elements in the array
    float average; // Average of the elements in the array
    int min = MAX_VALUE; // Minimum value in the array
    int max = MIN_VALUE; // Maximum value in the array

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Check if the size is within the allowed range
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    array = (int *)malloc(size * sizeof(int));

    // Check if the memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array with random numbers
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // Calculate the sum of the elements in the array
    for (i = 0; i < size; i++) {
        sum += array[i];
    }

    // Calculate the average of the elements in the array
    average = (float)sum / size;

    // Find the minimum and maximum values in the array
    for (i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Print the results
    printf("The sum of the elements in the array is: %d\n", sum);
    printf("The average of the elements in the array is: %.2f\n", average);
    printf("The minimum value in the array is: %d\n", min);
    printf("The maximum value in the array is: %d\n", max);

    // Free the memory allocated for the array
    free(array);

    return 0;
}