//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to generate an array of random numbers
void generate_numbers(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Numbers between 0 and 99
    }
}

// Recursive function to find the guessed number
int search_number(int arr[], int size, int guess, int index) {
    // Base case: If index exceeds the size of array
    if (index >= size) {
        return -1; // Indicate number is not found
    }
    // Check if the current element matches the guess
    if (arr[index] == guess) {
        return index; // Return the index of the found number
    }
    // Recursive case: check the next index
    return search_number(arr, size, guess, index + 1);
}

// Function to display the array
void display_array(int arr[], int size) {
    printf("The generated numbers are: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int numbers[SIZE];
    int guess, found_index;

    // Seed the random number generator
    srand(time(NULL));
    
    // Generate random numbers and display them
    generate_numbers(numbers, SIZE);
    display_array(numbers, SIZE);

    // Prompt the user for a number to guess
    printf("Enter a number to search in the array (0-99): ");
    scanf("%d", &guess);
    
    // Call recursive function to search for the number
    found_index = search_number(numbers, SIZE, guess, 0);

    // Provide feedback to the user based on the search result
    if (found_index != -1) {
        printf("The number %d was found at index %d.\n", guess, found_index);
    } else {
        printf("The number %d was not found in the array.\n", guess);
    }

    return 0;
}