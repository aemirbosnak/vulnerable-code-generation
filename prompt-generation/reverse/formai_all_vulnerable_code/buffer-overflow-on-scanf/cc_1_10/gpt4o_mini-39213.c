//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50
#define ITEM_NAME_LEN 100
#define BIDDER_NAME_LEN 100

typedef struct {
    char name[BIDDER_NAME_LEN];
    double bid;
} Bidder;

typedef struct {
    char name[ITEM_NAME_LEN];
    double startingPrice;
    Bidder bidders[MAX_BIDDERS];
    int bidderCount;
} AuctionItem;

void initializeAuctionItem(AuctionItem *item, const char *name, double startingPrice) {
    strcpy(item->name, name);
    item->startingPrice = startingPrice;
    item->bidderCount = 0;
}

void placeBid(AuctionItem *item) {
    if (item->bidderCount >= MAX_BIDDERS) {
        printf("Cannot accept more bidders for this item.\n");
        return;
    }

    Bidder newBidder;
    printf("Enter bidder name: ");
    scanf("%s", newBidder.name);
    
    printf("Enter bid amount (must be greater than %.2f): ", item->startingPrice);
    double bidAmount;
    scanf("%lf", &bidAmount);
    
    if (bidAmount <= item->startingPrice) {
        printf("Bid must be greater than the starting price!\n");
        return;
    }
    
    newBidder.bid = bidAmount;
    item->bidders[item->bidderCount++] = newBidder;
    item->startingPrice = bidAmount; // Update starting price to the new bid
    printf("Bid placed successfully by %s for %.2f!\n", newBidder.name, bidAmount);
}

void displayAuctionItem(const AuctionItem *item) {
    printf("Auction Item: %s\n", item->name);
    printf("Current highest bid: %.2f\n", item->startingPrice);
    printf("Bidders:\n");
    for (int i = 0; i < item->bidderCount; i++) {
        printf(" - %s: %.2f\n", item->bidders[i].name, item->bidders[i].bid);
    }
}

void displayHighestBidder(const AuctionItem *item) {
    if (item->bidderCount == 0) {
        printf("No bids placed for %s yet.\n", item->name);
        return;
    }

    printf("Current highest bidder for %s is %s with a bid of %.2f\n",
           item->name, item->bidders[item->bidderCount - 1].name, item->bidders[item->bidderCount - 1].bid);
}

int main() {
    AuctionItem items[MAX_ITEMS];
    int itemCount = 0;
    int choice;
    
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Auction Items\n");
        printf("4. Show Highest Bidder\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                if (itemCount >= MAX_ITEMS) {
                    printf("Maximum number of auction items reached.\n");
                    break;
                }
                char name[ITEM_NAME_LEN];
                double startingPrice;
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%lf", &startingPrice);
                initializeAuctionItem(&items[itemCount], name, startingPrice);
                itemCount++;
                printf("Auction item added successfully!\n");
                break;
            }
            case 2: {
                if (itemCount == 0) {
                    printf("No auction items available.\n");
                    break;
                }
                int itemIndex;
                printf("Enter item index (0 to %d): ", itemCount - 1);
                scanf("%d", &itemIndex);
                if (itemIndex < 0 || itemIndex >= itemCount) {
                    printf("Invalid item index.\n");
                    break;
                }
                placeBid(&items[itemIndex]);
                break;
            }
            case 3: {
                if (itemCount == 0) {
                    printf("No auction items available.\n");
                    break;
                }
                for (int i = 0; i < itemCount; i++) {
                    displayAuctionItem(&items[i]);
                }
                break;
            }
            case 4: {
                if (itemCount == 0) {
                    printf("No auction items available.\n");
                    break;
                }
                int itemIndex;
                printf("Enter item index (0 to %d): ", itemCount - 1);
                scanf("%d", &itemIndex);
                if (itemIndex < 0 || itemIndex >= itemCount) {
                    printf("Invalid item index.\n");
                    break;
                }
                displayHighestBidder(&items[itemIndex]);
                break;
            }
            case 5:
                printf("Exiting the auction system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}