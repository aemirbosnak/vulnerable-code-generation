//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BIDS 10
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    int amount;
} Bid;

int main() {
    Bid bids[MAX_BIDS];
    int num_bids = 0, current_bid = 0;
    bool bidding_open = true;
    int highest_bid = 0;
    char winner[MAX_NAME_SIZE];

    printf("Welcome to the Digital Auction System!\n\n");
    printf("Bidding is now open.\n");

    while (bidding_open) {
        char name[MAX_NAME_SIZE];
        int amount;

        printf("Bid #%d, enter your name and amount (or 'q' to quit): ", current_bid + 1);
        scanf("%s", name);

        if (name[0] == 'q' && name[1] == '\0') {
            bidding_open = false;
            break;
        }

        scanf("%d", &amount);

        Bid new_bid = { .amount = amount };
        strncpy(new_bid.name, name, MAX_NAME_SIZE);

        if (amount <= highest_bid) {
            printf("Your bid must be higher than the current highest bid of %d.\n", highest_bid);
        } else if (num_bids == MAX_BIDS) {
            printf("Sorry, no more bids can be accepted.\n");
        } else {
            bids[num_bids++] = new_bid;
            highest_bid = amount;
            strncpy(winner, name, MAX_NAME_SIZE);
            printf("%s is currently the highest bidder with a bid of %d.\n", winner, highest_bid);
        }

        printf("\n");
        current_bid++;
    }

    printf("\nBidding is now closed. Here are the final bids:\n\n");

    for (int i = 0; i < num_bids; i++) {
        printf("%s: %d\n", bids[i].name, bids[i].amount);
    }

    printf("\nThe winner is %s with a bid of %d.\n", winner, highest_bid);
    printf("Thank you for using the Digital Auction System!\n");

    return 0;
}