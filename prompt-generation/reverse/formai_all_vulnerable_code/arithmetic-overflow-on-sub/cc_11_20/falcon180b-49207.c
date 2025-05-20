//Falcon-180B DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int i, j, temp, n;
    int choice;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("\nUnsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    while (1) {
        printf("\nEnter 1 to sort in ascending order\nEnter 2 to sort in descending order\nEnter 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice == 1) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        } else if (choice == 2) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }

        printf("\nSorted array:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    return 0;
}