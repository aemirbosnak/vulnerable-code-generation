//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize the game world
    char world[5][6] = {
        {"******"},
        {"*    *"},
        {"*    *"},
        {"*    *"},
        {"******"},
    };
    int player_x = 1;
    int player_y = 1;

    // Main game loop
    while (1) {
        // Print the game world
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                printf("%c", world[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        printf("Enter a direction to move (w, a, s, d): ");
        scanf(" %c", &input);

        // Move the player
        switch (input) {
            case 'w':
                if (player_y > 0 && world[player_y - 1][player_x] != '*') {
                    player_y--;
                }
                break;
            case 'a':
                if (player_x > 0 && world[player_y][player_x - 1] != '*') {
                    player_x--;
                }
                break;
            case 's':
                if (player_y < 4 && world[player_y + 1][player_x] != '*') {
                    player_y++;
                }
                break;
            case 'd':
                if (player_x < 5 && world[player_y][player_x + 1] != '*') {
                    player_x++;
                }
                break;
        }

        // Check if the player has won
        if (player_x == 4 && player_y == 3) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}