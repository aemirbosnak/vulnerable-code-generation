//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search an element in an array
int search(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Input size of array
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    // Input elements of array
    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Search for an element in the array
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
    int index = search(arr, n, key);
    
    if (index == -1) {
        printf("Element not found in array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }
    
    return 0;
}