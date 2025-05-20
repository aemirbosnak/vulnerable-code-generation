//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
#define ARRAY_SIZE 15

void bucketSort(int arr[], int n) {
    int i, j, k;
    int buckets[BUCKET_SIZE][ARRAY_SIZE];
 
    for (i = 0; i < BUCKET_SIZE; i++)
        for (j = 0; j < ARRAY_SIZE; j++)
            buckets[i][j] = 0;
 
    for (i = 0; i < n; i++) {
        int bucket_num = (arr[i] / BUCKET_SIZE);
        for (j = 0; j < ARRAY_SIZE; j++) {
            if (buckets[bucket_num][j] == 0) {
                buckets[bucket_num][j] = arr[i];
                break;
            }
        }
    }
 
    for (i = 0, k = 0; i < BUCKET_SIZE; i++) 
        for (j = 0; j < ARRAY_SIZE; j++) 
            if (buckets[i][j] != 0) 
                arr[k++] = buckets[i][j];
}

int main() {
    int arr[ARRAY_SIZE], i;

    printf("Enter %d elements in the array:\n", ARRAY_SIZE);
    for (i = 0; i < ARRAY_SIZE; i++)
        scanf("%d", &arr[i]);

    printf("\nBefore sorting:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    
    bucketSort(arr, ARRAY_SIZE);
    
    printf("\n\nAfter sorting:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    return 0;
}