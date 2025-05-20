//GPT-4o-mini DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MONSTERS 5
#define MAX_ITEMS 3

typedef struct {
    char name[20];
    int health;
    int attack;
} Monster;

typedef struct {
    char name[20];
    int value;
} Item;

typedef struct {
    char name[20];
    int health;
    int treasure;
} Player;

void displayStatus(Player player) {
    printf("Player: %s | Health: %d | Treasure: %d\n", player.name, player.health, player.treasure);
}

void encounterMonster(Player *player, Monster monster) {
    printf("You encounter a %s!\n", monster.name);
    while (player->health > 0 && monster.health > 0) {
        printf("Choose your action:\n1) Attack\n2) Flee\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            monster.health -= player->treasure / 2; // Using treasure as attack power
            printf("You attack the %s!\n", monster.name);
            printf("%s health: %d\n", monster.name, monster.health);
            if (monster.health > 0) {
                player->health -= monster.attack;
                printf("%s attacks you!\n", monster.name);
                printf("Your health: %d\n", player->health);
            }
        } else if (choice == 2) {
            printf("You chose to flee!\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    if (player->health <= 0) {
        printf("You have been defeated by the %s...\n", monster.name);
        exit(0);
    } else if (monster.health <= 0) {
        printf("You defeated the %s!\n", monster.name);
        player->treasure += rand() % 100 + 1; // Add some random treasure
        printf("You collect treasure! Total treasure: %d\n", player->treasure);
    }
}

void findItem(Player *player, Item item) {
    printf("You found a %s worth %d treasure!\n", item.name, item.value);
    player->treasure += item.value;
    printf("Total treasure: %d\n", player->treasure);
}

int main() {
    srand(time(NULL));

    Player player = {"Hero", 100, 0};
    Monster monsters[MAX_MONSTERS] = {
        {"Goblin", 30, 5},
        {"Orc", 50, 10},
        {"Troll", 70, 15},
        {"Dragon", 100, 20},
        {"Zombie", 20, 3}
    };
    Item items[MAX_ITEMS] = {
        {"Gold Coin", 50},
        {"Diamond", 200},
        {"Potion", 30}
    };

    printf("Welcome to the Dungeon Adventure!\n");
    printf("Enter your hero name: ");
    scanf("%s", player.name);
    displayStatus(player);

    while (player.health > 0) {
        printf("\nYou are in a dark room. Choose an action:\n1) Explore\n2) Check Status\n3) Exit\n");
        int action;
        scanf("%d", &action);
        
        if (action == 1) {
            int event = rand() % 3; // 0: encounter monster, 1: find item, 2: rest
            if (event == 0) {
                encounterMonster(&player, monsters[rand() % MAX_MONSTERS]);
            } else if (event == 1) {
                findItem(&player, items[rand() % MAX_ITEMS]);
            } else {
                printf("You take a moment to rest and recover.\n");
                player.health += 20;
                if (player.health > 100) player.health = 100;
            }
        } else if (action == 2) {
            displayStatus(player);
        } else if (action == 3) {
            printf("Thank you for playing! Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid action! Try again.\n");
        }
    }

    printf("Game Over! You have succumbed to your injuries.\n");
    return 0;
}