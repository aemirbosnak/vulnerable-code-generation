//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of integers to be allocated dynamically: ");
    scanf("%d", &n);

    int *arr;
    arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!");
    } else {
        printf("Memory allocation succesful!\n");

        // Assign values to the array
        for (int i = 0; i < n; i++) {
            printf("Enter integer value to be stored in index %d: ", i);
            scanf("%d", &arr[i]);
        }

        // Display the values in the array
        printf("\nValues stored in the array are: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        // Reallocated memory if needed
        printf("\nEnter the new size of the array: ");
        scanf("%d", &n);
        arr = realloc(arr, n * sizeof(int));
        if (arr == NULL) {
            printf("Memory reallocation failed!");
        } else {
            printf("Memory reallocated succesfully!\n");

            // Assign values to the array
            for (int i = 0; i < n; i++) {
                printf("Enter integer value to be stored in index %d: ", i);
                scanf("%d", &arr[i]);
            }

            // Display the values in the array
            printf("\nValues stored in the array are: \n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
        }

        // Free the allocated memory
        free(arr);
        printf("\nMemory freed succesfully!");
    }

    return 0;
}