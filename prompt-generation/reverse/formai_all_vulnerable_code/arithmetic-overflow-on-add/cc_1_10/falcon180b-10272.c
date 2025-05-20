//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucket_sort(int arr[], int n) {
    int i, j, min, max;
    int bucket[MAX_SIZE];

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    max = max + 1; // add one to the maximum value to include all elements

    for (i = 0; i < max; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[arr[i]]; j++) {
            arr[i] = arr[i] + 1;
        }
    }
}

int main() {
    int n, i;
    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // generate random numbers between 1 and 100
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}