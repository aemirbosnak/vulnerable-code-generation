//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int key;
    char name[20];
} Element;

void bucketSort(Element arr[], int n) {
    int i, j, bucket, index;
    Element *pointerToElement;
    int *bucketArray;

    // Allocate memory for bucket array
    bucketArray = (int*) calloc(SIZE, sizeof(int));

    // Initialize bucket array
    for (i = 0; i < SIZE; i++) {
        bucketArray[i] = 0;
    }

    // Store elements in respective buckets based on keys
    for (i = 0; i < n; i++) {
        bucket = arr[i].key % SIZE;
        index = bucketArray[bucket];
        pointerToElement = (Element*) realloc(pointerToElement, sizeof(Element) * (index + 1));
        pointerToElement[index] = arr[i];
        bucketArray[bucket]++;
    }

    // Merge sorted buckets to get final sorted array
    int k = 0;
    for (i = 0; i < SIZE; i++) {
        if (bucketArray[i] > 0) {
            for (j = 0; j < bucketArray[i]; j++) {
                arr[k++] = pointerToElement[j];
            }
        }
        free(pointerToElement);
        pointerToElement = NULL;
    }

    free(bucketArray);
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    Element arr[SIZE];
    int i;

    printf("Enter %d elements:\n", SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("\nElement %d: ", i + 1);
        scanf("%d%s", &arr[i].key, arr[i].name);
    }

    start = clock();

    // Call bucketSort function
    bucketSort(arr, SIZE);

    end = clock();

    printf("\nSorted array in ascending order of keys:\n");
    for (i = 0; i < SIZE; i++) {
        printf("\nKey: %d | Name: %s", arr[i].key, arr[i].name);
    }

    printf("\n\nTime taken by bucketSort function: %f seconds", (cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC));

    return 0;
}