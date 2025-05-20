//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {
    int i, j, count[BUCKET_SIZE] = {0};
    int *bucket[BUCKET_SIZE];

    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        count[(arr[i] / BUCKET_SIZE) * BUCKET_SIZE]++;
    }

    for (i = 1; i < BUCKET_SIZE; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] / BUCKET_SIZE) * BUCKET_SIZE;
        bucket[j][count[j] - 1] = arr[i];
        count[j]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[i][i];
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}