//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 10

void generate_number(int *num);
void print_table(int board[ROWS][COLS]);
int check_win(int board[ROWS][COLS], int guess);
int check_validity(int guess);

int main(void)
{
    int board[ROWS][COLS], guess;
    int row = 0, col = 0, win = 0;
    srand(time(NULL));

    while (!win)
    {
        generate_number(&board[row][col]);
        print_table(board);
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (check_validity(guess))
        {
            if (check_win(board, guess))
            {
                printf("Congratulations, you guessed the number correctly!\n");
                win = 1;
            }
            else
            {
                printf("Sorry, that's not the correct number. Try again.\n");
            }
        }
        else
        {
            printf("Invalid input. Please enter a number between %d and %d.\n", MIN_NUM, MAX_NUM);
        }

        if (row >= ROWS || col >= COLS)
        {
            printf("Game over. You have reached the end of the board. Try again.\n");
            row = 0;
            col = 0;
        }
        else if (guess == board[row][col])
        {
            printf("Congratulations, you guessed the number correctly and are on the right spot!\n");
            win = 1;
        }
        else
        {
            row++;
            col = 0;
        }
    }

    return EXIT_SUCCESS;
}

void generate_number(int *num)
{
    *num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
}

void print_table(int board[ROWS][COLS])
{
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == ROWS - 1 && j == COLS - 1)
            {
                printf("%d ", board[i][j]);
                continue;
            }

            printf("%2d  ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[ROWS][COLS], int guess)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == guess)
            {
                return 1;
            }
        }
    }

    return 0;
}

int check_validity(int guess)
{
    if (guess >= MIN_NUM && guess <= MAX_NUM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}