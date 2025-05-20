//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dice_roll, player_one_roll, player_two_roll, player_one_points = 0, player_two_points = 0;
    char player_one_name[20], player_two_name[20];

    printf("Enter the name of player one:");
    scanf("%s", player_one_name);

    printf("Enter the name of player two:");
    scanf("%s", player_two_name);

    // Loop to simulate rolling the dice
    while (player_one_points < 10 && player_two_points < 10)
    {
        dice_roll = rand() % 6 + 1;
        player_one_roll = rand() % 6 + 1;
        player_two_roll = rand() % 6 + 1;

        // Calculate points for player one
        if (player_one_roll == dice_roll)
        {
            player_one_points++;
        }

        // Calculate points for player two
        if (player_two_roll == dice_roll)
        {
            player_two_points++;
        }

        // Display the results of the roll
        printf("Roll: %d, %d, %d", dice_roll, player_one_roll, player_two_roll);
        printf("\n");
    }

    // Print the winner
    if (player_one_points >= 10)
    {
        printf("%s won the game!", player_one_name);
    }
    else if (player_two_points >= 10)
    {
        printf("%s won the game!", player_two_name);
    }
    else
    {
        printf("No winner!");
    }

    return 0;
}