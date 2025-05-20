//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10 // Number of rooms in the haunted house

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the variables
    int current_room = 0; // The room the player is currently in
    int ghost_room = rand() % ROOMS; // The room the ghost is in (randomly selected)
    int exit_room = rand() % ROOMS; // The room the exit is in (randomly selected)
    int num_moves = 0; // Number of moves the player has made
    
    // Welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently in Room 0. Your goal is to find the exit before the ghost finds you.\n");
    
    // Main game loop
    while(1) {
        // Check if the player is in the same room as the ghost
        if(current_room == ghost_room) {
            printf("Oh no! You found the ghost! Game over.\n");
            break;
        }
        
        // Check if the player is in the exit room
        if(current_room == exit_room) {
            printf("Congratulations! You found the exit in %d moves.\n", num_moves);
            break;
        }
        
        // Generate a list of possible moves for the player
        int possible_moves[3], num_possible_moves = 0;
        if(current_room > 0) {
            possible_moves[num_possible_moves++] = -1; // Move to the previous room
        }
        if(current_room < ROOMS - 1) {
            possible_moves[num_possible_moves++] = 1; // Move to the next room
        }
        possible_moves[num_possible_moves++] = 0; // Stay in the current room
        
        // Print the possible moves to the player
        printf("You are currently in Room %d. Possible moves: ", current_room);
        for(int i = 0; i < num_possible_moves; i++) {
            if(possible_moves[i] == -1) {
                printf("Previous Room ");
            }
            else if(possible_moves[i] == 1) {
                printf("Next Room ");
            }
            else {
                printf("Stay ");
            }
        }
        printf("\n");
        
        // Get the player's move
        int player_move;
        printf("Enter your move: ");
        scanf("%d", &player_move);
        
        // Validate the player's move
        int valid_move = 0;
        for(int i = 0; i < num_possible_moves; i++) {
            if(player_move == possible_moves[i]) {
                valid_move = 1;
                break;
            }
        }
        if(!valid_move) {
            printf("Invalid move. Please try again.");
            continue;
        }
        
        // Update the player's position and number of moves
        current_room += player_move;
        num_moves++;
        
        // Randomly move the ghost
        if(rand() % 2) {
            if(ghost_room < ROOMS - 1) {
                ghost_room++; // Move the ghost to the next room
            }
        }
        else {
            if(ghost_room > 0) {
                ghost_room--; // Move the ghost to the previous room
            }
        }
    }
    
    return 0;
}