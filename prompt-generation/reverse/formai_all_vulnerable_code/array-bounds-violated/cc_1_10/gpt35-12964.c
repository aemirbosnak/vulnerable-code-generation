//FormAI DATASET v1.0 Category: Chess engine ; Style: random
#include <stdio.h>
#include <stdlib.h>

//Define the chess board with a 2D matrix
int board[8][8] = {
    {-1, -2, -3, -4, -5, -3, -2, -1},
    {-6, -6, -6, -6, -6, -6, -6, -6},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {6, 6, 6, 6, 6, 6, 6, 6},
    {1, 2, 3, 4, 5, 3, 2, 1}
};

//Define a function to print the board
void print_board() {
    printf("\n\n   A  B  C  D  E  F  G  H \n");
    printf("  -------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == -1) {
                printf(" bR");
            } else if (board[i][j] == -2) {
                printf(" bN");
            } else if (board[i][j] == -3) {
                printf(" bB");
            } else if (board[i][j] == -4) {
                printf(" bQ");
            } else if (board[i][j] == -5) {
                printf(" bK");
            } else if (board[i][j] == -6) {
                printf(" bp");
            } else if (board[i][j] == 1) {
                printf(" wR");
            } else if (board[i][j] == 2) {
                printf(" wN");
            } else if (board[i][j] == 3) {
                printf(" wB");
            } else if (board[i][j] == 4) {
                printf(" wQ");
            } else if (board[i][j] == 5) {
                printf(" wK");
            } else if (board[i][j] == 6) {
                printf(" wp");
            } else {
                printf("   ");
            }
        }
        printf(" | %d\n", i+1);
    }
    printf("  -------------------------\n");
    printf("   A  B  C  D  E  F  G  H \n\n");
}

//Define a function to move a piece
void move_piece() {
    char start_pos[2];
    char end_pos[2];
    printf("Enter the starting position of the piece to move (e.g. A2): ");
    scanf("%s", start_pos);
    printf("Enter the end position of the piece to move (e.g. A4): ");
    scanf("%s", end_pos);
    
    int start_row = start_pos[1] - '1';
    int start_col = start_pos[0] - 'A';
    int end_row = end_pos[1] - '1';
    int end_col = end_pos[0] - 'A';
    
    if (board[start_row][start_col] == 0) {
        printf("Error: There is no piece at that position!\n");
    } else if (board[end_row][end_col] != 0) {
        printf("Error: There is already a piece at that position!\n");
    } else {
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = 0;
    }
}

int main() {
    print_board();
    move_piece();
    print_board();
    
    return 0;
}