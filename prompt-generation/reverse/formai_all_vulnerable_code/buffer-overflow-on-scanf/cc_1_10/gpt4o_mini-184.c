//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10

typedef struct {
    int id;
    char name[50];
    char description[200];
    float starting_price;
    float bids[MAX_BIDS];
    int bid_count;
} AuctionItem;

typedef struct {
    AuctionItem items[MAX_ITEMS];
    int item_count;
} Auction;

void initialize_auction(Auction *auction) {
    auction->item_count = 0;
}

void add_item(Auction *auction, char *name, char *description, float starting_price) {
    if (auction->item_count >= MAX_ITEMS) {
        printf("Maximum items reached!\n");
        return;
    }
    
    AuctionItem newItem;
    newItem.id = auction->item_count + 1; // Simple ID assignment
    strncpy(newItem.name, name, sizeof(newItem.name));
    strncpy(newItem.description, description, sizeof(newItem.description));
    newItem.starting_price = starting_price;
    newItem.bid_count = 0;

    auction->items[auction->item_count] = newItem;
    auction->item_count++;
}

void place_bid(Auction *auction, int item_id, float bid) {
    if (item_id < 1 || item_id > auction->item_count) {
        printf("Invalid item ID!\n");
        return;
    }
    
    AuctionItem *item = &auction->items[item_id - 1];

    if (item->bid_count >= MAX_BIDS) {
        printf("Maximum bid limit reached for item %d!\n", item_id);
        return;
    }

    if (item->bid_count == 0 && bid < item->starting_price) {
        printf("Bid must be at least the starting price of %.2f!\n", item->starting_price);
        return;
    }

    if (item->bid_count > 0 && bid <= item->bids[item->bid_count - 1]) {
        printf("Bid must be higher than the last bid of %.2f!\n", item->bids[item->bid_count - 1]);
        return;
    }

    item->bids[item->bid_count] = bid;
    item->bid_count++;
    printf("Bid of %.2f placed on item %d: %s\n", bid, item_id, item->name);
}

void display_items(Auction *auction) {
    for (int i = 0; i < auction->item_count; i++) {
        AuctionItem *item = &auction->items[i];
        printf("Item ID: %d\n", item->id);
        printf("Name: %s\n", item->name);
        printf("Description: %s\n", item->description);
        printf("Starting Price: %.2f\n", item->starting_price);
        printf("Current Highest Bid: %.2f\n", (item->bid_count > 0 ? item->bids[item->bid_count - 1] : 0.0));
        printf("Number of Bids: %d\n", item->bid_count);
        printf("----------------------------------------\n");
    }
}

void auction_menu() {
    printf("Welcome to the Digital Auction System!\n");
    printf("1. Add Item\n");
    printf("2. Place Bid\n");
    printf("3. Display Items\n");
    printf("4. Exit\n");
}

int main() {
    Auction auction;
    initialize_auction(&auction);
    int choice = 0;

    while (1) {
        auction_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                char description[200];
                float starting_price;

                printf("Enter item name: ");
                getchar(); // consume newline
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove trailing newline

                printf("Enter item description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // remove trailing newline

                printf("Enter starting price: ");
                scanf("%f", &starting_price);

                add_item(&auction, name, description, starting_price);
                break;
            }
            case 2: {
                int item_id;
                float bid;

                printf("Enter item ID to bid on: ");
                scanf("%d", &item_id);
                printf("Enter your bid: ");
                scanf("%f", &bid);
                
                place_bid(&auction, item_id, bid);
                break;
            }
            case 3:
                display_items(&auction);
                break;
            case 4:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}