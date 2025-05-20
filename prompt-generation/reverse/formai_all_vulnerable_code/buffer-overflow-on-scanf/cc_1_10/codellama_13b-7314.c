//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10

typedef struct {
    int bid_amount;
    char *name;
} Bid;

void print_bids(Bid *bids, int num_bids) {
    printf("Bids:\n");
    for (int i = 0; i < num_bids; i++) {
        printf("* %s: %d\n", bids[i].name, bids[i].bid_amount);
    }
}

void auction(int num_bids) {
    Bid *bids = malloc(num_bids * sizeof(Bid));
    if (bids == NULL) {
        printf("Error: unable to allocate memory for bids\n");
        return;
    }

    for (int i = 0; i < num_bids; i++) {
        printf("Enter bidder name: ");
        bids[i].name = malloc(30 * sizeof(char));
        scanf("%s", bids[i].name);

        printf("Enter bid amount: ");
        scanf("%d", &bids[i].bid_amount);
    }

    print_bids(bids, num_bids);

    int winner_index = rand() % num_bids;
    printf("Winner: %s with bid %d\n", bids[winner_index].name, bids[winner_index].bid_amount);

    for (int i = 0; i < num_bids; i++) {
        free(bids[i].name);
    }
    free(bids);
}

int main() {
    srand(time(NULL));

    int num_bids;
    printf("Enter number of bids: ");
    scanf("%d", &num_bids);

    auction(num_bids);

    return 0;
}