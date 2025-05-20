//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    int arr[SIZE];
    clock_t start, end;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    bubble_sort(arr, n);
    end = clock();

    printf("Sorted array:\n");
    print_array(arr, n);

    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}