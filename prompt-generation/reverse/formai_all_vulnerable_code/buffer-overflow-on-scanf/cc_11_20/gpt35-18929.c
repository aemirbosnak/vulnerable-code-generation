//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("\n\n\t\tC Table Game\n\n");
    printf("Welcome to the C Table Game! This is a two player game, where each player takes turns selecting a number from a table.\nThe game ends when the table is empty and the player with the highest score wins. Let's get started!\n\n");

    int table[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36},
    };

    int score1 = 0, score2 = 0;
    bool player1_turn = true;

    while (true)
    {
        printf("\nTable:\n");
        for (int row = 0; row < 6; row++)
        {
            for (int col = 0; col < 6; col++)
            {
                printf("%2d ", table[row][col]);
            }
            printf("\n");
        }

        int row, col, selected_num;
        printf("\n%s's Turn:\n", player1_turn ? "Player 1" : "Player 2");
        printf("Enter the row and column of the number you want to select: ");
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 6 || col < 1 || col > 6)
        {
            printf("Invalid Input. Row and column values should be between 1 and 6\n");
            continue;
        }

        selected_num = table[row - 1][col - 1];
        if (selected_num < 1 || selected_num > 36)
        {
            printf("Invalid Input. The selected cell has already been chosen\n");
            continue;
        }

        if (player1_turn)
        {
            score1 += selected_num;
        }
        else
        {
            score2 += selected_num;
        }

        table[row - 1][col - 1] = 0;

        if (score1 + score2 == 630) // sum of numbers from 1 to 36
        {
            break;
        }

        player1_turn = !player1_turn; // switch players
    }

    printf("\n\nGame Over!\n");
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("It's a Tie!\n");
    }

    printf("\nFinal Score:\n");
    printf("Player 1: %d\n", score1);
    printf("Player 2: %d\n\n", score2);

    return 0;
}