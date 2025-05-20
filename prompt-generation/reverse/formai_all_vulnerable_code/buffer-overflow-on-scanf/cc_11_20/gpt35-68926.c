//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to The Island of Adventure!\n\n");
    
    int health = 10;
    int gold = 0;
    int sword = 0;
    
    // Introduction
    printf("You are a sailor on a ship that gets shipwrecked on a deserted island. You are the only survivor and your job is to find a way to escape the island.\n\n");
    
    // Gameplay loop
    while(health > 0)
    {
        // Print player stats
        printf("Health: %d\n", health);
        printf("Gold: %d\n", gold);
        printf("Sword: %s\n\n", sword ? "Yes" : "No");
        
        // Print options
        printf("What do you want to do?\n");
        printf("1. Explore the island.\n");
        printf("2. Collect wood.\n");
        printf("3. Hunt for food.\n");
        printf("4. Build a shelter.\n");
        printf("5. Buy a sword (10 gold).\n");
        printf("6. Try to escape.\n\n");
        
        // Get player action
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        
        // Process player action
        switch(choice)
        {
            case 1:
                printf("You explore the island and find a chest.\n");
                
                // Random chance of finding gold
                if(rand() % 2 == 0)
                {
                    int found_gold = rand() % 6 + 5; // Random number between 5 and 10
                    printf("You found %d gold!\n", found_gold);
                    gold += found_gold;
                }
                else
                {
                    printf("You found nothing of value.\n");
                }
                break;
                
            case 2:
                printf("You collect wood for your shelter.\n");
                break;
                
            case 3:
                printf("You hunt for food and find a wild boar.\n");
                
                // Random chance of losing health
                if(rand() % 2 == 0)
                {
                    printf("The boar injures you while you hunt.\n");
                    health -= 2;
                }
                else
                {
                    printf("You successfully hunted the boar!\n");
                }
                break;
                
            case 4:
                printf("You build a shelter to protect yourself from the elements.\n");
                break;
                
            case 5:
                if(gold >= 10)
                {
                    printf("You buy a sword to defend yourself from wild animals and pirates.\n");
                    sword = 1;
                    gold -= 10;
                }
                else
                {
                    printf("You don't have enough gold to buy a sword.\n");
                }
                break;
                
            case 6:
                if(sword)
                {
                    printf("You successfully escaped the island and sailed away safely.\n");
                    return 0;
                }
                else
                {
                    printf("You try to escape, but you are ambushed by pirates!\n");
                    printf("You fight bravely, but without a sword, you are no match for them.\n");
                    health = 0;
                    return 0;
                }
                break;
                
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
        
        // Random chance of losing health due to exhaustion
        if(rand() % 2 == 0)
        {
            printf("You feel tired and your health decreases.\n");
            health--;
        }
        
        // Check if player has died
        if(health <= 0)
        {
            printf("You have died. Game over.\n");
            return 0;
        }
        
        printf("\n");
    }
    
    return 0;
}