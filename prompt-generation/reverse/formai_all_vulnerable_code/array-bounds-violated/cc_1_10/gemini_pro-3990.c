//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
int player_x, player_y;
char map[10][10];

// Function to print the map
void print_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to handle player movement
void* move_player(void* arg) {
    while (1) {
        // Get the player's input
        char input = getchar();

        // Move the player based on the input
        switch (input) {
            case 'w':
                player_y--;
                break;
            case 's':
                player_y++;
                break;
            case 'a':
                player_x--;
                break;
            case 'd':
                player_x++;
                break;
        }

        // Check if the player has reached the exit
        if (map[player_y][player_x] == 'E') {
            printf("You win!\n");
            exit(0);
        }

        // Print the updated map
        print_map();
    }

    return NULL;
}

// Main function
int main() {
    // Initialize the map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '.';
        }
    }

    // Place the player on the map
    player_x = 0;
    player_y = 0;
    map[player_y][player_x] = 'P';

    // Place the exit on the map
    map[9][9] = 'E';

    // Create a thread to handle player movement
    pthread_t thread;
    pthread_create(&thread, NULL, move_player, NULL);

    // Keep the main thread running to handle user input
    while (1) {
        // Get the user's input
        char input = getchar();

        // Exit the game if the user enters 'q'
        if (input == 'q') {
            exit(0);
        }
    }

    return 0;
}