//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
void shuffle_board(char board[ROWS][COLS]);
int check_win_condition(char board[ROWS][COLS]);

int main()
{
    char board[ROWS][COLS];
    int guess_count = 0;
    int first_guess_row, first_guess_col, second_guess_row, second_guess_col;

    initialize_board(board);
    shuffle_board(board);
    print_board(board);

    while (!check_win_condition(board))
    {
        printf("\nEnter two numbers to flip over the cards (e.g. 1 2 3 4): ");
        scanf("%d %d %d %d", &first_guess_row, &first_guess_col, &second_guess_row, &second_guess_col);

        if (board[first_guess_row][first_guess_col] == board[second_guess_row][second_guess_col])
        {
            printf("\nYou found a match!\n");
            board[first_guess_row][first_guess_col] = ' ';
            board[second_guess_row][second_guess_col] = ' ';
        }
        else
        {
            printf("\nSorry, those cards do not match.\n");
        }

        guess_count++;
        print_board(board);
    }

    printf("\nCongratulations, you won the game in %d turns!\n", guess_count);

    return 0;
}

void initialize_board(char board[ROWS][COLS])
{
    int i, j;
    char current_char = 'A';

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = current_char;
            current_char++;
        }
    }
}

void print_board(char board[ROWS][COLS])
{
    int i, j;

    printf("\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

void shuffle_board(char board[ROWS][COLS])
{
    srand(time(NULL));
    int i, j;
    char temp;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            int random_row = rand() % ROWS;
            int random_col = rand() % COLS;

            temp = board[random_row][random_col];
            board[random_row][random_col] = board[i][j];
            board[i][j] = temp;
        }
    }
}

int check_win_condition(char board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] != ' ')
                return 0;
        }
    }

    return 1;
}