//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 20
#define MIN_VALUE -100
#define MAX_VALUE 100

int GorillaSearch(int *arr, int size, int target);
void PrintErrorAndExit(const char *message);
void PrintArray(int *arr, int size);

int main() {
    int arr[ARRAY_SIZE];
    int i, target;

    srand(time(NULL));

    printf("Welcome to GorillaSearch, the strongest binary search algorithm!\n");
    printf("Preparing the bananas array...\n");

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        printf("Banana %d: %d\n", i + 1, arr[i]);
    }

    PrintArray(arr, ARRAY_SIZE);
    printf("\nEnter the target integer to find in the bananas array: ");
    scanf("%d", &target);

    if (GorillaSearch(arr, ARRAY_SIZE, target) == -1) {
        PrintErrorAndExit("Target not found in the bananas array!");
    }

    printf("\nTarget %d found at index %d!\n", target, GorillaSearch(arr, ARRAY_SIZE, target) + 1);

    return 0;
}

int GorillaSearch(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void PrintArray(int *arr, int size) {
    int i;

    printf("\nBanana array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void PrintErrorAndExit(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}