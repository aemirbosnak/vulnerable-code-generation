//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    int id;
    char name[50];
    float starting_price;
    float current_bid;
    int is_active;
} Item;

typedef struct {
    int id;
    float amount;
    int item_id;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0, num_bids = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Cannot add more items. Max limit reached.\n");
        return;
    }
    
    Item item;
    item.id = num_items + 1;  // Unique item ID
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter starting price: ");
    scanf("%f", &item.starting_price);
    item.current_bid = item.starting_price;
    item.is_active = 1; // Item is active for bidding
    
    items[num_items++] = item;
    printf("Item added successfully! ID: %d, Name: %s\n", item.id, item.name);
}

void display_items() {
    printf("Active Auction Items:\n");
    for (int i = 0; i < num_items; i++) {
        if (items[i].is_active) {
            printf("ID: %d, Name: %s, Starting Price: %.2f, Current Bid: %.2f\n",
                   items[i].id, items[i].name,
                   items[i].starting_price, items[i].current_bid);
        }
    }
}

void place_bid() {
    int item_id;
    float bid_amount;

    printf("Enter item ID to bid on: ");
    scanf("%d", &item_id);

    // Check if the item ID is valid
    if (item_id <= 0 || item_id > num_items || !items[item_id - 1].is_active) {
        printf("Invalid item ID or item is not active for bidding.\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= items[item_id - 1].current_bid) {
        printf("Bid must be higher than the current bid of %.2f.\n", items[item_id - 1].current_bid);
        return;
    }

    // Record the bid
    if (num_bids >= MAX_BIDS) {
        printf("Cannot place more bids. Max limit reached.\n");
        return;
    }

    Bid bid;
    bid.id = num_bids + 1;  // Unique bid ID
    bid.item_id = item_id;
    bid.amount = bid_amount;

    bids[num_bids++] = bid;
    items[item_id - 1].current_bid = bid_amount; // Update current bid
    printf("Bid placed successfully! Bid ID: %d, Amount: %.2f\n", bid.id, bid.amount);
}

void end_auction() {
    int item_id;
    display_items();
    
    printf("Enter item ID to end auction: ");
    scanf("%d", &item_id);

    if (item_id <= 0 || item_id > num_items) {
        printf("Invalid item ID.\n");
        return;
    }
    
    items[item_id - 1].is_active = 0; // Mark item as inactive
    printf("Auction for item ID %d ended. Final bid amount: %.2f\n",
           item_id, items[item_id - 1].current_bid);
}

void display_bids() {
    printf("Bids Placed:\n");
    for (int i = 0; i < num_bids; i++) {
        printf("Bid ID: %d, Item ID: %d, Bid Amount: %.2f\n",
               bids[i].id, bids[i].item_id, bids[i].amount);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Place Bid\n");
        printf("4. End Auction\n");
        printf("5. Display Bids\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                end_auction();
                break;
            case 5:
                display_bids();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}