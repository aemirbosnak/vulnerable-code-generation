//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>

int main()
{
    // Start the game
    printf("Welcome to the Adventure Game!\n");

    // Prompt the player to choose their adventure
    int choice;
    printf("Do you want to explore a cave (1) or a castle (2)?\n");
    scanf("%d", &choice);

    // Process the player's choice
    if (choice == 1)
    {
        // Explore the cave
        printf("You are in a dark and damp cave. You can go left or right.\n");
        printf("Which way do you want to go?\n");
        int direction;
        scanf("%d", &direction);

        // Process the player's choice
        if (direction == 1)
        {
            printf("You go left and find a treasure chest!\n");
            printf("Do you want to open it (1) or leave it alone (2)?\n");
            int decision;
            scanf("%d", &decision);

            // Process the player's choice
            if (decision == 1)
            {
                printf("You open the treasure chest and find a golden amulet!\n");
                printf("Congratulations! You have won the game.\n");
            }
            else
            {
                printf("You leave the treasure chest alone and continue exploring the cave.\n");
            }
        }
        else if (direction == 2)
        {
            printf("You go right and find a dead end.\n");
            printf("You have lost the game.\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
    else if (choice == 2)
    {
        // Explore the castle
        printf("You are in a grand castle. You can go up or down.\n");
        printf("Which way do you want to go?\n");
        int direction;
        scanf("%d", &direction);

        // Process the player's choice
        if (direction == 1)
        {
            printf("You go up and find a secret passage.\n");
            printf("Do you want to take the passage (1) or turn back (2)?\n");
            int decision;
            scanf("%d", &decision);

            // Process the player's choice
            if (decision == 1)
            {
                printf("You take the secret passage and find a hidden room.\n");
                printf("Do you want to explore the room (1) or leave it alone (2)?\n");
                int exploration;
                scanf("%d", &exploration);

                // Process the player's choice
                if (exploration == 1)
                {
                    printf("You explore the hidden room and find a golden key!\n");
                    printf("Do you want to keep the key (1) or leave it behind (2)?\n");
                    int decision2;
                    scanf("%d", &decision2);

                    // Process the player's choice
                    if (decision2 == 1)
                    {
                        printf("You keep the golden key and continue exploring the castle.\n");
                    }
                    else
                    {
                        printf("You leave the golden key behind and continue exploring the castle.\n");
                    }
                }
                else
                {
                    printf("You leave the hidden room and continue exploring the castle.\n");
                }
            }
            else if (decision == 2)
            {
                printf("You turn back and continue exploring the castle.\n");
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
        }
        else if (direction == 2)
        {
            printf("You go down and find a room filled with traps.\n");
            printf("You have lost the game.\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}