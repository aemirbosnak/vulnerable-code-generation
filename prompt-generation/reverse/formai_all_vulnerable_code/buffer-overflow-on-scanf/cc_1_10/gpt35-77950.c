//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float* arr, int n);

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    float* arr = (float*) malloc(n*sizeof(float));
    printf("Enter %d elements to sort:\n", n);
    for(int i=0; i<n; i++) {
        scanf("%f", &arr[i]);
    }
    
    bucketSort(arr, n);
    
    printf("After sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}

void bucketSort(float* arr, int n) {
    int i, j;
    float* bucket;
    bucket = (float*) malloc(n*sizeof(float));
    for(int i=0; i<n; i++) {
        bucket[i] = 0;
    }
    for(i=0; i<n; i++) {
        j = (int)(n*arr[i]);
        bucket[j] = arr[i];
    }
    for(i=0; i<n; i++) {
        int k = i;
        float temp = bucket[i];
        for(j=i+1; j<n; j++) {
            if(bucket[j] < temp) {
                k = j;
                temp = bucket[j];
            }
        }
        bucket[k] = bucket[i];
        bucket[i] = temp;
    }
    for(i=0, j=0; i<n && j<n; i++) {
        if(bucket[i] != 0) {
            arr[j++] = bucket[i];
        }
    }
    free(bucket);
}