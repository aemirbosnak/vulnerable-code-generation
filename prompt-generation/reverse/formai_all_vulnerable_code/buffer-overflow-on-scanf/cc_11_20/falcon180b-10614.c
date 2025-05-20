//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {0};
    int i, j, temp, key;
    char sort_type;

    // Populate array with random numbers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Ask user for sorting type
    printf("Enter sorting type (A for ascending, D for descending): ");
    scanf(" %c", &sort_type);

    // Perform the sort
    if (sort_type == 'A' || sort_type == 'a') {
        for (i = 0; i < SIZE - 1; i++) {
            for (j = 0; j < SIZE - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    } else if (sort_type == 'D' || sort_type == 'd') {
        for (i = 0; i < SIZE - 1; i++) {
            for (j = 0; j < SIZE - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    } else {
        printf("Invalid sorting type.\n");
        return 1;
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}