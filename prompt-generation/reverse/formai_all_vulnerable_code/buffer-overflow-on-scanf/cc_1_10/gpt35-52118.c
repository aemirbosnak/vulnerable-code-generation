//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float balance;
    float transactions[MAX_TRANSACTIONS];
    int transaction_count;
} player;

void print_players(player players[], int num_players) {
    printf("Current Players: \n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s (Balance: $%.2f)\n", i+1, players[i].name, players[i].balance);
    }
}

void add_transaction(player players[], int num_players, int payer_index, float amount) {
    players[payer_index].transactions[players[payer_index].transaction_count] = -1 * amount;
    players[payer_index].transaction_count++;
    int debt_count = 0;
    for (int i = 0; i < num_players; i++) {
        if (i != payer_index && players[i].balance < 0) {
            debt_count++;
        }
    }
    if (debt_count == 0) {
        for (int i = 0; i < num_players; i++) {
            players[i].balance += players[i].transactions[players[i].transaction_count-1];
        }
        printf("Transaction added successfully!\n");
    } else {
        printf("Transaction added but balance is not settled yet. Please add more transactions.\n");
    }
}

int main() {
    player players[MAX_PLAYERS];
    int num_players = 0;
    int choice;
    do {
        printf("\n1. Add player\n2. Add transaction\n3. View players\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                if (num_players == MAX_PLAYERS) {
                    printf("Maximum players reached!\n");
                } else {
                    char temp_name[50];
                    printf("Enter player name: ");
                    scanf("%s", temp_name);
                    strcpy(players[num_players].name, temp_name);
                    players[num_players].balance = 0;
                    players[num_players].transaction_count = 0;
                    num_players++;
                    printf("Player added successfully!\n");
                }
                break;
            }
            case 2: {
                if (num_players < 2) {
                    printf("Need at least 2 players to add a transaction!\n");
                } else {
                    print_players(players, num_players);
                    int payer_index;
                    float amount;
                    printf("Enter payer index: ");
                    scanf("%d", &payer_index);
                    printf("Enter amount: ");
                    scanf("%f", &amount);
                    add_transaction(players, num_players, payer_index-1, amount);
                }
                break;
            }
            case 3: {
                if (num_players == 0) {
                    printf("No players added yet!\n");
                } else {
                    print_players(players, num_players);
                }
                break;
            }
            case 4: {
                exit(0);
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (1);

    return 0;
}