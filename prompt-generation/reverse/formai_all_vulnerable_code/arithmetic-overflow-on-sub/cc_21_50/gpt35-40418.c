//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>

int main()
{
    printf("Welcome to Tic Tac Toe!\n");

    char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7', '8', '9'} };
    int player = 1;
    char mark;

    int choice = 0;
    int row, column;

    do
    {
        // Print the board
        printf("\n");
        printf("   %c   |   %c   |   %c   \n", board[0][0], board[0][1], board[0][2]);
        printf("-------|-------|-------\n");
        printf("   %c   |   %c   |   %c   \n", board[1][0], board[1][1], board[1][2]);
        printf("-------|-------|-------\n");
        printf("   %c   |   %c   |   %c   \n", board[2][0], board[2][1], board[2][2]);

        // Set the player's mark
        if(player % 2 == 1)
            mark = 'X';
        else
            mark = 'O';

        // Get the player's move
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        // Determine the row and column of the move
        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        // Check if the move is valid
        if(board[row][column] == 'X' || board[row][column] == 'O')
        {
            printf("That move is not valid. Please try again.\n");
            continue;
        }

        // Update the board with the player's mark
        board[row][column] = mark;

        // Check if the game is won
        if(board[0][0] == mark && board[0][1] == mark && board[0][2] == mark
           || board[1][0] == mark && board[1][1] == mark && board[1][2] == mark
           || board[2][0] == mark && board[2][1] == mark && board[2][2] == mark
           || board[0][0] == mark && board[1][0] == mark && board[2][0] == mark
           || board[0][1] == mark && board[1][1] == mark && board[2][1] == mark
           || board[0][2] == mark && board[1][2] == mark && board[2][2] == mark
           || board[0][0] == mark && board[1][1] == mark && board[2][2] == mark
           || board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        {
            printf("\nCongratulations, player %d has won the game!\n", player);
            return 0;
        }

        // Check if the game is a draw
        if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3'
           && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6'
           && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        {
            printf("\nThe game is a draw.\n");
            return 0;
        }

        // Switch to the other player
        player++;

    } while(1);

    return 0;
}