//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char player1[10], player2[10];
    int row, col, valid, num = 1, player = 1, curr_player, i, j;
    char game_board[3][3] = {'_','_','_','_','_','_','_','_','_'};
    
    srand(time(NULL));
    printf("Welcome to the C Table game!\n");
    printf("Enter the name of player 1: ");
    fgets(player1, 10, stdin);
    printf("Enter the name of player 2: ");
    fgets(player2, 10, stdin);

    // Randomly choose the starting player
    curr_player = rand() % 2 + 1;
    printf("%s goes first!\n", curr_player == 1 ? player1 : player2);

    while (num <= 9)
    {
        printf("\n");
        printf("Current board:\n\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%c ", game_board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        valid = 0;
        printf("Player %d (%s), please choose the location (e.g., row column): ", curr_player, curr_player == 1 ? player1 : player2);

        // Ensure that player enters valid input
        while (!valid)
        {
            scanf("%d %d", &row, &col);
            if (row >=0 && row < 3 && col >= 0 && col < 3 && game_board[row][col] == '_')
            {
                valid = 1;
            }
            else
            {
                printf("Invalid input, please try again: ");
            }
        }

        // Update the game board
        game_board[row][col] = curr_player == 1 ? 'X' : 'O';

        // Check if current player has won
        if (game_board[row][0] == game_board[row][1] && game_board[row][1] == game_board[row][2] && game_board[row][2] == (curr_player == 1 ? 'X' : 'O'))
        {
            printf("Player %d (%s) has won!\n", curr_player, curr_player == 1 ? player1 : player2);
            break;
        }
        else if (game_board[0][col] == game_board[1][col] && game_board[1][col] == game_board[2][col] && game_board[2][col] == (curr_player == 1 ? 'X' : 'O'))
        {
            printf("Player %d (%s) has won!\n", curr_player, curr_player == 1 ? player1 : player2);
            break;
        }
        else if ((row == col && game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2] && game_board[2][2] == (curr_player == 1 ? 'X' : 'O'))
                 || (row + col == 2 && game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0] && game_board[2][0] == (curr_player == 1 ? 'X' : 'O')))
        {
            printf("Player %d (%s) has won!\n", curr_player, curr_player == 1 ? player1 : player2);
            break;
        }

        // If nobody has won and the board is full, then it's a tie
        if (num == 9)
        {
            printf("It's a tie!\n");
            break;
        }

        // Otherwise, swap to the other player
        curr_player = curr_player == 1 ? 2 : 1;
        num++;
    }

    return 0;
}