//Falcon-180B DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;
    int i, j, temp;

    srand(time(NULL));

    do {
        printf("Enter the size of the array (max %d): ", MAX_SIZE);
        scanf("%d", &size);
    } while (size <= 0 || size > MAX_SIZE);

    printf("Enter 1 to generate a random array or 2 to enter elements manually:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        for (i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
    } else {
        printf("Enter the elements of the array:\n");
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}