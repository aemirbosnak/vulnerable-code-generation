//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bid {
    char bidder[50];
    int bid;
};

int main() {
    int num_bidders = 0;
    printf("How many bidders are participating in the auction? ");
    scanf("%d", &num_bidders);

    struct Bid *bids = (struct Bid *) malloc(num_bidders * sizeof(struct Bid));

    for (int i = 0; i < num_bidders; i++) {
        printf("\nEnter bidder %d's name: ", i + 1);
        scanf("%s", bids[i].bidder);
        printf("\nEnter bidder %d's initial bid: ", i + 1);
        scanf("%d", &bids[i].bid);
    }

    printf("\nAuction has started! Enter 'quit' to end the auction.\n");

    int highest_bid = 0;
    char highest_bidder[50];

    while (1) {
        char input[10];
        printf("\nEnter a bid: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int bid = atoi(input);

        if (bid <= highest_bid) {
            printf("Sorry, this bid is too low. Enter a higher bid.\n");
            continue;
        }

        for (int i = 0; i < num_bidders; i++) {
            if (strcmp(bids[i].bidder, highest_bidder) == 0) {
                bids[i].bid = bid;
                break;
            }
        }

        highest_bid = bid;

        printf("Current highest bid is %d by %s.\n", highest_bid, highest_bidder);
    }

    printf("\nFinal bid results:\n");

    for (int i = 0; i < num_bidders; i++) {
        printf("%s bid %d.\n", bids[i].bidder, bids[i].bid);
    }

    free(bids);

    return 0;
}