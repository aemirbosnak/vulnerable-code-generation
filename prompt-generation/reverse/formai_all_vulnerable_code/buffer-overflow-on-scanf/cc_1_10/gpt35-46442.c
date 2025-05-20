//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>

// function to print the board
void print_board(char board[][8]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for(int row=0; row<8; row++) {
        printf("%d ", row);
        for(int col=0; col<8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if a move is valid
int is_valid_move(char current_player, char board[][8], int from_row, int from_col, int to_row, int to_col) {
    // check if the move is within the bounds of the board
    if(from_row<0 || from_row>7 || from_col<0 || from_col>7 || to_row<0 || to_row>7 || to_col<0 || to_col>7) {
        printf("Invalid move: out of bounds\n");
        return 0;
    }
    // check if the move is diagonal
    if(abs(from_row-to_row) != abs(from_col-to_col)) {
        printf("Invalid move: not diagonal\n");
        return 0;
    }
    // check if the move is only one square
    if(abs(from_row-to_row) != 1) {
        printf("Invalid move: more than one square\n");
        return 0;
    }
    // check if there is an opposing piece at the destination
    if(board[to_row][to_col] != '.' && board[to_row][to_col] != current_player) {
        printf("Invalid move: opposing piece at destination\n");
        return 0;
    }
    // all checks passed, move is valid
    return 1;
}

// function to make a move
void make_move(char board[][8], int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = '.';
}

// function to switch players
char switch_player(char current_player) {
    if(current_player == 'x') {
        return 'o';
    }
    else {
        return 'x';
    }
}

int main() {
    // initialize the board
    char board[8][8] = {{'.', 'x', '.', 'x', '.', 'x', '.', 'x'},
                        {'x', '.', 'x', '.', 'x', '.', 'x', '.'},
                        {'.', 'x', '.', 'x', '.', 'x', '.', 'x'},
                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                        {'o', '.', 'o', '.', 'o', '.', 'o', '.'},
                        {'.', 'o', '.', 'o', '.', 'o', '.', 'o'},
                        {'o', '.', 'o', '.', 'o', '.', 'o', '.'}};
    char current_player = 'x';
    // print the starting board
    print_board(board);
    // main game loop
    while(1) {
        // get user input for the move
        int from_row, from_col, to_row, to_col;
        printf("%c's turn (enter row column of piece to move and row column of destination): ", current_player);
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        // check if the move is valid
        if(is_valid_move(current_player, board, from_row, from_col, to_row, to_col)) {
            // make the move and switch players
            make_move(board, from_row, from_col, to_row, to_col);
            current_player = switch_player(current_player);
            // print the new board
            print_board(board);
        }
    }
    return 0;
}