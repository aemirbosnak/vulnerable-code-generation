//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_BIDS 10

typedef struct {
    char bidder[20];
    int bid;
} Bidder;

typedef struct {
    char item[20];
    int current_bid;
    int bid_count;
} Item;

int main() {
    Item item1;
    Item item2;
    Item *items[2] = {&item1, &item2};

    Bidder bidders[MAX_BIDDERS] = {{"Bidder1", 0}, {"Bidder2", 0}, {"Bidder3", 0}};
    int bid_counts[MAX_BIDDERS] = {0, 0, 0};

    for (int i = 0; i < MAX_BIDDERS; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bidders[i].bidder);
        printf("Enter initial bid: ");
        scanf("%d", &bidders[i].bid);
        bid_counts[i] = 1;
    }

    for (int i = 0; i < MAX_BIDS; i++) {
        int max_bidder = 0;
        int max_bid = 0;
        for (int j = 0; j < MAX_BIDDERS; j++) {
            if (bid_counts[j] > 0 && bidders[j].bid > max_bid) {
                max_bidder = j;
                max_bid = bidders[j].bid;
            }
        }

        for (int j = 0; j < MAX_BIDDERS; j++) {
            if (j == max_bidder) {
                printf("Bidder %s won the auction for %s with a bid of %d.\n", bidders[j].bidder, items[j]->item, max_bid);
                bid_counts[j] = 0;
            } else {
                bid_counts[j]++;
            }
        }

        for (int j = 0; j < MAX_BIDDERS; j++) {
            if (bid_counts[j] > 0) {
                bidders[j].bid++;
            }
        }
    }

    return 0;
}