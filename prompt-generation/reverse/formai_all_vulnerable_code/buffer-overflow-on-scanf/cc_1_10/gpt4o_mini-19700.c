//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ITEM_LENGTH 100

typedef struct {
    char itemName[MAX_ITEM_LENGTH];
    float startingBid;
    float currentBid;
    char highestBidder[MAX_NAME_LENGTH];
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float bidAmount;
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

void displayMenu();
void addItem();
void placeBid();
void displayItems();
void sendLoveLetter();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                sendLoveLetter();
                break;
            case 5:
                printf("Thank you for participating in our romantic auction! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Welcome to the Romantic Digital Auction! ---\n");
    printf("1. Add a new item\n");
    printf("2. Place a bid\n");
    printf("3. Display all items\n");
    printf("4. Send a love letter\n");
    printf("5. Exit\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached. Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter the name of the item: ");
    scanf(" %[^\n]", newItem.itemName);
    printf("Enter the starting bid for %s: ", newItem.itemName);
    scanf("%f", &newItem.startingBid);
    newItem.currentBid = newItem.startingBid;
    strcpy(newItem.highestBidder, "None");
    
    items[itemCount++] = newItem;
    printf("Item \"%s\" added successfully!\n", newItem.itemName);
}

void placeBid() {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
    
    printf("Enter your name: ");
    scanf(" %[^\n]", bidderName);
    
    printf("Enter the bid amount: ");
    scanf("%f", &bidAmount);

    printf("Choose an item to bid on (0 to %d): ", itemCount - 1);
    for (int i = 0; i < itemCount; i++) {
        printf("\n%d. %s - Current Bid: %.2f", i, items[i].itemName, items[i].currentBid);
    }
    
    int itemIndex;
    printf("\nYour choice: ");
    scanf("%d", &itemIndex);
    
    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item selection.\n");
        return;
    }

    if (bidAmount > items[itemIndex].currentBid) {
        items[itemIndex].currentBid = bidAmount;
        strcpy(items[itemIndex].highestBidder, bidderName);
        printf("Congratulations, %s! You have placed the highest bid of %.2f on \"%s\".\n", 
               bidderName, bidAmount, items[itemIndex].itemName);
    } else {
        printf("Your bid must be higher than the current bid of %.2f.\n", items[itemIndex].currentBid);
    }
}

void displayItems() {
    printf("\n--- Current Auction Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Starting Bid: %.2f, Current Bid: %.2f, Highest Bidder: %s\n", 
               i, items[i].itemName, items[i].startingBid, 
               items[i].currentBid, items[i].highestBidder);
    }
}

void sendLoveLetter() {
    char loverName[MAX_NAME_LENGTH];
    char message[256];
    
    printf("Enter your beloved's name: ");
    scanf(" %[^\n]", loverName);
    
    printf("Write your love message: ");
    scanf(" %[^\n]", message);
    
    printf("\n--- Sending Love Letter ---\n");
    printf("To: %s\n", loverName);
    printf("Message: %s\n", message);
    printf("Your love letter has been sent with all the romance in the air!\n");
}