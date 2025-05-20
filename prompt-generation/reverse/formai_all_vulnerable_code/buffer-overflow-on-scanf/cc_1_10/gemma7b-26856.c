//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void play_game() {
    // Define the game map
    int map[] = {
        1, 1, 1, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 0, 0, 0, 0,
        1, 0, 0, 0, 1
    };

    // Get the player's starting position
    int x = 0;
    int y = 0;

    // Loop until the player reaches the treasure
    while (map[y * 5 + x] != 3) {
        // Get the player's input
        char input;

        // Display the game map
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (map[i * 5 + j] == 1) {
                    printf("%c ", '*');
                } else if (map[i * 5 + j] == 2) {
                    printf("%c ", '.');
                } else if (map[i * 5 + j] == 3) {
                    printf("%c ", '#');
                } else {
                    printf("%c ", ' ');
                }
            }
            printf("\n");
        }

        // Move the player
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &input);

        // Validate the player's input
        switch (input) {
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
    }

    // The player has reached the treasure
    printf("You have found the treasure!\n");
}

int main() {
    play_game();

    return 0;
}