//FormAI DATASET v1.0 Category: Sorting ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Welcome to the random sorting program!\n");

    printf("Please enter the size of the array you would like to sort: ");
    int size;
    scanf("%d", &size);

    if (size < 1) {
        printf("Invalid array size. Program terminated. Thank you for using the random sorting program!\n");
        return 1;
    }

    printf("\nGenerating random array of size %d...\n\n", size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
    }

    printf("The original array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int swaps = 0;
    int comparisons = 0;
    int pass = 1;
    printf("\n\nStarting sort...\n");

    do {
        printf("\n\nPass %d:", pass);
        int temp;
        for (int i = 0; i < size - 1; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                swaps++;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            printf("\n\nComparing %d with %d...", arr[i], arr[i + 1]);
        }
        printf("\n\nEnd of Pass %d:\n", pass);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        pass++;
    } while (swaps != 0);

    printf("\n\nSorting complete!\n\nNumber of comparisons: %d\nNumber of swaps: %d", comparisons, swaps);
    printf("\n\nThe sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nThank you for using the random sorting program!\n");
    return 0;
}