//FormAI DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>

int main() {
    char board[8][8] = { // initial chess board setup
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    int turn = 0; // even turns are white, odd turns are black
    int gameover = 0;
    
    while (!gameover) {
        int from_row, from_col, to_row, to_col;
        printf("Enter move: ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        // TODO: validate input and check if move is legal

        board[to_row][to_col] = board[from_row][from_col];
        board[from_row][from_col] = ' ';

        // TODO: check for checkmate and stalemate conditions
        // if game is over, set gameover to 1

        // print updated chess board
        printf("\n");
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        turn++;
    }

    if (turn % 2 == 0) {
        printf("Black wins!\n");
    } else {
        printf("White wins!\n");
    }
    
    return 0;
}