//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>

char grid[3][3];   // the game board

void initialize_game()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid[i][j] = ' ';   // initialize all cells to empty
        }
    }
}

void display_game()
{
    int i, j;
    printf("\n");
    printf("   1   2   3\n");
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("%d|", i+1);
        for (j = 0; j < 3; j++) {
            printf(" %c |", grid[i][j]);
        }
        printf("\n");
        printf("-------------\n");
    }
}

int check_win(char symbol)
{
    int i, j;
    int win_flag = 0;
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            win_flag = 1;   // check rows
        }
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) {
            win_flag = 1;   // check columns
        }
    }
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        win_flag = 1;   // check diagonals
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        win_flag = 1;   // check diagonals
    }
    return win_flag;
}

int is_draw()
{
    int i, j;
    int draw_flag = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                // if there is an empty cell, the game is not a draw
                draw_flag = 0;
            }
        }
    }
    return draw_flag;
}

int main()
{
    int player = 1;
    int row, col;
    char mark;
    initialize_game();
    do {
        display_game();
        if (player % 2 == 1) {
            printf("\nPlayer 1, enter row and column: ");
            mark = 'X';
        } else {
            printf("\nPlayer 2, enter row and column: ");
            mark = 'O';
        }
        scanf("%d%d", &row, &col);
        if (grid[row-1][col-1] == ' ') {
            grid[row-1][col-1] = mark;
            player++;
        } else {
            printf("\nInvalid move, try again!\n");
        }
    } while (!check_win('X') && !check_win('O') && !is_draw());
    display_game();
    if (check_win('X')) {
        printf("\nPlayer 1 wins!\n");
    } else if (check_win('O')) {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nThe game is a draw!\n");
    }
    return 0;
}