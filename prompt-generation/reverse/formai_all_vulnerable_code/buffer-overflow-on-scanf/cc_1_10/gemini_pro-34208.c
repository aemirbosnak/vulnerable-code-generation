//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_EXPENSES 100

typedef struct {
    char name[32];
    int expenses[MAX_EXPENSES];
    int num_expenses;
} player_t;

player_t players[MAX_PLAYERS];
int num_players = 0;

void add_player(char *name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Error: maximum number of players reached\n");
        return;
    }

    strcpy(players[num_players].name, name);
    players[num_players].num_expenses = 0;
    num_players++;
}

void add_expense(char *name, int amount) {
    int i;

    for (i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].expenses[players[i].num_expenses] = amount;
            players[i].num_expenses++;
            return;
        }
    }

    printf("Error: player not found\n");
}

void print_expenses() {
    int i, j;

    for (i = 0; i < num_players; i++) {
        printf("%s\n", players[i].name);
        for (j = 0; j < players[i].num_expenses; j++) {
            printf("    %d\n", players[i].expenses[j]);
        }
    }
}

int main() {
    char command[32];
    char name[32];
    int amount;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add_player") == 0) {
            scanf("%s", name);
            add_player(name);
        } else if (strcmp(command, "add_expense") == 0) {
            scanf("%s %d", name, &amount);
            add_expense(name, amount);
        } else if (strcmp(command, "print_expenses") == 0) {
            print_expenses();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}