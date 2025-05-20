//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int i, n, max, min;
    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));

    printf("Buckets:\n");
    for (i = 0; i < range; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / (max - min + 1) * range;
        bucket[index]++;
    }

    printf("Bucket counts:\n");
    for (i = 0; i < range; i++) {
        printf("%d ", bucket[i]);
    }
    printf("\n");

    int sorted_arr[n];
    int j = 0;
    for (i = 0; i < range; i++) {
        for (int k = 0; k < bucket[i]; k++) {
            sorted_arr[j++] = i * (max - min + 1) + min + k;
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    return 0;
}