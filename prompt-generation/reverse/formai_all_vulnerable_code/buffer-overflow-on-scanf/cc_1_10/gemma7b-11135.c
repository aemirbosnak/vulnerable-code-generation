//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int team_a = 0, team_b = 0, round = 1, game_over = 0;
    char player_a_name[20], player_b_name[20];

    printf("Enter the name of player A: ");
    scanf("%s", player_a_name);

    printf("Enter the name of player B: ");
    scanf("%s", player_b_name);

    printf("Welcome to the Battle of the Feuding Families!\n");

    while (!game_over)
    {
        // Round starts
        printf("Round %d:\n", round);

        // Player A's turn
        printf("%s, choose your move (attack, defend, surrender): ", player_a_name);
        char move_a = getchar();

        // Player B's turn
        printf("%s, choose your move (attack, defend, surrender): ", player_b_name);
        char move_b = getchar();

        // Check if move is valid
        if (move_a != 'a' && move_a != 'd' && move_a != 's')
        {
            printf("Invalid move.\n");
            continue;
        }
        if (move_b != 'a' && move_b != 'd' && move_b != 's')
        {
            printf("Invalid move.\n");
            continue;
        }

        // Calculate damage and defend
        int damage_a = rand() % 5 + 1;
        int defend_b = rand() % 3 + 1;

        // Check if player B has defended successfully
        if (defend_b >= damage_a)
        {
            printf("%s has defended successfully.\n", player_b_name);
        }
        else
        {
            team_b++;
            printf("%s has been defeated. Team B wins!\n", player_a_name);
        }

        // Round ends
        round++;

        // Check if game is over
        if (team_a == 2 || team_b == 2)
        {
            game_over = 1;
        }
    }

    // Game over
    printf("The battle is over. The winner is: ");

    if (team_a == 2)
    {
        printf("%s\n", player_a_name);
    }
    else if (team_b == 2)
    {
        printf("%s\n", player_b_name);
    }
    else
    {
        printf("No winner\n");
    }

    printf("Thank you for playing!\n");
}

int main()
{
    play_game();

    return 0;
}