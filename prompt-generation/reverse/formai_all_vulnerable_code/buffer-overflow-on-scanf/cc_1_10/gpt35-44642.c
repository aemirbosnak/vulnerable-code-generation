//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(char board[3][3]);
int valid_move(char board[3][3], int row, int col);
int check_for_win(char board[3][3], char symbol);

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1, row, col, winner = 0, moves = 0;
    char symbol = 'X';

    srand(time(NULL));  // seeding the random number generator

    printf("\nLet's play Tic Tac Toe!\n\n");
    display_board(board);

    while (winner == 0 && moves < 9)
    {
        if (player == 1)
        {
            printf("Player 1's turn (X).\n");

            printf("Enter row number (0-2): ");
            scanf("%d", &row);

            printf("Enter column number (0-2): ");
            scanf("%d", &col);
        }
        else
        {
            printf("AI's turn (O).\n");

            // Generate random row and column until a valid move is found
            do
            {
                row = rand() % 3;
                col = rand() % 3;
            } while (!valid_move(board, row, col));
        }

        // Update the board with the player's move
        board[row][col] = symbol;

        // Display the updated board
        display_board(board);

        // Check for a win or tie
        if (check_for_win(board, symbol))
        {
            if (player == 1)
            {
                printf("Congratulations! Player %d (X) won!\n", player);
            }
            else
            {
                printf("AI (O) wins! Better luck next time.\n");
            }

            winner = 1;
        }
        else if (moves == 8)
        {
            printf("It's a tie!\n");
            winner = 1;
        }

        // Switch to the other player or AI
        if (player == 1)
        {
            player = 2;
            symbol = 'O';
        }
        else
        {
            player = 1;
            symbol = 'X';
        }

        moves++;
    }

    return 0;
}

// Function to display the current state of the board
void display_board(char board[3][3])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a move is valid
int valid_move(char board[3][3], int row, int col)
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        return 0;  // out of bounds
    }
    else if (board[row][col] != ' ')
    {
        return 0;  // spot already taken
    }
    else
    {
        return 1;
    }
}

// Function to check if a player has won
int check_for_win(char board[3][3], char symbol)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return 1;
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return 1;
    }

    return 0;
}