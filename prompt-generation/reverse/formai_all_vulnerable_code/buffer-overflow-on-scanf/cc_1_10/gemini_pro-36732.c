//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Struct to represent a card
typedef struct {
    int value;
    int is_flipped;
} Card;

// Function to initialize the game board
void init_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the board with random values
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10;
            board[i][j].is_flipped = 0;
        }
    }
}

// Function to print the game board
void print_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_flipped == 0) {
                printf(" [ ]");
            } else {
                printf(" [%d]", board[i][j].value);
            }
        }
        printf("\n");
    }
}

// Function to get the user's input
void get_input(int *row, int *col) {
    printf("Enter the row and column of the card you want to flip (e.g. 0 0): ");
    scanf("%d %d", row, col);
}

// Function to check if the game is over
int is_game_over(Card board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_flipped == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game board
    Card board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);

    // Print the initial game board
    print_board(board);

    // Main game loop
    while (!is_game_over(board)) {
        // Get the user's input
        int row, col;
        get_input(&row, &col);

        // Check if the input is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid input. Please enter a row and column between 0 and %d.\n", BOARD_SIZE - 1);
            continue;
        }

        // Flip the card
        board[row][col].is_flipped = 1;

        // Print the updated game board
        print_board(board);

        // Check if the user has matched two cards
        int found_match = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[row][col].value == board[i][j].value && (row != i || col != j)) {
                    found_match = 1;
                    break;
                }
            }
        }

        // If the user has matched two cards, remove them from the board
        if (found_match) {
            board[row][col].value = -1;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[row][col].value == board[i][j].value && (row != i || col != j)) {
                        board[i][j].value = -1;
                    }
                }
            }

            printf("You found a match!\n");
        }
    }

    // Print the final game board
    print_board(board);

    // Congratulate the user on winning the game
    printf("Congratulations! You won the game!\n");

    return 0;
}