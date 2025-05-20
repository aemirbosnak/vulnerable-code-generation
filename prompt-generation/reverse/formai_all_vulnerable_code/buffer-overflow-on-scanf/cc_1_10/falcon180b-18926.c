//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100000
#define BUCKET_SIZE 10

typedef struct {
    int data;
    int index;
} bucket_t;

void bucket_sort(int arr[], int size) {
    int i;
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucket_count = range / BUCKET_SIZE + 1;

    bucket_t *buckets = (bucket_t *) malloc(bucket_count * sizeof(bucket_t));

    for (i = 0; i < bucket_count; i++) {
        buckets[i].data = -1;
    }

    for (i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min) / BUCKET_SIZE;
        buckets[bucket_index].data = arr[i];
        buckets[bucket_index].index = i;
    }

    for (i = 0; i < bucket_count; i++) {
        if (buckets[i].data!= -1) {
            int j;
            for (j = buckets[i].index; j < size - 1 && arr[j] == buckets[i].data; j++) {
                arr[j] = arr[j + 1];
            }
            arr[j] = buckets[i].data;
        }
    }

    free(buckets);
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}