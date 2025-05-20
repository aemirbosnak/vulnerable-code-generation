//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to perform binary search on the array
int binarySearch(int arr[], int left, int right, int key){

    int mid;
    
    while (left <= right){
        mid = (left + right) / 2;
        
        if (arr[mid] == key)
            return mid;
            
        else if (arr[mid] > key)
            right = mid - 1;
        
        else
            left = mid + 1;
    }


    return -1;
}

// Main function
int main(){

    int i, n, key, result;
    int arr[100];

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Prompt the user to enter the values for the array
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array
    for(i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Prompt the user to enter the value to be searched
    printf("Enter the value to be searched: ");
    scanf("%d", &key); 

    // Call the binarySearch function
    result = binarySearch(arr, 0, n-1, key);

    // Check if the value was found or not
    if(result == -1)
        printf("Value not found in the array. Try Again\n");
    else
        printf("Value found at index %d\n", result);

    return 0;
}