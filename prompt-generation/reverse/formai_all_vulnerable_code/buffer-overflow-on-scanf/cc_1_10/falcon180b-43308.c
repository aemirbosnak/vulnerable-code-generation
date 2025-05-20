//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int data;
    int index;
} Bucket;

int compare(const void *a, const void *b) {
    Bucket *bucketA = (Bucket *)a;
    Bucket *bucketB = (Bucket *)b;
    return bucketA->data - bucketB->data;
}

void bucketSort(Bucket *arr, int n) {
    int i, j;
    Bucket *temp;
    Bucket *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        temp = (Bucket *)malloc(sizeof(Bucket));
        temp->data = arr[i].data;
        temp->index = arr[i].index;
        bucket[temp->data] = temp;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            arr[j++] = *(bucket[i]);
        }
    }
}

int main() {
    int i, n;
    scanf("%d", &n);
    Bucket *arr = (Bucket *)malloc(sizeof(Bucket) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }
    bucketSort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
    return 0;
}