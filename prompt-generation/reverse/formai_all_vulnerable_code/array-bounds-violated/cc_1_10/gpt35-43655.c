//FormAI DATASET v1.0 Category: Checkers Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = { {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
                     {'b', '-', 'b', '-', 'b', '-', 'b', '-'},
                     {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
                     {'-', '-', '-', '-', '-', '-', '-', '-'},
                     {'-', '-', '-', '-', '-', '-', '-', '-'},
                     {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
                     {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
                     {'r', '-', 'r', '-', 'r', '-', 'r', '-'} };
                     
int turn = 0; // 0 for black's turn, 1 for red's turn

void printBoard() {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for(i = 0; i < 8; i++) {
        printf("%d ", i);
        for(j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int can_move(char piece, int from_row, int from_col, int to_row, int to_col) {
    // Implement your logic here
    return 1;
}

int move(char piece, int from_row, int from_col, int to_row, int to_col) {
    if(can_move(piece, from_row, from_col, to_row, to_col)) {
        board[to_row][to_col] = piece;
        board[from_row][from_col] = '-';
        return 1;
    } else {
        printf("Invalid move!\n");
        return 0;
    }
}

int main() {
    int from_row, from_col, to_row, to_col;
    char piece;
    while(1) {
        printBoard();
        if(turn == 0) {
            piece = 'b';
            printf("Black's turn\n");
        } else {
            piece = 'r';
            printf("Red's turn\n");
        }
        printf("Enter coordinates of piece to move: ");
        scanf("%d %d", &from_row, &from_col);
        printf("Enter coordinates to move to: ");
        scanf("%d %d", &to_row, &to_col);
        if(move(piece, from_row, from_col, to_row, to_col)) {
            turn = !turn;
        }
    }
    return 0;
}