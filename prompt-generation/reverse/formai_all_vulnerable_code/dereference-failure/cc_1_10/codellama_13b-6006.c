//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        int value;
        int index;
    } bucket_t;

    int compare(const void *a, const void *b) {
        bucket_t *b1 = (bucket_t *)a;
        bucket_t *b2 = (bucket_t *)b;
        return b1->value - b2->value;
    }

    void bucket_sort(int *arr, int size) {
        int i, j;
        int bucket_count = 10;
        bucket_t *buckets[bucket_count];

        for (i = 0; i < size; i++) {
            int index = arr[i] * (bucket_count - 1) / arr[size - 1];
            buckets[index] = malloc(sizeof(bucket_t));
            buckets[index]->value = arr[i];
            buckets[index]->index = i;
        }

        for (i = 0; i < bucket_count; i++) {
            if (buckets[i] != NULL) {
                qsort(buckets[i], 1, sizeof(bucket_t), compare);
            }
        }

        for (i = 0, j = 0; i < bucket_count; i++) {
            if (buckets[i] != NULL) {
                arr[j++] = buckets[i]->value;
                free(buckets[i]);
            }
        }
    }

    int main() {
        int arr[] = {4, 2, 1, 3, 5};
        int size = sizeof(arr) / sizeof(arr[0]);
        bucket_sort(arr, size);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
    }