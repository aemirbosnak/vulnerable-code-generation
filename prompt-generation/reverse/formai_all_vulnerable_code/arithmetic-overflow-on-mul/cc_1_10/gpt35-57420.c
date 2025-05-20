//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void display_board(char board[ROWS][COLS], int row, int col) {
    int i, j;
    printf("  ");
    for (i = 0; i < col; i++) {
        printf("%2d", i);
    }
    printf("\n");
    for (i = 0; i < row; i++) {
        printf("%2d ", i);
        for (j = 0; j < col; j++) {
            printf("%2c", board[i][j]);
        }
        printf("\n");
    }
}

int count_mines(char board[ROWS][COLS], int row, int col, int x, int y) {
    int count = 0, i, j;
    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < row && j >= 0 && j < col && board[i][j] == '*') {
                count++;
            }
        }
    }
    return count;
}

void expand_board(char mines[ROWS][COLS], char show_board[ROWS][COLS], int row, int col, int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return;  // out of boundary
    }
    if (show_board[x][y] != '-') {
        return;  // already revealed
    }
    int count = count_mines(mines, row, col, x, y);
    if (count) {
        show_board[x][y] = count + '0';
        return;  // terminate
    }
    show_board[x][y] = ' ';
    expand_board(mines, show_board, row, col, x-1, y-1);
    expand_board(mines, show_board, row, col, x-1, y);
    expand_board(mines, show_board, row, col, x-1, y+1);
    expand_board(mines, show_board, row, col, x, y-1);
    expand_board(mines, show_board, row, col, x, y+1);
    expand_board(mines, show_board, row, col, x+1, y-1);
    expand_board(mines, show_board, row, col, x+1, y);
    expand_board(mines, show_board, row, col, x+1, y+1);    
}

int main() {
    char mines[ROWS][COLS], show_board[ROWS][COLS];
    int row, col, mines_num, i, j;
    int x, y, safe_cells;
    printf("Enter the size of the board (row col): ");
    scanf("%d %d", &row, &col);
    printf("Enter the number of mines: ");
    scanf("%d", &mines_num);
    if (mines_num >= row*col) {
        printf("Too many mines!\n");
        exit(0);
    }
    // initialize the blank board and the mines
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            mines[i][j] = '.';
            show_board[i][j] = '-';
        }
    }
    // plant mines
    srand(time(NULL)); // seed random number
    for (i = 0; i < mines_num; i++) {
        x = rand() % row; 
        y = rand() % col;
        if (mines[x][y] == '*') { // already a mine
            i--; // try again
        } else {
            mines[x][y] = '*';
        }
    }
    safe_cells = row*col - mines_num;
    do {
        display_board(show_board, row, col);
        printf("Enter a cell (row col): ");
        scanf("%d %d", &x, &y);
        if (mines[x][y] == '*') {
            printf("Explosion! Game over.\n");
            break;
        } else {
            expand_board(mines, show_board, row, col, x, y);
            safe_cells--;
        }
    } while (safe_cells > 0);
    if (safe_cells == 0) {
        printf("Congratulations! You've won the game!\n");
    }
    printf("Game over.\n");
    return 0;
}