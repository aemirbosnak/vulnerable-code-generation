//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the sum of all elements in an array
long long int sum_array(int arr[], int size) {
    long long int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int size;
    int *arr;
    double elapsed_time;

    // Get the array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Fill the array with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate the sum of all elements in the array
    clock_t start_time = clock();
    long long int sum = sum_array(arr, size);
    clock_t end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the sum and the elapsed time
    printf("The sum of all elements in the array is: %lld\n", sum);
    printf("The elapsed time is: %lf seconds\n", elapsed_time);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}