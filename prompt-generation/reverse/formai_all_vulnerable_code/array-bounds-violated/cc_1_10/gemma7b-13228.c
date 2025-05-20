//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the adventure game map
char map[5][5] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'J'},
    {'K', 'L', 'M', 'N', 'O'},
    {'P', 'Q', 'R', 'S', 'T'},
    {'U', 'V', 'W', 'X', 'Y'}
};

// Define the player's position
int player_x = 0;
int player_y = 0;

// Define the player's inventory
char inventory[10] = "";

// Define the game loop
void play_game() {
    // Display the map
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            printf("%c ", map[y][x]);
        }
        printf("\n");
    }

    // Get the player's input
    char input;
    printf("Enter your move (N, S, E, W): ");
    scanf(" %c", &input);

    // Move the player
    switch (input) {
        case 'N':
            player_y--;
            break;
        case 'S':
            player_y++;
            break;
        case 'E':
            player_x++;
            break;
        case 'W':
            player_x--;
            break;
    }

    // Check if the player has reached the end of the game
    if (map[player_y][player_x] == 'E') {
        printf("You have won the game!");
    } else {
        play_game();
    }
}

int main() {
    // Initialize the game
    play_game();

    return 0;
}