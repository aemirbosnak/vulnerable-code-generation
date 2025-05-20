//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the entropy of a dataset
double calculate_entropy(int *array, int size) {
    int freq[100] = {0};
    double entropy = 0.0;

    // Count frequencies of each element
    for (int i = 0; i < size; i++) {
        freq[array[i]]++;
    }

    // Calculate entropy
    for (int i = 0; i < 100; i++) {
        if (freq[i] > 0) {
            double probability = (double)freq[i] / size;
            entropy -= probability * log2(probability);
        }
    }

    return entropy;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function implementing a modified bubble sort based on entropy
void entropy_based_sort(int *array, int size) {
    int i, j;
    double initial_entropy = calculate_entropy(array, size);
    printf("Initial Entropy: %.4f\n", initial_entropy);

    // Sorting process
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    double final_entropy = calculate_entropy(array, size);
    printf("Final Entropy: %.4f\n", final_entropy);
}

// Function to print the array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Driver function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int size;

    printf("Enter the number of elements to sort (max 100): ");
    scanf("%d", &size);
    if(size > 100 || size <= 0) {
        printf("Invalid size. Please enter a number between 1 and 100.\n");
        return 1;
    }

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill the array with random numbers
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Original Array:\n");
    print_array(array, size);

    // Perform sorting
    entropy_based_sort(array, size);

    printf("Sorted Array:\n");
    print_array(array, size);

    // Free allocated memory
    free(array);
    return 0;
}