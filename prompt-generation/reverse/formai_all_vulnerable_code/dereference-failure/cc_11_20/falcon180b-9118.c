//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, n, max, min, range;
    int *arr;
    int *bucket;
    int freq[MAX_SIZE];
    int j;
    int sum = 0;
    int count = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error!");
        exit(0);
    }

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the range of the array: ");
    scanf("%d", &range);

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

    range = max - min + 1;

    bucket = (int *) malloc(range * sizeof(int));
    if (bucket == NULL) {
        printf("Memory error!");
        exit(0);
    }

    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        j = arr[i] - min;
        freq[j]++;
    }

    for (i = 0; i < range; i++) {
        freq[i] += freq[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = arr[i] - min;
        bucket[freq[j] - 1] = arr[i];
        freq[j]--;
        sum += arr[i];
        count++;

        if (count == n) {
            break;
        }
    }

    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    free(bucket);

    return 0;
}