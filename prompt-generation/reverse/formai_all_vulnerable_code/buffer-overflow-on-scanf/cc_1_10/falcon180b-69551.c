//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, max, min, range;
    int *arr;

    // get number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // allocate memory for array
    arr = (int *)malloc(n * sizeof(int));

    // get elements from user
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // find min and max values in array
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // calculate range of values in array
    range = max - min + 1;

    // create buckets and distribute elements into them
    int *buckets = (int *)malloc(range * sizeof(int));
    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < n; i++) {
        j = arr[i] - min;
        buckets[j]++;
    }

    // sort elements by concatenating buckets
    int k = 0;
    for (i = 0; i < range; i++) {
        while (buckets[i] > 0) {
            arr[k++] = min + i;
            buckets[i]--;
        }
    }

    // print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}