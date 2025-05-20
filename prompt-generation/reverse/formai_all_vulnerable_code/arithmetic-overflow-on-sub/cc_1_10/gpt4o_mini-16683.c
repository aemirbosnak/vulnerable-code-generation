//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    char description[200];
    float startingPrice;
    float currentPrice;
    int auctionTime; // in seconds
    time_t endTime;
    int highestBidIndex;
} Item;

typedef struct {
    char bidderName[50];
    float bidAmount;
    time_t bidTime;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;
int bidCount = 0;

void displayWelcomeMessage() {
    printf("======================================\n");
    printf("      Welcome to Digital Auction      \n");
    printf("======================================\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[itemCount].name);
    printf("Enter item description: ");
    getchar(); // consume newline
    fgets(items[itemCount].description, 200, stdin);
    items[itemCount].description[strcspn(items[itemCount].description, "\n")] = 0; // remove newline
    printf("Enter starting price: ");
    scanf("%f", &items[itemCount].startingPrice);
    items[itemCount].currentPrice = items[itemCount].startingPrice;
    printf("Enter auction time in seconds: ");
    scanf("%d", &items[itemCount].auctionTime);
    items[itemCount].endTime = time(NULL) + items[itemCount].auctionTime;
    items[itemCount].highestBidIndex = -1;
    itemCount++;
    printf("Item added successfully!\n");
}

void displayItems() {
    printf("\nCurrent Items for Auction:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s (%s)\n", i + 1, items[i].name, items[i].description);
        printf("   Starting Price: $%.2f\n", items[i].startingPrice);
        printf("   Current Price: $%.2f\n", items[i].currentPrice);
        printf("   Auction Ends In: %ld seconds\n", (items[i].endTime - time(NULL)));
        printf("--------------------------------------\n");
    }
}

void placeBid() {
    displayItems();
    int itemIndex;
    printf("Choose an item to bid on (1-%d): ", itemCount);
    scanf("%d", &itemIndex);
    itemIndex--; // to zero-based index

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item selected.\n");
        return;
    }

    if (time(NULL) > items[itemIndex].endTime) {
        printf("This auction has already ended.\n");
        return;
    }

    char bidderName[50];
    printf("Enter your name: ");
    scanf("%s", bidderName);
    
    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].currentPrice) {
        printf("Bid amount must be higher than the current price of $%.2f.\n", items[itemIndex].currentPrice);
        return;
    }

    Bid newBid;
    strcpy(newBid.bidderName, bidderName);
    newBid.bidAmount = bidAmount;
    newBid.bidTime = time(NULL);

    bids[bidCount++] = newBid;
    items[itemIndex].currentPrice = bidAmount;
    items[itemIndex].highestBidIndex = bidCount - 1;

    printf("Bid placed successfully!\n");
}

void displayBids() {
    printf("\nBidding History:\n");
    for (int i = 0; i < bidCount; i++) {
        printf("Bidder: %s - Amount: $%.2f - Time: %s", 
                bids[i].bidderName, 
                bids[i].bidAmount, 
                ctime(&bids[i].bidTime));
    }
}

void endAuction() {
    for (int i = 0; i < itemCount; i++) {
        if (time(NULL) > items[i].endTime) {
            if (items[i].highestBidIndex != -1) {
                printf("Auction for %s ended. Winner: %s with bid of $%.2f\n", 
                       items[i].name, 
                       bids[items[i].highestBidIndex].bidderName, 
                       bids[items[i].highestBidIndex].bidAmount);
            } else {
                printf("Auction for %s ended with no bids.\n", items[i].name);
            }
        }
    }
}

int main() {
    int choice;
    displayWelcomeMessage();
    while (1) {
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Place Bid\n");
        printf("4. View Bidding History\n");
        printf("5. End Auctions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayBids();
                break;
            case 5:
                endAuction();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}