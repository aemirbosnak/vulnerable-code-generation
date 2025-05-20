//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int health;
    int attack_power;
} Player;

typedef struct {
    char name[NAME_LENGTH];
    int health;
    int attack_power;
} Enemy;

void initialize_player(Player *player);
void initialize_enemy(Enemy *enemy);
void encounter_enemy(Player *player, Enemy *enemy);
void summary(Player *player);
void random_event(Player *player);
void display_status(Player *player);

int main() {
    srand(time(NULL));
    Player player;
    Enemy enemies[MAX_ENEMIES];
    initialize_player(&player);
    
    for (int i = 0; i < MAX_ENEMIES; i++) {
        initialize_enemy(&enemies[i]);
    }
    
    int action;
    while (player.health > 0) {
        printf("\n--- Space Adventure ---\n");
        display_status(&player);
        
        printf("Choose your action:\n");
        printf("1. Explore\n");
        printf("2. Check Inventory\n");
        printf("3. Use Item\n");
        printf("4. Exit Game\n");
        printf("Enter your choice: ");
        
        scanf("%d", &action);
        
        switch(action) {
            case 1:
                random_event(&player);
                break;
            case 2:
                printf("Inventory is empty for now.\n");
                break;
            case 3:
                printf("No items to use.\n");
                break;
            case 4:
                printf("Exiting Game...\n");
                player.health = 0; // To exit loop
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
        
        if (player.health > 0) {
            for (int i = 0; i < MAX_ENEMIES; i++) {
                if (rand() % 3 == 0) { 
                    encounter_enemy(&player, &enemies[i]);
                }
            } 
        }
    }
    
    summary(&player);
    return 0;
}

void initialize_player(Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->attack_power = rand() % 20 + 5; // Random attack power between 5-25
}

void initialize_enemy(Enemy *enemy) {
    sprintf(enemy->name, "Enemy%d", rand() % 100);
    enemy->health = rand() % 50 + 20; // Health between 20 - 70
    enemy->attack_power = rand() % 15 + 3; // Attack power between 3 - 17
}

void encounter_enemy(Player *player, Enemy *enemy) {
    printf("\nEncountered %s!\n", enemy->name);
    
    while (player->health > 0 && enemy->health > 0) {
        printf("%s attacks %s for %d damage!\n", player->name, enemy->name, player->attack_power);
        enemy->health -= player->attack_power;
        
        if (enemy->health > 0) {
            printf("%s attacks %s for %d damage!\n", enemy->name, player->name, enemy->attack_power);
            player->health -= enemy->attack_power;
        }
        
        printf("Player Health: %d | Enemy Health: %d\n", player->health, enemy->health);
    }

    if (player->health > 0) {
        printf("%s defeated %s!\n", player->name, enemy->name);
    } else {
        printf("%s was defeated by %s.\n", player->name, enemy->name);
    }
}

void random_event(Player *player) {
    int event = rand() % 3;
    
    switch(event) {
        case 0:
            printf("You find a stash of space crystals! Health +20\n");
            player->health += 20;
            break;
        case 1:
            printf("A meteor shower hits! Health -10\n");
            player->health -= 10;
            break;
        case 2:
            printf("You discover an abandoned spaceship and salvage supplies! Health +5\n");
            player->health += 5;
            break;
        default:
            break;
    }
}

void summary(Player *player) {
    printf("\n--- Game Over ---\n");
    printf("Player: %s\n", player->name);
    printf("Final Health: %d\n", player->health);
}
 
void display_status(Player *player) {
    printf("Player Name: %s\n", player->name);
    printf("Current Health: %d\n", player->health);
    printf("Attack Power: %d\n", player->attack_power);
}