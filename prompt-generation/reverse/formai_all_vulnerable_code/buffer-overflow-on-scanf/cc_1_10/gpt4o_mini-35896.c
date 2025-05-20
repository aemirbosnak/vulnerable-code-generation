//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>

#define SIZE 10

// A function that tells a riddle and collects the user's guess
int riddle(int* array) {
    int guess;
    printf("In a land full of numbers, one is hidden among these:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nWhat number do you seek? ");
    scanf("%d", &guess);
    return guess;
}

// A function to enact the search and give feedback
void search_and_feedback(int* array, int guess) {
    int found = -1;  // Flag to indicate the number's status (found or not)
    
    for(int i = 0; i < SIZE; i++) {
        if(array[i] == guess) {
            found = i;  // Capture the index of the found number
            break;      // Exit the loop as we found the number
        }
    }

    // Provide feedback based on the search result
    if(found != -1) {
        printf("The number %d is hidden at the index %d! 🌟\n", guess, found);
    } else {
        printf("Oh no! The number %d is not among the hidden treasures! 🏴‍☠️\n", guess);
    }
}

// A function to generate a mystical array of hidden numbers
void generate_hidden_numbers(int* array) {
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;  // Hide numbers between 0 and 99
    }
}

// The main function that orchestrates the riddle
int main() {
    int hidden_numbers[SIZE];
    srand(time(NULL));  // Seed the random number generator with current time

    generate_hidden_numbers(hidden_numbers);  // Generate numbers
    int user_guess = riddle(hidden_numbers);   // Get user's guess
    search_and_feedback(hidden_numbers, user_guess);  // Search for the guess

    return 0;  // Exit the program
}