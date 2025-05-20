//FormAI DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int value;
} Bid;

void displayBids(Bid *bids, int numBids) {
    printf("Current Bids:\n");
    for (int i = 0; i < numBids; i++) {
        printf("%s: $%d\n", bids[i].name, bids[i].value);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Bid *bids = NULL;
    int numBids = 0;
    int maxBids;

    printf("Enter the maximum number of bids: ");
    scanf("%d", &maxBids);
    printf("\n");

    bids = malloc(maxBids * sizeof(Bid));
    if (bids == NULL) {
        printf("Error: Memory allocation failed for bids array.\n");
        return 1;
    }

    char name[20];
    int value;
    int biddingOpen = 1;

    while (biddingOpen) {
        printf("Enter your name or 'q' to quit: ");
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter your bid: ");
        scanf("%d", &value);

        Bid newBid;
        strcpy(newBid.name, name);
        newBid.value = value;

        if (numBids < maxBids) {
            bids[numBids] = newBid;
            numBids++;
            displayBids(bids, numBids);
        } else {
            int indexToReplace = rand() % maxBids;
            bids[indexToReplace] = newBid;
            displayBids(bids, maxBids);
        }
    }

    free(bids);
    return 0;
}