//Gemma-7B DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, score = 0, round = 0, turn = 0;
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    system("clear");

    // Game Loop
    while (score < 5)
    {
        // Round Start
        round++;
        turn = (round % 2) ? 1 : 2;

        // Player Move
        printf("It is player %d's turn.\n", turn);
        printf("Enter the row and column of the tile you want to move to (1-5): ");
        scanf("%d %d", &i, &j);

        // Tile Validation
        if (i < 1 || i > 5 || j < 1 || j > 5)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place Tile
        board[i][j] = turn;

        // Check for Win
        if (board[i][j] == turn && board[i-1][j] == turn && board[i+1][j] == turn && board[i][j-1] == turn)
        {
            score++;
            printf("Congratulations! You have won the game!\n");
        }
        else if (board[i][j] == turn && board[i][j-1] == turn && board[i][j+1] == turn)
        {
            score++;
            printf("Congratulations! You have won the game!\n");
        }
        else if (board[i][j] == turn && board[i-1][j] == turn && board[i+1][j] == turn)
        {
            score++;
            printf("Congratulations! You have won the game!\n");
        }

        // Display Board
        system("clear");
        printf("Game Board:\n");
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Game Over
    system("clear");
    printf("Game Over!\n");
    printf("Final Score: %d\n", score);

    return 0;
}