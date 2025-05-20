//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// The partition function for the quicksort algorithm
int partition(int array[], int low, int high, int asc) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if ((asc && array[j] < pivot) || (!asc && array[j] > pivot)) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high, int asc) {
    if (low < high) {
        int pi = partition(array, low, high, asc);
        quickSort(array, low, pi - 1, asc);
        quickSort(array, pi + 1, high, asc);
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n = 0;
    int asc = 1; // 1 for ascending, 0 for descending
    int *array = NULL;

    printf("Welcome to the Sorting Program!\n");
    printf("How many numbers would you like to sort? ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Please enter the numbers to sort:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    int choice;
    scanf("%d", &choice);

    // Set the sorting order based on user choice
    if (choice == 2) {
        asc = 0;
    }

    printf("You have entered:\n");
    printArray(array, n);

    // Sort the array using quick sort
    quickSort(array, 0, n - 1, asc);

    printf("Sorted array in %s order:\n", asc ? "ascending" : "descending");
    printArray(array, n);

    // Free the dynamically allocated memory
    free(array);

    printf("Thank you for using the sorting program. Goodbye!\n");
    return 0;
}