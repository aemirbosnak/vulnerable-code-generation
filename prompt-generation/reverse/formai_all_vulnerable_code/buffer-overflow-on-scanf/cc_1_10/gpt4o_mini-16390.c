//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50

typedef struct {
    char name[50];
    float currentBid;
    char item_name[50];
    time_t auctionEndTime;
} Item;

typedef struct {
    char bidderName[50];
    float bidAmount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDDERS];
int itemCount = 0;
int bidCount = 0;

void createItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Max item limit reached.\n");
        return;
    }
    
    Item *item = &items[itemCount++];
    
    printf("Enter item name: ");
    scanf("%s", item->item_name);
    
    printf("Enter starting bid amount: ");
    scanf("%f", &item->currentBid);
    
    printf("Enter auction duration in seconds: ");
    int duration;
    scanf("%d", &duration);
    
    item->auctionEndTime = time(NULL) + duration;

    printf("Item %s created with starting bid %.2f and auction ending in %d seconds.\n", 
           item->item_name, item->currentBid, duration);
}

void placeBid() {
    if (bidCount >= MAX_BIDDERS) {
        printf("Max bid limit reached.\n");
        return;
    }
    
    if (itemCount == 0) {
        printf("No items available for bidding.\n");
        return; 
    }

    printf("Available items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Current Bid: %.2f\n", i + 1, items[i].item_name, items[i].currentBid);
    }

    printf("Select an item number to bid on: ");
    int itemNumber;
    scanf("%d", &itemNumber);

    if (itemNumber < 1 || itemNumber > itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    Item *selectedItem = &items[itemNumber - 1];
    
    if (time(NULL) > selectedItem->auctionEndTime) {
        printf("This auction has already ended.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", bids[bidCount].bidderName);
    
    printf("Enter your bid amount: ");
    scanf("%f", &bids[bidCount].bidAmount);
    
    if (bids[bidCount].bidAmount <= selectedItem->currentBid) {
        printf("Bid must be higher than the current bid of %.2f.\n", selectedItem->currentBid);
        return;
    }

    selectedItem->currentBid = bids[bidCount].bidAmount;
    printf("Bid of %.2f placed by %s on item %s.\n", 
           bids[bidCount].bidAmount, bids[bidCount].bidderName, selectedItem->item_name);
    
    bidCount++;
}

void closeAuction() {
    if (itemCount == 0) {
        printf("No items to close.\n");
        return;    
    }

    for (int i = 0; i < itemCount; i++) {
        if (time(NULL) > items[i].auctionEndTime) {
            printf("Auction for item %s has ended. Final bid: %.2f\n", 
                   items[i].item_name, items[i].currentBid);
            // Reset the item for future auctions
            items[i].currentBid = 0;
            strcpy(items[i].item_name, "");
        }
    }
}

void displayMenu() {
    printf("\n--- Digital Auction System ---\n");
    printf("1. Create Item\n");
    printf("2. Place Bid\n");
    printf("3. Close Auctions\n");
    printf("4. Exit\n");
    printf("\nSelect an option: ");
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                closeAuction();
                break;
            case 4:
                printf("Exiting the auction system. Have a great day!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}