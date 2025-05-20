//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include<stdio.h>
#include<stdlib.h>

//function to search the key in the array
int binary_search(int arr[], int n, int key){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1; //key not found
}

//function to print the array
void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int*)calloc(n, sizeof(int));
    if(arr == NULL){
        printf("Memory allocation error.\n");
        exit(0);
    }
    
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    printf("The entered array is: ");
    print_array(arr, n);
    
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    int index = binary_search(arr, n, key);
    if(index == -1){
        printf("The key %d is not found.\n", key);
    }
    else{
        printf("The key %d is found at index %d.\n", key, index);
    }
    
    free(arr);
    return 0;
}