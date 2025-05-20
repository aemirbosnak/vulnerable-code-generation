//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int bid;
} Bidder;

void displayBidders(Bidder* bidders, int count) {
    printf("Current bidders:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%d\n", bidders[i].name, bidders[i].bid);
    }
}

int main() {
    srand(time(NULL));
    int itemPrice = rand() % 100 + 1;
    int numBidders = rand() % 10 + 1;
    Bidder* bidders = malloc(numBidders * sizeof(Bidder));

    for (int i = 0; i < numBidders; i++) {
        bidders[i].bid = rand() % itemPrice + 1;
        sprintf(bidders[i].name, "Bidder %d", i + 1);
    }

    int highestBid = 0;
    int highestBidder = 0;

    while (1) {
        displayBidders(bidders, numBidders);

        int choice;
        printf("\nEnter your choice:\n1. Place a bid\n2. View current bids\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int bid;
            printf("Enter your bid:\n");
            scanf("%d", &bid);

            if (bid > highestBid) {
                highestBid = bid;
                highestBidder = numBidders - 1;
            }
        } else if (choice == 2) {
            continue;
        } else if (choice == 3) {
            break;
        }
    }

    printf("\nHighest bid: $%d by %s\n", highestBid, bidders[highestBidder].name);

    free(bidders);
    return 0;
}