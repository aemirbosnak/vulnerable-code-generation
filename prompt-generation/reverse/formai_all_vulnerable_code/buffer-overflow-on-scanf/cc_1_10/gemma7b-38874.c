//Gemma-7B DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int player1_choice, player2_choice;
    char player1_name[20], player2_name[20];

    // Error handling - Invalid input
    while (1)
    {
        printf("Enter your name: ");
        scanf("%s", player1_name);

        if (strlen(player1_name) < 1)
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        break;
    }

    // Error handling - Invalid choice
    while (1)
    {
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &player1_choice);

        if (player1_choice < 1 || player1_choice > 3)
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        break;
    }

    // Error handling - Duplicate name
    if (strcmp(player1_name, player2_name) == 0)
    {
        printf("Error: Duplicate name. Please use different names.\n");
        exit(1);
    }

    // Game logic
    // ...

    return 0;
}