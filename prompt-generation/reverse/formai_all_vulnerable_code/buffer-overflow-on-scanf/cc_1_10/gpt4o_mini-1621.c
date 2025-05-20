//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 10
#define NAME_LENGTH 50

typedef struct {
    char item_name[NAME_LENGTH];
    float starting_price;
    float highest_bid;
    char highest_bidder[NAME_LENGTH];
} AuctionItem;

typedef struct {
    AuctionItem items[MAX_ITEMS];
    int item_count;
} Auction;

void initialize_auction(Auction *auction) {
    auction->item_count = 0;
}

void add_item(Auction *auction, const char *item_name, float starting_price) {
    if (auction->item_count < MAX_ITEMS) {
        strcpy(auction->items[auction->item_count].item_name, item_name);
        auction->items[auction->item_count].starting_price = starting_price;
        auction->items[auction->item_count].highest_bid = starting_price;
        strcpy(auction->items[auction->item_count].highest_bidder, "None");
        auction->item_count++;
        printf("Item '%s' added to the auction.\n", item_name);
    } else {
        printf("Cannot add more items to the auction.\n");
    }
}

void display_auction_items(Auction *auction) {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < auction->item_count; i++) {
        printf("Item: %s, Starting Price: %.2f, Highest Bid: %.2f, Highest Bidder: %s\n",
                auction->items[i].item_name,
                auction->items[i].starting_price,
                auction->items[i].highest_bid,
                auction->items[i].highest_bidder);
    }
}

void place_bid(Auction *auction, const char *item_name, const char *bidder_name, float bid_amount) {
    for (int i = 0; i < auction->item_count; i++) {
        if (strcmp(auction->items[i].item_name, item_name) == 0) {
            if (bid_amount > auction->items[i].highest_bid) {
                auction->items[i].highest_bid = bid_amount;
                strcpy(auction->items[i].highest_bidder, bidder_name);
                printf("Bid placed successfully on '%s' by %s for %.2f.\n", item_name, bidder_name, bid_amount);
            } else {
                printf("Bid not high enough. Current highest bid is %.2f.\n", auction->items[i].highest_bid);
            }
            return;
        }
    }
    printf("Item '%s' not found in the auction.\n", item_name);
}

void display_menu() {
    printf("\n--- Digital Auction System ---\n");
    printf("1. Add Auction Item\n");
    printf("2. Display Auction Items\n");
    printf("3. Place Bid\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    Auction auction;
    initialize_auction(&auction);

    int choice;
    char item_name[NAME_LENGTH];
    char bidder_name[NAME_LENGTH];
    float amount;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter starting price: ");
                scanf("%f", &amount);
                add_item(&auction, item_name, amount);
                break;
            case 2:
                display_auction_items(&auction);
                break;
            case 3:
                printf("Enter item name to bid on: ");
                scanf("%s", item_name);
                printf("Enter bidder name: ");
                scanf("%s", bidder_name);
                printf("Enter bid amount: ");
                scanf("%f", &amount);
                place_bid(&auction, item_name, bidder_name, amount);
                break;
            case 4:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}