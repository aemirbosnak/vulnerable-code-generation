//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_BIDDERS 10

typedef struct {
    char name[50];
    int bid;
} bidder;

bidder bidders[MAX_BIDDERS];
int num_bidders = 0;
int highest_bid = 0;
int winner_index = -1;

void accept_bid(int bidder_index) {
    if (bidder_index >= 0 && bidder_index < num_bidders) {
        printf("Bidder %s, please enter your bid: ", bidders[bidder_index].name);
        scanf("%d", &bidders[bidder_index].bid);
        if (bidders[bidder_index].bid > highest_bid) {
            highest_bid = bidders[bidder_index].bid;
            winner_index = bidder_index;
        }
    } else {
        printf("Invalid bidder index.\n");
    }
}

void print_current_bid() {
    if (num_bidders > 0) {
        printf("\nCurrent highest bid: %d by %s\n", highest_bid, bidders[winner_index].name);
    } else {
        printf("No bids yet.\n");
    }
}

void auction(char* item_name) {
    printf("\nAuction for %s:\n", item_name);
    for (int i = 0; i < num_bidders; i++) {
        accept_bid(i);
        print_current_bid();
    }
}

int main() {
    char item_name[50];
    printf("Enter the item name: ");
    scanf("%s", item_name);

    printf("Enter the number of bidders:\n");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_bidders; i++) {
        printf("\nBidder %d:\n", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].bid = 0;
    }

    auction(item_name);

    if (winner_index != -1) {
        printf("\nCongratulations, %s, you are the winner with a bid of %d!\n", bidders[winner_index].name, highest_bid);
    } else {
        printf("No winner.\n");
    }

    return 0;
}