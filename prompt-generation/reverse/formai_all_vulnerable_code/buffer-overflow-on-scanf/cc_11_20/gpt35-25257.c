//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int level = 1;
    int health = 100;
    int energy = 100;
    int inventory[3] = {0};
    
    srand(time(NULL));
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new planets.\n");
    
    while (level <= 5 && health > 0 && energy > 0)
    {
        printf("Level %d\n", level);
        printf("Health: %d\n", health);
        printf("Energy: %d\n", energy);
        printf("Inventory: [%d, %d, %d]\n", inventory[0], inventory[1], inventory[2]);
        printf("Choose your action:\n");
        printf("1. Explore planet\n");
        printf("2. Rest and recharge\n");
        printf("3. Check inventory\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("You land on a new planet...\n");
                int n = rand() % 3;
                if (n == 0)
                {
                    printf("You find a strange artifact!\n");
                    inventory[0]++;
                }
                else if (n == 1)
                {
                    printf("You encounter hostile alien life forms!\n");
                    health -= 20;
                }
                else
                {
                    printf("You find a mineral deposit!\n");
                    inventory[1]++;
                }
                energy -= 10;
                break;
            case 2:
                printf("You rest and recharge your energy...\n");
                energy += 50;
                health += 10;
                break;
            case 3:
                printf("You check your inventory...\n");
                printf("Artifacts: %d\n", inventory[0]);
                printf("Minerals: %d\n", inventory[1]);
                printf("Food: %d\n", inventory[2]);
                break;
            default:
                printf("Invalid choice.\n");
        }
        level++;
    }
    
    if (health <= 0 || energy <= 0)
    {
        printf("Game over.\n");
    }
    else
    {
        printf("Congratulations! You completed your space mission.\n");
    }
    
    return 0;
}