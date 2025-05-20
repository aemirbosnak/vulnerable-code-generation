//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 100

int compare_int(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int n) {
    int i, j;
    int* bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        int min_index = arr[i] * MAX_SIZE / MAX_VALUE;
        if (bucket[min_index] == NULL) {
            bucket[min_index] = malloc(sizeof(int));
        }
        int* temp = bucket[min_index];
        while (*temp!= 0) {
            temp = temp + 1;
        }
        *temp = arr[i];
    }
    int index = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < n; j++) {
                if (arr[j] == i * MAX_VALUE / MAX_SIZE) {
                    arr[index++] = arr[j];
                    break;
                }
            }
        }
    }
}

int main() {
    int i, n;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}