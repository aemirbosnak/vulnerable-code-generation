//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bidder {
    char name[50];
    int bid;
    int bid_increments;
} bidder;

void get_bidders(bidder *bidders, int num_bidders) {
    for (int i = 0; i < num_bidders; i++) {
        bidders[i].bid = 0;
        bidders[i].bid_increments = 100;
        printf("Enter bidder name: ");
        scanf("%s", bidders[i].name);
    }
}

void update_bids(bidder *bidders, int num_bidders) {
    int current_bid = 0;
    for (int i = 0; i < num_bidders; i++) {
        printf("Current bid: %s (%d)\n", bidders[i].name, bidders[i].bid);
        printf("Enter new bid: ");
        scanf("%d", &bidders[i].bid);
        if (bidders[i].bid > current_bid) {
            current_bid = bidders[i].bid;
        }
    }
}

int main() {
    int num_bidders = 0;
    char name[50];
    int bid = 0;
    int bid_increments = 100;
    while (1) {
        printf("Enter bidder name: ");
        scanf("%s", name);
        if (strcmp(name, "end") == 0) {
            break;
        }
        num_bidders++;
        printf("Enter new bid: ");
        scanf("%d", &bid);
        printf("Enter bid increment: ");
        scanf("%d", &bid_increments);
        if (num_bidders == 1) {
            printf("Bidder %s: %d\n", name, bid);
        } else {
            printf("Bidder %s: %d\n", name, bid);
            printf("Current bid: ");
            scanf("%d", &bid);
            if (bid > bid) {
                printf("New highest bid: %s (%d)\n", name, bid);
                bid = bid;
            } else if (bid > bid) {
                printf("New highest bid: %s (%d)\n", name, bid);
                bid = bid;
            }
        }
    }
    return 0;
}