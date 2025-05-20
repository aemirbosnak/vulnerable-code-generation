//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ITEM_LEN 20
#define MAX_BID_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char item[MAX_ITEM_LEN];
    int bid;
} Bidder;

void print_bidder(Bidder bidder) {
    printf("Name: %s\n", bidder.name);
    printf("Item: %s\n", bidder.item);
    printf("Bid: %d\n", bidder.bid);
}

int main() {
    int num_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder bidders[num_bidders];
    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        printf("Enter the item being auctioned: ");
        scanf("%s", bidders[i].item);
        printf("Enter the bid amount: ");
        scanf("%d", &bidders[i].bid);
    }

    printf("Current bids:\n");
    for (int i = 0; i < num_bidders; i++) {
        print_bidder(bidders[i]);
    }

    int highest_bid = 0;
    int highest_bidder_index = 0;
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].bid > highest_bid) {
            highest_bid = bidders[i].bid;
            highest_bidder_index = i;
        }
    }

    printf("The highest bid is %d by %s.\n", highest_bid, bidders[highest_bidder_index].name);

    return 0;
}