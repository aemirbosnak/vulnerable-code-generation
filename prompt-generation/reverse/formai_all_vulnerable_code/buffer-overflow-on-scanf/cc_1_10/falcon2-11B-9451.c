//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int max_val(int* arr, int n) {
    int max_so_far = 0;
    int max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here = arr[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }

    return max_so_far;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max_element = max_val(arr, n);
    printf("The maximum element in the array is: %d\n", max_element);

    free(arr);
    return 0;
}