//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

//Defining the bucket size and the range of numbers to be sorted
#define BUCKET_SIZE 10
#define RANGE 1000

//Defining a function to swap two elements of an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Defining the bucket sort function
void bucket_sort(int* arr, int n) {
    int i, j = 0;
    int max_val = arr[0];
    int min_val = arr[0];
    
    //Finding the maximum and the minimum values in the given array
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    
    //Finding the range of values
    int range = max_val - min_val;
    range /= BUCKET_SIZE - 1;
    range++;
    
    //Creating the buckets
    int **buckets = (int **) malloc(sizeof(int *) * BUCKET_SIZE);
    for (i = 0; i < BUCKET_SIZE; i++)
        buckets[i] = (int *) malloc(sizeof(int) * (n / BUCKET_SIZE + 1));
    
    //Filling the buckets
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min_val) / range;
        if (index >= BUCKET_SIZE)
            index = BUCKET_SIZE - 1;
        buckets[index][j++] = arr[i];
    }
    
    //Sorting the buckets and merging them
    for (i = 0; i < BUCKET_SIZE; i++) {
        int k = j;
        j = 0;
        for (; j < k - 1; j++) {
            int l = j + 1;
            for (; l < k; l++) {
                if (buckets[i][l] < buckets[i][j])
                    swap(&buckets[i][l], &buckets[i][j]);
            }
        }       
    }
    j = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        int k = j;
        j = 0;
        for (; j < k || buckets[i][j - k] != 0; j++) {
            arr[j] = buckets[i][j - k];
        }
    }
    
    //Freeing the memory allocated for the buckets
    for (i = 0; i < BUCKET_SIZE; i++)
        free(buckets[i]);
    free(buckets);
}

//Main function
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bucket_sort(arr, n);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}