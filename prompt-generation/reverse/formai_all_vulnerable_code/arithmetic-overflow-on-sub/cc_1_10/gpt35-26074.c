//FormAI DATASET v1.0 Category: Sorting ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

// Function signatures
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(){

    int n, arr[MAX_SIZE];

    // Taking input size and array elements from the user
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // Sorting the array using merge sort
    merge_sort(arr, 0, n-1);

    // Printing the sorted array
    printf("\nSorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;

}

// Function to perform Merge Sort
void merge_sort(int arr[], int left, int right){

    if(left<right){

        int mid = (left+right)/2;

        // Sorting the left half
        merge_sort(arr, left, mid);

        // Sorting the right half
        merge_sort(arr, mid+1, right);

        // Merging the two sorted halves
        merge(arr, left, mid, right);

    }

}

// Function to merge two sorted arrays
void merge(int arr[], int left, int mid, int right){

    int i=left, j=mid+1, k=left;
    int temp[MAX_SIZE];

    // Comparing the elements of both halves and storing them in temporary array
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    // Copying the remaining elements of left half, if any
    while(i<=mid){
        temp[k++] = arr[i++];
    }

    // Copying the remaining elements of right half, if any
    while(j<=right){
        temp[k++] = arr[j++];
    }

    // Copying the sorted elements from temporary array to original array
    for(int l=left; l<=right; l++){
        arr[l] = temp[l];
    }

}