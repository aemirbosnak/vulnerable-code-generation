//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_TURNS 10

int main() {
    // Set seed for random number generation
    srand(time(NULL));
    
    // Game start
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are in a post-apocalyptic world and have stumbled upon a haunted house.\n");
    printf("You have %d turns to explore the house and find the treasure before the ghosts get you!\n", MAX_TURNS);
    
    // Initialize player and room variables
    int player_health = 100;
    int player_score = 0;
    int current_room = 1;
    int found_treasure = 0;
    
    // Create the rooms
    int rooms[MAX_ROOMS][2];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i][0] = rand() % 100 + 1;  // Ghost health
        rooms[i][1] = rand() % 2;        // Treasure (0 = no treasure, 1 = treasure)
    }
    
    // Game loop
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        // Print player status
        printf("Turn %d:\n", turn+1);
        printf("Health: %d\nScore: %d\n", player_health, player_score);
        
        // Print room and ghost status
        printf("You are in room %d.\n", current_room);
        printf("There is a ghost with %d health in the room.\n", rooms[current_room-1][0]);
        if (rooms[current_room-1][1]) {
            printf("You have found the treasure in this room!\n");
            player_score += 10;
            found_treasure = 1;
        }
        
        // Prompt player to take action
        printf("What do you want to do?\n");
        printf("1. Attack ghost\n");
        printf("2. Move to next room\n");
        printf("3. Quit game\n");
        int choice;
        scanf("%d", &choice);
        
        // Process player's choice
        switch(choice) {
            case 1:
                // Attack the ghost
                printf("You attack the ghost!\n");
                rooms[current_room-1][0] -= rand() % 20 + 1;
                if (rooms[current_room-1][0] <= 0) {
                    printf("You have defeated the ghost!\n");
                    player_score += 5;
                } else {
                    printf("The ghost now has %d health left.\n", rooms[current_room-1][0]);
                    // Ghost attacks player
                    int damage = rand() % 10 + 1;
                    player_health -= damage;
                    printf("The ghost attacks you and deals %d damage.\n", damage);
                }
                break;
            case 2:
                // Move to next room
                if (current_room == MAX_ROOMS) {
                    printf("You have reached the last room!\n");
                } else {
                    printf("You move to the next room.\n");
                    current_room++;
                }
                break;
            case 3:
                // Quit game
                printf("Thanks for playing!\n");
                return 0;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
        }
        
        // Check if player has found all the treasure
        if (found_treasure && player_score == MAX_ROOMS*10) {
            printf("Congratulations! You have found all the treasure and won the game!\n");
            printf("Final score: %d\n", player_score);
            return 0;
        }
        
        // Check if player is still alive
        if (player_health <= 0) {
            printf("You have been defeated by the ghosts.\n");
            printf("Final score: %d\n", player_score);
            return 0;
        }
        
        // Give player some time to read
        printf("\n");
    }
    
    // If player runs out of turns
    printf("You have run out of turns!\n");
    printf("Final score: %d\n", player_score);
    return 0;
}