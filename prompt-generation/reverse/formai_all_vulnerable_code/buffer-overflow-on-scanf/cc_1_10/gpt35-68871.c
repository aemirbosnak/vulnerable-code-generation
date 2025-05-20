//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int generate_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Define the player structure
typedef struct player {
    char name[50];
    int health;
    int num_lasers;
    int num_missiles;
} Player;

// Define the enemy structure
typedef struct enemy {
    char type[50];
    int health;
    int damage;
} Enemy;

// Function to initialize player
void initialize_player(Player *player) {
    printf("Enter your name: ");
    scanf("%s", (*player).name);
    (*player).health = 100;
    (*player).num_lasers = 10;
    (*player).num_missiles = 5;
}

// Function to initialize enemy
void initialize_enemy(Enemy *enemy) {
    int num = generate_random(1, 3);
    switch(num) {
        case 1:
            (*enemy).health = 50;
            (*enemy).damage = 10;
            sprintf((*enemy).type, "Small Alien");
            break;
        case 2:
            (*enemy).health = 75;
            (*enemy).damage = 15;
            sprintf((*enemy).type, "Medium Alien");
            break;
        case 3:
            (*enemy).health = 100;
            (*enemy).damage = 20;
            sprintf((*enemy).type, "Large Alien");
            break;
    }
}

// Main game loop
int main() {
    printf("Welcome to Procedural Space Adventure!\n");
    Player player;
    initialize_player(&player);
    
    // Set up the random number generator
    srand(time(NULL));
    
    // Loop through the game until the player's health reaches zero
    int score = 0;
    int num_enemies = 0;
    while(player.health > 0) {
        // Initialize a new enemy
        Enemy enemy;
        initialize_enemy(&enemy);
        num_enemies++;
        
        // Print enemy information
        printf("\n\n\nYou have encountered a %s!\n", enemy.type);
        printf("It has %d health and does %d damage per attack.\n", enemy.health, enemy.damage);
        
        // Loop through the combat until either the player or enemy has been defeated
        while(player.health > 0 && enemy.health > 0) {
            // Print player information
            printf("\n\n\nYour health: %d\n", player.health);
            printf("Your laser ammo: %d\n", player.num_lasers);
            printf("Your missile ammo: %d\n", player.num_missiles);
            
            // Get the player's choice of action
            printf("\nWhat will you do?\n");
            printf("1. Shoot lasers\n");
            printf("2. Shoot missiles\n");
            printf("3. Run away\n");
            int choice;
            scanf("%d", &choice);
            
            // Perform the player's chosen action
            switch(choice) {
                case 1:
                    if(player.num_lasers > 0) {
                        printf("\nYou shoot the enemy with your lasers!\n");
                        enemy.health -= generate_random(5, 15);
                        player.num_lasers--;
                    } else {
                        printf("\nYou're all out of laser ammo!\n");
                    }
                    break;
                case 2:
                    if(player.num_missiles > 0) {
                        printf("\nYou shoot the enemy with your missiles!\n");
                        enemy.health -= generate_random(15, 25);
                        player.num_missiles--;
                    } else {
                        printf("\nYou're all out of missile ammo!\n");
                    }
                    break;
                case 3:
                    printf("\nYou run away from the %s!\n", enemy.type);
                    enemy.health = 0;
                    break;
                default:
                    printf("\nInvalid choice, try again!\n");
                    break;
            }
            
            // If the enemy is still alive, have them attack the player
            if(enemy.health > 0) {
                int enemy_damage = generate_random(5, enemy.damage);
                printf("\nThe %s attacks you for %d damage!\n", enemy.type, enemy_damage);
                player.health -= enemy_damage;
            }
        }
        
        // If the player is still alive, print victory message and increase the score
        if(player.health > 0) {
            printf("\n\n\nYou have defeated the %s!\n", enemy.type);
            printf("Your health is now %d\n", player.health);
            score += enemy.health;
        }
    }
    
    // Print game over message with score and number of enemies defeated
    printf("\n\n\nGame over! You defeated %d enemies and scored %d points!\n", num_enemies, score);
    
    return 0;
}