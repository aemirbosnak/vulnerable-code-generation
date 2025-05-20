//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
int turn = 0;

// This function displays the current state of the tic-tac-toe board
void display_board()
{
    printf("\n-------Tic Tac Toe-------\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

// This function checks if the game has ended with a winner or a draw
int check_game_end()
{
    int i, j;

    // Check rows for a winner
    for(i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] == 'X')
                return 1;
            else if(board[i][0] == 'O')
                return 2;
        }
    }

    // Check columns for a winner
    for(i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] == 'X')
                return 1;
            else if(board[0][i] == 'O')
                return 2;
        }
    }

    // Check diagonals for a winner
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == 'X')
            return 1;
        else if(board[0][0] == 'O')
            return 2;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if(board[0][2] == 'X')
            return 1;
        else if(board[0][2] == 'O')
            return 2;
    }

    // Check for a draw
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
                return 0;
        }
    }

    return 3; // Draw
}

// This function allows the AI to make its move
void ai_turn()
{
    int i, j;

    printf("\nAI thinking...\n");

    // Check rows for a potential win
    for(i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] != ' ' && board[i][2] == ' ')
        {
            board[i][2] = 'O';
            return;
        }
        else if(board[i][0] == board[i][2] && board[i][0] != ' ' && board[i][1] == ' ')
        {
            board[i][1] = 'O';
            return;
        }
        else if(board[i][1] == board[i][2] && board[i][1] != ' ' && board[i][0] == ' ')
        {
            board[i][0] = 'O';
            return;
        }
    }

    // Check columns for a potential win
    for(i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] != ' ' && board[2][i] == ' ')
        {
            board[2][i] = 'O';
            return;
        }
        else if(board[0][i] == board[2][i] && board[0][i] != ' ' && board[1][i] == ' ')
        {
            board[1][i] = 'O';
            return;
        }
        else if(board[1][i] == board[2][i] && board[1][i] != ' ' && board[0][i] == ' ')
        {
            board[0][i] = 'O';
            return;
        }
    }

    // Check diagonals for a potential win
    if(board[0][0] == board[1][1] && board[0][0] != ' ' && board[2][2] == ' ')
    {
        board[2][2] = 'O';
        return;
    }
    else if(board[0][0] == board[2][2] && board[0][0] != ' ' && board[1][1] == ' ')
    {
        board[1][1] = 'O';
        return;
    }
    else if(board[1][1] == board[2][2] && board[1][1] != ' ' && board[0][0] == ' ')
    {
        board[0][0] = 'O';
        return;
    }

    if(board[0][2] == board[1][1] && board[0][2] != ' ' && board[2][0] == ' ')
    {
        board[2][0] = 'O';
        return;
    }
    else if(board[0][2] == board[2][0] && board[0][2] != ' ' && board[1][1] == ' ')
    {
        board[1][1] = 'O';
        return;
    }
    else if(board[1][1] == board[2][0] && board[1][1] != ' ' && board[0][2] == ' ')
    {
        board[0][2] = 'O';
        return;
    }

    // If there are no potential wins, make a random move
    while(1)
    {
        i = rand() % 3;
        j = rand() % 3;

        if(board[i][j] == ' ')
        {
            board[i][j] = 'O';
            break;
        }
    }

    return;
}

int main()
{
    int i, j, x, y, end_state;

    printf("\n-------Tic Tac Toe with AI-------\n\n");

    // Initialize the board to all spaces
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Randomly determine who goes first
    turn = rand() % 2 + 1;

    while(1)
    {
        display_board();

        // Player's turn
        if(turn == 1)
        {
            printf("Player 1 (X), enter your move: ");
            scanf("%d %d", &x, &y);

            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = 'X';
                turn = 2;
            }
            else
            {
                printf("Invalid move! Try again.\n");
            }
        }

        // AI's turn
        else
        {
            ai_turn();
            turn = 1;
        }

        // Check if the game has ended
        end_state = check_game_end();

        if(end_state == 1)
        {
            printf("\nPlayer 1 (X) wins!\n");
            display_board();
            break;
        }
        else if(end_state == 2)
        {
            printf("\nAI (O) wins!\n");
            display_board();
            break;
        }
        else if(end_state == 3)
        {
            printf("\nDraw!\n");
            display_board();
            break;
        }
    }

    return 0;
}