//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void bucketSort(Element arr[], int n) {
    Element bucket[MAX_SIZE];
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        bucket[arr[i].data / 10].index = i;
        count++;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i].index!= -1) {
            arr[count++] = bucket[i];
        }
    }
}

int main() {
    Element arr[MAX_SIZE];
    int n, i, max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
    }

    max = arr[0].data;
    min = arr[0].data;

    for (i = 1; i < n; i++) {
        if (arr[i].data > max) {
            max = arr[i].data;
        }
        if (arr[i].data < min) {
            min = arr[i].data;
        }
    }

    printf("Range: %d to %d\n", min, max);

    bucketSort(arr, n);

    printf("Sorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    return 0;
}