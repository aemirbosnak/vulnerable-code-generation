//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include <stdio.h>

int main()
{
    char name[20];
    int choice, room, inventory[] = {0, 0, 0, 0, 0};
    room = 1;

    printf("Welcome to the Mysterious Mansion!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (1)
    {
        system("cls");
        printf("You are in Room %d.\n", room);

        if (inventory[0] != 0)
        {
            printf("Inventory: %c, %c, %c, %c, %c\n", inventory[0], inventory[1], inventory[2], inventory[3], inventory[4]);
        }

        printf("What do you want to do? (1) Explore, (2) Search, (3) Use Item, (4) Leave\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                room++;
                break;
            case 2:
                inventory[0] = inventory[0] + 1;
                break;
            case 3:
                if (inventory[0] > 0)
                {
                    printf("Please select an item to use: ");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                        case 1:
                            printf("You used the sword to fight the monster.\n");
                            inventory[0] = inventory[0] - 1;
                            break;
                        case 2:
                            printf("You used the potion to heal yourself.\n");
                            inventory[0] = inventory[0] - 1;
                            break;
                        case 3:
                            printf("You used the key to unlock the secret room.\n");
                            inventory[0] = inventory[0] - 1;
                            room++;
                            break;
                        default:
                            printf("Invalid item selection.\n");
                            break;
                    }
                }
                else
                {
                    printf("You have no items to use.\n");
                }
                break;
            case 4:
                printf("Thank you for playing. See you next time.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        system("pause");
    }
}