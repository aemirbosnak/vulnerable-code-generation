//FormAI DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>

int linearSearch(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int x){
    while (l <= r){
        int m = l + (r-l)/2;
        if (arr[m] == x){
            return m;
        }
        if (arr[m] < x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}

int main(){
    int n, x, arr[100], i, choice, index;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    
    printf("Choose the search algorithm you want to use:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    scanf("%d", &choice);
    
    switch (choice){
        case 1:
            index = linearSearch(arr, n, x);
            break;
        case 2:
            index = binarySearch(arr, 0, n-1, x);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }
    
    if (index == -1){
        printf("Element not found in the array!\n");
    }
    else{
        printf("Element found at index %d!\n", index);
    }
    
    return 0;
}