//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int id;
    char item[50];
    float price;
} Auction;

void printAuction(Auction a) {
    printf("\nAuction ID: %d\nItem: %s\nPrice: $%.2f\n", a.id, a.item, a.price);
}

int main() {
    srand(time(NULL));
    Auction items[10];

    // Initializing the auction items
    for(int i=0; i<10; i++) {
        items[i].id = i+1;
        sprintf(items[i].item, "Item %d", i+1);
        items[i].price = ((float)(rand() % 1000))/2;
        printAuction(items[i]);
    }

    // Let the auction begin
    printf("\n\nThe auction is starting!\n\n");
    int itemIndex, bidderCount = 0, maxBidders = 5;
    int bidderIDs[maxBidders];
    float bidAmounts[maxBidders];

    while(1) {
        printf("\nWhich item do you want to bid on? Enter auction ID: ");
        scanf("%d", &itemIndex);

        // Check if auction is valid
        if(itemIndex < 1 || itemIndex > 10) {
            printf("Invalid auction ID!");
            continue;
        }

        // Check if item has already been sold
        if(items[itemIndex-1].price < 0) {
            printf("Sorry, this item has already been sold!");
            continue;
        }

        float currentPrice = items[itemIndex-1].price;
        printf("Current Price: $%.2f", currentPrice);

        // Check if there is room for another bidder
        if(bidderCount >= maxBidders) {
            printf("\nSorry, there is no room for more bidders!");
            continue;
        }

        int bidderID;
        float bidAmount;

        printf("\nEnter your bidder ID: ");
        scanf("%d", &bidderID);

        // Check if bidder ID is unique
        for(int i=0; i<bidderCount; i++) {
            if(bidderID == bidderIDs[i]) {
                printf("Sorry, this bidder ID is already taken!");
                break;
            }
        }

        printf("Enter your bid amount: ");
        scanf("%f", &bidAmount);

        // Check if bid is higher than current price
        if(bidAmount <= currentPrice) {
            printf("Sorry, your bid must be higher than the current price!");
            continue;
        }

        // Update auction item and record bid
        items[itemIndex-1].price = bidAmount;
        bidderIDs[bidderCount] = bidderID;
        bidAmounts[bidderCount] = bidAmount;
        bidderCount++;

        printf("Bid accepted!\n");
    }

    return 0;
}