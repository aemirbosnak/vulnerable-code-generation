//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void bubble_sort(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }

    void bubble_sort_mind_bending(int arr[], int n) {
        int max_value = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max_value) {
                max_value = arr[i];
            }
        }

        for (int i = 0; i < max_value; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[j] > i) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }

    int main() {
        int arr[] = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10};
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("Unsorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        bubble_sort(arr, n);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        bubble_sort_mind_bending(arr, n);

        printf("Sorted array (mind-bending): ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        return 0;
    }