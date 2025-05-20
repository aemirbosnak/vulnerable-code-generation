//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed RNG
    
    // Introductory text
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dense forest, with no idea how you got here.\n");
    printf("You can go: north, south, east, or west. Choose wisely.\n\n");
    
    // Variables to track position and health
    int position_x = 0;
    int position_y = 0;
    int health = 100;
    
    // Game loop
    while (health > 0) {
        // Print current position and health
        printf("Your position: (%d, %d)\n", position_x, position_y);
        printf("Your health: %d\n", health);
        
        // Prompt for user input
        printf("Where would you like to go? ");
        char input[10];
        scanf("%s", input);
        
        // Determine the new position based on user input
        int new_position_x = position_x;
        int new_position_y = position_y;
        
        if (strcmp(input, "north") == 0) {
            new_position_y++;
        } else if (strcmp(input, "south") == 0) {
            new_position_y--;
        } else if (strcmp(input, "east") == 0) {
            new_position_x++;
        } else if (strcmp(input, "west") == 0) {
            new_position_x--;
        } else {
            // Invalid input
            printf("Invalid input. Please enter north, south, east, or west.\n\n");
            continue;
        }
        
        // Calculate the distance traveled
        int distance = abs(new_position_x - position_x) + abs(new_position_y - position_y);
        printf("You travel %d steps.\n", distance);
        
        // Random chance for an encounter
        int encounter_chance = rand() % 10;
        if (encounter_chance == 0) {
            // Battle!
            printf("You have encountered an enemy!\n");
            int enemy_strength = rand() % 50 + 1; // enemy strength between 1 and 50
            printf("The enemy has a strength of %d.\n", enemy_strength);
            printf("You engage in battle...\n");
            int damage_to_enemy = rand() % 20 + 1; // damage between 1 and 20
            int damage_to_player = rand() % enemy_strength + 1; // damage between 1 and enemy strength
            if (damage_to_enemy > enemy_strength * 0.8) {
                printf("Critical hit! You dealt %d damage to the enemy.\n", damage_to_enemy);
            } else {
                printf("You dealt %d damage to the enemy.\n", damage_to_enemy);
            }
            health -= damage_to_player;
            if (health <= 0) {
                printf("You have been defeated...\n");
                break;
            }
            printf("The enemy dealt %d damage to you.\n", damage_to_player);
        }
        
        // Update position
        position_x = new_position_x;
        position_y = new_position_y;
        
        // Check if player has won
        if (position_x == 10 && position_y == 10) {
            printf("Congrats! You have found the treasure and won the game!\n");
            break;
        }
    }
    
    printf("Thanks for playing!\n");
    
    return 0;
}