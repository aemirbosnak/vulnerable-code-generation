//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int playing = 1;
    char response[10]; // Store user inputs
    int health = 100;
    int ghostsKilled = 0;
    int floorsCleared = 0;
    int level = 1;
    
    // Setting up random numbers
    srand(time(NULL));
    int ghostHealth = rand() % 20 + 10;
    int ghostAttack = rand() % 10 + 5;
    int floorGhostChance = rand() % 10 + 1; // 1 in 10 chance of encountering a ghost on each floor
    
    // Introductory message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are on the ground floor of the haunted house.\n");
    printf("Type 'play' to begin.\n");
    
    // Main game loop
    while (playing) {
        scanf("%s", &response); // Store user input
        
        // Handling user input
        if (strcmp(response, "play") == 0) {
            // Starting the game
            printf("You ascend to the first floor...\n");
            printf("You encounter a ghost!\n");
            printf("Press 'fight' to begin the battle, or 'run' to try to escape.\n");
        } else if (strcmp(response, "fight") == 0) {
            // Battle logic
            while (ghostHealth > 0 && health > 0) {
                printf("You attack the ghost for %d damage!\n", rand() % 10 + 5);
                ghostHealth -= rand() % 10 + 5;
                printf("The ghost attacks you for %d damage!\n", ghostAttack);
                health -= ghostAttack;
            }
            
            if (ghostHealth <= 0) {
                // If the ghost is defeated
                ghostsKilled++;
                printf("Congratulations! You defeated the ghost!\n");
                if (ghostsKilled == (level * 2)) {
                    // If all ghosts on the current level are defeated, proceed to the next level
                    level++;
                    floorsCleared++;
                    printf("You ascend to the next level...\n");
                    ghostHealth = rand() % (20 * level) + (10 * level); // Ghost health and attack scales with level
                    ghostAttack = rand() % (10 * level) + (5 * level);
                    floorGhostChance = rand() % 10 + 1; // Reset ghost spawn chance
                } else {
                    // Otherwise, proceed to the next floor if there is a ghost spawn chance
                    if (rand() % 10 + 1 <= floorGhostChance) {
                        printf("You ascend to the next floor...\n");
                        printf("You encounter a ghost!\n");
                        printf("Press 'fight' to begin the battle, or 'run' to try to escape.\n");
                        ghostHealth = rand() % (20 * level) + (10 * level);
                        ghostAttack = rand() % (10 * level) + (5 * level);
                    } else {
                        printf("You ascend to the next floor...\n");
                        printf("You are safe... for now.\n");
                        floorsCleared++;
                        floorGhostChance = rand() % 10 + 1;
                    }
                }
            } else {
                // If the player loses
                printf("You were defeated by the ghost...\n");
                printf("You cleared %d floors and defeated %d ghosts.\n", floorsCleared, ghostsKilled);
                playing = 0; // End game loop
            }
        } else if (strcmp(response, "run") == 0) {
            // Attempt to escape
            if (rand() % 2 == 0) {
                printf("You successfully escaped!\n");
                printf("You cleared %d floors and defeated %d ghosts.\n", floorsCleared, ghostsKilled);
                playing = 0;
            } else {
                printf("You were unable to escape and are forced to fight the ghost!\n");
                printf("Press 'fight' to begin the battle.\n");
            }
        }
    }
    
    return 0;
}