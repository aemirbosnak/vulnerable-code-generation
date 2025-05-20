//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s, to the wondrous world of Text-Based Adventure Games!\n", name);

    // Create a simple inventory
    int inventory[3] = {0, 0, 0};

    // Define the game map
    char map[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'J'},
        {'K', 'L', 'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Y'}
    };

    // Player's current position
    int x = 0;
    int y = 0;

    // Game loop
    while (1)
    {
        // Display the game map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's choice
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > 4)
        {
            printf("Invalid choice.\n");
            continue;
        }

        // Move the player
        switch (choice)
        {
            case 1:
                x--;
                break;
            case 2:
                x++;
                break;
            case 3:
                y--;
                break;
            case 4:
                y++;
                break;
        }

        // Check if the player has reached the end of the game
        if (map[x][y] == 'Y')
        {
            printf("Congratulations, %s, you have won the game!\n", name);
            break;
        }

        // Display the player's current position
        printf("Your current position is (%d, %d).", x, y);
    }

    return 0;
}