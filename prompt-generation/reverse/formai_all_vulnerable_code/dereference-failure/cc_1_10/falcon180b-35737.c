//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

//Bucket Sort Function
void bucket_sort(int arr[], int n) {
    int i, j, max_val, min_val, range;
    int *bucket;

    //Allocate memory for buckets
    bucket = (int *) malloc(n * sizeof(int));

    //Find the range of the array
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        else if (arr[i] < min_val)
            min_val = arr[i];
    }
    range = max_val - min_val + 1;

    //Initialize all buckets to zero
    for (i = 0; i < range; i++)
        bucket[i] = 0;

    //Insert elements into buckets
    for (i = 0; i < n; i++) {
        j = arr[i] - min_val;
        bucket[j]++;
    }

    //Modify the array by summing the elements in each bucket
    for (i = 0; i < n; i++) {
        j = arr[i] - min_val;
        bucket[j]--;
        arr[i] = min_val + j;
    }

    //Free memory allocated for buckets
    free(bucket);
}

//Main Function
int main() {
    int n, i;

    //Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //Allocate memory for the array
    int *arr = (int *) malloc(n * sizeof(int));

    //Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    //Sort the array using Bucket Sort
    bucket_sort(arr, n);

    //Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}