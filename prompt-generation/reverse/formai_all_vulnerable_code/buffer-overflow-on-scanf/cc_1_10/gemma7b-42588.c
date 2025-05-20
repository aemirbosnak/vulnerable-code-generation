//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, inventory[] = {0, 0, 0}, location = 1;

    system("clear");
    printf("You are in a mysterious forest clearing. A towering tree stands in the center.\n");

    // Inventory management
    printf("Your inventory: ");
    for (int i = 0; i < 3; i++)
    {
        if (inventory[i] != 0)
        {
            printf("%d ", inventory[i]);
        }
    }

    // Main game loop
    while (location != 5)
    {
        // Display available options
        printf("\nWhat do you want to do? (1) Search the tree, (2) Approach the clearing, (3) Examine your inventory, (4) Leave the forest:\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Search the tree logic
                break;
            case 2:
                // Approach the clearing logic
                break;
            case 3:
                // Examine inventory logic
                break;
            case 4:
                // Leave the forest logic
                location = 5;
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }

        system("clear");
        printf("You are in a mysterious forest clearing. A towering tree stands in the center.\n");

        // Inventory management
        printf("Your inventory: ");
        for (int i = 0; i < 3; i++)
        {
            if (inventory[i] != 0)
            {
                printf("%d ", inventory[i]);
            }
        }
    }

    // Game end
    printf("\nYou have left the forest. Thank you for playing!\n");
}