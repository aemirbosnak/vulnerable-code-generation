//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000
#define BUCKETS 10

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i;
    Element* bucket[BUCKETS] = {0};
    int count[BUCKETS] = {0};

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / (MAX_SIZE / BUCKETS) % BUCKETS;
        bucket[bucketIndex] = (Element*)realloc(bucket[bucketIndex], sizeof(Element) * (count[bucketIndex] + 1));
        bucket[bucketIndex][count[bucketIndex]] = (Element){arr[i], i};
        count[bucketIndex]++;
    }

    for (int j = 0; j < BUCKETS; j++) {
        int start = 0;
        for (int i = 0; i < count[j]; i++) {
            int index = bucket[j][i].index;
            arr[index] = bucket[j][i].data;
        }
        free(bucket[j]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}