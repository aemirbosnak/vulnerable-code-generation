//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define game board size
#define ROWS 5
#define COLS 5

// Define player starting position
#define START_ROW 0
#define START_COL 0

// Define enemy starting position
#define ENEMY_ROW 4
#define ENEMY_COL 4

// Define maximum number of moves allowed
#define MAX_MOVES 10

int main()
{
    int row = START_ROW;
    int col = START_COL;
    int enemy_row = ENEMY_ROW;
    int enemy_col = ENEMY_COL;
    int moves_left = MAX_MOVES;

    // Initialize the game board
    char game_board[ROWS][COLS] = {
        {'S', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', 'E'}
    };

    srand(time(NULL)); // Initialize the random seed

    printf("Welcome to the Terminal Maze Game!\n");
    printf("You are the 'S' on the board, and you need to reach the 'E'.\n");
    printf("Beware of the enemy 'X' - if you meet, you lose!\n");
    printf("You have %d moves left. Good luck!\n", moves_left);

    // Main game loop
    while (moves_left > 0 && (row != enemy_row || col != enemy_col))
    {
        // Print the game board
        printf("\n");
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%c ", game_board[i][j]);
            }
            printf("\n");
        }

        // Get user input for direction to move
        char direction;
        printf("\nEnter direction to move (W/A/S/D): ");
        scanf(" %c", &direction);

        // Move player in selected direction
        switch (direction)
        {
            case 'W':
                if (row > 0) row--;
                break;
            case 'A':
                if (col > 0) col--;
                break;
            case 'S':
                if (row < ROWS - 1) row++;
                break;
            case 'D':
                if (col < COLS - 1) col++;
                break;
            default:
                printf("Invalid direction. Try again!\n");
                continue;
        }

        // Check if the player has won
        if (row == ENEMY_ROW && col == ENEMY_COL)
        {
            printf("\nYou have met the enemy 'X' and lost the game!\n");
            continue;
        }
        else if (row == ROWS - 1 && col == COLS - 1)
        {
            printf("\nCongratulations! You have reached the 'E' and won the game!\n");
            break;
        }

        // Move the enemy randomly
        int num = rand() % 4;
        switch (num)
        {
            case 0:
                if (enemy_row > 0) enemy_row--;
                break;
            case 1:
                if (enemy_col > 0) enemy_col--;
                break;
            case 2:
                if (enemy_row < ROWS - 1) enemy_row++;
                break;
            case 3:
                if (enemy_col < COLS - 1) enemy_col++;
                break;
            default:
                break;
        }

        // Check if the enemy has met the player
        if (row == enemy_row && col == enemy_col)
        {
            printf("\nYou have met the enemy 'X' and lost the game!\n");
            break;
        }

        // Reduce the number of moves left
        moves_left--;
        printf("\nYou have %d moves left.\n", moves_left);
    }

    printf("Thanks for playing the Terminal Maze Game!\n");

    return 0;
}