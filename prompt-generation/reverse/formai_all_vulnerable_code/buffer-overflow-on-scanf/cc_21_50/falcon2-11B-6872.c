//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    // Initialize the game map
    int map[MAX_SIZE][MAX_SIZE] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Prompt the user for initial position
    printf("Enter your starting position (x, y): ");
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    // Check if the starting position is valid
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE) {
        printf("Invalid starting position. Please try again.\n");
        return 1;
    }

    // Set the player's current position
    map[x][y] = 'P';

    // Prompt the user for direction
    printf("Enter your direction (N, S, E, W): ");
    char direction = 0;
    scanf(" %c", &direction);

    // Check if the direction is valid
    if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
        // Move the player in the specified direction
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }

        // Check if the new position is valid
        if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE) {
            printf("Invalid position. Please try again.\n");
            return 1;
        }

        // Set the player's new position
        map[x][y] = 'P';
    } else {
        printf("Invalid direction. Please try again.\n");
        return 1;
    }

    // Continue the game loop
    while (1) {
        // Display the current position
        printf("You are currently at position (%d, %d)\n", x, y);

        // Prompt the user for direction
        printf("Enter your direction (N, S, E, W): ");
        scanf(" %c", &direction);

        // Check if the direction is valid
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            // Move the player in the specified direction
            switch (direction) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }

            // Check if the new position is valid
            if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE) {
                printf("Invalid position. Please try again.\n");
                return 1;
            }

            // Set the player's new position
            map[x][y] = 'P';
        } else {
            printf("Invalid direction. Please try again.\n");
            return 1;
        }
    }

    return 0;
}