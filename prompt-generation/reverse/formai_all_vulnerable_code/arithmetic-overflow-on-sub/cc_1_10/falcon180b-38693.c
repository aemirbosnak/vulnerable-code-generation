//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000

int arr[MAX];

void bubbleSort(int n) {
    int i, j;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bucketSort(int n) {
    int i, j, max = arr[0];
    for (i=1; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int *bucket = (int *)malloc(max*sizeof(int));
    for (i=0; i<max; i++) {
        bucket[i] = 0;
    }
    for (i=0; i<n; i++) {
        bucket[arr[i]]++;
    }
    int index = 0;
    for (i=0; i<max; i++) {
        for (j=0; j<bucket[i]; j++) {
            arr[index++] = i;
        }
    }
    free(bucket);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for (i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    srand(time(NULL));
    bubbleSort(n);
    printf("Sorted array using Bubble Sort:\n");
    for (i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    bucketSort(n);
    printf("Sorted array using Bucket Sort:\n");
    for (i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}