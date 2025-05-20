//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int arr[], int n, int k) {

    int i, j;
    int count[k];

    // initializing the counts for the elements in the array.
    for(i=0; i < k; i++){
        count[i] = 0;
    }

    // placing each element of array to its bucket.
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // placing the elements back into the array.
    for (i=0, j=0; i < k; i++) {
        while (count[i]--) {
            arr[j++] = i;
        }
    }
}


// driver function to test the above code
int main() {

    int n, k;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the range of the array:\n");
    scanf("%d", &k);
    int arr[n];

    // Random Generation of elements
    srand(time(0));
    for (int i=0; i<n; i++) {
        arr[i] = rand() % k;
    }

    printf("Unsorted array: \n");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n, k);

    printf("Sorted array: \n");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}