//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bucket_sort(int arr[], int n) {
    int i, j, k, index;
    int *bucket[MAX];
    for(i=0; i<n; i++) {
        index = arr[i]/10;
        if(index == 0) {
            index = 10;
        }
        for(j=0; j<index; j++) {
            if(bucket[j] == NULL) {
                bucket[j] = (int *)malloc(sizeof(int));
                *bucket[j] = 0;
            }
        }
        for(k=0; k<n; k++) {
            if(arr[k] == arr[i]) {
                swap(&arr[k], &arr[i]);
                break;
            }
        }
    }
    for(i=0; i<MAX; i++) {
        if(bucket[i]!= NULL) {
            for(j=0; j<n; j++) {
                if(arr[j] == i*10) {
                    break;
                }
            }
            for(k=0; k<n; k++) {
                if(arr[k] == i*10) {
                    swap(&arr[k], &arr[j]);
                    break;
                }
            }
        }
    }
}

void main() {
    int arr[] = {7, 3, 1, 6, 5, 2, 8, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("After sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}