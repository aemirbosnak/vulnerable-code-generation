//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, inventory[] = {0, 0, 0, 0}, romance_level = 0;
    char name[20];
    char location = 'a';

    printf("Please enter your name: ");
    scanf("%s", name);

    while (1)
    {
        system("cls");
        printf("You are in %c. What do you want to do? (1) Travel, (2) Interact, (3) Inspect Inventory, (4) Romance\n", location);
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                location = 'b';
                break;
            case 2:
                printf("Who are you interacting with? ");
                scanf("%s", name);

                if (inventory[0] > 0)
                {
                    printf("You gave %s a gift. They are now happy.\n", name);
                    inventory[0]--;
                }
                else
                {
                    printf("You have nothing to give.\n");
                }

                romance_level++;
                break;
            case 3:
                printf("Your inventory: \n");
                for (int i = 0; i < 4; i++)
                {
                    printf("%d. %s\n", inventory[i], inventory[i] > 0 ? "Taken" : "Available");
                }
                break;
            case 4:
                if (romance_level > 0)
                {
                    printf("You have successfully romanced %s. They are yours forever.\n", name);
                    romance_level = 0;
                }
                else
                {
                    printf("You have not yet romanced anyone.\n");
                }
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (inventory[0] >= 3)
        {
            printf("You have collected enough gifts. You can now romance someone.\n");
        }

        if (romance_level >= 3)
        {
            printf("You have successfully achieved the highest level of romance. Congratulations!\n");
            break;
        }
    }
}