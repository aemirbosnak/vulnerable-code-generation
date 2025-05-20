//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Pair;

void bucketSort(Pair arr[], int n) {
    Pair temp[MAX_SIZE];
    int i, j, k, max, min, range;

    // Find the range of the array
    max = arr[0].data;
    min = arr[0].data;
    for (i = 1; i < n; i++) {
        if (arr[i].data > max)
            max = arr[i].data;
        if (arr[i].data < min)
            min = arr[i].data;
    }
    range = max - min + 1;

    // Create n empty buckets
    for (i = 0; i < n; i++) {
        temp[i].data = 0;
        temp[i].index = -1;
    }

    // Put each element in its bucket
    for (i = 0; i < n; i++) {
        k = (arr[i].data - min) * n / range;
        if (temp[k].index == -1) {
            temp[k].index = i;
        } else {
            temp[k].index = -2;
        }
    }

    // Sort the buckets
    for (i = 0; i < n; i++) {
        if (temp[i].index!= -2) {
            arr[temp[i].index] = arr[i];
            temp[i].index = -1;
        }
    }
}

int main() {
    Pair arr[MAX_SIZE];
    int n, i;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements from the user
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // Sort the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    return 0;
}