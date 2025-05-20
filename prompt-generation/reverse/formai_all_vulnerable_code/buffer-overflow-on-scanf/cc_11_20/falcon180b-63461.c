//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main() {
    int arr[MAX], n, i, j, k, max, min;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Taking input from user
    printf("Enter the elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding the minimum and maximum values in the array
    max = arr[0];
    min = arr[0];
    for(i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculating the range and number of buckets
    int range = max - min + 1;
    int num_buckets = (range / 10) + 1;

    // Creating the buckets
    int *buckets[num_buckets];
    for(i=0; i<num_buckets; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * 10);
    }

    // Distributing the elements into the buckets
    for(i=0; i<n; i++) {
        j = (arr[i] - min) / 10;
        k = 0;
        while(buckets[j][k]!= -1) {
            k++;
        }
        buckets[j][k] = arr[i];
    }

    // Sorting the buckets
    for(i=0; i<num_buckets; i++) {
        for(j=0; j<10; j++) {
            if(buckets[i][j]!= -1) {
                printf("%d ", buckets[i][j]);
            }
        }
    }

    return 0;
}