//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_BIDS 100

typedef struct {
    int id;
    char name[100];
    float starting_bid;
    float current_bid;
    int highest_bidder;
    int bid_count;
} AuctionItem;

typedef struct {
    int id;
    char name[100];
    float bid_amount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int item_count = 0;

void display_items() {
    printf("\nAvailable Auction Items:\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d | Name: %s | Starting Bid: $%.2f | Current Bid: $%.2f | Highest Bidder: %d\n",
            items[i].id, items[i].name, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder);
    }
}

void add_auction_item(char *name, float starting_bid) {
    if (item_count < MAX_ITEMS) {
        items[item_count].id = item_count + 1;
        strcpy(items[item_count].name, name);
        items[item_count].starting_bid = starting_bid;
        items[item_count].current_bid = starting_bid;
        items[item_count].highest_bidder = -1; // No bids yet
        items[item_count].bid_count = 0;
        item_count++;
        printf("Auction item '%s' added successfully.\n", name);
    } else {
        printf("Auction item limit reached, cannot add more items.\n");
    }
}

void place_bid(int item_id, char *bidder_name, float bid_amount) {
    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID.\n");
        return;
    }

    AuctionItem *item = &items[item_id - 1];

    if (bid_amount > item->current_bid && bid_amount > item->starting_bid) {
        item->current_bid = bid_amount;
        item->highest_bidder = item->bid_count;  // Increment and assign to the new bidder
        bids[item->bid_count].id = item->bid_count + 1;
        strcpy(bids[item->bid_count].name, bidder_name);
        bids[item->bid_count].bid_amount = bid_amount;
        item->bid_count++;
        printf("Bid of $%.2f placed successfully by %s for item '%s'.\n", bid_amount, bidder_name, item->name);
    } else {
        printf("Bid of $%.2f is too low for item '%s'.\n", bid_amount, item->name);
    }
}

void finalize_auction(int item_id) {
    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID.\n");
        return;
    }

    AuctionItem *item = &items[item_id - 1];

    if (item->highest_bidder != -1) {
        printf("Auction for '%s' finalized. Winner: %s with a bid of $%.2f.\n", item->name,
            bids[item->highest_bidder].name, item->current_bid);
    } else {
        printf("No bids were placed for item '%s'. Auction not finalized.\n", item->name);
    }
}

int main() {
    int choice;
    char name[100], bidder_name[100];
    float starting_bid, bid_amount;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Finalize Auction\n");
        printf("4. Display Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting bid: ");
                scanf("%f", &starting_bid);
                add_auction_item(name, starting_bid);
                break;
            case 2:
                printf("Enter the item ID to bid on: ");
                int item_id;
                scanf("%d", &item_id);
                printf("Enter your name: ");
                scanf("%s", bidder_name);
                printf("Enter your bid amount: ");
                scanf("%f", &bid_amount);
                place_bid(item_id, bidder_name, bid_amount);
                break;
            case 3:
                printf("Enter the item ID to finalize: ");
                int finalize_id;
                scanf("%d", &finalize_id);
                finalize_auction(finalize_id);
                break;
            case 4:
                display_items();
                break;
            case 5:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}