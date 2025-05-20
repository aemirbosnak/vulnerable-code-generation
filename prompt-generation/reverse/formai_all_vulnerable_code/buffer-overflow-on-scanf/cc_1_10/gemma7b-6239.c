//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

char player_symbol = 'X';
char computer_symbol = 'O';

void display_board()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int is_board_full()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            if (board[r][c] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_win()
{
    // Horizontal wins
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != ' ')
        {
            return 1;
        }
    }

    // Vertical wins
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != ' ')
        {
            return 1;
        }
    }

    // Diagonal wins
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        return 1;
    }

    // Draw
    if (is_board_full() == 1)
    {
        return 2;
    }

    return 0;
}

void computer_move()
{
    // Randomly choose a move
    srand(time(NULL));
    int row = rand() % BOARD_SIZE;
    int column = rand() % BOARD_SIZE;

    // If the move is valid, make it
    if (board[row][column] == ' ')
    {
        board[row][column] = computer_symbol;
    }
}

int main()
{
    // Initialize the board
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            board[r][c] = ' ';
        }
    }

    // Display the board
    display_board();

    // Game loop
    while (1)
    {
        // Get the player's move
        int row = 0;
        int column = 0;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &row, &column);

        // Validate the move
        if (board[row][column] != ' ' || row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][column] = player_symbol;

        // Display the board
        display_board();

        // Check if the player has won or if the board is full
        int result = check_win();
        if (result == 1)
        {
            printf("You win!\n");
            break;
        } else if (result == 2)
        {
            printf("It's a draw.\n");
            break;
        }

        // Make the computer's move
        computer_move();

        // Display the board
        display_board();

        // Check if the computer has won or if the board is full
        result = check_win();
        if (result == 1)
        {
            printf("Computer wins!\n");
            break;
        } else if (result == 2)
        {
            printf("It's a draw.\n");
            break;
        }
    }

    return 0;
}