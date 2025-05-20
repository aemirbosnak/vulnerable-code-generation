//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>

// Define constants for the board size and the characters used to represent X and O
#define BOARD_SIZE 3
#define X_CHAR 'X'
#define O_CHAR 'O'

// Define a 2D array to represent the board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board to be empty
void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the current state of the board
void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n- - -\n");
    }
}

// Check if the game has been won
int check_win() {
    int i, j, row_count, col_count, diag_count1, diag_count2;
    char last_char;
    
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        last_char = board[i][0];
        row_count = 0;
        for (j = 1; j < BOARD_SIZE; j++) {
            if (board[i][j] == last_char && last_char != ' ') {
                row_count++;
            }
            last_char = board[i][j];
        }
        if (row_count == BOARD_SIZE - 1) {
            return 1;
        }
    }
    
    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        last_char = board[0][j];
        col_count = 0;
        for (i = 1; i < BOARD_SIZE; i++) {
            if (board[i][j] == last_char && last_char != ' ') {
                col_count++;
            }
            last_char = board[i][j];
        }
        if (col_count == BOARD_SIZE - 1) {
            return 1;
        }
    }
    
    // Check diagonals
    diag_count1 = 0;
    last_char = board[0][0];
    for (i = 1; i < BOARD_SIZE; i++) {
        if (board[i][i] == last_char && last_char != ' ') {
            diag_count1++;
        }
        last_char = board[i][i];
    }
    if (diag_count1 == BOARD_SIZE - 1) {
        return 1;
    }
    
    diag_count2 = 0;
    last_char = board[0][BOARD_SIZE - 1];
    for (i = 1; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] == last_char && last_char != ' ') {
            diag_count2++;
        }
        last_char = board[i][BOARD_SIZE - i - 1];
    }
    if (diag_count2 == BOARD_SIZE - 1) {
        return 1;
    }
    
    return 0;
}

// Prompt the user for a row and column to make a move
void get_user_move(int *row, int *col) {
    printf("Enter a row number (1-3): ");
    scanf("%d", row);
    printf("Enter a column number (1-3): ");
    scanf("%d", col);
    *row -= 1;
    *col -= 1;
}

// AI strategy: choose a random available cell
void get_ai_move(int *row, int *col) {
    int i, j;
    do {
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
    } while (board[*row][*col] != ' ');
}

// Main function to run the Tic Tac Toe game
int main() {
    int win_flag = 0, user_turn = 1;
    int row, col;
    
    initialize_board();
    
    while (!win_flag) {
        printf("\nCurrent board state:\n");
        print_board();
        if (user_turn) {
            get_user_move(&row, &col);
            while (board[row][col] != ' ') {
                printf("This cell is already occupied. Please choose another one.\n");
                get_user_move(&row, &col);
            }
            board[row][col] = X_CHAR;
            user_turn = 0;
        } else {
            printf("\nAI's turn:\n");
            get_ai_move(&row, &col);
            board[row][col] = O_CHAR;
            user_turn = 1;
        }
        win_flag = check_win();
    }
    
    printf("\nFinal board state:\n");
    print_board();
    if (user_turn) {
        printf("The AI wins!\n");
    } else {
        printf("You win!\n");
    }
    
    return 0;
}