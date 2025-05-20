//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BIDDERS 50
#define MAX_NAME_LEN 20
#define MAX_BID 100000

typedef struct {
    char name[MAX_NAME_LEN];
    int bid;
    int register_time;
} Bidder;

Bidder bidders[MAX_BIDDERS];
int num_bidders = 0;

void register_bid(char* name, int bid) {
    if (num_bidders >= MAX_BIDDERS) {
        printf("Max number of bidders reached.\n");
        return;
    }

    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].bid = bid;
    bidders[num_bidders].register_time = time(NULL);
    num_bidders++;
}

Bidder get_highest_bidder() {
    int highest_bid_index = 0;
    int highest_bid = bidders[0].bid;

    for (int i = 1; i < num_bidders; i++) {
        if (bidders[i].bid > highest_bid) {
            highest_bid_index = i;
            highest_bid = bidders[i].bid;
        }
        else if (bidders[i].bid == highest_bid && bidders[i].register_time < bidders[highest_bid_index].register_time) {
            highest_bid_index = i;
        }
    }

    return bidders[highest_bid_index];
}

int main() {
    char name[MAX_NAME_LEN];
    int bid;

    printf("Welcome to the Digital Auction System!\n");

    while (1) {
        printf("\nPlease enter your name: ");
        scanf("%s", name);

        printf("Please enter your bid: ");
        scanf("%d", &bid);

        if (bid > MAX_BID) {
            printf("Invalid bid. Maximum bid allowed is %d.\n", MAX_BID);
            continue;
        }

        register_bid(name, bid);

        Bidder highest_bidder = get_highest_bidder();

        if (num_bidders > 0) {
            printf("\nThe highest bid of %d is placed by %s.", highest_bidder.bid, highest_bidder.name);
        }
        else {
            printf("\nNo bids have been placed yet.");
        }

        printf("\nDo you want to place another bid? (y/n): ");
        char answer;
        scanf("%c", &answer);

        if (answer != 'y') {
            break;
        }
    }

    printf("\nThank you for using the Digital Auction System!");

    return 0;
}