//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_BIDS 100

typedef struct {
    int bid;
    char name[50];
} Bid;

void printBids(Bid *bids, int numBids) {
    for (int i = 0; i < numBids; i++) {
        printf("%d - %s\n", bids[i].bid, bids[i].name);
    }
}

void addBid(Bid *bids, int *numBids, int bid, char *name) {
    if (*numBids >= MAX_BIDS) {
        printf("Cannot add more bids, auction is full.\n");
        return;
    }
    bids[*numBids].bid = bid;
    strcpy(bids[*numBids].name, name);
    *numBids += 1;
}

void removeBid(Bid *bids, int *numBids, int index) {
    if (index < 0 || index >= *numBids) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *numBids - 1; i++) {
        bids[i] = bids[i + 1];
    }
    *numBids -= 1;
}

void updateBid(Bid *bids, int *numBids, int index, int bid) {
    if (index < 0 || index >= *numBids) {
        printf("Invalid index.\n");
        return;
    }
    bids[index].bid = bid;
}

int getHighestBid(Bid *bids, int numBids) {
    int highestBid = 0;
    for (int i = 0; i < numBids; i++) {
        if (bids[i].bid > highestBid) {
            highestBid = bids[i].bid;
        }
    }
    return highestBid;
}

void clearBids(Bid *bids, int *numBids) {
    *numBids = 0;
}

int main() {
    Bid bids[MAX_BIDS];
    int numBids = 0;

    srand(time(NULL));

    printf("Welcome to the Digital Auction System!\n");

    while (true) {
        printf("Enter a bid amount: ");
        int bid;
        scanf("%d", &bid);

        if (bid < 0) {
            break;
        }

        char name[50];
        printf("Enter your name: ");
        scanf("%s", name);

        addBid(bids, &numBids, bid, name);
    }

    printf("\nAuction results:\n");
    printBids(bids, numBids);

    int highestBid = getHighestBid(bids, numBids);
    printf("\nThe highest bid is %d.\n", highestBid);

    return 0;
}