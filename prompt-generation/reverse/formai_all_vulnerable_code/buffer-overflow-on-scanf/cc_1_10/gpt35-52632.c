//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 5
#define COLS 5
#define MAX_PLAYERS 4

// Function prototypes
void print_board(int board[][COLS]);
void generate_numbers(int numbers[]);
int get_random_number(int numbers[]);
void mark_board(int board[][COLS], int num);
int detect_winner(int board[][COLS]);

// Main function
int main()
{
    int board[ROWS][COLS], numbers[75], player_scores[MAX_PLAYERS] = {0};
    int num_players, winner = -1, round_num = 0, i, j;
    srand(time(NULL)); // Initialize random number generator with current time

    printf("Welcome to Bingo Simulator!\n");
    printf("How many players (2-%d)? ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Validate number of players
    if (num_players < 2 || num_players > MAX_PLAYERS)
    {
        printf("Invalid number of players.\n");
        return 1;
    }

    // Initialize board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = 0;
        }
    }

    // Generate random numbers
    generate_numbers(numbers);

    // Game loop
    while (winner == -1)
    {
        int player, num;

        // Increment round number
        round_num++;

        printf("\nRound %d:\n", round_num);

        // Generate random number
        num = get_random_number(numbers);

        printf("Next number is: %d\n", num);

        // Mark board
        mark_board(board, num);

        // Print board for each player
        for (player = 1; player <= num_players; player++)
        {
            printf("\nPlayer %d's board:\n", player);
            print_board(board);
        }

        // Detect winner
        winner = detect_winner(board);

        // Add score to winning player
        if (winner != -1)
        {
            printf("Player %d wins!\n", winner);
            player_scores[winner - 1] += 10;
        }
    }

    // Print final scores
    printf("\nFinal scores:\n");
    for (i = 0; i < num_players; i++)
    {
        printf("Player %d: %d points\n", i + 1, player_scores[i]);
    }

    return 0;
}

// Function to print board
void print_board(int board[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate random numbers
void generate_numbers(int numbers[])
{
    int i;

    for (i = 0; i < 75; i++)
    {
        numbers[i] = i + 1;
    }
}

// Function to get random number from array
int get_random_number(int numbers[])
{
    int index = rand() % 75;
    int num = numbers[index];

    // Remove number from array
    numbers[index] = numbers[74];

    return num;
}

// Function to mark board with number
void mark_board(int board[][COLS], int num)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == num)
            {
                board[i][j] = -num; // Mark number as negative
            }
        }
    }
}

// Function to detect winner
int detect_winner(int board[][COLS])
{
    int i, j, player;

    // Check rows
    for (i = 0; i < ROWS; i++)
    {
        for (player = 1; player <= MAX_PLAYERS; player++)
        {
            int count = 0;
            for (j = 0; j < COLS; j++)
            {
                if (board[i][j] < 0 && -board[i][j] == player)
                {
                    count++;
                }
            }
            if (count == COLS)
            {
                return player;
            }
        }
    }

    // Check columns
    for (j = 0; j < COLS; j++)
    {
        for (player = 1; player <= MAX_PLAYERS; player++)
        {
            int count = 0;
            for (i = 0; i < ROWS; i++)
            {
                if (board[i][j] < 0 && -board[i][j] == player)
                {
                    count++;
                }
            }
            if (count == ROWS)
            {
                return player;
            }
        }
    }

    // Check diagonals
    for (player = 1; player <= MAX_PLAYERS; player++)
    {
        int count = 0;
        for (i = 0, j = 0; i < ROWS && j < COLS; i++, j++)
        {
            if (board[i][j] < 0 && -board[i][j] == player)
            {
                count++;
            }
        }
        if (count == ROWS)
        {
            return player;
        }
    }
    for (player = 1; player <= MAX_PLAYERS; player++)
    {
        int count = 0;
        for (i = 0, j = COLS - 1; i < ROWS && j >= 0; i++, j--)
        {
            if (board[i][j] < 0 && -board[i][j] == player)
            {
                count++;
            }
        }
        if (count == ROWS)
        {
            return player;
        }
    }

    return -1;
}