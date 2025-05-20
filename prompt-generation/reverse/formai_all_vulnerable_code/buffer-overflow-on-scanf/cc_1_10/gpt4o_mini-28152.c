//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void add_number(int **arr, int *current_size, int *next_index, int number) {
    // Check if the current index exceeds the allocated size
    if (*next_index >= *current_size) {
        // Double the size of the array
        *current_size *= 2;
        // Reallocate the array to the new size
        int *temp = realloc(*arr, (*current_size) * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            exit(1); // Exit if memory reallocation fails
        }
        *arr = temp; // Update the array pointer
    }
    // Store the new number and increment the index
    (*arr)[*next_index] = number;
    (*next_index)++;
}

void print_numbers(int *arr, int size) {
    printf("You have entered the following numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int initial_size = 4; // Start with space for 4 numbers
    int *numbers = malloc(initial_size * sizeof(int));
    if (numbers == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1; // Exit if initial allocation fails
    }
    
    int current_size = initial_size; // Current allocated size
    int next_index = 0; // Number of elements added

    printf("Enter integers (enter -1 to stop):\n");

    while (1) {
        int number;
        scanf("%d", &number);
        
        if (number == -1) {
            break; // Exit loop on sentinel value
        }
        
        add_number(&numbers, &current_size, &next_index, number);
    }

    print_numbers(numbers, next_index);

    // Free the allocated memory when done
    free(numbers);
    return 0;
}