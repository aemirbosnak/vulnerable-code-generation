//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int choice, x, y, z, map[10][10] = {{0}}, travel_cost = 0, treasure_found = 0;

    // Create a map
    map[0][0] = 1;
    map[0][1] = 1;
    map[1][0] = 1;
    map[1][1] = 1;

    // Initialize the player's position
    x = 0;
    y = 0;

    // Start the game loop
    while (!treasure_found)
    {
        // Display the map
        for (z = 0; z < 10; z++)
        {
            for (int w = 0; w < 10; w++)
            {
                printf("%d ", map[z][w]);
            }
            printf("\n");
        }

        // Get the player's choice
        printf("Enter your choice (N, S, E, W): ");
        scanf("%d", &choice);

        // Move the player
        switch (choice)
        {
            case 1:
                y--;
                break;
            case 2:
                y++;
                break;
            case 3:
                x++;
                break;
            case 4:
                x--;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Check if the player has found the treasure
        if (map[y][x] == 2)
        {
            treasure_found = 1;
            printf("You have found the treasure!\n");
        }

        // Calculate the travel cost
        travel_cost++;

        // Print the travel cost
        printf("Travel cost: %d\n", travel_cost);
    }

    // End the game
    return 0;
}