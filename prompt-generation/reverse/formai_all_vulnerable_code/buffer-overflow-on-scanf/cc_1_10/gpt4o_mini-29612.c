//GPT-4o-mini DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_MONSTERS 3
#define TREASURE_COUNT 5

typedef struct {
    char name[20];
    int health;
    int strength;
} Player;

typedef struct {
    char *name;
    int health;
    int strength;
} Monster;

typedef struct {
    char *name;
    int value;
} Treasure;


// Function declarations
void welcome();
void create_player(Player *player);
void encounter_monster(Player *player);
void find_treasure(Player *player);
void display_status(Player *player);
void play_game(Player *player);

int main() {
    Player player;
    welcome();
    create_player(&player);
    play_game(&player);
    return 0;
}

void welcome() {
    printf("**************************************\n");
    printf("      Welcome to Cave Explorer!      \n");
    printf("**************************************\n");
    printf("Get ready to explore the spooky cave.\n");
    printf("You'll encounter monsters and treasures!\n");
}

void create_player(Player *player) {
    printf("First, please enter your name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    // Remove newline character from name
    player->name[strcspn(player->name, "\n")] = 0;
    
    player->health = 100;
    player->strength = 20;
    printf("Welcome, %s! Your health is %d and strength is %d.\n", player->name, player->health, player->strength);
}

void encounter_monster(Player *player) {
    Monster monsters[MAX_MONSTERS] = {
        {"Goblin", 30, 10},
        {"Troll", 50, 15},
        {"Skeleton", 20, 5}
    };
    
    srand(time(NULL));
    int random_index = rand() % MAX_MONSTERS;
    Monster monster = monsters[random_index];
    
    printf("A wild %s appears!\n", monster.name);
    while (player->health > 0 && monster.health > 0) {
        printf("You attack the %s for %d damage!\n", monster.name, player->strength);
        monster.health -= player->strength;
        if (monster.health > 0) {
            printf("The %s attacks you for %d damage!\n", monster.name, monster.strength);
            player->health -= monster.strength;
        }
        display_status(player);
    }
    
    if (player->health <= 0) {
        printf("You have been defeated by the %s. Game Over.\n", monster.name);
        exit(0);
    } else {
        printf("You defeated the %s!\n", monster.name);
    }
}

void find_treasure(Player *player) {
    Treasure treasures[TREASURE_COUNT] = {
        {"Gold Coin", 10},
        {"Silver Necklace", 30},
        {"Ancient Artifact", 100},
        {"Emerald", 50},
        {"Ruby", 70}
    };
    
    srand(time(NULL));
    int random_index = rand() % TREASURE_COUNT;
    Treasure found_treasure = treasures[random_index];
    
    printf("You found a %s worth %d points!\n", found_treasure.name, found_treasure.value);
}

void display_status(Player *player) {
    printf("Current Status: %s | Health: %d\n", player->name, player->health);
}

void play_game(Player *player) {
    char choice;
    while (player->health > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore Cave (Encounter Monster)\n");
        printf("2. Search for Treasure\n");
        printf("3. Check Status\n");
        printf("4. Exit Game\n");
        printf("Choose an option (1-4): ");
        
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                encounter_monster(player);
                break;
            case '2':
                find_treasure(player);
                break;
            case '3':
                display_status(player);
                break;
            case '4':
                printf("Thanks for playing, %s! Goodbye!\n", player->name);
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}