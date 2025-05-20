//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_RANGE 1000000

int main() {
    int i, n, range, *arr;
    float *buckets;
    FILE *fp;
    char filename[20];
    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the range of elements: ");
    scanf("%d", &range);

    arr = (int*) malloc(n * sizeof(int));
    buckets = (float*) malloc(range * sizeof(float));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }

    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++) {
        buckets[(arr[i] / range) * range]++;
    }

    for (i = 1; i < range; i++) {
        buckets[i] += buckets[i - 1];
    }

    printf("\nBucket sizes:\n");
    for (i = 0; i < range; i++) {
        printf("%d ", buckets[i]);
    }

    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] / range) * range;
        while (buckets[bucket_index] == 0) {
            bucket_index += range;
        }
        buckets[bucket_index]--;
        int j = (int) (bucket_index / range) * range;
        while (j < bucket_index) {
            arr[j] = arr[j + 1];
            j++;
        }
        arr[j] = arr[i];
    }

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    sprintf(filename, "sorted_array.txt");
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    return 0;
}