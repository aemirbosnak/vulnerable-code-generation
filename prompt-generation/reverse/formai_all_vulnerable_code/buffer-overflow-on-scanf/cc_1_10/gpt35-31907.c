//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Define an array of integers to be searched
int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 101, 122, 133};
int n = sizeof(arr) / sizeof(arr[0]); // Number of elements in the array

// Paranoid search function
int paranoidSearch(int x) {
    int i = 0;
    
    while (i < n) {
        
        if (arr[i] == x) {
            // We found the element
            printf("Element found at index %d\n", i);
            return i;
        }
        
        // Randomly choose the next index to search
        int nextIndex = rand() % n;
        
        // Make sure it's not the current index or out of bounds
        while (nextIndex == i || nextIndex >= n)
            nextIndex = rand() % n;
        
        // Check nextIndex
        if (arr[nextIndex] == x) {
            // We found the element
            printf("Element found at index %d\n", nextIndex);
            return nextIndex;
        }
        
        // Move on to the next randomly chosen index
        i = nextIndex;
    }
    
    // If we exhaust all possibilities, the element is not in the array
    printf("Element not found\n");
    return -1;
}

int main() {
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    
    paranoidSearch(x);
    
    return 0;
}