//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// function prototypes
void print_board(char board[][COLS]);
bool is_valid_move(char board[][COLS], int row, int col);
bool is_board_full(char board[][COLS]);
bool has_any_row(char board[][COLS], char symbol);
bool has_any_column(char board[][COLS], char symbol);
bool has_any_diagonal(char board[][COLS], char symbol);
bool has_won(char board[][COLS], char symbol);
void player_move(char board[][COLS], char symbol);
void computer_move(char board[][COLS], char symbol);

int main(void) {
    char board[ROWS][COLS] = {{'1','2','3'},
                              {'4','5','6'},
                              {'7','8','9'}};
    char player_symbol = 'X', computer_symbol = 'O';
    bool game_over = false;
    int turn_counter = 0;
    
    // seed the random number generator for the computer's move
    srand((unsigned) time(NULL));
    
    // loop until game over
    while (!game_over) {
        // print the board
        print_board(board);
        
        // get player's move and update the board
        player_move(board, player_symbol);
        turn_counter++;
        
        // check if player has won
        if (has_won(board, player_symbol)) {
            printf("Congratulations! You have won!\n");
            game_over = true;
            continue;
        }
        
        // check if board is full (tie game)
        if (is_board_full(board)) {
            printf("Tie game!\n");
            game_over = true;
            continue;
        }
        
        // get computer's move and update the board
        computer_move(board, computer_symbol);
        turn_counter++;
        
        // check if computer has won
        if (has_won(board, computer_symbol)) {
            printf("Sorry, the computer has won.\n");
            game_over = true;
            continue;
        }
        
        // check if board is full (tie game)
        if (is_board_full(board)) {
            printf("Tie game!\n");
            game_over = true;
            continue;
        }
    }
    
    // print the final board
    print_board(board);
    
    return 0;
}

// prints the tic-tac-toe board
void print_board(char board[][COLS]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// checks if a move is valid
bool is_valid_move(char board[][COLS], int row, int col) {
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

// checks if the board is full
bool is_board_full(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// checks if any row has all symbols matching
bool has_any_row(char board[][COLS], char symbol) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        bool match = true;
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != symbol) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

// checks if any column has all symbols matching
bool has_any_column(char board[][COLS], char symbol) {
    int i, j;
    for (i = 0; i < COLS; i++) {
        bool match = true;
        for (j = 0; j < ROWS; j++) {
            if (board[j][i] != symbol) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

// checks if any diagonal has all symbols matching
bool has_any_diagonal(char board[][COLS], char symbol) {
    bool match = true;
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i][i] != symbol) {
            match = false;
            break;
        }
    }
    if (match) {
        return true;
    }
    match = true;
    for (i = ROWS - 1; i >= 0; i--) {
        if (board[ROWS - i - 1][i] != symbol) {
            match = false;
            break;
        }
    }
    if (match) {
        return true;
    }
    return false;
}

// checks if a player has won
bool has_won(char board[][COLS], char symbol) {
    return (has_any_row(board, symbol) || has_any_column(board, symbol) || has_any_diagonal(board, symbol));
}

// prompts the player for their move and updates the board
void player_move(char board[][COLS], char symbol) {
    int row, col;
    while (true) {
        printf("Enter the row (1-3) and column (1-3) of your move: ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid input. Try again.\n");
        } else if (!is_valid_move(board, row, col)) {
            printf("That space is already occupied. Try again.\n");
        } else {
            break;
        }
    }
    board[row][col] = symbol;
}

// selects a random move for the computer and updates the board
void computer_move(char board[][COLS], char symbol) {
    printf("Computer's move:\n");
    int row, col;
    while (true) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (is_valid_move(board, row, col)) {
            break;
        }
    }
    printf("Row: %d Column: %d\n", row + 1, col + 1);
    board[row][col] = symbol;
}