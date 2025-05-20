//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *ptr, *sum, i, j, k;
    
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Allocate dynamic memory for the array of integers
    ptr = (int*) malloc(n * sizeof(int));

    // Allocate dynamic memory for the running sum array
    sum = (int*) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if(ptr == NULL || sum == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    // Initialize the array of integers with random values
    for(i = 0; i < n; i++) {
        ptr[i] = rand() % 100; // Generate random numbers between 0-99
    }

    // Initialize the running sum array with the first value of the array of integers
    sum[0] = ptr[0];

    // Calculate the running sum of the array of integers
    for(j = 1; j < n; j++) {
        sum[j] = sum[j-1] + ptr[j];
    }

    // Print the array of integers and their running sum
    printf("The array of integers: \n");
    for(k = 0; k < n; k++) {
        printf("%d ", ptr[k]);
    }
    printf("\n\nThe running sum of the array of integers: \n");
    for(k = 0; k < n; k++) {
        printf("%d ", sum[k]);
    }

    // Deallocate the dynamic memory
    free(ptr);
    free(sum);

    return 0;
}