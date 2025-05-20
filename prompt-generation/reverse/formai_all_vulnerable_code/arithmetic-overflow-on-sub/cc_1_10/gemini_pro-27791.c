//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A tale of two arrays in the vast expanse of memory, locked in a dance of order and chaos.
 */

int main(void) {
    int n, i, j;
    int *a, *temp;

    // Read the size of the first array, the realm of chaos.
    printf("Enter the size of the first array: ");
    scanf("%d", &n);

    // Allocate memory for the first array, a haven for unsorted numbers.
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed! The dance cannot begin...\n");
        return 1;
    }

    // Read the unsorted numbers into the first array, like raindrops in a storm.
    printf("Enter the unsorted numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Now it's time to establish order, one swap at a time.
    for (i = 0; i < n - 1; i++) {
        // Find the smallest number in the unsorted part of the array.
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the smallest number with the current element.
        temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }

    // The storm has passed, and order reigns supreme.
    printf("The sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Free the memory allocated for the array, returning it to the vast expanse of memory.
    free(a);

    return 0;
}