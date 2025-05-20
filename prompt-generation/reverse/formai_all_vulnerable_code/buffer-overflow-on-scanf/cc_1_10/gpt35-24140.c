//FormAI DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_players;
    printf("Welcome to the Digital Auction System!\n\n");
    printf("How many players will be participating in this auction?\n");
    scanf("%d", &num_players);

    // Check if there are enough players
    if (num_players < 2) {
        printf("Sorry, there need to be at least 2 players to start the auction.\n");
        return 0;
    }

    int *bids = calloc(num_players, sizeof(int));
    srand(time(NULL));

    printf("\nLet the auction begin!\n");

    int highest_bid = 0;
    int winner;
    int count = 0;
    while (1) {
        if (count == num_players) break;

        // Randomly select a player to bid
        int player = rand() % num_players + 1;
        printf("Player %d, enter your bid: ", player);
        int bid;
        scanf("%d", &bid);

        // Check if the bid is valid
        if (bid < 0) {
            printf("Invalid bid. Please enter a positive number.\n");
            continue;
        }

        // Update the highest bid and winner if necessary
        if (bid > highest_bid) {
            highest_bid = bid;
            winner = player;
        }

        // Update the bids array
        bids[player - 1] = bid;
        count++;

        printf("\nCurrent highest bid: %d\n", highest_bid);
        printf("Bids so far: ");
        for (int i = 0; i < num_players; i++) {
            printf("%d ", bids[i]);
        }
        printf("\n\n");
    }

    // Print the winner and winning bid
    printf("Congratulations, Player %d! You won the auction with a bid of %d.\n", winner, highest_bid);

    free(bids);

    return 0;
}