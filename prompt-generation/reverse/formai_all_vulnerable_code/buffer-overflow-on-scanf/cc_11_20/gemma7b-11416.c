//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>

int main()
{
    // Define the map of the universe
    char universe[2][2] = {
        {'S', 'O'},
        {'R', 'E'}
    };

    // Current position of the spaceship
    int x = 0, y = 0;

    // Game loop
    while (1)
    {
        // Print the map
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%c ", universe[i][j]);
            }
            printf("\n");
        }

        // Get the user's input
        char input;
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &input);

        // Move the spaceship
        switch (input)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the spaceship has reached the edge of the universe
        if (x < 0 || x >= 1 || y < 0 || y >= 1)
        {
            printf("You have reached the edge of the universe.\n");
            break;
        }

        // Continue the game loop
    }

    return 0;
}