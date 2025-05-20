//GPT-4o-mini DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_HEALTH 100
#define ATTACK_DAMAGE 20
#define HEAL_AMOUNT 15

typedef struct {
    char name[20];
    int health;
    int level;
} Player;

typedef struct {
    char enemyName[20];
    int enemyHealth;
    int enemyLevel;
} Enemy;

// Function prototypes
void displayIntro(Player *player);
void generateEnemies(Enemy *enemies, int count);
void battle(Player *player, Enemy *enemy);
void playerTurn(Player *player, Enemy *enemy);
void enemyTurn(Player *player, Enemy *enemy);
void heal(Player *player);
void displayStats(Player *player, Enemy *enemy);
void clearScreen();

// Main function
int main() {
    srand(time(NULL));
    
    Player player;
    Enemy enemies[MAX_ENEMIES];

    printf("Enter your character's name: ");
    scanf("%s", player.name);
    player.health = MAX_HEALTH;
    player.level = 1;

    displayIntro(&player);
    generateEnemies(enemies, MAX_ENEMIES);

    for (int i = 0; i < MAX_ENEMIES; i++) {
        printf("\nA wild %s appears!\n", enemies[i].enemyName);
        battle(&player, &enemies[i]);
        if (player.health <= 0) {
            printf("\nYou have been defeated. Game Over.\n");
            return 0;
        }
    }

    printf("\nCongratulations, %s! You have defeated all enemies!\n", player.name);
    return 0;
}

// Function to display the introductory message
void displayIntro(Player *player) {
    clearScreen();
    printf("Welcome, brave %s!\n", player->name);
    printf("Your adventure begins now!\n");
}

// Function to generate enemies
void generateEnemies(Enemy *enemies, int count) {
    char *enemyNames[] = {"Goblin", "Troll", "Skeleton", "Orc", "Zombie"};
    for (int i = 0; i < count; i++) {
        int randomIndex = rand() % 5;
        snprintf(enemies[i].enemyName, sizeof(enemies[i].enemyName), "%s", enemyNames[randomIndex]);
        enemies[i].enemyHealth = MAX_HEALTH;
        enemies[i].enemyLevel = 1;
    }
}

// Function to simulate battle with the enemy
void battle(Player *player, Enemy *enemy) {
    while (player->health > 0 && enemy->enemyHealth > 0) {
        displayStats(player, enemy);
        playerTurn(player, enemy);

        if (enemy->enemyHealth > 0) {
            enemyTurn(player, enemy);
        }
    }
}

// Function for player's turn
void playerTurn(Player *player, Enemy *enemy) {
    int choice;
    printf("\nYour turn! Choose an action:\n");
    printf("1. Attack\n");
    printf("2. Heal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("%s attacks %s dealing %d damage!\n", player->name, enemy->enemyName, ATTACK_DAMAGE);
        enemy->enemyHealth -= ATTACK_DAMAGE;
    } else if (choice == 2) {
        heal(player);
    } else {
        printf("Invalid choice! You lose your turn.\n");
    }
}

// Function for enemy's turn
void enemyTurn(Player *player, Enemy *enemy) {
    printf("%s attacks you dealing %d damage!\n", enemy->enemyName, ATTACK_DAMAGE);
    player->health -= ATTACK_DAMAGE;
}

// Function to heal the player
void heal(Player *player) {
    if (player->health + HEAL_AMOUNT > MAX_HEALTH) {
        player->health = MAX_HEALTH;
    } else {
        player->health += HEAL_AMOUNT;
    }
    printf("%s heals for %d health!\n", player->name, HEAL_AMOUNT);
}

// Function to display the player and enemy stats
void displayStats(Player *player, Enemy *enemy) {
    printf("\n----- Stats -----\n");
    printf("Player (%s) Health: %d\n", player->name, player->health);
    printf("Enemy (%s) Health: %d\n", enemy->enemyName, enemy->enemyHealth);
    printf("------------------\n");
}

// Function to clear the console screen
void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the terminal screen
}