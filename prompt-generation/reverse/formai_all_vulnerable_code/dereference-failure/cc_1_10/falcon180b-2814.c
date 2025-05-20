//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int index;
} Bucket;

void swap(Bucket* a, Bucket* b) {
    Bucket temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Bucket arr[], int low, int high) {
    int pivot = arr[high].value;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void bucketSort(Bucket arr[], int n) {
    int max = arr[0].value;
    int min = arr[0].value;

    for (int i = 0; i < n; i++) {
        if (arr[i].value > max) {
            max = arr[i].value;
        }

        if (arr[i].value < min) {
            min = arr[i].value;
        }
    }

    int range = max - min + 1;
    Bucket* buckets = (Bucket*) malloc(range * sizeof(Bucket));

    for (int i = 0; i < range; i++) {
        buckets[i].index = -1;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i].value - min) / (max - min) * range;
        buckets[bucketIndex].index = i;
    }

    for (int i = 0; i < range; i++) {
        if (buckets[i].index!= -1) {
            arr[i].index = buckets[i].index;
        }
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i].index;
        arr[index].value = i;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Bucket arr[MAX_SIZE];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        arr[i].value = i;
        arr[i].index = i;
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].value);
    }

    return 0;
}