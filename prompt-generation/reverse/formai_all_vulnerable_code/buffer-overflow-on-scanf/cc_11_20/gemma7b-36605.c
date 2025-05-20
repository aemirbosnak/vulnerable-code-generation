//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the map of the town
char map[10][10] = {
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'S', 'S', 'S', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'S', 'N', 'S', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'S', 'S', 'N', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
};

int main() {
    // Initialize the player's position
    int x = 0;
    int y = 0;

    // Loop until the player exits the town
    while (1) {
        // Display the map
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        printf("Enter your move (N, S, E, W): ");
        scanf("%c", &input);

        // Move the player
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
        }

        // Check if the player has reached the exit
        if (map[y][x] == 'E') {
            printf("You have exited the town!");
            break;
        }

        // Check if the player has walked off the map
        if (x < 0 || x >= 10 || y < 0 || y >= 10) {
            printf("You have walked off the map!");
            break;
        }
    }

    return 0;
}