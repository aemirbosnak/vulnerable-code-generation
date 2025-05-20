//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Define the card structure
typedef struct {
    int num;
    int revealed;
} card;

// Function to create the game board
void create_board(card board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the board with random numbers
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].num = rand() % NUM_PAIRS;
            board[i][j].revealed = 0;
        }
    }

    // Shuffle the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int r1 = rand() % BOARD_SIZE;
            int c1 = rand() % BOARD_SIZE;
            int r2 = rand() % BOARD_SIZE;
            int c2 = rand() % BOARD_SIZE;

            card temp = board[r1][c1];
            board[r1][c1] = board[r2][c2];
            board[r2][c2] = temp;
        }
    }
}

// Function to print the game board
void print_board(card board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d ", board[i][j].num);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to get the player's move
void get_move(card board[BOARD_SIZE][BOARD_SIZE], int *row, int *col) {
    printf("Enter the row and column of the card you want to reveal (e.g. 1 2): ");
    scanf("%d %d", row, col);

    // Check if the move is valid
    while (*row < 1 || *row > BOARD_SIZE || *col < 1 || *col > BOARD_SIZE || board[*row - 1][*col - 1].revealed) {
        printf("Invalid move. Please enter a valid row and column: ");
        scanf("%d %d", row, col);
    }
}

// Function to check if the game is over
int is_game_over(card board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to play the game
void play_game(card board[BOARD_SIZE][BOARD_SIZE]) {
    int flips = 0;
    int first_row, first_col, second_row, second_col;

    while (!is_game_over(board)) {
        // Get the player's first move
        get_move(board, &first_row, &first_col);
        board[first_row - 1][first_col - 1].revealed = 1;

        // Get the player's second move
        get_move(board, &second_row, &second_col);
        board[second_row - 1][second_col - 1].revealed = 1;

        // Check if the player matched a pair
        if (board[first_row - 1][first_col - 1].num == board[second_row - 1][second_col - 1].num) {
            printf("Match!\n");
            flips += 2;
        } else {
            printf("No match. Try again.\n");
            board[first_row - 1][first_col - 1].revealed = 0;
            board[second_row - 1][second_col - 1].revealed = 0;
        }

        // Print the game board
        print_board(board);
    }

    printf("Congratulations! You won the game in %d flips.\n", flips);
}

int main() {
    card board[BOARD_SIZE][BOARD_SIZE];

    // Create the game board
    create_board(board);

    // Print the game board
    print_board(board);

    // Play the game
    play_game(board);

    return 0;
}