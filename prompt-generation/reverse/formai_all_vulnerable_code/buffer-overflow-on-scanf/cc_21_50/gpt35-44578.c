//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Ephemeral Adventure Game!\n");
    printf("Are you ready to begin? (y/n): ");
    
    char input;
    scanf(" %c", &input);
    
    if (input == 'y') {
        printf("Great! Let's begin...\n");
        
        // Define game variables
        int health = 100;
        int attack = 10;
        int defense = 5;
        int gold = 0;
        int level = 1;
        int boss_health = 150;
        
        // Define enemy variables
        char* enemies[] = {"Goblin", "Ogre", "Troll", "Dragon"};
        int enemy_attacks[] = {8, 12, 15, 20};
        int enemy_defenses[] = {2, 4, 6, 10};
        int enemy_healths[] = {50, 75, 100, 150};
        int enemy_gold[] = {10, 20, 30, 50};
        int enemy_levels[] = {1, 2, 3, 5};
        int num_enemies = sizeof(enemies) / sizeof(char*);
        
        // Define shop variables
        int shop_attack = 15;
        int shop_defense = 10;
        int shop_health = 50;
        int shop_price = 25;
        int has_potion = 0;
        
        // Seed random number generator
        srand(time(NULL));
        
        // Begin game loop
        while (health > 0) {
            // Print current stats
            printf("\nLEVEL: %d\nHEALTH: %d\nATTACK: %d\nDEFENSE: %d\nGOLD: %d\n", level, health, attack, defense, gold);
            
            // Print menu
            printf("\nWhat would you like to do?\n1) Go into the forest\n2) Visit the shop\n3) View inventory\n4) Quit game\n");
            
            int choice;
            scanf("%d", &choice);
            
            // Handle menu choice
            switch (choice) {
                case 1:
                    printf("\nYou enter the forest...\n");
                    
                    // Generate random enemy
                    int enemy_index = rand() % num_enemies;
                    char* enemy = enemies[enemy_index];
                    int enemy_attack = enemy_attacks[enemy_index];
                    int enemy_defense = enemy_defenses[enemy_index];
                    int enemy_health = enemy_healths[enemy_index];
                    int enemy_level = enemy_levels[enemy_index];
                    int enemy_reward = enemy_gold[enemy_index];
                    
                    printf("You stumble upon a %s!\n", enemy);
                    
                    // Begin battle loop
                    while (1) {
                        // Print health and enemy health
                        printf("\nYOUR HEALTH: %d\nENEMY HEALTH: %d\n", health, enemy_health);
                        
                        // Player's turn
                        printf("It's your turn to attack! How much damage do you want to deal? (1 - %d): ", attack);
                        
                        int player_attack;
                        scanf("%d", &player_attack);
                        
                        if (player_attack < 1 || player_attack > attack) {
                            printf("Invalid input. You lose your turn.\n");
                        }
                        else {
                            enemy_health -= player_attack;
                            printf("\nYou dealt %d damage! The %s has %d health remaining.\n", player_attack, enemy, enemy_health);
                        }
                        
                        // Check if enemy defeated
                        if (enemy_health <= 0) {
                            printf("\nCongratulations, you have defeated the %s! You earned %d gold.\n", enemy, enemy_reward);
                            gold += enemy_reward;
                            level += enemy_level;
                            break;
                        }
                        
                        // Enemy's turn
                        printf("\nIt's the %s's turn to attack! The %s deals %d damage. How much will you defend? (1 - %d): ", enemy, enemy, enemy_attack, defense);
                        
                        int player_defense;
                        scanf("%d", &player_defense);
                        
                        if (player_defense < 1 || player_defense > defense) {
                            printf("Invalid input. You lose your turn.\n");
                        }
                        else {
                            int damage = enemy_attack - player_defense;
                            if (damage <= 0) {
                                damage = 1;
                            }
                            health -= damage;
                            printf("\nThe %s dealt %d damage! You have %d health remaining.\n", enemy, damage, health);
                        }
                        
                        // Check if player defeated
                        if (health <= 0) {
                            printf("\nYou have been defeated!\n");
                            break;
                        }
                    }
                    
                    break;
                
                case 2:
                    printf("\nWelcome to the shop!\n");
                    printf("You can purchase a potion for 25 gold. This will restore your health to %d.\n", shop_health);
                    printf("You can also upgrade your attack for 25 gold, or your defense for 25 gold.\n");
                    printf("What would you like to purchase?\n1) Potion\n2) Attack upgrade\n3) Defense upgrade\n4) Leave shop\n");
                    
                    int shop_choice;
                    scanf("%d", &shop_choice);
                    
                    switch (shop_choice) {
                        case 1:
                            if (gold < shop_price) {
                                printf("\nYou do not have enough gold to purchase this item.\n");
                            }
                            else {
                                gold -= shop_price;
                                health = shop_health;
                                has_potion = 1;
                            }
                            break;
                        
                        case 2:
                            if (gold < shop_price) {
                                printf("\nYou do not have enough gold to purchase this item.\n");
                            }
                            else {
                                gold -= shop_price;
                                attack = shop_attack;
                            }
                            break;
                        
                        case 3:
                            if (gold < shop_price) {
                                printf("\nYou do not have enough gold to purchase this item.\n");
                            }
                            else {
                                gold -= shop_price;
                                defense = shop_defense;
                            }
                            break;
                        
                        case 4:
                            printf("\nThanks for stopping by!\n");
                            break;
                        
                        default:
                            printf("\nInvalid input.\n");
                            break;
                    }
                    
                    break;
                
                case 3:
                    printf("\nINVENTORY:\n");
                    
                    if (has_potion) {
                        printf("- Potion\n");
                    }
                    else {
                        printf("- No items\n");
                    }
                    
                    break;
                
                case 4:
                    printf("\nThanks for playing the Ephemeral Adventure Game!\n");
                    return 0;
                
                default:
                    printf("\nInvalid input.\n");
                    break;
            }
            
            // Check if player can battle boss
            if (level == 10) {
                printf("\nYou have reached the end of your journey!\n");
                printf("A ferocious dragon awaits you. Are you ready to take on the challenge? (y/n): ");
                
                char boss_input;
                scanf(" %c", &boss_input);
                
                if (boss_input == 'y') {
                    printf("\nYou face the dragon...\n");
                    
                    while (1) {
                        // Print health and boss health
                        printf("\nYOUR HEALTH: %d\nENEMY HEALTH: %d\n", health, boss_health);
                        
                        // Player's turn
                        printf("It's your turn to attack! How much damage do you want to deal? (1 - %d): ", attack);
                        
                        int player_attack;
                        scanf("%d", &player_attack);
                        
                        if (player_attack < 1 || player_attack > attack) {
                            printf("Invalid input. You lose your turn.\n");
                        }
                        else {
                            boss_health -= player_attack;
                            printf("\nYou dealt %d damage! The dragon has %d health remaining.\n", player_attack, boss_health);
                        }
                        
                        // Check if boss defeated
                        if (boss_health <= 0) {
                            printf("\nCongratulations, you have defeated the dragon! You have won the game!\n");
                            return 0;
                        }
                        
                        // Boss's turn
                        printf("\nIt's the dragon's turn to attack! The dragon deals %d damage. How much will you defend? (1 - %d): ", 25, defense);
                        
                        int player_defense;
                        scanf("%d", &player_defense);
                        
                        if (player_defense < 1 || player_defense > defense) {
                            printf("Invalid input. You lose your turn.\n");
                        }
                        else {
                            int damage = 25 - player_defense;
                            if (damage <= 0) {
                                damage = 1;
                            }
                            health -= damage;
                            printf("\nThe dragon dealt %d damage! You have %d health remaining.\n", damage, health);
                        }
                        
                        // Check if player defeated
                        if (health <= 0) {
                            printf("\nYou have been defeated!\n");
                            break;
                        }
                    }
                }
                else {
                    printf("\nGame over.\n");
                    return 0;
                }
            }
        }
    }
    else {
        printf("Goodbye!\n");
    }
    
    return 0;
}