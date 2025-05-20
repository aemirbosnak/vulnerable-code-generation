//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of integers you want to allocate: ");
    scanf("%d", &n);

    // Allocating memory dynamically
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory Allocation failed!\n");
        return -1; // Exit program with error code
    }

    // Taking input from user
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying the input integers
    printf("Input integers are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the input integers using bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Displaying the sorted integers
    printf("Sorted integers are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Freeing the dynamically allocated memory
    free(arr);

    return 0; // Exit program with success code
}