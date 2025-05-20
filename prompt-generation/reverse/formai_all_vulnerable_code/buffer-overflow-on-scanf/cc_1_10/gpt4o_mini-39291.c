//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);

int main() {
    int *arr, n;

    printf("🌟 Welcome to the Sorting Extravaganza! 🌟\n");
    printf("📊 How many numbers do you want to sort? ");
    scanf("%d", &n);

    // Dynamically allocate array
    arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("💔 Memory allocation failed! Exiting program...\n");
        return 1;
    }

    printf("🚀 Great! Now, let's fill the array with %d numbers! 🚀\n", n);
    for(int i = 0; i < n; i++) {
        printf("🖊️ Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("✨ Here are your unsorted numbers: ");
    printArray(arr, n);

    // Call QuickSort
    printf("🔍 Sorting is in progress, hold tight! 🔍\n");
    quickSort(arr, 0, n - 1);
    
    printf("✅ Sort complete! Your sorted numbers are: ");
    printArray(arr, n);

    // Free allocated memory
    free(arr);
    printf("🌈 Thanks for using the Sorting Extravaganza! Goodbye! 🌈\n");
    return 0;
}

// QuickSort algorithm implementation
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before
        // and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to perform partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Index of smaller element

    for(int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap the pivot element with the element at i+1
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("[ ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}