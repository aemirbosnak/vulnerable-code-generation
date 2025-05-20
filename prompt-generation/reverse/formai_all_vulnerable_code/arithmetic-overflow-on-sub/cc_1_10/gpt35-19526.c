//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ROWS 3
#define COLS 3
#define MAX_MOVE 9
#define BUFFER_SIZE 50

typedef struct {
    int row;
    int col;
} Move;

// Initializes an empty game board
void init_board(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Prints the current state of the game board
void print_board(char board[ROWS][COLS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        printf("\t\t\t\t\t  %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if(i != ROWS-1) {
            printf("\t\t\t\t\t ---|---|---\n");
        }
    }
}

// Checks if the game board is fully occupied
int is_board_full(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Checks if the specified row is fully occupied by the given character
int is_row_full(char board[ROWS][COLS], int row, char ch) {
    for(int j=0; j<COLS; j++) {
        if(board[row][j] != ch) {
            return 0;
        }
    }
    return 1;
}

// Checks if the specified column is fully occupied by the given character
int is_col_full(char board[ROWS][COLS], int col, char ch) {
    for(int i=0; i<ROWS; i++) {
        if(board[i][col] != ch) {
            return 0;
        }
    }
    return 1;
}

// Checks if any of the diagonals are fully occupied by the given character
int is_any_diag_full(char board[ROWS][COLS], char ch) {
    if(board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) {
        return 1;
    }
    if(board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) {
        return 1;
    }
    return 0;
}

// Checks if the player with the specified character has won the game
int has_won(char board[ROWS][COLS], char ch) {
    for(int i=0; i<ROWS; i++) {
        if(is_row_full(board, i, ch)) {
            return 1;
        }
    }
    for(int j=0; j<COLS; j++) {
        if(is_col_full(board, j, ch)) {
            return 1;
        }
    }
    if(is_any_diag_full(board, ch)) {
        return 1;
    }
    return 0;
}

// Generates a random move for the computer
Move generate_computer_move(char board[ROWS][COLS]) {
    Move move;

    do {
        move.row = rand() % ROWS;
        move.col = rand() % COLS;
    } while(board[move.row][move.col] != ' ');

    return move;
}

// Gets the move entered by the player
Move get_player_move(char board[ROWS][COLS]) {
    char input[BUFFER_SIZE], ch;
    int row, col;

    do {
        printf("\n\t\t\t\t\tEnter your move (row,column): ");
        fgets(input, BUFFER_SIZE, stdin);
        sscanf(input, "%d,%d%c", &row, &col, &ch);
        row--;
        col--;
    } while(row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ');

    Move move;
    move.row = row;
    move.col = col;
    return move;
}

int main() {
    char board[ROWS][COLS];
    Move move;
    int player_turn = 1;

    srand(time(NULL));
    init_board(board);

    printf("\n\t\t\t\t\t  Welcome to Tic Tac Toe!\n");

    // Game loop
    while(1) {
        print_board(board);

        if(player_turn) {
            printf("\n\t\t\t\t\t    Your turn (X)\n");
            move = get_player_move(board);
            board[move.row][move.col] = 'X';
        }
        else {
            printf("\n\t\t\t\t\t   Computer's turn (O)\n");
            move = generate_computer_move(board);
            board[move.row][move.col] = 'O';
        }

        if(has_won(board, 'X')) {
            print_board(board);
            printf("\n\t\t\t\t\t     Congratulation! You won!\n");
            break;
        }
        if(has_won(board, 'O')) {
            print_board(board);
            printf("\n\t\t\t\t\t        Game over! You lost!\n");
            break;
        }
        if(is_board_full(board)) {
            print_board(board);
            printf("\n\t\t\t\t\t         Game over! It's a tie!\n");
            break;
        }

        player_turn = !player_turn;
    }

    return 0;
}