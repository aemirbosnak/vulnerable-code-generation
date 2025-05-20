//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_PAIRS 8

// Function to shuffle the array
void shuffle(int *array, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        j = rand() % size;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to print the game board
void print_board(int *board, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i * size + j] == 0) {
                printf("  ");
            } else {
                printf("%d ", board[i * size + j]);
            }
        }
        printf("\n");
    }
}

// Function to get the player's input
void get_input(int *board, int size, int *first_choice, int *second_choice) {
    int row1, col1, row2, col2;
    printf("Enter the row and column of the first card: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second card: ");
    scanf("%d %d", &row2, &col2);
    *first_choice = board[row1 * size + col1];
    *second_choice = board[row2 * size + col2];
}

// Function to check if the player's guess is correct
int check_guess(int first_choice, int second_choice) {
    return first_choice == second_choice;
}

// Function to play the game
void play_game(int *board, int size) {
    int first_choice, second_choice;
    int num_guesses = 0;
    int num_correct = 0;

    // Shuffle the board
    shuffle(board, size * size);

    // Print the board
    print_board(board, size);

    // Get the player's input
    while (num_correct < NUM_PAIRS) {
        get_input(board, size, &first_choice, &second_choice);

        // Check if the player's guess is correct
        if (check_guess(first_choice, second_choice)) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect!\n");
        }

        // Print the board
        print_board(board, size);

        // Increment the number of guesses
        num_guesses++;
    }

    // Print the final score
    printf("You won in %d guesses!\n", num_guesses);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board
    int board[SIZE * SIZE];
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i * SIZE + j] = 0;
        }
    }

    // Place the pairs of cards on the board
    int pairs[NUM_PAIRS] = {1, 1, 2, 2, 3, 3, 4, 4};
    int index = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (index < NUM_PAIRS) {
                board[i * SIZE + j] = pairs[index];
                index++;
            }
        }
    }

    // Play the game
    play_game(board, SIZE);

    return 0;
}