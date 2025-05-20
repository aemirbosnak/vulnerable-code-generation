//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// A structure to represent the search results
typedef struct {
    int *index; // To store the indices of found numbers
    int count;  // Number of times the number was found
} SearchResult;

// Function to perform linear search
SearchResult linearSearch(int arr[], int size, int target) {
    SearchResult result;
    result.index = (int *)malloc(MAX_SIZE * sizeof(int)); // Allocate memory for indices
    result.count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            result.index[result.count] = i; // Store index
            result.count++;
            printf("Surprise! Found %d at index %d!\n", target, i);
        }
    }
    return result;
}

// Function to perform binary search (array must be sorted)
SearchResult binarySearch(int arr[], int size, int target) {
    SearchResult result;
    result.index = (int *)malloc(MAX_SIZE * sizeof(int)); // Allocate memory for indices
    result.count = 0;
    
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result.index[result.count] = mid; // Found the target
            result.count++;
            printf("Surprise! Found %d at index %d!\n", target, mid);
            
            // Check for duplicates towards the left
            int left = mid - 1;
            while (left >= low && arr[left] == target) {
                result.index[result.count] = left;
                result.count++;
                printf("Surprise! Found %d at index %d!\n", target, left);
                left--;
            }

            // Check for duplicates towards the right
            int right = mid + 1;
            while (right <= high && arr[right] == target) {
                result.index[result.count] = right;
                result.count++;
                printf("Surprise! Found %d at index %d!\n", target, right);
                right++;
            }
            break; // Exit as we have found all occurrences
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to sort the array using bubble sort (for demonstration purposes)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to free the search result memory
void freeSearchResult(SearchResult result) {
    free(result.index);
}

int main() {
    int arr[MAX_SIZE], n, target, choice;
    
    printf("Welcome to the Surprise Search Program!\n");
    printf("How many elements do you want to enter (max %d)? ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n > MAX_SIZE) {
        printf("Exceeded maximum size. Exiting!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (array needs to be sorted)\n");
    scanf("%d", &choice);

    if (choice == 2) {
        printf("Sorting the array for binary search...\n");
        bubbleSort(arr, n);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    SearchResult result;
    if (choice == 1) {
        result = linearSearch(arr, n, target);
    } else {
        result = binarySearch(arr, n, target);
    }

    if (result.count == 0) {
        printf("Oops! %d was not found in the array...\n", target);
    } else {
        printf("Total occurrences of %d found: %d\n", target, result.count);
        printf("Indices: ");
        for (int i = 0; i < result.count; i++) {
            printf("%d ", result.index[i]);
        }
        printf("\n");
    }

    freeSearchResult(result); // Free allocated memory
    return 0;
}