//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void initialize_board(char board[][3]);
void print_board(char board[][3]);
int get_move(char player, char board[][3]);
char check_win(char board[][3]);

int main(void)
{
    char board[3][3];
    char player = 'X';
    char winner = '\0';
    int move_row, move_col;

    initialize_board(board);
    print_board(board);

    // game loop
    while (winner == '\0')
    {
        // get player move
        printf("Player %c's turn.\n", player);
        do
        {
            printf("Enter row (0-2): ");
            scanf("%d", &move_row);
            printf("Enter column (0-2): ");
            scanf("%d", &move_col);
            if (board[move_row][move_col] != '-')
            {
                printf("Invalid move, try again.\n");
            }
        }
        while (board[move_row][move_col] != '-');
        board[move_row][move_col] = player;

        // check for win
        winner = check_win(board);
        if (winner != '\0') break;

        // switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';

        // print board
        print_board(board);
    }

    // print winner
    if (winner == 'X' || winner == 'O')
        printf("Player %c wins!\n", winner);
    else
        printf("Tie game!\n");

    return 0;
}

void initialize_board(char board[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[][3])
{
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_move(char player, char board[][3])
{
    // TODO
}

char check_win(char board[][3])
{
    // TODO
}