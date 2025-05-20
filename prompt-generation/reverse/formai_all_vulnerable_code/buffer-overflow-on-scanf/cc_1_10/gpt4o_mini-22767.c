//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 50
#define MAX_BIDS 100

typedef struct {
    char name[50];
    float basePrice;
    float currentBid;
    char highestBidder[50];
    int bidsCount;
} AuctionItem;

typedef struct {
    char bidderName[50];
    float bidAmount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;
int bidCount = 0;

void displayWelcomeMessage();
void displayItems();
void addItem();
void placeBid();
void showItemDetails(int itemId);
void closeAuction();

int main() {
    srand(time(NULL)); // Initialize seed for randomness
    int choice;
    
    displayWelcomeMessage();

    do {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Add Auction Item\n");
        printf("2. Place a Bid\n");
        printf("3. View Items\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: placeBid(); break;
            case 3: displayItems(); break;
            case 4: closeAuction(); break;
            case 5: printf("Exiting... Thank you!\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayWelcomeMessage() {
    printf("Welcome to the Mind-Bending Digital Auction System!\n");
    printf("Where dreams of riches collide with the thrill of bidding.\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached! Cannot add more items.\n");
        return;
    }
    
    AuctionItem newItem;
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", newItem.name);
    printf("Enter base price: ");
    scanf("%f", &newItem.basePrice);
    newItem.currentBid = newItem.basePrice;
    strcpy(newItem.highestBidder, "None");
    newItem.bidsCount = 0;

    items[itemCount++] = newItem;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void displayItems() {
    printf("\nAvailable Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Base Price: %.2f, Current Bid: %.2f, Highest Bidder: %s\n",
               i + 1, items[i].name, items[i].basePrice, items[i].currentBid, items[i].highestBidder);
    }
}

void placeBid() {
    int itemId;
    char bidder[50];
    float bidAmount;

    displayItems();
    printf("Select the item number to bid on: ");
    scanf("%d", &itemId);

    if (itemId < 1 || itemId > itemCount) {
        printf("Invalid item selected.\n");
        return;
    }

    printf("Enter your name: ");
    scanf(" %[^\n]%*c", bidder);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    AuctionItem* item = &items[itemId - 1]; // Adjust for 0-indexing

    if (bidAmount <= item->currentBid) {
        printf("Your bid must be higher than the current bid of %.2f.\n", item->currentBid);
        return;
    }

    item->currentBid = bidAmount;
    strcpy(item->highestBidder, bidder);
    item->bidsCount++;

    printf("Bid placed successfully! New highest bid for '%s': %.2f by %s.\n",
           item->name, item->currentBid, item->highestBidder);
}

void closeAuction() {
    printf("Closing Auction...\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Winner: %s, Winning Bid: %.2f\n",
               items[i].name, items[i].highestBidder, items[i].currentBid);
    }
    printf("Auction closed. Thank you for participating!\n");
    exit(0);
}