//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    float starting_price;
    float current_bid;
    char highest_bidder[50];
} AuctionItem;

typedef struct {
    char name[50];
    float bid_amount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int item_count = 0;
int bid_count = 0;

void add_item(const char *name, float starting_price) {
    if (item_count >= MAX_ITEMS) {
        printf("Maximum item limit reached!\n");
        return;
    }
    strcpy(items[item_count].name, name);
    items[item_count].starting_price = starting_price;
    items[item_count].current_bid = starting_price;
    strcpy(items[item_count].highest_bidder, "No bids yet");
    item_count++;
    printf("Item '%s' added with starting price %.2f\n", name, starting_price);
}

void place_bid(const char *item_name, const char *bidder_name, float bid_amount) {
    int found = -1;
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Item '%s' not found!\n", item_name);
        return;
    }

    if (bid_amount <= items[found].current_bid) {
        printf("Bid amount must be higher than the current bid (%.2f).\n", items[found].current_bid);
        return;
    }

    strcpy(bids[bid_count].name, bidder_name);
    bids[bid_count].bid_amount = bid_amount;
    bid_count++;

    items[found].current_bid = bid_amount;
    strcpy(items[found].highest_bidder, bidder_name);
    printf("Bid of %.2f placed on '%s' by '%s'\n", bid_amount, item_name, bidder_name);
}

void display_auction_items() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < item_count; i++) {
        printf(" - %s: Starting Price: %.2f, Current Bid: %.2f, Highest Bidder: %s\n",
               items[i].name, items[i].starting_price, items[i].current_bid, items[i].highest_bidder);
    }
}

void display_bids() {
    printf("\nBids placed:\n");
    for (int i = 0; i < bid_count; i++) {
        printf(" - Bidder: %s, Amount: %.2f\n", bids[i].name, bids[i].bid_amount);
    }
}

void auction_menu() {
    int choice;
    char item_name[50], bidder_name[50];
    float starting_price, bid_amount;

    do {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Add New Item\n");
        printf("2. Place a Bid\n");
        printf("3. Display Auction Items\n");
        printf("4. Display Bid History\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter starting price: ");
                scanf("%f", &starting_price);
                add_item(item_name, starting_price);
                break;
            case 2:
                printf("Enter item name to bid on: ");
                scanf("%s", item_name);
                printf("Enter your name: ");
                scanf("%s", bidder_name);
                printf("Enter bid amount: ");
                scanf("%f", &bid_amount);
                place_bid(item_name, bidder_name, bid_amount);
                break;
            case 3:
                display_auction_items();
                break;
            case 4:
                display_bids();
                break;
            case 5:
                printf("Exiting auction system.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    auction_menu();
    return 0;
}