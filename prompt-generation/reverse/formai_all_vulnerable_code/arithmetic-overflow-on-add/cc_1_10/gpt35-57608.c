//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_MOVES 20

void print_board(char board[ROWS][COLS], int row, int col);
int get_random(int min, int max);

int main()
{
    char board[ROWS][COLS];
    int player_row, player_col;
    int moves_left = MAX_MOVES;
    int target_row = get_random(0, ROWS-1);
    int target_col = get_random(0, COLS-1);

    // initialize board and player position
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
    player_row = get_random(0, ROWS-1);
    player_col = get_random(0, COLS-1);
    board[player_row][player_col] = 'P';

    // place target
    board[target_row][target_col] = 'T';

    printf("\nWelcome to the Post-Apocalyptic Game!\n");
    printf("You are a survivor in a world destroyed by a nuclear war.\n");
    printf("Your mission is to find the target before your moves run out.\n");

    while (moves_left > 0) {
        printf("\nMoves Left: %d\n", moves_left);
        print_board(board, ROWS, COLS);

        int row_move, col_move;
        printf("Enter row move (-1, 0, 1): ");
        scanf("%d", &row_move);
        printf("Enter col move (-1, 0, 1): ");
        scanf("%d", &col_move);

        // make move
        int new_row = player_row + row_move;
        int new_col = player_col + col_move;

        if (new_row < 0 || new_row >= ROWS) {
            printf("Invalid move!\n");
        }
        else if (new_col < 0 || new_col >= COLS) {
            printf("Invalid move!\n");
        }
        else {
            board[player_row][player_col] = '.';
            player_row = new_row;
            player_col = new_col;
            moves_left--;
            if (player_row == target_row && player_col == target_col) {
                printf("\nCongratulations! You found the target and survived!\n");
                print_board(board, ROWS, COLS);
                return 0;
            }
            board[player_row][player_col] = 'P';
        }
    }

    printf("\nGame over! You ran out of moves and did not find the target.\n");
    printf("The target was at row %d and column %d.\n", target_row, target_col);
    print_board(board, ROWS, COLS);

    return 0;
}

void print_board(char board[ROWS][COLS], int row, int col)
{
    printf("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int get_random(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}