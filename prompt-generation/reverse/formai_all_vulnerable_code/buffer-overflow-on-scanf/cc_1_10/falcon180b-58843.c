//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];
    int range;

    for(i=0;i<n;i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;
    for(i=0;i<MAX_SIZE;i++) {
        bucket[i] = malloc(n * sizeof(int));
    }

    for(i=0;i<n;i++) {
        k = (arr[i] - min) * MAX_SIZE / range;
        if(k == MAX_SIZE) {
            k--;
        }
        bucket[k] = realloc(bucket[k], (j+1) * sizeof(int));
        bucket[k][j] = arr[i];
        j++;
    }

    for(i=0;i<n;i++) {
        for(j=0;j<MAX_SIZE;j++) {
            if(bucket[j]!= NULL) {
                arr[i] = bucket[j][0];
                bucket[j] = realloc(bucket[j], (j) * sizeof(int));
                break;
            }
        }
    }

    for(i=0;i<MAX_SIZE;i++) {
        free(bucket[i]);
    }
}

int main() {
    int n, i;
    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for(i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}