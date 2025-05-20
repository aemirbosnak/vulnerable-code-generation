//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int health = 100;
    int strength = 20;
    int inventory[5] = {0, 0, 0, 0, 0};
    int current_location = 1;

    // Game Loop
    while (health > 0)
    {
        // Display current location and inventory
        printf("You are at location %d.\n", current_location);
        printf("Your inventory: ");
        for (int i = 0; i < 5; i++)
        {
            if (inventory[i] != 0)
            {
                printf("%d ", inventory[i]);
            }
        }

        // Get user input
        char input[20];
        printf("\nEnter command: ");
        scanf("%s", input);

        // Process user input
        switch (input[0])
        {
            case 'w':
                current_location++;
                break;
            case 's':
                current_location--;
                break;
            case 'a':
                inventory[0]++;
                break;
            case 'd':
                inventory[1]++;
                break;
            case 'f':
                if (inventory[2] > 0)
                {
                    inventory[2]--;
                    health++;
                }
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Check if player has won or lost
        if (health <= 0)
        {
            printf("Game Over.\n");
        }
        else if (current_location == 5)
        {
            printf("You have won!\n");
        }
    }

    return 0;
}