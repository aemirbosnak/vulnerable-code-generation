//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    int index;
} Bucket;

void swap(Bucket *a, Bucket *b) {
    Bucket temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(Bucket *arr, int n) {
    Bucket *bucket[MAX_SIZE];
    int i, j, k;
    for (i = 0; i < n; i++) {
        arr[i].index = (int)arr[i].data * MAX_SIZE / (n - 1);
        for (j = 0; j < MAX_SIZE; j++) {
            if (bucket[j] == NULL) {
                bucket[j] = &arr[i];
                break;
            }
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = i; j < MAX_SIZE; j++) {
                if (bucket[j]!= NULL) {
                    if (bucket[j]->data < bucket[i]->data) {
                        swap(bucket[j], bucket[i]);
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (bucket[j]!= NULL && bucket[j]->index == i) {
                arr[i] = *bucket[j];
                bucket[j] = NULL;
                break;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    Bucket *arr = (Bucket *)malloc(n * sizeof(Bucket));
    printf("Enter the elements to sort:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
    }
    srand(time(NULL));
    bucketSort(arr, n);
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
    free(arr);
    return 0;
}