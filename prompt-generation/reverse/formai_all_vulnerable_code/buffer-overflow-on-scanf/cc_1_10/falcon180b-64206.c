//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_CATEGORY_LENGTH 50
#define MAX_AMOUNT_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} item_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    item_t items[MAX_ITEMS];
} player_t;

player_t players[MAX_PLAYERS];
int num_players;

void init_player(player_t* player, char* name) {
    strcpy(player->name, name);
    player->score = 0;
    memset(player->items, 0, sizeof(item_t) * MAX_ITEMS);
}

int add_item(player_t* player, item_t* item) {
    int i;
    for (i = 0; i < player->score; i++) {
        if (strcmp(player->items[i].name, item->name) == 0) {
            return 0; // item already exists
        }
    }
    strcpy(player->items[player->score].name, item->name);
    strcpy(player->items[player->score].description, item->description);
    strcpy(player->items[player->score].category, item->category);
    player->items[player->score].amount = item->amount;
    player->score++;
    return 1; // item added successfully
}

void display_items(player_t* player) {
    int i;
    for (i = 0; i < player->score; i++) {
        printf("Name: %s\nDescription: %s\nCategory: %s\nAmount: %.2f\n\n",
               player->items[i].name, player->items[i].description,
               player->items[i].category, player->items[i].amount);
    }
}

void main() {
    int i, j, choice;
    char name[MAX_NAME_LENGTH];

    printf("Welcome to Personal Finance Planner\n");
    printf("How many players? (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i+1);
        scanf("%s", name);
        init_player(&players[i], name);
    }

    while (1) {
        printf("\nPlayer %s's turn\n", players[0].name);
        printf("1. Add item\n2. Display items\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item description: ");
            scanf("%s", players[0].items[players[0].score-1].description);
            printf("Enter item category: ");
            scanf("%s", players[0].items[players[0].score-1].category);
            printf("Enter item amount: ");
            scanf("%f", &players[0].items[players[0].score-1].amount);
            break;
        case 2:
            display_items(&players[0]);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}