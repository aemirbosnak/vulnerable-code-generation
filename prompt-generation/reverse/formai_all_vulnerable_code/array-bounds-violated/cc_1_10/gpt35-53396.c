//FormAI DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>

// Function to perform linear search of an item in an array
int linear_search(int arr[], int n, int item) {
    for(int i=0; i<n; i++) {
        if(arr[i] == item)
            return i;
    }
    return -1;
}

// Function to perform binary search of an item in a sorted array
int binary_search(int arr[], int n, int item) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == item)
            return mid;
        else if(arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, item, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the item to search: ");
    scanf("%d", &item);
    printf("Enter the search algorithm to use (1 for linear, 2 for binary): ");
    scanf("%d", &choice);
    int index;
    if(choice == 1)
        index = linear_search(arr, n, item);
    else if(choice == 2) {
        // Sort the array before performing binary search
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        index = binary_search(arr, n, item);
    }
    else {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }
    if(index == -1)
        printf("%d not found in the array.\n", item);
    else
        printf("%d found at index %d.\n", item, index);
    return 0;
}