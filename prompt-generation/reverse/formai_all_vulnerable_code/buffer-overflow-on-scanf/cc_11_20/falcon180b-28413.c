//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n;
    int i, j, k;
    int max = 0;
    int min = 1000000;
    int *buckets[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        buckets[i] = (int *) malloc(sizeof(int));
    }

    printf("Bucket sort:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                k = 0;
                break;
            }
        }
        if (j == n) {
            k = n;
        }
        buckets[k] = (int *) realloc(buckets[k], sizeof(int) * (k + 1));
        buckets[k][k] = arr[i];
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                k = 0;
                break;
            }
        }
        if (j == n) {
            k = n;
        }
        printf("%d ", buckets[k][k]);
    }

    for (i = 0; i < n; i++) {
        free(buckets[i]);
    }

    return 0;
}