//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char item[100];
    int price;
    int bids[10];
    int bidder;
} AuctionItem;

AuctionItem items[10];

int main() {
    int i, numBids;
    int bidPrice, newBid;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        sprintf(items[i].item, "Item %d", i + 1);
        items[i].price = rand() % 100 + 1;
        items[i].bids[0] = items[i].price;
        items[i].bidder = -1;
    }

    printf("Welcome to the Digital Auction System!\n");
    printf("Here are the items up for auction:\n");
    for (i = 0; i < 10; i++) {
        printf("%s\n", items[i].item);
    }

    while (1) {
        printf("\nChoose an item number (0-%d): ", 9);
        scanf("%d", &numBids);
        if (numBids < 0 || numBids > 9) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("\nChoose a bid amount (1-%d): ", items[numBids].price);
        scanf("%d", &bidPrice);
        if (bidPrice < 1 || bidPrice > items[numBids].price) {
            printf("Invalid bid amount. Please try again.\n");
            continue;
        }

        for (i = 0; i < 10; i++) {
            if (i!= numBids) {
                items[i].bids[0] = items[i].price;
                items[i].bidder = -1;
            }
        }

        items[numBids].bids[items[numBids].bidder] = bidPrice;
        items[numBids].bidder++;

        if (items[numBids].bidder == 10) {
            items[numBids].bidder = 0;
        }

        if (items[numBids].bids[items[numBids].bidder] > bidPrice) {
            printf("Bid too low. Please try again.\n");
            continue;
        }

        printf("\nCongratulations! You have won the auction for %s!\n", items[numBids].item);
        break;
    }

    return 0;
}