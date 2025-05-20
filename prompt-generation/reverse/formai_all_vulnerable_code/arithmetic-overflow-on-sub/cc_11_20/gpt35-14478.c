//FormAI DATASET v1.0 Category: Table Game ; Style: random
// This program allows two players to play a unique table game called "Fruit Basket"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1, player2, round, score1=0, score2=0;
    char fruits[5][10] = {"apple", "banana", "orange", "grape", "mango"};

    srand(time(NULL));

    // Welcome message
    printf("Welcome to the game of Fruit Basket!\n");
    printf("The game is played between two players.\n");
    printf("Each player will pick a fruit from a basket and score points based on the fruit chosen.\n");
    printf("The player with the highest score after 10 rounds wins.\n\n");

    // Game loop
    for (round=1; round<=10; round++)
    {
        printf("Round %d:\n", round);

        // Player 1's turn
        printf("Player 1, pick a fruit (1-5): ");
        scanf("%d", &player1);
        printf("\nPlayer 1 picked %s\n", fruits[player1-1]);

        // Player 2's turn
        printf("Player 2, pick a fruit (1-5): ");
        scanf("%d", &player2);
        printf("\nPlayer 2 picked %s\n", fruits[player2-1]);

        // Calculate scores
        switch (player1)
        {
            case 1: score1 += 10; break;
            case 2: score1 += 5; break;
            case 3: score1 += 7; break;
            case 4: score1 += 3; break;
            case 5: score1 += 8; break;
        }

        switch (player2)
        {
            case 1: score2 += 10; break;
            case 2: score2 += 5; break;
            case 3: score2 += 7; break;
            case 4: score2 += 3; break;
            case 5: score2 += 8; break;
        }

        // Display scores
        printf("Score after round %d:\n", round);
        printf("Player 1: %d\n", score1);
        printf("Player 2: %d\n\n", score2);
    }

    // Determine winner
    printf("End of game!\n");
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}