//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000
#define BUCKET_SIZE 10

int buckets[MAX_SIZE/BUCKET_SIZE];
int arr[MAX_SIZE];

void initializeBuckets() {
    for(int i=0; i<MAX_SIZE/BUCKET_SIZE; i++) {
        buckets[i] = -1;
    }
}

int getBucketIndex(int num) {
    return (int)floor((double)num/BUCKET_SIZE);
}

void insertIntoBucket(int num) {
    int index = getBucketIndex(num);
    if(buckets[index] == -1) {
        buckets[index] = num;
    }
    else {
        printf("Bucket is full\n");
    }
}

void bucketSort(int n) {
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        insertIntoBucket(arr[i]);
    }

    int j=0;
    for(int i=0; i<MAX_SIZE/BUCKET_SIZE; i++) {
        if(buckets[i]!= -1) {
            printf("Bucket %d: ", i);
            while(buckets[i]!= -1) {
                printf("%d ", buckets[i]);
                buckets[i] = -1;
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    initializeBuckets();

    bucketSort(n);

    return 0;
}