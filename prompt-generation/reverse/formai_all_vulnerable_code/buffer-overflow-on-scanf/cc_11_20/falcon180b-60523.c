//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int i, j, k;
    char choice;

    // Initialize array with random numbers
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Display initial array
    printf("The initial array is:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ask user for operation
    printf("Enter the operation you want to perform (s for sort, r for reverse): ");
    scanf("%c", &choice);

    // Perform chosen operation
    switch (choice) {
        case's':
            // Sort array in ascending order
            for (i = 0; i < SIZE - 1; i++) {
                for (j = i + 1; j < SIZE; j++) {
                    if (arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("The sorted array is:\n");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 'r':
            // Reverse array
            for (i = 0; i < SIZE / 2; i++) {
                int temp = arr[i];
                arr[i] = arr[SIZE - i - 1];
                arr[SIZE - i - 1] = temp;
            }
            printf("The reversed array is:\n");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid operation. Please try again.\n");
    }

    return 0;
}