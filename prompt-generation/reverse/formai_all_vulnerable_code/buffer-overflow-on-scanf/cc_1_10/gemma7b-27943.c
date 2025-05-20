//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    int health = 100;
    char location = 'a';

    printf("Welcome to the text-based adventure game, %s!", name);

    while (health > 0)
    {
        printf("\nYou are currently at location %c.", location);

        printf("\nWhat would you like to do? (1) Attack, (2) Defend, (3) Search, (4) Use Item:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You attacked the enemy and dealt %d damage.", rand() % 10);
                break;
            case 2:
                printf("You defended against the enemy's attack and took no damage.");
                break;
            case 3:
                printf("You searched the area and found a health potion.");
                health++;
                break;
            case 4:
                printf("You used an item to heal yourself and regained %d health.", rand() % 10);
                health++;
                break;
            default:
                printf("Invalid input.");
                break;
        }

        // Combat logic
        // ...

        // Location change logic
        // ...

        // Other actions
        // ...
    }

    printf("\nGame over. You have run out of health.");

    return 0;
}