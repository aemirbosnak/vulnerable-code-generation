//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    
    return -1;
}

int binary_search(int arr[], int low, int high, int key) {
    if(low > high) {
        return -1;
    }
    
    int mid = (low+high)/2;
    
    if(arr[mid] == key) {
        return mid;
    }
    else if(arr[mid] > key) {
        return binary_search(arr, low, mid-1, key);
    }
    else {
        return binary_search(arr, mid+1, high, key);
    }
}

int main() {
    int n, key, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    
    printf("\nEnter the type of searching algorithm to use -\n1. Linear Search\n2. Binary Search\nChoice: ");
    scanf("%d", &choice);
    
    int position;
    
    switch(choice) {
        case 1:
            position = linear_search(arr, n, key);
            break;
            
        case 2:
            position = binary_search(arr, 0, n-1, key);
            break;
            
        default:
            printf("\nInvalid choice!\n");
            return 0;
    }
    
    if(position == -1) {
        printf("\nElement not found :(\n");
    }
    else {
        printf("\nElement found at position %d\n", position+1);
    }
    
    return 0;
}