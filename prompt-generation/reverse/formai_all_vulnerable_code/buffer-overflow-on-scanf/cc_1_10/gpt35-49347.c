//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Constants */
#define MAX_BIDS 10
#define ITEM_NAME_SIZE 30
#define NAME_SIZE 20

/* Define Structures */
typedef struct {
    int bidID;
    char bidderName[NAME_SIZE];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[ITEM_NAME_SIZE];
    float startingPrice;
    float currentBid;
    Bid bidHistory[MAX_BIDS];
    int numBids;
} Item;

/* Define Function Prototypes */
void displayMenu();
int getChoice();
void addItem(Item items[], int* numItems);
void displayItems(Item items[], int numItems);
void displayItem(Item item);
void placeBid(Item items[], int numItems);
void displayBidHistory(Item item);
void sortBids(Item item);

/* Main Function */
int main() {
    Item items[10];
    int choice, numItems = 0;

    do {
        displayMenu();
        choice = getChoice();

        switch(choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                displayItems(items, numItems);
                break;
            case 3:
                placeBid(items, numItems);
                break;
            case 4:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

/* Display the main menu */
void displayMenu() {
    printf("\n");
    printf("DIGITAL AUCTION SYSTEM\n");
    printf("----------------------\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Place Bid\n");
    printf("4. Quit\n");
}

/* Get the user's menu choice */
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

/* Add an item to the auction */
void addItem(Item items[], int* numItems) {
    Item newItem;

    printf("--- ADD NEW ITEM ---\n");
    printf("Name: ");
    scanf("%s", newItem.itemName);

    printf("Starting Price: ");
    scanf("%f", &newItem.startingPrice);

    newItem.currentBid = newItem.startingPrice;
    newItem.numBids = 0;

    items[*numItems] = newItem;
    *numItems += 1;

    printf("Item successfully added!\n");
}

/* Display all items in the auction */
void displayItems(Item items[], int numItems) {
    printf("--- LIST OF ITEMS ---\n");
    for(int i=0; i<numItems; i++) {
        printf("[%d] %s\n", i+1, items[i].itemName);
    }
}

/* Display details of a single item */
void displayItem(Item item) {
    printf("--- ITEM DETAILS ---\n");
    printf("Name: %s\n", item.itemName);
    printf("Starting Price: %.2f\n", item.startingPrice);
    printf("Current Bid: %.2f\n", item.currentBid);
    printf("Number of Bids: %d\n", item.numBids);
    printf("Bid History:\n");
    
    displayBidHistory(item);
}

/* Place a bid on an item */
void placeBid(Item items[], int numItems) {
    int itemChoice, bidID;
    float bidAmount;
    char bidderName[NAME_SIZE];

    printf("--- PLACE A BID ---\n");
    displayItems(items, numItems);

    printf("\nWhich item would you like to bid on? ");
    scanf("%d", &itemChoice);

    if(itemChoice < 1 || itemChoice > numItems) {
        printf("Invalid item choice. Please try again.\n");
        return;
    }

    Item* item = &items[itemChoice-1];

    printf("Bidder Name: ");
    scanf("%s", bidderName);

    printf("Bid Amount: ");
    scanf("%f", &bidAmount);

    if(bidAmount <= item->currentBid) {
        printf("Bid amount must be higher than current bid. Please try again.\n");
        return;
    }

    Bid newBid;
    newBid.bidID = item->numBids + 1;
    strcpy(newBid.bidderName, bidderName);
    newBid.bidAmount = bidAmount;

    item->bidHistory[item->numBids] = newBid;
    item->numBids += 1;
    item->currentBid = bidAmount;

    printf("Bid successfully placed!");
}

/* Display the bid history of an item */
void displayBidHistory(Item item) {
    if(item.numBids == 0) {
        printf("No bids have been placed on this item yet.\n");
        return;
    }

    sortBids(item);

    printf("%-10s %-20s %-10s\n", "Bid ID", "Bidder Name", "Bid Amount");
    for(int i=0; i<item.numBids; i++) {
        Bid bid = item.bidHistory[i];
        printf("%-10d %-20s %-10.2f\n", bid.bidID, bid.bidderName, bid.bidAmount);
    }
}

/* Sort the bids on an item by bid amount (highest to lowest) */
void sortBids(Item item) {
    for(int i=0; i<item.numBids-1; i++) {
        for(int j=0; j<item.numBids-i-1; j++) {
            if(item.bidHistory[j].bidAmount < item.bidHistory[j+1].bidAmount) {
                Bid temp = item.bidHistory[j];
                item.bidHistory[j] = item.bidHistory[j+1];
                item.bidHistory[j+1] = temp;
            }
        }
    }
}