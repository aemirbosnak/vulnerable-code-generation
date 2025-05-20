//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>

// Initializing the Board's size
#define BOARD_SIZE 8

/*
    Function to initialize the board to the starting position
    for the player's pieces
*/
void initialize_board(char board[][BOARD_SIZE]) {

    // Filling in the board with empty spaces
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if((row + col) % 2 == 0) {
                board[row][col] = ' ';
            }
            else{
                board[row][col] = '-';
            }
        }
    }

    // Positioning the player's pieces on the board
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if((row + col) % 2 == 0) {
                board[row][col] = 'O';
            }
        }
    }
}

/*
    Function to print the board on the console
*/
void print_board(char board[][BOARD_SIZE]) {

    // Printing the column indexes
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col+1);
    }
    printf("\n");

    // Printing the rows of the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        // Printing the row index
        printf("%d ", row+1);

        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }

        printf("\n");
    }
}

int main() {

    // Initializing the board with the starting position for the player's pieces
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    // Printing the current board
    printf("Starting position for the player's pieces:\n");
    print_board(board);

    // Game loop
    while(1) {

        int row, col; // Variables to store the user input

        // Getting the user's move (starting position)
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);

        // Getting the user's move (destination position)
        printf("Enter the row and column of the position where you want to move the piece: ");
        int new_row, new_col;
        scanf("%d %d", &new_row, &new_col);

        // Checking if the move is valid
        if(board[row-1][col-1] == 'O' && board[new_row-1][new_col-1] == ' ') {

            // Making the move
            board[new_row-1][new_col-1] = 'O';
            board[row-1][col-1] = ' ';

            // Printing the new board
            printf("New position after your move:\n");
            print_board(board);
        }
        else{
            printf("Invalid move. Try again!\n");
        }
    }

    return 0;
}