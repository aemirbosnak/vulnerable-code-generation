//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

// Function to perform a binary search recursively
int binary_search(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is smaller than mid, search in the left subarray
        if (arr[mid] > target) {
            return binary_search(arr, left, mid - 1, target);
        }

        // Otherwise, search in the right subarray
        return binary_search(arr, mid + 1, right, target);
    }

    // Target not found
    return -1;
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to fill the array with Fibonacci numbers
void generate_fibonacci(int arr[], int n, int a, int b, int index) {
    if (index < n) {
        arr[index] = a; // Store current Fibonacci number
        generate_fibonacci(arr, n, b, a + b, index + 1); // Move to the next Fibonacci number
    }
}

// Recursive function to sum the elements of an array
int sum_array(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + sum_array(arr, n - 1);
}

// Main function
int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    int fibonacci[n]; // Declare array to hold Fibonacci numbers

    // Generate Fibonacci sequence
    generate_fibonacci(fibonacci, n, 0, 1, 0);
    
    // Print generated Fibonacci sequence
    printf("Fibonacci Sequence:\n");
    print_array(fibonacci, n);

    // Calculate the sum of the Fibonacci numbers
    int sum = sum_array(fibonacci, n);
    printf("Sum of Fibonacci Sequence: %d\n", sum);

    // Perform binary search on the Fibonacci array 
    int target;
    printf("Enter a number to search in the Fibonacci sequence: ");
    scanf("%d", &target);

    int result = binary_search(fibonacci, 0, n - 1, target);
    if (result != -1) {
        printf("%d found at index %d.\n", target, result);
    } else {
        printf("%d not found in the Fibonacci sequence.\n", target);
    }

    return 0;
}