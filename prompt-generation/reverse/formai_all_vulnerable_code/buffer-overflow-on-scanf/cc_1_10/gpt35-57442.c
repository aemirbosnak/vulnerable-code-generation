//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void journey_to_the_stars(int difficulty_level);
void alien_encounter(int alien_strength, int player_strength);
void game_over();

int main()
{
    srand(time(0));
    int difficulty_level = 1;
    while(1) // game loop
    {
        printf("Welcome to Journey to the Stars!\n");
        printf("Difficulty Level: %d\n", difficulty_level);
        printf("You are the captain of the starship \"Enterprise\" and your mission is to explore the far reaches of space.\n");
        
        journey_to_the_stars(difficulty_level);
        
        if(difficulty_level == 5)
        {
            printf("Congratulations, you have completed your mission and returned safely to Earth!\n");
            break;
        }
        
        printf("Do you want to continue your mission?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        
        int choice;
        scanf("%d", &choice);
        
        if(choice == 2)
        {
            break;
        }
        else
        {
            difficulty_level++;
        }
    }
    
    return 0;
}

void journey_to_the_stars(int difficulty_level)
{
    printf("Entering hyperspace...\n");
    int alien_strength = rand() % difficulty_level + 1;
    int player_strength = (rand() % (difficulty_level * 2)) + 1;
    alien_encounter(alien_strength, player_strength);
}

void alien_encounter(int alien_strength, int player_strength)
{
    printf("You have encountered an alien ship!\n");
    printf("Alien Strength: %d\n", alien_strength);
    printf("Player Strength: %d\n", player_strength);
    
    if(player_strength >= alien_strength)
    {
        printf("You have defeated the alien ship and obtained valuable resources!\n");
    }
    else
    {
        printf("You have been defeated by the alien ship...\n");
        game_over();
    }
}

void game_over()
{
    printf("GAME OVER\n");
    exit(0);
}