//FormAI DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(){
    int n, i, x, index, choice;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements of the array: ", n);
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    printf("Enter the element to search: ");
    scanf("%d", &x);
    
    printf("\nChoose which searching algorithm to use:\n1. Binary search\n2. Linear search\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            start = clock();
            index = binarySearch(arr, 0, n-1, x);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if(index == -1)
                printf("Element not found in the array.");
            else
                printf("Element found at index %d.", index);
            printf("\nTime taken by Binary search: %f seconds", cpu_time_used);
            break;
            
        case 2:
            start = clock();
            for(i=0;i<n;i++){
                if(arr[i] == x){
                    index = i;
                    break;
                }
            }
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            if(index == -1)
                printf("Element not found in the array.");
            else
                printf("Element found at index %d.", index);
            printf("\nTime taken by Linear search: %f seconds", cpu_time_used);
            break;
            
        default:
            printf("Invalid choice!");
            break;
    }
    
    return 0;
}