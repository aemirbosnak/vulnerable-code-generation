//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_BIDDERS 10
#define MAX_BIDS 10

typedef struct {
    int id;
    int bid;
} Bid;

typedef struct {
    int id;
    int bids[MAX_BIDS];
} Bidder;

Bidder bidders[MAX_BIDDERS];
Bid bids[MAX_BIDS];

int main() {
    int num_bidders, num_bids, i, j;
    int bidder_id, bid;

    srand(time(NULL));

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    for (i = 0; i < num_bidders; i++) {
        bidders[i].id = i;
        for (j = 0; j < num_bids; j++) {
            bidder_id = rand() % num_bidders;
            bid = rand() % 100;
            bidders[i].bids[j] = bid;
        }
    }

    for (i = 0; i < num_bids; i++) {
        bid = rand() % 100;
        bids[i].id = i;
        bids[i].bid = bid;
    }

    for (i = 0; i < num_bidders; i++) {
        printf("Bidder %d: ", bidders[i].id);
        for (j = 0; j < num_bids; j++) {
            printf("%d ", bidders[i].bids[j]);
        }
        printf("\n");
    }

    for (i = 0; i < num_bids; i++) {
        printf("Bid %d: ", bids[i].id);
        printf("%d\n", bids[i].bid);
    }

    return 0;
}