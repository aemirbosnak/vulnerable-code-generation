//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_SIZE 10
#define MAX_SIZE 10000

void shocking_search(int arr[], int size, int target);

int main() {
    int arr[MAX_SIZE], i, size, target;
    clock_t start, end;

    printf("***** SHOCKING SEARCH ALGORITHM *****\n");

    printf("Enter array size (min. %d, max. %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target element: ");
    scanf("%d", &target);

    printf("\n***** BEFORE THE SHOCK *****\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    shocking_search(arr, size, target);
    end = clock();

    printf("\n***** AFTER THE SHOCK *****\n");
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Target found at index %d\n", i);
            break;
        }
    }

    printf("Execution time: %f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void shocking_search(int arr[], int size, int target) {
    int i = 0, j = size - 1, mid;

    while (i <= j) {
        mid = (i + j) / 2;

        if (arr[mid] == target) {
            printf("\n***** THE SHOCK HITS! *****\n");
            printf("Element found at index %d\n", mid);
            exit(EXIT_SUCCESS);
        }

        if (arr[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }

        if (i > j) {
            printf("\n***** THE SHOCK FAILS! *****\n");
            printf("Element not found in array\n");
            exit(EXIT_FAILURE);
        }
    }
}