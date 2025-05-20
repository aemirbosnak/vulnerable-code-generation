//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int start;
    int end;
} Range;

void merge(int arr[], Range merge_range) {
    int i, j, k;
    int n1 = merge_range.end - merge_range.start + 1;
    int n2 = (merge_range.end + 1) % (2 * sizeof(int)) - (merge_range.start + 1);

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[merge_range.start + i];

    for (i = 0; i < n2; i++)
        R[i] = arr[merge_range.start + merge_range.end + 1 + i];

    i = 0;
    j = 0;
    k = merge_range.start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], Range sort_range) {
    if (sort_range.start >= sort_range.end)
        return;

    Range left = {sort_range.start, (sort_range.start + sort_range.end) / 2};
    Range right = {(sort_range.start + sort_range.end) / 2 + 1, sort_range.end};

    merge_sort(arr, left);
    merge_sort(arr, right);
    merge(arr, sort_range);
}

int main() {
    int arr_size;
    scanf("%d", &arr_size);

    int *arr = (int *)malloc(arr_size * sizeof(int));

    for (int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    merge_sort(arr, (Range){0, arr_size - 1});
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array in Ascending Order:\n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Time Taken by Merge Sort: %.16fs\n", time_taken);

    free(arr);
    return 0;
}