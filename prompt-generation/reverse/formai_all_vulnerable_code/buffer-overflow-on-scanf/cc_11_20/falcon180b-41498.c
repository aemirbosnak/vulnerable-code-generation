//Falcon-180B DATASET v1.0 Category: Educational ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], n, i, j, temp;
    char choice;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1; // generate random array size between 1 and 100

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; // generate random elements between 0 and 99
    }

    do {
        printf("\nEnter your choice:\n");
        printf("1. Sort array in ascending order\n");
        printf("2. Sort array in descending order\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("\nSorted array in ascending order:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                break;

            case '2':
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("\nSorted array in descending order:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                break;

            case '3':
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please enter again.\n");
        }
    } while (choice!= '3');

    return 0;
}