//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototype */
void generateBoard(int board[], int size);
void printBoard(int board[], int size);
void swap(int *a, int *b);
void shuffle(int board[], int size);
void playGame(int board[], int size);

int main() {
    const int SIZE = 16; // Board size
    int board[SIZE];

    // Generate the board
    generateBoard(board, SIZE);

    // Shuffle the board
    shuffle(board, SIZE);

    // Print the board
    printBoard(board, SIZE);

    // Play the game
    playGame(board, SIZE);

    return 0;
}

/**
 * Function - generateBoard
 * Generates a memory game board with numbers 0 - 7
 * Each number is repeated twice
 * 
 * @param board - pointer to the board array
 * @param size - size of the board
 * 
 */
void generateBoard(int board[], int size) {
    int i, j;
    for (i = 0; i < size / 2; i++) {
        board[i] = i;
        board[i + size / 2] = i;
    }
}

/**
 * Function - printBoard
 * Prints the memory game board
 * 
 * @param board - pointer to the board array
 * @param size - size of the board
 * 
 */
void printBoard(int board[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%2d ", board[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

/**
 * Function - swap
 * Swaps the values of two integers
 * 
 * @param a - pointer to the first integer
 * @param b - pointer to the second integer
 * 
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Function - shuffle
 * Shuffles the memory game board randomly
 * 
 * @param board - pointer to the board array
 * @param size - size of the board
 * 
 */
void shuffle(int board[], int size) {
    srand(time(NULL)); // Seed the random number generator
    int i, j;
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        swap(&board[i], &board[j]);
    }
}

/**
 * Function - playGame
 * Plays the memory game
 * 
 * @param board - pointer to the board array
 * @param size - size of the board
 * 
 */
void playGame(int board[], int size) {
    int guess1, guess2;
    int guesses = 0;
    int matches = 0;
    int index1, index2;
    int visible[size];

    // Set all the cards as invisible
    int i;
    for (i = 0; i < size; i++) {
        visible[i] = 0;
    }

    while (matches < size / 2) {
        // Ask the user for their first guess
        printf("Enter two card numbers (0-15): ");
        scanf("%d %d", &guess1, &guess2);

        // Check that the guesses are in range and not the same
        if (guess1 < 0 || guess1 > 15 || guess2 < 0 || guess2 > 15 || guess1 == guess2) {
            printf("Invalid guess\n");
            continue;
        }

        // Check if the cards are already visible
        if (visible[guess1] || visible[guess2]) {
            printf("Card already visible\n");
            continue;
        }

        // Get the indices of the guesses on the board
        index1 = -1;
        index2 = -1;
        for (i = 0; i < size; i++) {
            if (board[i] == guess1) {
                index1 = i;
            }
            if (board[i] == guess2) {
                index2 = i;
            }
        }

        // Check if the cards match
        if (board[index1] == board[index2]) {
            printf("Match!\n");
            visible[index1] = 1;
            visible[index2] = 1;
            matches++;
        } else {
            printf("No match\n");
        }

        // Print the current board state
        for (i = 0; i < size; i++) {
            if (visible[i]) {
                printf("%2d ", board[i]);
            } else {
                printf("X  ");
            }
            if ((i + 1) % 4 == 0) {
                printf("\n");
            }
        }
        printf("\n");

        // Increment the guess count
        guesses++;
    }

    // Print the final results
    printf("Game over!\n");
    printf("It took you %d guesses to match all the cards.\n", guesses);
}