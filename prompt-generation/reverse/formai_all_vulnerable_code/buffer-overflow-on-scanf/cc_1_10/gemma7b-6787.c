//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void display_menu(void)
{
    printf("\nPlease select an option:");
    printf("\n1. Travel to the North");
    printf("\n2. Travel to the South");
    printf("\n3. Travel to the East");
    printf("\n4. Travel to the West");
    printf("\n5. Inventory");
    printf("\nPlease enter your choice:");
}

void travel(int direction)
{
    switch (direction)
    {
        case 1:
            printf("You traveled North.\n");
            break;
        case 2:
            printf("You traveled South.\n");
            break;
        case 3:
            printf("You traveled East.\n");
            break;
        case 4:
            printf("You traveled West.\n");
            break;
    }
}

void inventory(void)
{
    printf("Your inventory:\n");
    // List the items in the player's inventory
}

int main()
{
    int choice;

    // Create a game loop
    while (1)
    {
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                travel(1);
                break;
            case 2:
                travel(2);
                break;
            case 3:
                travel(3);
                break;
            case 4:
                travel(4);
                break;
            case 5:
                inventory();
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Check if the player wants to continue
        printf("Do you want to continue? (y/n): ");
        char continue_yn;
        scanf(" %c", &continue_yn);

        // If the player does not want to continue, break out of the game loop
        if (continue_yn == 'n')
        {
            break;
        }
    }

    // End of game
    printf("Thank you for playing!\n");

    return 0;
}