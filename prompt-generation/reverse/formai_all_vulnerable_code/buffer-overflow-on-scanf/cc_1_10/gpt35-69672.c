//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // setting the seed for random number generator
    int player_health = 100, ghost_health = 50, potion = 1, choice;
    
    printf("*** Welcome to the Haunted House Simulator ***\n\n");
    printf("You are alone in a haunted house and a ghost is chasing you.\n");
    printf("You have to escape the house before the ghost catches you.\n");
    
    // game loop
    while(1)
    {
        printf("\n\nYou have %d health points and ghost has %d health points.\n", player_health, ghost_health);
        
        // player choice
        printf("\nEnter your choice:\n1. Attack the ghost.\n2. Drink potion.\n");
        scanf("%d", &choice);
        
        if(choice == 1) // player attack
        {
            int damage = rand() % 21 + 20; // attack damage of player
            ghost_health -= damage;
            printf("\nYou attacked the ghost and inflicted %d damage.\n", damage);
            
            if(ghost_health <= 0) // if ghost is defeated
            {
                printf("Congratulations! You have defeated the ghost and escaped the haunted house.\n");
                break;
            }
            
            // ghost attack
            damage = rand() % 21 + 10; // attack damage of ghost
            player_health -= damage;
            printf("Ghost attacked you and inflicted %d damage.\n", damage);
            
            if(player_health <= 0) // if player is defeated
            {
                printf("Sorry! The ghost has caught you and you have been captured...\n");
                break;
            }
        }
        else if(choice == 2) // player drinks potion
        {
            if(potion == 0)
            {
                printf("\nSorry! You have used all the potions.\n");
            }
            else
            {
                player_health += 25; // heal player by 25 health points
                potion--;
                printf("\nYou drank the potion and your health points increased to %d.\n", player_health);
                
                // ghost attack
                int damage = rand() % 21 + 10;
                player_health -= damage;
                printf("Ghost attacked you and inflicted %d damage.\n", damage);
                
                if(player_health <= 0) // if player is defeated
                {
                    printf("Sorry! The ghost has caught you and you have been captured...\n");
                    break;
                }
            }
        }
        else // invalid choice
        {
            printf("\nInvalid choice! Please enter again.\n");
        }
    }
    
    return 0;
}