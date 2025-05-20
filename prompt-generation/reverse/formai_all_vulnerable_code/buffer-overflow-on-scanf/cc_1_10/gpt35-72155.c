//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random numbers
    int player_hp = 100; // Player's health points
    int enemy_hp = 100; // Enemy's health points
    printf("You have entered a mysterious castle...\n");
    printf("A dragon suddenly appears and attacks you!\n");
    
    while (1) { // Loop until either player or enemy is defeated
        int attack_choice; // Variable to store player's attack choice
        printf("Your HP: %d\n", player_hp); // Display player's HP
        printf("Dragon's HP: %d\n", enemy_hp); // Display enemy's HP
        printf("Choose your attack:\n");
        printf("1. Sword Slash\n");
        printf("2. Magic Blast\n");
        scanf("%d", &attack_choice); // Take player's attack choice input
        
        int player_attack; // Variable to store player's damage
        int enemy_attack; // Variable to store enemy's damage
        
        switch (attack_choice) { // Determine player's attack type
            case 1: // Sword Slash
                player_attack = rand() % 11 + 15; // Random number between 15 and 25
                printf("You use your sword to slash the dragon for %d damage!\n", player_attack);
                break;
            case 2: // Magic Blast
                player_attack = rand() % 6 + 25; // Random number between 25 and 30
                printf("You cast a magic blast at the dragon for %d damage!\n", player_attack);
                break;
            default: // Invalid input
                printf("Invalid choice! Please choose again.\n");
                continue; // Restart loop to take valid input
        }
        
        enemy_hp -= player_attack; // Subtract player's damage from enemy's HP
        if (enemy_hp <= 0) { // Enemy defeated
            printf("You have defeated the dragon!\n");
            break; // End game
        }
        
        enemy_attack = rand() % 11 + 10; // Random number between 10 and 20
        player_hp -= enemy_attack; // Subtract enemy's damage from player's HP
        printf("The dragon attacks you for %d damage!\n", enemy_attack);
        if (player_hp <= 0) { // Player defeated
            printf("You have been defeated by the dragon...\n");
            break; // End game
        }       
    }   
    return 0;
}