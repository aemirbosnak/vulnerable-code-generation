//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float starting_price;
    float current_bid;
    char highest_bidder[MAX_NAME_LENGTH];
} Item;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float balance;
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int item_count = 0;
int bidder_count = 0;

void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Maximum item limit reached\n");
        return;
    }
    Item new_item;
    new_item.id = item_count + 1;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter starting price: ");
    scanf("%f", &new_item.starting_price);
    new_item.current_bid = new_item.starting_price;
    strcpy(new_item.highest_bidder, "No bids yet");

    items[item_count] = new_item;
    item_count++;
    printf("Item added successfully!\n");
}

void addBidder() {
    if (bidder_count >= MAX_BIDDERS) {
        printf("Maximum bidder limit reached\n");
        return;
    }
    Bidder new_bidder;
    new_bidder.id = bidder_count + 1;
    printf("Enter bidder name: ");
    scanf("%s", new_bidder.name);
    printf("Enter initial balance: ");
    scanf("%f", &new_bidder.balance);

    bidders[bidder_count] = new_bidder;
    bidder_count++;
    printf("Bidder added successfully!\n");
}

void placeBid() {
    int item_id, bidder_id;
    float bid_amount;

    printf("Enter item ID to bid on: ");
    scanf("%d", &item_id);
    printf("Enter bidder ID: ");
    scanf("%d", &bidder_id);
    printf("Enter bid amount: ");
    scanf("%f", &bid_amount);

    if (item_id < 1 || item_id > item_count || bidder_id < 1 || bidder_id > bidder_count) {
        printf("Invalid item or bidder ID\n");
        return;
    }

    Item *item = &items[item_id - 1];
    Bidder *bidder = &bidders[bidder_id - 1];

    if (bid_amount <= item->current_bid) {
        printf("Bid amount must be greater than the current bid of %.2f\n", item->current_bid);
        return;
    }

    if (bid_amount > bidder->balance) {
        printf("Bidder does not have sufficient balance\n");
        return;
    }

    // Update the item's current bid and highest bidder
    item->current_bid = bid_amount;
    strcpy(item->highest_bidder, bidder->name);
    // Deduct the bid amount from the bidder's balance
    bidder->balance -= bid_amount;

    printf("Bid placed successfully!\n");
}

void displayItems() {
    printf("\n---- Auction Items ----\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item ID: %d\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Starting Price: %.2f\n", items[i].starting_price);
        printf("Current Bid: %.2f\n", items[i].current_bid);
        printf("Highest Bidder: %s\n", items[i].highest_bidder);
        printf("\n");
    }
}

void displayBidders() {
    printf("\n---- Registered Bidders ----\n");
    for (int i = 0; i < bidder_count; i++) {
        printf("Bidder ID: %d\n", bidders[i].id);
        printf("Name: %s\n", bidders[i].name);
        printf("Balance: %.2f\n", bidders[i].balance);
        printf("\n");
    }
}

void auctionMenu() {
    int choice;
    do {
        printf("\n---- Digital Auction System ----\n");
        printf("1. Add Item\n");
        printf("2. Add Bidder\n");
        printf("3. Place Bid\n");
        printf("4. Display Items\n");
        printf("5. Display Bidders\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                addBidder();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                displayBidders();
                break;
            case 6:
                printf("Exiting the auction system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    auctionMenu();
    return 0;
}