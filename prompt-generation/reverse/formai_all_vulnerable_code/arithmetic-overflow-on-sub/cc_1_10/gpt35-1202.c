//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

// A function to perform linear search
int linear_search(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;  // If the key is not found, return -1
}

// A function to perform binary search
int binary_search(int arr[], int start, int end, int key){
    if(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid]==key){  // If key is present at the middle
            return mid;
        }
        if(arr[mid]>key){  // If key is smaller than mid
            return binary_search(arr, start, mid-1, key);
        }
        else{  // If key is greater than mid
            return binary_search(arr, mid+1, end, key);
        }
    }
    return -1;  // If the key is not found, return -1
}

int main(){
    int n, key, choice;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    
    printf("Choose an algorithm to perform searching:\n");
    printf("1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);
    
    int index;
    if(choice==1){
        index = linear_search(arr, n, key);
    }
    else if(choice==2){
        index = binary_search(arr, 0, n-1, key);
    }
    else{
        printf("Invalid choice!\n");
        return 0;
    }
    
    if(index!=-1){
        printf("Element found at index %d\n", index);
    }
    else{
        printf("Element not found!\n");
    }
    
    return 0;
}