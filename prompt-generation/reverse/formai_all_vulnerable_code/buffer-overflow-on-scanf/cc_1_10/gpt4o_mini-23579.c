//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_EXPENSES 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float expenses[MAX_EXPENSES];
    int expense_count;
} Player;

void addExpense(Player *player) {
    if (player->expense_count < MAX_EXPENSES) {
        float expense;
        printf("Enter the amount for %s: ", player->name);
        scanf("%f", &expense);
        player->expenses[player->expense_count] = expense;
        player->expense_count++;
    } else {
        printf("Max expense limit reached for %s.\n", player->name);
    }
}

void viewExpenses(Player *player) {
    printf("\nExpenses for %s:\n", player->name);
    float total = 0.0;
    for (int i = 0; i < player->expense_count; i++) {
        printf("Expense %d: %.2f\n", i + 1, player->expenses[i]);
        total += player->expenses[i];
    }
    printf("Total expenses for %s: %.2f\n", player->name, total);
}

void calculateSplit(Player players[], int player_count) {
    float total = 0.0;

    for (int i = 0; i < player_count; i++) {
        for (int j = 0; j < players[i].expense_count; j++) {
            total += players[i].expenses[j];
        }
    }

    float split_amount = total / player_count;
    printf("\nEach player should contribute: %.2f\n", split_amount);
    for (int i = 0; i < player_count; i++) {
        float player_total = 0.0;
        for (int j = 0; j < players[i].expense_count; j++) {
            player_total += players[i].expenses[j];
        }
        printf("%s should %s %.2f\n", players[i].name, (player_total > split_amount) ? 
                "receive" : "pay", (player_total > split_amount) ? (player_total - split_amount) : (split_amount - player_total));
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count = 0;
    int choice;
    
    while (1) {
        printf("\nMultiplayer Expense Tracker\n");
        printf("1. Add Player\n");
        printf("2. Add Expense\n");
        printf("3. View Expenses\n");
        printf("4. Calculate Split\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (player_count < MAX_PLAYERS) {
                    printf("Enter player name: ");
                    scanf("%s", players[player_count].name);
                    players[player_count].expense_count = 0;
                    player_count++;
                } else {
                    printf("Maximum number of players reached.\n");
                }
                break;

            case 2:
                {
                    if (player_count > 0) {
                        printf("Select Player (1 to %d): ", player_count);
                        int idx;
                        scanf("%d", &idx);
                        if (idx >= 1 && idx <= player_count) {
                            addExpense(&players[idx - 1]);
                        } else {
                            printf("Invalid player selection.\n");
                        }
                    } else {
                        printf("No players available. Please add a player first.\n");
                    }
                }
                break;

            case 3:
                if (player_count > 0) {
                    for (int i = 0; i < player_count; i++) {
                        viewExpenses(&players[i]);
                    }
                } else {
                    printf("No players available. Please add a player first.\n");
                }
                break;

            case 4:
                if (player_count > 0) {
                    calculateSplit(players, player_count);
                } else {
                    printf("No players available. Please add a player first.\n");
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}