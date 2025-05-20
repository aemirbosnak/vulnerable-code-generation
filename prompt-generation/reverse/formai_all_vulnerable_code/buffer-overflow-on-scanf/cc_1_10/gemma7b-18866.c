//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, inventory[] = {0, 0, 0}, room = 1, monster_health = 100;

    system("CLS");
    printf("Welcome to the wacky world of Wonderville!\n");
    printf("You are in Room %d. There is a mysterious monster lurking nearby.\n", room);

    // Loop until the player wins or loses
    while (room != 5 && monster_health > 0)
    {
        printf("What do you want to do? (1) Attack, (2) Use Item, (3) Defend\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inventory[0]++;
                monster_health -= inventory[0];
                printf("You attacked the monster and dealt %d damage.\n", inventory[0]);
                break;
            case 2:
                if (inventory[1] > 0)
                {
                    inventory[1]--;
                    monster_health -= inventory[1];
                    printf("You used an item and dealt %d damage.\n", inventory[1]);
                }
                else
                {
                    printf("You do not have any items.\n");
                }
                break;
            case 3:
                inventory[2]++;
                printf("You defended yourself and blocked the monster's attack.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        system("CLS");
        printf("You are in Room %d. The monster's health is at %d.\n", room, monster_health);

        // Check if the player has won or lost
        if (monster_health <= 0)
        {
            room = 5;
            printf("Congratulations! You have defeated the monster!\n");
        }
        else if (room == 5)
        {
            printf("Game Over! You have been defeated by the monster.\n");
        }
    }

    return 0;
}