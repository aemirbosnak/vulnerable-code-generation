//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, inventory[5] = {0, 0, 0, 0, 0}, room = 1, monster_health = 100, player_health = 100;

    system("cls");
    printf("You wake up in a dark and dusty room. You have no recollection of how you ended up here.\n");

    while (player_health > 0 && monster_health > 0)
    {
        printf("What do you want to do? (1) Attack, (2) Search, (3) Defend\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inventory[0] = 1;
                monster_health -= 20;
                printf("You attack the monster and deal 20 damage.\n");
                break;
            case 2:
                printf("You search the room and find a sword and a healing potion.\n");
                inventory[1] = 1;
                inventory[2] = 1;
                break;
            case 3:
                inventory[3] = 1;
                printf("You defend against the monster's attack.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (monster_health <= 0)
        {
            printf("You have slain the monster. You have won!\n");
            room = 2;
        }
        else if (player_health <= 0)
        {
            printf("You have died. Game Over.\n");
            room = 0;
        }
    }

    system("pause");
}