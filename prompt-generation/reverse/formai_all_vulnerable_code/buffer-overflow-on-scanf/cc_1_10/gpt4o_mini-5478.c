//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define game constants
#define MAX_HEALTH 100
#define MAX_ENEMY_HEALTH 50
#define NUM_ENEMIES 3

// Define actions
typedef enum {
    ACTION_ATTACK,
    ACTION_HEAL,
    ACTION_RUN,
    ACTION_EXIT
} Action;

// Define Enemy structure
typedef struct {
    char name[20];
    int health;
    int damage;
} Enemy;

// Function declarations
void printStatus(int playerHealth, Enemy enemies[], int numEnemies);
Action chooseAction();
void attack(Enemy *enemy, int *playerHealth);
void heal(int *playerHealth);
void run();

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Player health
    int playerHealth = MAX_HEALTH;
    
    // Initialize enemies
    Enemy enemies[NUM_ENEMIES] = {
        {"Goblin", MAX_ENEMY_HEALTH, 10},
        {"Orc", MAX_ENEMY_HEALTH, 15},
        {"Troll", MAX_ENEMY_HEALTH, 20}
    };

    int currentEnemy = 0;

    printf("Welcome to the Mathematical Battle Adventure!\n\n");

    while (playerHealth > 0 && currentEnemy < NUM_ENEMIES) {
        // Print player and enemy status
        printStatus(playerHealth, enemies, NUM_ENEMIES);

        // Player chooses an action
        Action action = chooseAction();

        switch (action) {
            case ACTION_ATTACK:
                attack(&enemies[currentEnemy], &playerHealth);
                if (enemies[currentEnemy].health <= 0) {
                    printf("You have defeated the %s!\n\n", enemies[currentEnemy].name);
                    currentEnemy++;
                }
                break;
            case ACTION_HEAL:
                heal(&playerHealth);
                break;
            case ACTION_RUN:
                run();
                playerHealth = 0;  // Set player's health to 0 to end the game
                break;
            case ACTION_EXIT:
                printf("Exiting the game. Goodbye!\n");
                exit(0);
        }
        
        // Enemy attacks
        if (enemies[currentEnemy].health > 0) {
            printf("The %s attacks you for %d damage!\n", enemies[currentEnemy].name, enemies[currentEnemy].damage);
            playerHealth -= enemies[currentEnemy].damage;
        }
    }

    if (playerHealth <= 0) {
        printf("You have been defeated. Game over!\n");
    } else {
        printf("Congratulations! You've defeated all enemies!\n");
    }
    return 0;
}

void printStatus(int playerHealth, Enemy enemies[], int numEnemies) {
    printf("Player Health: %d\n", playerHealth);
    for (int i = 0; i < numEnemies; i++) {
        printf("%s Health: %d\n", enemies[i].name, enemies[i].health);
    }
    printf("\n");
}

Action chooseAction() {
    int choice;
    printf("Choose your action:\n");
    printf("0: Attack\n1: Heal\n2: Run\n3: Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    while (choice < 0 || choice > 3) {
        printf("Invalid choice. Try again: ");
        scanf("%d", &choice);
    }
    return (Action)choice;
}

void attack(Enemy *enemy, int *playerHealth) {
    int damage = rand() % 20 + 1;  // Random attack damage between 1-20
    enemy->health -= damage;
    printf("You attack the %s for %d damage!\n", enemy->name, damage);
}

void heal(int *playerHealth) {
    int healAmount = rand() % 15 + 1;  // Random heal between 1-15
    *playerHealth += healAmount;
    if (*playerHealth > MAX_HEALTH) {
        *playerHealth = MAX_HEALTH;
    }
    printf("You heal yourself for %d health points!\n", healAmount);
}

void run() {
    printf("You run away from the battle!\n");
}