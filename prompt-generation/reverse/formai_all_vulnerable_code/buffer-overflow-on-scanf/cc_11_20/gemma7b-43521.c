//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    int inventory[5] = {0, 0, 0, 0, 0};
    inventory[0] = 10;
    inventory[1] = 5;
    inventory[2] = 2;
    inventory[3] = 1;

    int location = 0;
    char current_room[20] = "The dank tavern";

    printf("Welcome, %s, to the dank tavern!\n", name);
    printf("You are in: %s\n", current_room);

    // Main game loop
    while (1)
    {
        // Display available actions
        printf("What would you like to do? (look, go, interact, inventory)\n");

        char action[20];
        scanf("%s", action);

        // Check if action is valid
        if (strcmp(action, "look") == 0)
        {
            // Describe the current room
            printf("The tavern is a dark and smoky place.\n");
            printf("You see the bartender, a few patrons, and a pile of barrels.\n");
        }
        else if (strcmp(action, "go") == 0)
        {
            // Check if there is a direction available
            if (location > 0)
            {
                // Move to the next room
                location--;
                current_room[0] = 'A';
                printf("You have moved to the next room.\n");
            }
            else
            {
                printf("There is no direction available.\n");
            }
        }
        else if (strcmp(action, "interact") == 0)
        {
            // Interact with the bartender or other patrons
            printf("What would you like to do? (talk, drink, etc.)\n");

            char interaction[20];
            scanf("%s", interaction);

            // Check if interaction is valid
            if (strcmp(interaction, "talk") == 0)
            {
                // Talk to the bartender or other patrons
                printf("The bartender is a friendly man.\n");
                printf("He offers you a drink and a story.\n");
            }
            else if (strcmp(interaction, "drink") == 0)
            {
                // Drink a beer or other beverage
                printf("You drink a beer.\n");
                printf("You feel tipsy.\n");
            }
        }
        else if (strcmp(action, "inventory") == 0)
        {
            // Display your inventory
            printf("Your inventory: \n");
            for (int i = 0; i < 5; i++)
            {
                if (inventory[i] > 0)
                {
                    printf("%d. %s\n", i + 1, inventory[i]);
                }
            }
        }
        else
        {
            printf("Invalid action.\n");
        }

        // Check if the player wants to continue
        char continue_game[20];
        printf("Do you want to continue? (yes/no)\n");
        scanf("%s", continue_game);

        // If the player does not want to continue, end the game
        if (strcmp(continue_game, "no") == 0)
        {
            break;
        }
    }

    // End the game
    printf("Thank you for playing, %s!\n", name);
    return 0;
}