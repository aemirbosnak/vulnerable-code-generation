//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int key;
    char name[50];
} Element;

void bucketSort(Element arr[], int n, int bucketSize) {
    int i, j, index;
    Element *bucket[10];

    for (i = 0; i < 10; i++)
        bucket[i] = (Element *)calloc(bucketSize, sizeof(Element));

    for (i = 0; i < n; i++) {
        index = (arr[i].key % 10) * bucketSize / bucketSize;
        bucket[index][arr[i].key % bucketSize] = arr[i];
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < bucketSize; j++) {
            if (bucket[i][j].key != -1) {
                for (int k = j; k > 0 && bucket[i][k-1].key > bucket[i][k].key; k--) {
                    Element temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k-1];
                    bucket[i][k-1] = temp;
                }
            }
        }

        for (int k = 0; k < bucketSize && bucket[i][k].key != -1; k++) {
            int pos = (bucket[i][k].key % n);
            arr[pos] = bucket[i][k];
            bucket[i][k].key = -1;
        }
    }

    for (int i = 0; i < 10; i++)
        free(bucket[i]);
}

void printArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s (%d) ", arr[i].name, arr[i].key);
    }
    printf("\n");
}

int main() {
    int n, i, bucketSize = 5;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    Element *arr = (Element *)calloc(n, sizeof(Element));

    printf("Enter elements (name space key):\n");
    for (i = 0; i < n; i++) {
        scanf("%s %d", arr[i].name, &arr[i].key);
        arr[i].key = abs(arr[i].key);
    }

    bucketSort(arr, n, bucketSize);
    printArray(arr, n);

    free(arr);

    return 0;
}