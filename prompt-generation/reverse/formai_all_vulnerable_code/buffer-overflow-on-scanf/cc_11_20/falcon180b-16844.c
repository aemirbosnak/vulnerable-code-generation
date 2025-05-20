//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, j;

    // Reading array elements from user
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bucket Sort Algorithm
    int max = arr[0];
    for(i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int bucket_size = max/n;

    int *bucket[n];

    for(i=0; i<n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * bucket_size);
    }

    for(i=0; i<n; i++) {
        for(j=0; j<bucket_size; j++) {
            bucket[i][j] = 0;
        }
    }

    for(i=0; i<n; i++) {
        int index = arr[i]/bucket_size;
        bucket[index][arr[i]%bucket_size] = 1;
    }

    for(i=0; i<n; i++) {
        int index = arr[i]/bucket_size;
        int k = 0;
        for(j=0; j<bucket_size; j++) {
            if(bucket[index][j] == 1) {
                arr[k++] = i*bucket_size + j;
            }
        }
    }

    // Printing sorted array
    printf("Sorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}