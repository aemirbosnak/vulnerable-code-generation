//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_SIZE 100

int main(int argc, char *argv[]) {
    int size = 0;
    int *arr = NULL;
    int i = 0;
    int sum = 0;
    int count = 0;
    clock_t start = clock();
    clock_t end = clock();
    double cpu_time_used = 0.0;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the size is valid
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid size. Please enter a size between %d and %d.\n", MIN_SIZE, MAX_SIZE);
        return 1;
    }

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));

    // Initialize the array with random values
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate the sum of the array
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Calculate the average of the array
    double avg = (double)sum / size;

    // Print the results
    printf("The sum of the array is: %d\n", sum);
    printf("The average of the array is: %.2f\n", avg);

    // Free the memory allocated for the array
    free(arr);

    // Calculate the CPU time used by the program
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the CPU time used by the program
    printf("CPU time used by the program: %.2f seconds\n", cpu_time_used);

    return 0;
}