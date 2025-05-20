//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Memory game board size

// Function prototypes
void shuffle_array(int arr[], int n);
void initialize_board(int board[][BOARD_SIZE], int n);
void print_board(int board[][BOARD_SIZE], int n);
void play_game(int board[][BOARD_SIZE], int n);
void clear_input_buffer();

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize game board
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board, BOARD_SIZE);

    // Play the game
    play_game(board, BOARD_SIZE);

    return 0;
}

// Function to randomly shuffle an array
void shuffle_array(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() % (n - i); // Generate random index
        int temp = arr[i]; // Swap values at i and j
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to initialize the game board with pairs of numbers
void initialize_board(int board[][BOARD_SIZE], int n) {
    int pairs[n*n/2]; // Array to hold pairs of numbers
    for (int i = 0; i < n*n/2; i++) {
        pairs[2*i] = i+1; // Add pairs of numbers to array
        pairs[2*i+1] = i+1;
    }
    shuffle_array(pairs, n*n); // Shuffle the pairs

    // Fill the board with shuffled pairs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = pairs[n*i+j];
        }
    }
}

// Function to print the game board
void print_board(int board[][BOARD_SIZE], int n) {
    printf(" ");
    for (int i = 0; i < n; i++) {
        printf(" %d", i+1);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d", i+1);
        for (int j = 0; j < n; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
}

// Function to clear the input buffer
void clear_input_buffer() {
    // Read each character from the buffer until newline
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// Function to play the game
void play_game(int board[][BOARD_SIZE], int n) {
    int num_pairs = n*n/2; // Number of pairs in game
    int pairs_found = 0; // Number of pairs found so far
    int guess1_row, guess1_col, guess2_row, guess2_col; // Variables to store user guesses

    printf("\nWelcome to the Memory Game!\n");
    while (pairs_found < num_pairs) {
        print_board(board, n); // Print current game board

        // Get first guess from user
        do {
            printf("Enter row and column of first guess (separated by space): ");
        } while (scanf("%d %d", &guess1_row, &guess1_col) != 2 || guess1_row < 1 || guess1_row > n || guess1_col < 1 || guess1_col > n); // Loop until valid input provided
        clear_input_buffer();

        // Check if guess is correct
        if (board[guess1_row-1][guess1_col-1] > 0) { // Check if guess has not already been made
            board[guess1_row-1][guess1_col-1] = -board[guess1_row-1][guess1_col-1]; // Mark first guess as made
            print_board(board, n); // Print updated game board

            // Get second guess from user
            do {
                printf("Enter row and column of second guess (separated by space): ");
            } while (scanf("%d %d", &guess2_row, &guess2_col) != 2 || guess2_row < 1 || guess2_row > n || guess2_col < 1 || guess2_col > n); // Loop until valid input provided
            clear_input_buffer();

            // Check if second guess is correct
            if (board[guess2_row-1][guess2_col-1] > 0) {
                board[guess2_row-1][guess2_col-1] = -board[guess2_row-1][guess2_col-1]; // Mark second guess as made
                print_board(board, n); // Print updated game board

                // Check if guesses match
                if (board[guess1_row-1][guess1_col-1] == board[guess2_row-1][guess2_col-1]) {
                    printf("Congratulations! You found a pair!\n\n");
                    pairs_found++;
                } else {
                    printf("Sorry, those do not match.\n\n");
                    board[guess1_row-1][guess1_col-1] = -board[guess1_row-1][guess1_col-1]; // Mark both guesses as not made
                    board[guess2_row-1][guess2_col-1] = -board[guess2_row-1][guess2_col-1];
                }
            } else {
                printf("You have already guessed that one.\n\n");
            }
        } else {
            printf("You have already guessed that one.\n\n");
        }
    }
    printf("Congratulations! You found all the pairs!\n");
}