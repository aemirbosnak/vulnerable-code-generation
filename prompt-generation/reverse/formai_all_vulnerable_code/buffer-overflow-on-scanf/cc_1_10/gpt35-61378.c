//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char name[20], decision;
    int health = 100, coins = 0, sword = 0, shield = 0;

    printf("Welcome to the Adventure Game! Please enter your name: ");
    scanf("%s", name);
    printf("\n%s, you find yourself in a dense forest, unsure of your location.", name);
    printf("\nYour objective is to find the treasure at the end of the forest before the sun sets and without dying.");
    printf("\nYou currently have %d health, %d coins, and no weapons.\n", health, coins);
    printf("\nPress 'y' to start your adventure or 'n' to quit: ");
    scanf(" %c", &decision);

    if(decision == 'y')
    {
        printf("\nYou begin walking into the forest and come across a wooden sword on the ground.");
        printf("\nDo you want to pick it up? Press 'y' for yes and 'n' for no: ");
        scanf(" %c", &decision);

        if(decision == 'y')
        {
            sword = 1;
            printf("\nYou picked up the wooden sword! You now have a weapon.\n");
        }
        else
        {
            printf("\nYou left the sword behind. Let's continue on.\n");
        }

        printf("\nAs you're walking, you hear rustling in the bushes and out jumps a bandit!");
        printf("\nDo you want to fight the bandit or run away? Press 'f' to fight or 'r' to run: ");
        scanf(" %c", &decision);

        if(decision == 'f')
        {
            if(sword == 1)
            {
                printf("\nYou engage in a sword fight with the bandit and come out victorious!");
                printf("\nYou gained 10 coins from the bandit's loot.\n");
                coins += 10;
            }
            else
            {
                printf("\nYou don't have a weapon to fight with! You take damage from the bandit and lose 10 health.\n");
                health -= 10;
            }
        }
        else
        {
            printf("\nYou run away from the bandit and escape unharmed.\n");
        }

        printf("\nAfter defeating or escaping from the bandit, you continue deeper into the forest.");
        printf("\nYou come across a clearing and see a chest in the distance.");
        printf("\nDo you want to approach the chest or keep walking? Press 'a' to approach or 'k' to keep walking: ");
        scanf(" %c", &decision);

        if(decision == 'a')
        {
            printf("\nYou approach the chest and discover a shield! You now have extra protection.\n");
            shield = 1;
        }
        else
        {
            printf("\nYou keep walking and come across a dangerous ravine.");
            printf("\nDo you want to risk jumping over the ravine to save time or walk around it? Press 'j' to jump or 'w' to walk around: ");
            scanf(" %c", &decision);

            if(decision == 'j')
            {
                printf("\nYou make a running leap and successfully jump over the ravine!");
                printf("\nHowever, you lost 20 health due to the exhaustion of running and jumping.\n");
                health -= 20;
            }
            else
            {
                printf("\nYou decided to take the safe route and walk around the ravine.");
                printf("\nIt takes longer, but you don't sustain any damage.\n");
            }
        }

        printf("\nAs the sun is beginning to set, you finally arrive at the end of the forest and find the treasure chest!");
        printf("\nYou open the chest and discover a whopping 100 coins!");
        printf("\nCongratulations, %s! You've completed the adventure with %d health and %d coins.", name, health, coins);
    }
    else
    {
        printf("\nGoodbye, adventurer!");
    }

    return 0;
}