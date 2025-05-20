//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>

// this struct represents a single mortgage player
struct mortgage_player {
    char name[30];
    double balance;
    double initial_owed;
    double monthly_payment;
    int months_left;
};

// function to update the balance and months left for each player
void update_balance(struct mortgage_player* player) {
    player->balance -= player->monthly_payment;
    player->months_left--;
}

int main() {
    int num_players;
    printf("Enter the number of players (2 or more): ");
    scanf("%d", &num_players);

    // allocate memory for array of mortgage players
    struct mortgage_player* players = malloc(num_players * sizeof(struct mortgage_player));

    // initialize each player's data
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        printf("Enter player %d's initial owed amount: ", i+1);
        scanf("%lf", &players[i].initial_owed);
        printf("Enter player %d's monthly payment amount: ", i+1);
        scanf("%lf", &players[i].monthly_payment);
        players[i].balance = players[i].initial_owed;
        players[i].months_left = 0;
    }

    // get the number of months each player wants to play
    int total_months, turn_num = 1;
    printf("Enter the total number of months to play: ");
    scanf("%d", &total_months);

    // run the game for the specified number of months
    for (int month = 1; month <= total_months; month++) {
        printf("MONTH %d:\n", month);

        // each player takes a turn to update their balance
        for (int i = 0; i < num_players; i++) {
            printf("\n%s's turn:", players[i].name);
            update_balance(&players[i]);
            printf("\n%s's new balance: %lf", players[i].name, players[i].balance);

            if (players[i].months_left == 0) {
                // if the player has zero months left, calculate their final balance and announce the winner
                players[i].months_left = month;
                printf("\n%s is the winner with a total of %d months and a final balance of %lf!", players[i].name, players[i].months_left, players[i].balance);
                return 0;  // end the game
            }
        }

        // increment the turn number for the next month
        turn_num++;
    }

    // if no player wins by the end of the game, announce the player with the smallest balance as the winner
    double min_balance = players[0].balance;
    struct mortgage_player* winner = &players[0];
    for (int i = 0; i < num_players; i++) {
        if (players[i].balance < min_balance) {
            min_balance = players[i].balance;
            winner = &players[i];
        }
    }
    printf("\nGAME ENDED: %s is the winner with a final balance of %lf!", winner->name, winner->balance);

    // free the allocated memory
    free(players);
    return 0;
}