//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n;
    double x, y, z;
    double *array;

    // Allocate memory for the array
    array = (double *) malloc(MAX_SIZE * sizeof(double));
    if (array == NULL) {
        printf("Error: Failed to allocate memory!\n");
        exit(1);
    }

    // Prompt the user for the size of the array
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Populate the array with random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    // Sort the array in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                x = array[i];
                array[i] = array[j];
                array[j] = x;
            }
        }
    }

    // Calculate the mean, median, and mode of the array
    x = 0.0;
    y = 0.0;
    z = 0.0;
    for (i = 0; i < n; i++) {
        x += array[i];
        y += array[i] * array[i];
    }
    x /= n;
    y /= n;
    y = sqrt(y - x * x);
    z = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] == z) {
            z++;
        } else if (array[i] < z) {
            z = array[i];
        }
    }

    // Print the results
    printf("Mean: %.2f\n", x);
    printf("Median: %.2f\n", y);
    printf("Mode: %d\n", z);

    // Free the memory allocated for the array
    free(array);

    return 0;
}