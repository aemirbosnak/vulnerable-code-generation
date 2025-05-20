//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    else
        return 0;
}

void swap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int *arr, int n) {
    int *bucket[MAX_SIZE];
    int i, j;
    for (i = 0; i < n; i++)
        bucket[arr[i]]++;
    for (i = 0; i < MAX_SIZE; i++)
        if (bucket[i]) {
            for (j = 0; j < bucket[i]; j++) {
                arr[j] = i;
                bucket[i]--;
            }
        }
}

void print_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i, n;
    int *arr;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    free(arr);
    return 0;
}