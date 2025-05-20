//FormAI DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // 4x4 board size

// Function declarations
void init_board(int board[BOARD_SIZE][BOARD_SIZE], int pairs);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int check_match(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE]; // the game board
    int pairs = BOARD_SIZE * BOARD_SIZE / 2; // number of pairs of cards
    int choices_left = pairs * 2; // number of unmatched cards left
    int score = 0; // the player's score
    int row1, col1, row2, col2; // the player's choices for each turn
    int i, j; // loop indices

    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the game board
    init_board(board, pairs);

    // Print the initial game board
    print_board(board);

    // Game loop
    while (choices_left > 0) {
        // Get the player's first choice
        printf("\nEnter the row and column of your first choice: ");
        scanf("%d %d", &row1, &col1);

        // Make sure the choice is valid
        if (row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        // Check if the card has already been matched
        if (board[row1][col1] == -1) {
            printf("That card has already been matched, please try again.\n");
            continue;
        }

        // Get the player's second choice
        printf("Enter the row and column of your second choice: ");
        scanf("%d %d", &row2, &col2);

        // Make sure the choice is valid
        if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        // Check if the card has already been matched
        if (board[row2][col2] == -1) {
            printf("That card has already been matched, please try again.\n");
            continue;
        }

        // Check if the two choices match
        if (check_match(board, row1, col1, row2, col2)) {
            printf("You found a match!\n");
            board[row1][col1] = -1;
            board[row2][col2] = -1;
            score++;
            choices_left -= 2;
        } else {
            printf("Sorry, those cards don't match.\n");
        }

        // Print the current game board
        print_board(board);
    }

    // Game over
    printf("\nGame over! You found all the matches in %d turns.\n", score);

    return 0;
}

// Initialize the game board with pairs of numbers
void init_board(int board[BOARD_SIZE][BOARD_SIZE], int pairs) {
    int i, j;
    int nums[pairs * 2];

    // Generate pairs of numbers
    for (i = 0; i < pairs; i++) {
        nums[i] = nums[i + pairs] = i + 1;
    }

    // Shuffle the numbers
    for (i = pairs * 2 - 1; i > 0; i--) {
        j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Fill the board with the shuffled numbers
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = nums[i * BOARD_SIZE + j];
        }
    }
}

// Print the current state of the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    printf("\n");

    // Print the column headers
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%3d", i + 1);
    }
    printf("\n");

    // Print the row headers and board contents
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%3d", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf("   ");
            } else {
                printf("%3d", 0); // Hide the number until it's matched
            }
        }
        printf("\n");
    }
}

// Check if the two cards at the given positions on the board match
int check_match(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}