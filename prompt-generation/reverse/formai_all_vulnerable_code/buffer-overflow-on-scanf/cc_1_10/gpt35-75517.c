//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5
#define MAX_PLAYERS 4

void print_board(int board[][COLS]);
int check_win(int board[][COLS], int player);
int generate_number(int numbers[]);
void mark_board(int board[][COLS], int number);
int next_player(int current_player);

int main()
{
    int players[MAX_PLAYERS];
    int scores[MAX_PLAYERS];
    int board[ROWS][COLS] = {{0}};
    int numbers[ROWS * COLS] = {0};
    int current_player = 0;
    int total_players = 0;
    int number = 0;
    int winner = -1;
    int num_gen = 0;

    printf("Enter the number of players: ");
    scanf("%d", &total_players);

    if (total_players > 4)
    {
        printf("Maximum 4 players allowed. Setting to 4.\n");
        total_players = 4;
    }

    for (int i = 0; i < total_players; i++)
    {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", &players[i]);
        scores[i] = 0;
    }

    printf("Starting bingo game...\n");
    srand(time(0));

    // Generate the bingo numbers
    for (int i = 0; i < ROWS * COLS; i++)
    {
        numbers[i] = i + 1;
    }

    // Shuffle the numbers
    for (int i = 0; i < ROWS * COLS; i++)
    {
        int temp = numbers[i];
        int random_index = rand() % (ROWS * COLS);

        numbers[i] = numbers[random_index];
        numbers[random_index] = temp;
    }

    // Main game loop
    while (winner == -1)
    {
        // Output the current board
        printf("\nCurrent board:\n");
        print_board(board);

        // Generate the next number
        number = generate_number(numbers);

        // Output the next number
        printf("\nNext number is: %d\n", number);

        // Mark the board and check for a win
        mark_board(board, number);
        if (check_win(board, current_player))
        {
            winner = current_player;
        }
        else
        {
            // Move to the next player
            current_player = next_player(current_player);
        }
    }

    // Output the winner
    printf("\nCongratulations %s! You have won.\n\n", players[winner]);

    return 0;
}

// Function to print the board
void print_board(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d ", board[i][j]);
        }

        printf("\n");
    }
}

// Function to check if a player has won
int check_win(int board[][COLS], int player)
{
    // Check rows
    for (int i = 0; i < ROWS; i++)
    {
        int row_sum = 0;

        for (int j = 0; j < COLS; j++)
        {
            row_sum += board[i][j];
        }

        if (row_sum == COLS)
        {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++)
    {
        int col_sum = 0;

        for (int j = 0; j < ROWS; j++)
        {
            col_sum += board[j][i];
        }

        if (col_sum == ROWS)
        {
            return 1;
        }
    }

    // Check diagonal from top-left to bottom-right
    int diag_sum = 0;

    for (int i = 0; i < ROWS; i++)
    {
        diag_sum += board[i][i];
    }

    if (diag_sum == ROWS)
    {
        return 1;
    }

    // Check diagonal from top-right to bottom-left
    diag_sum = 0;

    for (int i = 0; i < ROWS; i++)
    {
        diag_sum += board[i][COLS - i - 1];
    }

    if (diag_sum == ROWS)
    {
        return 1;
    }

    return 0;
}

// Function to generate the next number
int generate_number(int numbers[])
{
    static int num_index = -1;

    num_index++;

    return numbers[num_index];
}

// Function to mark the board
void mark_board(int board[][COLS], int number)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == number)
            {
                board[i][j] = 0;
            }
        }
    }
}

// Function to get the next player
int next_player(int current_player)
{
    return (current_player + 1) % MAX_PLAYERS;
}