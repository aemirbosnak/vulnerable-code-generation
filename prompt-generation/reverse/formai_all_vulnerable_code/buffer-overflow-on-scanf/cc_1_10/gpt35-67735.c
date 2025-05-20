//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BID_SIZE 5

// Auction item structure
typedef struct {
    int itemID;
    char itemName[50];
    double minBid;
    int numBids;
    double bids[BID_SIZE];
    char bidderNames[BID_SIZE][50];
} AuctionItem;

// Function to print an Auction Item
void printAuctionItem(AuctionItem item) {
    printf("Item #%d: %s\n", item.itemID, item.itemName);
    printf("Minimum Bid: $%.2f\n", item.minBid);
    printf("Number of Bids: %d\n", item.numBids);
    printf("Current Bids:\n");
    for(int i = 0; i < BID_SIZE; i++) {
        if(item.bids[i] != 0) {
            printf("$%.2f - %s\n", item.bids[i], item.bidderNames[i]);
        }
    }
    printf("\n");
}

int main() {
    int numItems;
    printf("How many items are up for auction? ");
    scanf("%d", &numItems);

    // Allocate memory for array of Auction Items
    AuctionItem *items = (AuctionItem*) malloc(numItems * sizeof(AuctionItem));

    // User inputs information for each item
    for(int i = 0; i < numItems; i++) {
        printf("\nENTER DETAILS FOR ITEM #%d\n", i+1);
        items[i].itemID = i + 1;

        printf("Item Name: ");
        scanf("%s", items[i].itemName);

        printf("Minimum Bid: ");
        scanf("%lf", &items[i].minBid);

        items[i].numBids = 0;
        for(int j = 0; j < BID_SIZE; j++) {
            items[i].bids[j] = 0;
            strcpy(items[i].bidderNames[j], "");
        }
    }

    // Auction begins
    int quit = 0;
    while(!quit) {
        printf("\nCURRENTLY UP FOR AUCTION:\n");
        for(int i = 0; i < numItems; i++) {
            printAuctionItem(items[i]);
        }

        // User inputs their bid
        int itemNum;
        double bidAmount;
        char bidderName[50];
        printf("\nEnter the item number you would like to bid on (or enter 0 to quit): ");
        scanf("%d", &itemNum);

        if(itemNum == 0) {
            quit = 1;
            continue;
        }

        if(itemNum < 1 || itemNum > numItems) {
            printf("Invalid item number!\n");
            continue;
        }

        printf("Enter your bid amount: ");
        scanf("%lf", &bidAmount);

        printf("Enter your name: ");
        scanf("%s", bidderName);

        // Adding the bid to the item's bids array, if it is higher than the current bids
        AuctionItem *item = &items[itemNum-1];
        int added = 0;
        for(int i = 0; i < BID_SIZE; i++) {
            if(bidAmount > item->bids[i]) {
                for(int j = BID_SIZE-1; j > i; j--) {
                    item->bids[j] = item->bids[j-1];
                    strcpy(item->bidderNames[j], item->bidderNames[j-1]);
                }
                item->bids[i] = bidAmount;
                strcpy(item->bidderNames[i], bidderName);
                item->numBids++;
                added = 1;
                break;
            }
        }

        if(!added) {
            printf("Sorry, your bid is not high enough!\n");
        }
    }

    // Free memory allocated for array of Auction Items
    free(items);

    return 0;
}