//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucketSort(int arr[], int n)
{
    int i, j;
    int *bucket[n];
    int min = arr[0], max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int range = max - min + 1;
    for (i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(range * sizeof(int));
        for (j = 0; j < range; j++)
            bucket[i][j] = 0;
    }

    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / (max - min) * range;
        bucket[index][arr[i] - min]++;
    }

    for (i = 0; i < n; i++) {
        int k = 0;
        for (j = 0; j < range; j++) {
            while (bucket[i][j]-- > 0) {
                arr[k++] = min + j;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    start = clock();
    bucketSort(arr, n);
    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %lf seconds\n", time_taken);

    return 0;
}