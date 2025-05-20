//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Function to find the minimum element in an array
int min_element(int arr[], int size) {
    int min = arr[0];
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

// Function to perform bubble sort
void bubble_sort(int arr[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX], i, n, sum, diff, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    min = arr[0];

    printf("\nSorted array: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nSum of first %d and last %d elements: %d", n / 2, n / 2, (sum = arr[0] + arr[n - 1]));

    for (i = 1; i < n / 2; i++) {
        diff = arr[i] - arr[i - 1];
        sum += diff;
    }

    printf("\nDifference between consecutive elements of the sorted array: %d", sum);

    return 0;
}