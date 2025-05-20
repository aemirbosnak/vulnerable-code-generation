//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, k, max = arr[0], min = arr[0], range, bucketSize = 10;
    int *bucket[MAX/bucketSize];

    for(i=1; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
        else if(arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;

    for(i=0; i<MAX/bucketSize; i++)
        bucket[i] = (int*)malloc(range*sizeof(int));

    for(i=0; i<n; i++) {
        k = (arr[i] - min)/(max - min)*(MAX/bucketSize);
        bucket[k] = (int*)realloc(bucket[k], (k*sizeof(int))+sizeof(int));
        bucket[k][k] = arr[i];
    }

    for(i=0; i<MAX/bucketSize; i++) {
        for(j=0; j<range; j++) {
            if(bucket[i][j]!= -1) {
                arr[j] = bucket[i][j];
                j++;
            }
        }
    }

    for(i=0; i<MAX/bucketSize; i++)
        free(bucket[i]);
}

int main() {
    int i, n;
    srand(time(0));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(i=0; i<n; i++) {
        arr[i] = rand() % (MAX - 1) + 1;
        printf("%d ", arr[i]);
    }

    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}