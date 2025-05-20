//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 50

typedef struct {
    int value;
    int count;
} element;

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Update the 'count' of elements with the same value
                for (int k = i + 1; k <= j; k++) {
                    if (arr[k] == arr[j]) {
                        ((element *)arr)[k].count++;
                    }
                }
            }
        }
    }
}

void print_array_and_mode(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }

    printf("\nMode: ");
    int max_count = 0;
    int mode = 0;

    for (int i = 0; i < size; i++) {
        if ( ((element *)arr)[i].count > max_count) {
            max_count = ((element *)arr)[i].count;
            mode = ((element *)arr)[i].value;
        }
    }

    printf("%d\n", mode);
}

int main() {
    int arr[ARRAY_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);
    print_array_and_mode(arr, n);

    return 0;
}