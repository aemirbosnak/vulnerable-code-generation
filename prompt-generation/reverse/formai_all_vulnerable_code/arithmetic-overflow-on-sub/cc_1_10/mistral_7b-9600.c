//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int getLastIndex(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > arr[i - 1]) {
            return i;
        }
    }
    return -1;
}

void intelligentBubbleSort(int arr[], int n) {
    int lastIndex = 0;
    while (lastIndex != -1) {
        lastIndex = getLastIndex(arr, n);
        if (lastIndex != -1) {
            for (int i = 0; i < lastIndex; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(&arr[i], &arr[i + 1]);
                }
            }
            n = lastIndex;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    intelligentBubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}