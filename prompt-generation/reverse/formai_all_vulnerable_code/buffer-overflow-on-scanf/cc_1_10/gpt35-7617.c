//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
//This is an example implementation of the Bucket Sort algorithm in C

#include <stdio.h>
#include <stdlib.h>

//Defining the maximum number of elements in the array
#define MAX 100

//Defining the number of buckets
#define BUCKET_NUM 5

//Defining the function to swap values between two pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Defining the function to sort the array using bucket sort technique
void bucketSort(int arr[], int n) {
    int i, j;
    int bucket[BUCKET_NUM];
    
    //initializing all the buckets with 0
    for(i = 0; i < BUCKET_NUM; i++) {
        bucket[i] = 0;
    }
    
    //counting the number of elements in each bucket
    for(i = 0; i < n; i++) {
        bucket[arr[i]/BUCKET_NUM]++;
    }
    
    //sorting elements within the buckets using insertion sort
    for(i = 0; i < BUCKET_NUM; i++) {
        //sorting each bucket using insertion sort
        for(j = 0; j < bucket[i]; j++) {
            int k;
            int temp = i*BUCKET_NUM + j;
            for(k = j+1; k < bucket[i]; k++) {
                if(temp > i*BUCKET_NUM + k) {
                    swap(&arr[i*BUCKET_NUM + j], &arr[i*BUCKET_NUM + k]);
                }
            }
        }
    }
}

int main() {
    int arr[MAX];
    int i, n;
    
    //inputting the values of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    //sorting the array using bucket sort
    bucketSort(arr, n);
    
    //displaying the sorted array
    printf("\nThe sorted array is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}