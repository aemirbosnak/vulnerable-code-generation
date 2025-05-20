//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to EnergyBlast Game!\n");
    printf("In this game, you are a space fighter pilot trying to defend your planet from an alien invasion.\n");
    printf("Your mission is to blast away the enemy ships and protect your planet!\n");
    
    srand(time(NULL)); // initialize random seed
    
    int alien_ships = 10; // number of alien ships
    int player_lives = 3; // number of player lives
    int score = 0; // player score
    
    while(alien_ships > 0 && player_lives > 0) // game loop
    {
        printf("\nAlien ships remaining: %d\n", alien_ships);
        printf("Your lives: %d\n", player_lives);
        printf("Your score: %d\n", score);
        
        int rand_num = rand() % 3; // generate random number between 0 and 2
        
        if(rand_num == 0) // enemy ship
        {
            printf("An enemy ship is attacking!\n");
            printf("What would you like to do?\n");
            printf("1. Blast it!\n");
            printf("2. Dodge it!\n");
            
            int choice;
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You blast the enemy ship!\n");
                score += 10;
                alien_ships--;
                
                if(score % 50 == 0) // extra life every 50 points
                {
                    player_lives++;
                    printf("You have earned an extra life!\n");
                }
            }
            else if(choice == 2)
            {
                printf("You dodge the enemy ship!\n");
            }
            else // invalid choice
            {
                printf("Invalid choice! Penalty: Lose a life.\n");
                player_lives--;
            }
        }
        else // power-up
        {
            printf("A power-up has appeared!\n");
            printf("What would you like to do?\n");
            printf("1. Catch it!\n");
            printf("2. Ignore it!\n");
            
            int choice;
            scanf("%d", &choice);
            
            if(choice == 1)
            {
                printf("You catch the power-up!\n");
                score += 20;
                player_lives++;
            }
            else if(choice == 2)
            {
                printf("You ignore the power-up!\n");
            }
            else // invalid choice
            {
                printf("Invalid choice! Penalty: Lose a life.\n");
                player_lives--;
            }
        }
    }
    
    if(alien_ships == 0) // player wins
    {
        printf("\nCongratulations! You have successfully defended your planet!\n");
        printf("Final score: %d\n", score);
    }
    else if(player_lives == 0) // player loses
    {
        printf("\nGame over! The aliens have taken over your planet!\n");
        printf("Final score: %d\n", score);
    }
    
    return 0;
}