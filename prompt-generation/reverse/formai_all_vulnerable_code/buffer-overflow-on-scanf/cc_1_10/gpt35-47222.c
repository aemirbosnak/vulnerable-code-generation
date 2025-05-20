//FormAI DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>

// Define the size of the array
#define SIZE 10

// Function that implements the Binary Search Algorithm
int binarySearch(int arr[], int l, int r, int target){
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    // Define an array
    int arr[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    // Print the array
    printf("Array:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Prompt user to enter target value
    printf("Enter target value: ");
    int target;
    scanf("%d", &target);
    printf("\n");

    // Search for target value using Binary Search Algorithm
    int result = binarySearch(arr, 0, SIZE - 1, target);

    // If target value is not found
    if (result == -1){
        printf("Target value not found in array.\n");
    }
    // If target value is found
    else{
        printf("Target value found at index %d.\n", result);
    }

    return 0;
}