//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the main adventure function
int main() {

    // Create a hero named Jack
    char hero_name[] = "Jack";

    // Initialize the hero's inventory
    int inventory[3] = {0, 0, 0};

    // Define the game map
    int map[5][5] = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 0, 1, 1}
    };

    // Start the adventure
    while (1) {

        // Display the game map
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                printf("%c ", map[row][col]);
            }
            printf("\n");
        }

        // Get the hero's move
        char move;
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &move);

        // Move the hero
        switch (move) {
            case 'N':
                inventory[1]++;
                map[hero_name[0] - 'a'][hero_name[1] - 'a']--;
                printf("You moved north.\n");
                break;
            case 'S':
                inventory[1]--;
                map[hero_name[0] - 'a'][hero_name[1] - 'a']++;
                printf("You moved south.\n");
                break;
            case 'E':
                inventory[2]++;
                map[hero_name[0] - 'a'][hero_name[1] - 'a']--;
                printf("You moved east.\n");
                break;
            case 'W':
                inventory[2]--;
                map[hero_name[0] - 'a'][hero_name[1] - 'a']++;
                printf("You moved west.\n");
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check if the hero has won or lost
        if (inventory[2] == 3) {
            printf("You have won!\n");
            break;
        } else if (map[hero_name[0] - 'a'][hero_name[1] - 'a'] == 0) {
            printf("You have lost.\n");
            break;
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}