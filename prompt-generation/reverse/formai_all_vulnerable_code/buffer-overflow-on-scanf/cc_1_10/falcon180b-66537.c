//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int i, n;
    int bucket[MAX_SIZE];
    int *p;

    // Input the number of elements to be sorted
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Initialize the bucket array
    for(i = 0; i < MAX_SIZE; i++) {
        bucket[i] = 0;
    }

    // Input the elements to be sorted
    int arr[n];
    printf("Enter the elements to be sorted:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Distribute the elements into the bucket array
    for(i = 0; i < n; i++) {
        p = &bucket[arr[i]];
        *p += 1;
    }

    // Sort the elements using the bucket array
    for(i = 0; i < MAX_SIZE; i++) {
        if(bucket[i] > 0) {
            printf("Bucket %d: ", i);
            for(int j = 0; j < bucket[i]; j++) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }

    // Output the sorted elements
    printf("\nSorted Elements:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}