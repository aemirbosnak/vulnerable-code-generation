//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>

int main()
{
    // Initialize the game variables
    int score = 0;
    int level = 1;

    // Start the game loop
    while (level <= 5)
    {
        // Get user input
        int choice;
        printf("Level %d:\n", level);
        printf("1. Attack\n");
        printf("2. Heal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        // Process user input
        if (choice == 1)
        {
            // Attack the enemy
            printf("You attacked the enemy!\n");
            score += 10;
        }
        else if (choice == 2)
        {
            // Heal yourself
            printf("You healed yourself!\n");
        }
        else if (choice == 3)
        {
            // Exit the game
            printf("Game over.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }

        // Increase the level
        level++;
    }

    // Display the final score
    printf("Final score: %d\n", score);

    return 0;
}