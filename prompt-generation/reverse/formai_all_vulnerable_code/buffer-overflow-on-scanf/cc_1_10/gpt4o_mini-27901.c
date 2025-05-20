//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int energy;
    int items;
} Player;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int damage;
    int health;
} Monster;

void displayIntro();
void displayStatus(Player *player);
void encounterMonster(Player *player);
void rest(Player *player);
void explore(Player *player);
void gameLoop(Player *player);
void clearInputBuffer();

int main() {
    Player player = {"Hero", 100, 100, 0};
    
    displayIntro();
    gameLoop(&player);
    
    return 0;
}

void displayIntro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are about to embark on an adventure filled with challenges and excitement.\n\n");
}

void displayStatus(Player *player) {
    printf("Player Status:\n");
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Energy: %d\n", player->energy);
    printf("Items Collected: %d\n", player->items);
    printf("-----------------------------------\n");
}

void encounterMonster(Player *player) {
    Monster monster = {"Goblin", 20, 50};
    
    printf("A wild %s appeared!\n", monster.name);
    while (monster.health > 0 && player->health > 0) {
        printf("You have encountered a %s! It has %d health left.\n", monster.name, monster.health);
        printf("What will you do? (1: Attack, 2: Flee): ");
        
        int choice;
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                printf("You attack the %s!\n", monster.name);
                monster.health -= 10;
                printf("You dealt 10 damage. %s has %d health left.\n", monster.name, monster.health);
                break;
            case 2:
                printf("You fled from the battle.\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
        
        if (monster.health > 0) {
            printf("%s attacks you!\n", monster.name);
            player->health -= monster.damage;
            printf("You took %d damage. You have %d health left.\n", monster.damage, player->health);
        }
    }
    
    if (monster.health <= 0) {
        printf("You have defeated the %s!\n", monster.name);
        player->items += 1;
        printf("You collected an item! Total items: %d\n", player->items);
    } else {
        printf("You have been defeated! Game Over.\n");
        exit(0);
    }
}

void rest(Player *player) {
    printf("You decided to rest...\n");
    player->health += 20;
    player->energy += 20;
    if (player->health > 100) player->health = 100;
    if (player->energy > 100) player->energy = 100;
    printf("You rested for a while. Health: %d, Energy: %d\n", player->health, player->energy);
}

void explore(Player *player) {
    int randomEvent = rand() % 2;
    
    if (randomEvent == 0) {
        printf("You explore and find some items!\n");
        player->items += 1;
        printf("You now have %d items.\n", player->items);
    } else {
        encounterMonster(player);
    }
}

void gameLoop(Player *player) {
    srand(time(NULL));
    
    while (1) {
        displayStatus(player);
        
        printf("What would you like to do? (1: Explore, 2: Rest, 3: Exit): ");
        
        int action;
        scanf("%d", &action);
        clearInputBuffer();
        
        switch (action) {
            case 1:
                explore(player);
                break;
            case 2:
                rest(player);
                break;
            case 3:
                printf("Exiting the game. Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}