//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Function to perform Jump Search on a sorted array
int jumpSearch(int arr[], int n, int x) {
    // Finding the block size to jump
    int step = sqrt(n); 
    int prev = 0;

    // Finding the block where the element is present (if it is present)
    while (arr[step - 1] < x && step < n) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Element not found
        }
    }

    // Linear search within the block for the element
    for (int j = prev; j < step && j < n; j++) {
        if (arr[j] == x) {
            return j; // Element found
        }
    }
    return -1; // Element not found
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to drive the program
int main() {
    // Size of the array
    int n;

    // User input for the size of the array
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // User input for the elements of the array
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array
    printArray(arr, n);

    // Element to be searched
    int x;
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    // Performing Jump Search
    int result = jumpSearch(arr, n, x);
    
    // Outputting the result
    if (result != -1) {
        printf("Element %d found at index %d\n", x, result);
    } else {
        printf("Element %d not found in the array\n", x);
    }

    // Freeing allocated memory
    free(arr);
    
    return 0;
}