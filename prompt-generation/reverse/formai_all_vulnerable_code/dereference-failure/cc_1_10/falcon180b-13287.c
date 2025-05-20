//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max_val, min_val, range, *count;
    clock_t start, end;

    max_val = arr[0];
    min_val = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }

    range = max_val - min_val + 1;
    count = (int *) malloc(range * sizeof(int));
    for (i = 0; i < range; i++)
        count[i] = 0;

    for (i = 0; i < n; i++) {
        count[(arr[i] - min_val) / (RANGE / range)]++;
    }

    for (i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] - min_val) / (RANGE / range);
        count[j]--;
        arr[count[j]] = arr[i];
    }

    free(count);
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Before sorting:\n");
    print_array(arr, n);

    bucket_sort(arr, n);

    printf("After sorting:\n");
    print_array(arr, n);

    free(arr);
    return 0;
}