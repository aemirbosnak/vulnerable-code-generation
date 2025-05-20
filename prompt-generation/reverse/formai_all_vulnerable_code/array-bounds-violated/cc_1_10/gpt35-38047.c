//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to display the Tic Tac Toe game board
void display(char board[])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to return the winner of the game
char check_winner(char board[])
{
    // Check for horizontal winners
    if(board[0] == board[1] && board[1] == board[2])
        return board[0];
    if(board[3] == board[4] && board[4] == board[5])
        return board[3];
    if(board[6] == board[7] && board[7] == board[8])
        return board[6];

    // Check for vertical winners
    if(board[0] == board[3] && board[3] == board[6])
        return board[0];
    if(board[1] == board[4] && board[4] == board[7])
        return board[1];
    if(board[2] == board[5] && board[5] == board[8])
        return board[2];

    // Check for diagonal winners
    if(board[0] == board[4] && board[4] == board[8])
        return board[0];
    if(board[2] == board[4] && board[4] == board[6])
        return board[2];

    return ' ';
}

// Function to check if the game board is full
int check_full(char board[])
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == ' ')
            return 0;
    }

    return 1;
}

// Function to play a move for the computer
void play_move(char board[], char computer, char player)
{
    int i;

    // If any move can win, take that move
    for(i = 0; i < 9; i++)
    {
        if(board[i] == ' ')
        {
            board[i] = computer;

            if(check_winner(board) == computer)
            {
                return;
            }
            else
            {
                board[i] = ' ';
            }
        }
    }

    // If any move can make the player lose, block that move
    for(i = 0; i < 9; i++)
    {
        if(board[i] == ' ')
        {
            board[i] = player;

            if(check_winner(board) == player)
            {
                board[i] = computer;
                return;
            }
            else
            {
                board[i] = ' ';
            }
        }
    }

    // Take any corner spot
    if(board[0] == ' ')
    {
        board[0] = computer;
        return;
    }

    if(board[2] == ' ')
    {
        board[2] = computer;
        return;
    }

    if(board[6] == ' ')
    {
        board[6] = computer;
        return;
    }

    if(board[8] == ' ')
    {
        board[8] = computer;
        return;
    }

    // Take the center spot
    if(board[4] == ' ')
    {
        board[4] = computer;
        return;
    }

    // Take any edge spot
    if(board[1] == ' ')
    {
        board[1] = computer;
        return;
    }

    if(board[3] == ' ')
    {
        board[3] = computer;
        return;
    }

    if(board[5] == ' ')
    {
        board[5] = computer;
        return;
    }

    if(board[7] == ' ')
    {
        board[7] = computer;
        return;
    }
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player, computer, winner;

    // Ask the player for their choice of symbol
    printf("Choose X or O: ");
    scanf("%c", &player);
    getchar();

    // Set the computer symbol
    if(player == 'X')
        computer = 'O';
    else
        computer = 'X';

    while(1)
    {
        // Display the game board
        display(board);

        // Ask the player for their move
        int player_move;
        printf("Enter a number (1-9) for your move: ");
        scanf("%d", &player_move);
        getchar();

        if(board[player_move-1] != ' ')
        {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[player_move-1] = player;

        // Check if the game has been won or tied
        winner = check_winner(board);

        if(winner != ' ')
        {
            display(board);
            printf("Congratulations, %c has won!\n", winner);
            break;
        }

        if(check_full(board))
        {
            display(board);
            printf("Tie game.\n");
            break;
        }

        // Play a move for the computer
        play_move(board, computer, player);

        // Check if the game has been won or tied
        winner = check_winner(board);

        if(winner != ' ')
        {
            display(board);
            printf("Sorry, %c has won.\n", winner);
            break;
        }

        if(check_full(board))
        {
            display(board);
            printf("Tie game.\n");
            break;
        }
    }

    return 0;
}