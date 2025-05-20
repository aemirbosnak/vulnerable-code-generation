//Falcon-180B DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void paranoid_bubble_sort(int arr[], int n) {
    int i, j, swapped;
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Paranoid Bubble Sort completed in %lf seconds.\n", cpu_time_used);
}

int main() {
    int arr[MAX_SIZE];
    int n;

    srand(time(NULL));

    printf("Enter the number of elements to be sorted (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    printf("\n");
    paranoid_bubble_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}