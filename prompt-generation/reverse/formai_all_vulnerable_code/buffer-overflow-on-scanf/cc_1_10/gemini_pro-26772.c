//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: curious
#pragma vintage
#include <stdio.h>
#include <stdlib.h>

// The ol' auctioneer
struct Auctioneer {
    char *name;
    int gavel;
};

// The eager bidders
struct Bidder {
    char *name;
    int bid;
};

// The prized possession
struct Item {
    char *name;
    int value;
};

// The heart of the auction
void conduct_auction(struct Auctioneer *auctioneer, struct Item *item, struct Bidder **bidders, int num_bidders) {
    printf("\nHear ye, hear ye! %s, the esteemed auctioneer, welcomes you to the Digital Auction System!\n", auctioneer->name);
    printf("Today's prized possession is the magnificent %s, valued at %d. Shall we begin the bidding?\n", item->name, item->value);

    int highest_bid = -1;
    struct Bidder *highest_bidder = NULL;

    while (1) {
        printf("\nPlace your bids, my lords and ladies!\n");

        for (int i = 0; i < num_bidders; i++) {
            printf("%s, what is thy bid?\n", bidders[i]->name);
            scanf("%d", &bidders[i]->bid);

            if (bidders[i]->bid > highest_bid) {
                highest_bid = bidders[i]->bid;
                highest_bidder = bidders[i];
            }
        }

        printf("\nThe highest bid stands at %d by %s. Shall we continue?\n", highest_bid, highest_bidder->name);

        char choice;
        scanf(" %c", &choice); // Skip leading whitespace

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("\nSold! To the noble %s for %d. May you cherish your new possession.\n", highest_bidder->name, highest_bid);
}

int main(void) {
    // Initialize the auctioneer, item, and bidders
    struct Auctioneer auctioneer = {"Sir Reginald Von Bidsworth", 1729};
    struct Item item = {"The Golden Chalice", 500};
    struct Bidder bidders[] = {
        {"Lady Jane", 400},
        {"Lord Byron", 550},
        {"Sir William", 480},
        {"Queen Eleanor", 600}
    };

    // Conduct the auction
    conduct_auction(&auctioneer, &item, bidders, sizeof(bidders) / sizeof(bidders[0]));

    return 0;
}