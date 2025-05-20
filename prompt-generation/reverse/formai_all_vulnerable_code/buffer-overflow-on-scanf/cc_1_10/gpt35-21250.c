//FormAI DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Medieval sorting function
void medieval_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Medieval Sorting Program\n-------------------------\n");

    int n, i;
    printf("Enter the number of integers to sort: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n < 1) {
        printf("Invalid number of integers.\n");
        exit(1);
    }

    // Generate random array of integers
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 101; // Random number between 0 and 100
    }

    // Print unsorted array
    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using medieval sorting function
    medieval_sort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}