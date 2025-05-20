//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct player {
    char name[50];
    int health;
    int attack;
    int defense;
    int gold;
};

// Function to initialize player stats
void initialize_player(struct player *p, char *name) {
    strcpy(p->name, name);
    p->health = 100;
    p->attack = 5;
    p->defense = 2;
    p->gold = 0;
}

// Function to generate a random number between min and max
int generate_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate a battle between players
void simulate_battle(struct player *p1, struct player *p2) {
    // Loop until one player's health reaches 0
    while (p1->health > 0 && p2->health > 0) {
        // Player 1 attacks Player 2
        int damage = generate_random(p1->attack, p1->attack + 5) - p2->defense;
        if (damage < 0) {
            damage = 0;
        }
        printf("%s attacks %s and deals %d damage.\n", p1->name, p2->name, damage);
        p2->health -= damage;
        if (p2->health <= 0) {
            printf("%s has been defeated!\n", p2->name);
            printf("%s gains %d gold.\n", p1->name, p2->gold);
            p1->gold += p2->gold;
            return;
        }
        // Player 2 attacks Player 1
        damage = generate_random(p2->attack, p2->attack + 5) - p1->defense;
        if (damage < 0) {
            damage = 0;
        }
        printf("%s attacks %s and deals %d damage.\n", p2->name, p1->name, damage);
        p1->health -= damage;
        if (p1->health <= 0) {
            printf("%s has been defeated!\n", p1->name);
            printf("%s gains %d gold.\n", p2->name, p1->gold);
            p2->gold += p1->gold;
            return;
        }
    }
}

int main() {
    // Set random seed
    srand(time(NULL));
    
    printf("Welcome to the Adventure Game! Please enter your name: ");
    char name[50];
    scanf("%s", name);
    struct player player1;
    initialize_player(&player1, name);
    printf("Welcome, %s! You have been given 100 health, 5 attack, and 2 defense.\n", name);
    
    // Start game loop
    int playing = 1;
    while (playing) {
        printf("\n%s, what would you like to do? (1) Battle (2) Shop (3) Quit\n", player1.name);
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            // Battle random enemy
            char enemy_name[50];
            sprintf(enemy_name, "Enemy%d", generate_random(1, 5));
            struct player enemy;
            initialize_player(&enemy, enemy_name);
            enemy.attack = generate_random(3, 8);
            enemy.defense = generate_random(1, 5);
            enemy.gold = generate_random(5, 15);
            
            printf("You are facing %s! Good luck!\n", enemy.name);
            simulate_battle(&player1, &enemy);
        } else if (choice == 2) {
            // Enter shop
            int shop_open = 1;
            while (shop_open) {
                printf("Welcome to the shop! You currently have %d gold. What would you like to buy? (1) Health Potion (10 gold) (2) Attack Upgrade (25 gold) (3) Defense Upgrade (20 gold) (4) Leave shop\n", player1.gold);
                int shop_choice;
                scanf("%d", &shop_choice);
                if (shop_choice == 1) {
                    if (player1.gold >= 10) {
                        player1.health += 50;
                        player1.gold -= 10;
                        printf("You bought a health potion. %s's health is now %d.\n", player1.name, player1.health);
                    } else {
                        printf("You do not have enough gold.\n");
                    }
                } else if (shop_choice == 2) {
                    if (player1.gold >= 25) {
                        player1.attack += 5;
                        player1.gold -= 25;
                        printf("You bought an attack upgrade. %s's attack is now %d.\n", player1.name, player1.attack);
                    } else {
                        printf("You do not have enough gold.\n");
                    }
                } else if (shop_choice == 3) {
                    if (player1.gold >= 20) {
                        player1.defense += 2;
                        player1.gold -= 20;
                        printf("You bought a defense upgrade. %s's defense is now %d.\n", player1.name, player1.defense);
                    } else {
                        printf("You do not have enough gold.\n");
                    }
                } else if (shop_choice == 4) {
                    shop_open = 0;
                    printf("Leaving shop...\n");
                }
            }
        } else if (choice == 3) {
            // Quit game
            printf("Thanks for playing Adventure Game!\n");
            playing = 0;
        } else {
            printf("Invalid choice. Please choose again.\n");
        }
    }
    
    return 0;
}