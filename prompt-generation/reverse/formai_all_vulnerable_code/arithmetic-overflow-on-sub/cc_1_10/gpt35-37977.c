//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int board[3][3]; // Tic Tac Toe board

void initialize_board() // Function to initialize the board
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

void print_board() // Function to print the board
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("  ");
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" ");
            }
            else if (board[i][j] == 1)
            {
                printf("X");
            }
            else
            {
                printf("O");
            }

            if (j != 2)
            {
               printf(" | ");
            }
        }
        printf("\n");
        if (i != 2)
        {
            printf("  ---------\n");
        }
    }
    printf("\n");
}

int check_win(int player) // Function to check if a player has won
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
        else if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

void computer_turn() // Function for computer's turn
{
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != 0);

    board[row][col] = 2;
}

int main()
{
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X. The computer is O.\n");
    printf("You go first.\n");

    initialize_board(); // Initialize the board

    print_board(); // Print the initial board

    int player_turn = 1; // Player goes first

    while (1) // Main game loop
    {
        if (player_turn) // Player's turn
        {
            int row, col;
            printf("Enter the row and column (1-3) where you want to place your X:\n");
            scanf("%d %d", &row, &col);
            row--;
            col--;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != 0)
            {
                printf("Invalid move, try again.\n");
                continue;
            }

            board[row][col] = 1;

            if (check_win(1))
            {
                printf("Congratulations, you win!\n");
                print_board();
                break;
            }

            player_turn = 0;
        }
        else // Computer's turn
        {
            printf("Computer's turn:\n");

            computer_turn();

            if (check_win(2))
            {
                printf("Sorry, you lose.\n");
                print_board();
                break;
            }

            player_turn = 1;
        }

        print_board();
    }

    return 0;
}