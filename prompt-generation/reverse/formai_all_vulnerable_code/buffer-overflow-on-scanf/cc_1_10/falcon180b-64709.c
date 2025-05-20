//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ITEMS 20
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 80
#define MAX_AMOUNT 9999.99

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    time_t date;
} item_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    item_t items[MAX_ITEMS];
    int num_items;
} player_t;

void add_item(player_t *player) {
    printf("Enter item name: ");
    scanf("%s", player->items[player->num_items].name);
    printf("Enter item description: ");
    scanf("%s", player->items[player->num_items].description);
    printf("Enter item amount: ");
    scanf("%f", &player->items[player->num_items].amount);
    time(&player->items[player->num_items].date);
    player->num_items++;
}

void view_items(player_t *player) {
    printf("Items for player %s:\n", player->name);
    for (int i = 0; i < player->num_items; i++) {
        printf("%s - %.2f - %s\n", player->items[i].name, player->items[i].amount, ctime(&player->items[i].date));
    }
}

void main() {
    player_t players[MAX_PLAYERS];
    int num_players = 0;

    while (num_players < MAX_PLAYERS) {
        printf("Enter name for player %d: ", num_players + 1);
        scanf("%s", players[num_players].name);
        num_players++;
    }

    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", players[0].name);
                add_item(&players[0]);
                break;
            case 2:
                printf("Enter player name: ");
                scanf("%s", players[0].name);
                view_items(&players[0]);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
}