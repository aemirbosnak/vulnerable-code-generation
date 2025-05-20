//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Declare our trusty sorting function
void bubbleSort(int *arr, int n) {
    // Let's get this party started!
    for (int i = 0; i < n; i++) {
        // Time to shake things up!
        for (int j = 0; j < n - i - 1; j++) {
            // Oh no, it's a bubble!
            if (arr[j] > arr[j + 1]) {
                // Let's pop that bubble right away!
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    // Get ready for some sorting action!
    int n;
    printf("Give us a number, and we'll sort a list for ya!\n");
    scanf("%d", &n);

    // Time to create our list of numbers
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Now, give us those numbers, separated by spaces.\n");

    // Get the numbers from the user
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort, here we come!
    bubbleSort(arr, n);

    // Ta-da! Here's your sorted list:
    printf("And the sorted list is:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");

    // Don't forget to clean up!
    free(arr);
    return 0;
}