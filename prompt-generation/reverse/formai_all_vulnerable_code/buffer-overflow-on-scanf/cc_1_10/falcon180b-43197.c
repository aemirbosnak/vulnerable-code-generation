//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void bucketSort(element arr[], int n) {
    element bucket[MAX_SIZE];
    int i, j, k;
    int max = arr[0].data;
    int min = arr[0].data;

    // find the maximum and minimum values in the array
    for (i = 0; i < n; i++) {
        if (arr[i].data > max) {
            max = arr[i].data;
        }
        if (arr[i].data < min) {
            min = arr[i].data;
        }
    }

    // create the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (element) { 0, -1 };
    }

    // place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        k = (arr[i].data - min) * MAX_SIZE / (max - min);
        bucket[k].data += arr[i].data;
        bucket[k].index++;
    }

    // place the elements back in the array
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        while (bucket[j].index > 0) {
            arr[i++] = bucket[j];
            bucket[j].index--;
        }
    }
}

int main() {
    element arr[MAX_SIZE];
    int n, i;

    // read the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // sort the array
    bucketSort(arr, n);

    // print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    return 0;
}