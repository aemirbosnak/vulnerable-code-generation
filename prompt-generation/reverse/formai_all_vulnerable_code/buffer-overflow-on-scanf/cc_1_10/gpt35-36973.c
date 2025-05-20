//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct AuctionItem {
    char name[20];
    int bidderCount;
    float highestBid;
};

int main() {
    int itemNum, bidderNum, i, j;
    float bid;
    struct AuctionItem items[10];

    // Taking input for number of auction items
    printf("Enter number of auction items: ");
    scanf("%d", &itemNum);

    // Taking input for auction item names
    for(i=0; i<itemNum; i++) {
        printf("Enter name of item %d: ", i+1);
        scanf("%s", &items[i].name);
        items[i].bidderCount = 0;
        items[i].highestBid = 0;
    }

    // Taking input for number of bidders for each auction item
    for(i=0; i<itemNum; i++) {
        printf("Enter number of bidders for item %s: ", items[i].name);
        scanf("%d", &bidderNum);

        // Taking input for bids from each bidder for each auction item
        for(j=0; j<bidderNum; j++) {
            printf("Enter bid from bidder %d for item %s: ", j+1, items[i].name);
            scanf("%f", &bid);

            // Updating highest bid and bidder count for the current auction item
            if(bid > items[i].highestBid) {
                items[i].highestBid = bid;
                items[i].bidderCount = j+1;
            }
        }
    }

    // Displaying results
    printf("\nResults:\n");
    for(i=0; i<itemNum; i++) {
        printf("Item: %s, Highest Bid: $%.2f, Bidder Count: %d\n", items[i].name, items[i].highestBid, items[i].bidderCount);
    }

    return 0;
}