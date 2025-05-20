//FormAI DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char itemName[50];
    float bidPrice;
    char bidderName[50];
};

int main() {
    int numItems, numBidders;
    struct Item items[10];
    char bidders[10][50];

    printf("Welcome to the Digital Auction System.\n");

    // Get number of items
    printf("Please enter the number of items: ");
    scanf("%d", &numItems);
    getchar();

    // Get item details
    for (int i = 0; i < numItems; i++) {
        printf("Item %d\n", i+1);
        printf("Item name: ");
        fgets(items[i].itemName, 50, stdin);
        items[i].itemName[strcspn(items[i].itemName, "\n")] = '\0'; // Remove newline character
        printf("Starting bid price: ");
        scanf("%f", &items[i].bidPrice);
        getchar();
        printf("\n");
    }

    // Get number of bidders
    printf("Please enter the number of bidders: ");
    scanf("%d", &numBidders);
    getchar();

    // Get bidders' names
    for (int i = 0; i < numBidders; i++) {
        printf("Bidder %d\n", i+1);
        printf("Name: ");
        fgets(bidders[i], 50, stdin);
        bidders[i][strcspn(bidders[i], "\n")] = '\0'; // Remove newline character
        printf("\n");
    }

    // Start bidding process
    int numBids = 0;
    while (numBids < numItems) {
        for (int i = 0; i < numItems; i++) {
            printf("ITEM %d: %s\n", i+1, items[i].itemName);
            printf("Starting bid price: %.2f\n", items[i].bidPrice);

            struct Item highestBid;
            highestBid.bidPrice = items[i].bidPrice;
            int winner = -1;

            for (int j = 0; j < numBidders; j++) {
                printf("%s's bid: ", bidders[j]);
                float bid;
                scanf("%f", &bid);
                getchar();

                if (bid > highestBid.bidPrice) {
                    highestBid.bidPrice = bid;
                    strcpy(highestBid.bidderName, bidders[j]);
                    winner = j;
                }
            }

            if (winner == -1) {
                printf("No bids received for this item.\n");
            } else {
                strcpy(items[i].bidderName, bidders[winner]);
                items[i].bidPrice = highestBid.bidPrice;
                printf("The winner of the bidding process for item %d is: %s\n", i+1, highestBid.bidderName);
            }

            numBids++;
            printf("\n");
        }
    }

    // Display results
    printf("Bidding has ended. The results are:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: %s\n", i+1, items[i].itemName);
        if (strlen(items[i].bidderName) == 0) {
            printf("No bids were received for this item.\n");
        } else {
            printf("Winner: %s\n", items[i].bidderName);
            printf("Winning bid: %.2f\n", items[i].bidPrice);
        }
        printf("\n");
    }

    return 0;
}