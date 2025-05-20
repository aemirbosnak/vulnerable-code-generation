//FormAI DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ROWS 4
#define COLS 4
 
void print_board(int board[][COLS], int rows) {
    int i, j;
 
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}
 
void initialize_board(int board[][COLS], int rows) {
    int i, j, num = 1;
 
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = num++;
        }
    }
}
 
void shuffle_board(int board[][COLS], int rows) {
    int i, j, temp;
 
    srand(time(NULL));
 
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            int x = rand() % rows;
            int y = rand() % COLS;
 
            temp = board[i][j];
            board[i][j] = board[x][y];
            board[x][y] = temp;
        }
    }
}
 
int main(void) {
    int board[ROWS][COLS];
    int row1, col1, row2, col2;
    int count = 0;
 
    initialize_board(board, ROWS);
    shuffle_board(board, ROWS);
 
    print_board(board, ROWS);
 
    while (1) {
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &row1, &col1);
 
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &row2, &col2);
 
        if (board[row1][col1] == board[row2][col2]) {
            printf("Match!\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            count++;
        }
        else {
            printf("No match.\n");
        }
 
        print_board(board, ROWS);
 
        if (count == ROWS * COLS / 2) {
            printf("You win!\n");
            break;
        }
    }
 
    return 0;
}