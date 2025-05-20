//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    int item_id;
    char name[50];
    float starting_price;
    float current_price;
    int highest_bidder_id;
    int bid_count;
} Item;

typedef struct {
    int bidder_id;
    char name[50];
    float bid_amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];

int item_count = 0;
int bid_count = 0;

void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Cannot add more items to auction.\n");
        return;
    }
    Item new_item;
    new_item.item_id = item_count + 1;

    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter starting price: ");
    scanf("%f", &new_item.starting_price);
    
    new_item.current_price = new_item.starting_price;
    new_item.highest_bidder_id = -1;
    new_item.bid_count = 0;

    items[item_count++] = new_item;
    printf("Item added successfully!\n");
}

void displayItems() {
    printf("\nAvailable Items:\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item ID: %d\n", items[i].item_id);
        printf("Item Name: %s\n", items[i].name);
        printf("Current Price: %.2f\n", items[i].current_price);
        printf("Highest Bidder ID: %d\n", items[i].highest_bidder_id);
        printf("Number of Bids: %d\n", items[i].bid_count);
        printf("------------\n");
    }
}

void placeBid() {
    int item_id;
    float bid_amount;
    printf("Enter item ID you want to bid on: ");
    scanf("%d", &item_id);

    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID.\n");
        return;
    }

    printf("Enter your bidder ID: ");
    int bidder_id;
    scanf("%d", &bidder_id);
    
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= items[item_id - 1].current_price) {
        printf("Bid amount must be higher than the current price.\n");
        return;
    }

    // Update item and bids
    items[item_id - 1].current_price = bid_amount;
    items[item_id - 1].highest_bidder_id = bidder_id;
    items[item_id - 1].bid_count++;

    // Record the bid
    if (bid_count < MAX_BIDS) {
        bids[bid_count].bidder_id = bidder_id;
        strcpy(bids[bid_count].name, "Bidder"); // Generic name
        bids[bid_count].bid_amount = bid_amount;
        bid_count++;
    }

    printf("Bid placed successfully!\n");
}

void displayBids() {
    printf("\nAll Bids:\n");
    for (int i = 0; i < bid_count; i++) {
        printf("Bidder ID: %d, Bid Amount: %.2f\n", bids[i].bidder_id, bids[i].bid_amount);
    }
}

void auctionMenu() {
    int choice;
    do {
        printf("\nDigital Auction System Menu\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Place Bid\n");
        printf("4. Display Bids\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: placeBid(); break;
            case 4: displayBids(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    auctionMenu();
    return 0;
}