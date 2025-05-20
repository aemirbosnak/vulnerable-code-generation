//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 5
#define MAX_STRING_LEN 20

struct player_stats {
    char name[MAX_STRING_LEN];
    int health;
    int coins;
};

struct item {
    char name[MAX_STRING_LEN];
    int cost;
    int health_restore;
};

void print_intro() {
    printf("You find yourself in the middle of a dark forest. You have no memory of how you got here, but you have a feeling that something is not right.\n\n");
}

void print_menu() {
    printf("What do you want to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Rest and restore health (+5 coins)\n");
    printf("3. Visit the market\n");
    printf("4. Check your stats\n");
    printf("5. Quit\n\n");
}

void print_stats(struct player_stats stats) {
    printf("Name: %s\n", stats.name);
    printf("Health: %d\n", stats.health);
    printf("Coins: %d\n", stats.coins);
}

void print_market(struct item market[MAX_ITEMS]) {
    printf("Welcome to the market!\n");
    printf("Here are the items for sale:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s (%d coins, restores %d health)\n", i+1, market[i].name, market[i].cost, market[i].health_restore);
    }
    printf("\n");
}

void explore(struct player_stats *stats) {
    printf("You wander through the forest, hoping to find something useful.\n");
    printf("Suddenly, you hear a noise and realize that you are being chased by a pack of wolves!\n");
    printf("\n");

    int damage = rand() % 6 + 5;
    int coins = rand() % 11;

    printf("You try to run, but the wolves catch up to you and bite you, causing %d damage.\n", damage);
    stats->health -= damage;
    if (stats->health <= 0) {
        printf("You have died. Game over.\n");
        exit(0);
    }

    printf("You manage to fend off the wolves and escape, but you lose %d coins.\n", coins);
    stats->coins -= coins;
    printf("\n");
}

void rest(struct player_stats *stats) {
    printf("You find a cozy spot in the forest and take a nap.\n");
    printf("You wake up feeling refreshed and notice that you have gained 5 coins.\n");
    stats->health = 100;
    stats->coins += 5;
    printf("\n");
}

void visit_market(struct player_stats *stats, struct item market[MAX_ITEMS]) {
    print_market(market);
    printf("What do you want to buy? (or enter 0 to exit)\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= MAX_ITEMS) {
        if (stats->coins >= market[choice-1].cost) {
            printf("You bought %s for %d coins.\n", market[choice-1].name, market[choice-1].cost);
            stats->coins -= market[choice-1].cost;
            stats->health += market[choice-1].health_restore;
            printf("Your health is now %d.\n", stats->health);
        } else {
            printf("You do not have enough coins.\n");
        }
    }
    printf("\n");
}

int main() {
    struct player_stats stats = {"Player 1", 100, 10};
    struct item market[MAX_ITEMS] = {{"Apple", 2, 10}, {"Potion", 5, 50}, {"Bread", 3, 15}, {"Bandage", 1, 5}, {"Meat", 7, 30}};

    print_intro();

    while (true) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                explore(&stats);
                break;
            case 2:
                rest(&stats);
                break;
            case 3:
                visit_market(&stats, market);
                break;
            case 4:
                print_stats(stats);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}