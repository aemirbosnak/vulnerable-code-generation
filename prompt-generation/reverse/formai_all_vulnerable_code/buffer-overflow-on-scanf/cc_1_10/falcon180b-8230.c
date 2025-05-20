//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_BUDGET_ITEMS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float budget;
    float income;
    float expenses[MAX_BUDGET_ITEMS];
    int num_expenses;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    printf("Enter player name: ");
    scanf("%s", players[num_players].name);

    printf("Enter player budget: ");
    scanf("%f", &players[num_players].budget);

    printf("Enter player income: ");
    scanf("%f", &players[num_players].income);

    printf("Enter number of expenses: ");
    scanf("%d", &players[num_players].num_expenses);

    for (int i = 0; i < players[num_players].num_expenses; i++) {
        printf("Enter expense %d: ", i+1);
        scanf("%f", &players[num_players].expenses[i]);
    }

    num_players++;
}

void display_player_budget(Player* player) {
    printf("Player: %s\n", player->name);
    printf("Budget: $%.2f\n", player->budget);
    printf("Income: $%.2f\n", player->income);
    printf("Expenses:\n");

    for (int i = 0; i < player->num_expenses; i++) {
        printf("- $%.2f\n", player->expenses[i]);
    }
}

void main() {
    num_players = 0;

    while (num_players < MAX_PLAYERS) {
        add_player();
    }

    printf("Players:\n");

    for (int i = 0; i < num_players; i++) {
        display_player_budget(&players[i]);
    }
}