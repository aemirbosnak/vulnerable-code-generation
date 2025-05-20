//FormAI DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_score = 0;
    int computer_score = 0;
    int turn_score = 0;
    int num_dice = 1;
    int player_choice = 0;
    srand(time(NULL));

    printf("Welcome to Mind-bending Dice Game! You will be competing against a computer.\n");
    printf("The goal is to score exactly 50 points. Each turn, you can choose to roll one or two dice. \n");
    printf("However, if you score over 50 points, your turn is forfeit and the computer gets a turn. \n");
    printf("The first to reach exactly 50 points wins! \n\n");

    while (player_score < 50 && computer_score < 50)
    {
        printf("Your current score: %d\n", player_score);
        printf("Computers current score: %d\n", computer_score);

        printf("Enter 1 to roll one dice or 2 to roll two dice: ");
        scanf("%d", &player_choice);

        turn_score = 0;
        for (int i = 0; i < player_choice; i++)
        {
            int roll = (rand() % 6) + 1;
            printf("Dice %d: %d\n", i+1, roll);
            turn_score += roll;
        }

        printf("Your turn score: %d\n", turn_score);
        player_score += turn_score;

        if (player_score > 50)
        {
            printf("You went over 50 points! Your turn is forfeit. Computer's turn.\n");
            continue;
        }

        if (player_score == 50)
        {
            printf("You won!\n");
            break;
        }

        printf("Computers turn.\n");

        turn_score = 0;
        for (int i = 0; i < num_dice; i++)
        {
            int roll = rand() % 6 + 1;
            printf("Dice %d: %d\n", i+1, roll);
            turn_score += roll;
        }

        printf("Computer's turn score: %d\n", turn_score);
        computer_score += turn_score;

        if (computer_score > 50)
        {
            printf("Computer went over 50 points! Your turn.\n");
            continue;
        }

        if (computer_score == 50)
        {
            printf("Computer won!\n");
            break;
        }
    }

    return 0;
}