//FormAI DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
int check_win(int revealed[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0}; // 0 represents unrevealed, 1 represents revealed
    int guesses[2][2] = {0};  // stores the row and column of the last two guesses
    int num_guesses = 0; // stores the number of guesses made so far

    initialize_board(board);
    print_board(board, revealed);

    while (!check_win(revealed))
    {
        int row, col;
        printf("Enter a row and column to reveal: ");
        scanf("%d %d", &row, &col);

        // check if the selected cell has already been revealed or is out of range
        if (revealed[row][col] == 1 || row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            printf("Invalid choice, try again.\n");
            continue;
        }

        // reveal the selected cell
        revealed[row][col] = 1;
        num_guesses++;
        guesses[num_guesses % 2][0] = row;
        guesses[num_guesses % 2][1] = col;

        print_board(board, revealed);

        // check for a match
        if (num_guesses % 2 == 0 && board[guesses[0][0]][guesses[0][1]] == board[guesses[1][0]][guesses[1][1]])
        {
            printf("Match found!\n");
        }
        else if (num_guesses % 2 == 0)
        {
            printf("No match found.\n");

            // let the player see the cells before they are hidden again
            usleep(1000000);
            revealed[guesses[0][0]][guesses[0][1]] = 0;
            revealed[guesses[1][0]][guesses[1][1]] = 0;

            print_board(board, revealed);
        }
    }

    printf("Congratulations, you won!\n");

    return 0;
}

void initialize_board(int board[ROWS][COLS])
{
    // seed the random number generator
    srand(time(NULL));

    int values[ROWS * COLS / 2];
    for (int i = 0; i < ROWS * COLS / 2; i++)
    {
        values[i] = rand() % 100; // generate a random value between 0 and 99
    }

    // shuffle the values
    for (int i = 0; i < ROWS * COLS / 2; i++)
    {
        int j = rand() % (ROWS * COLS / 2);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // distribute the values on the board
    int index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = values[index];
            index++;
        }
    }
}

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (revealed[i][j])
            {
                printf("%d\t", board[i][j]);
            }
            else
            {
                // print a random post-apocalyptic symbol to mask the value
                int symbol = rand() % 5;
                switch (symbol)
                {
                    case 0:
                        printf("°\t");
                        break;
                    case 1:
                        printf("*\t");
                        break;
                    case 2:
                        printf("!\t");
                        break;
                    case 3:
                        printf("#\t");
                        break;
                    case 4:
                        printf("+\t");
                        break;
                }
            }
        }
        printf("\n");
    }
}

int check_win(int revealed[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (revealed[i][j] == 0)
            {
                return 0; // game not over yet
            }
        }
    }

    return 1; // all cells have been revealed
}