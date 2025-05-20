//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ghost_position = 5; // Initialize starting position of ghost
    int player_position = 1; // Initialize starting position of player
    int move_count = 0; // Initialize move count to 0
    int player_moves; // Initialize variable to store player moves
    srand(time(NULL)); // Initialize random number generator

    printf("Welcome to the Haunted House Simulator Game!\n");
    printf("You are trapped in a haunted house and need to escape before the ghost catches you!\n");
    
    // Game loop
    while (player_position < 10) {
        printf("You are currently in room %d. The ghost is in room %d.\n", player_position, ghost_position);
        printf("Enter the number of moves you want to make in this turn (1-2): ");
        scanf("%d", &player_moves);
        
        // Check if player entered valid move count
        if (player_moves < 1 || player_moves > 2) {
            printf("Invalid move count! Please enter a number between 1 and 2.\n");
            continue;
        }
        
        // Move player
        player_position += player_moves;
        
        // Move ghost
        ghost_position += (rand() % 2) + 1;

        // Display current positions
        printf("You moved %d rooms and are now in room %d.\n", player_moves, player_position);
        printf("The ghost moved %d rooms and is now in room %d.\n", (rand() % 2) + 1, ghost_position);
        
        // Check for collision with ghost
        if (player_position == ghost_position) {
            printf("Oh no! You were caught by the ghost and lost the game.\n");
            break;
        }
        
        // Increment move count
        move_count++;
    }
    
    // Check if player won the game
    if (player_position >= 10) {
        printf("Congratulations! You escaped the haunted house in %d moves and won the game!\n", move_count);
    }
    
    return 0;
}