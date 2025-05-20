//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define ITEM_NAME_LEN 50
#define USER_NAME_LEN 50

typedef struct {
    char name[ITEM_NAME_LEN];
    float starting_price;
    float current_bid;
    char highest_bidder[USER_NAME_LEN];
    int auction_open;
} AuctionItem;

typedef struct {
    char username[USER_NAME_LEN];
    float bid_amount;
} Bid;

AuctionItem items[MAX_ITEMS];
int item_count = 0;

void initialize_item(AuctionItem *item, const char *name, float starting_price) {
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->current_bid = starting_price;
    strcpy(item->highest_bidder, "None");
    item->auction_open = 1;
}

void start_auction() {
    char item_name[ITEM_NAME_LEN];
    float starting_price;
    
    printf("Enter the name of the auction item: ");
    scanf("%s", item_name);
    printf("Enter the starting price: ");
    scanf("%f", &starting_price);
    
    initialize_item(&items[item_count], item_name, starting_price);
    item_count++;
    printf("Auction for %s has been started with a starting price of $%.2f\n", item_name, starting_price);
}

void place_bid() {
    char bidder[USER_NAME_LEN];
    char item_name[ITEM_NAME_LEN];
    float bid_amount;

    printf("Enter your username: ");
    scanf("%s", bidder);
    printf("Enter the item name you want to bid on: ");
    scanf("%s", item_name);
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            if (items[i].auction_open) {
                if (bid_amount > items[i].current_bid) {
                    items[i].current_bid = bid_amount;
                    strcpy(items[i].highest_bidder, bidder);
                    printf("Bid accepted! Current highest bid for %s is $%.2f by %s\n", items[i].name, items[i].current_bid, items[i].highest_bidder);
                } else {
                    printf("Bid rejected! Your bid must be higher than the current bid of $%.2f\n", items[i].current_bid);
                }
            } else {
                printf("Auction for %s is closed.\n", items[i].name);
            }
            return;
        }
    }
    printf("Item %s not found.\n", item_name);
}

void close_auction() {
    char item_name[ITEM_NAME_LEN];

    printf("Enter the item name to close auction: ");
    scanf("%s", item_name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].auction_open = 0;
            printf("Auction for %s has been closed. Final bid was $%.2f by %s\n", items[i].name, items[i].current_bid, items[i].highest_bidder);
            return;
        }
    }
    printf("Item %s not found.\n", item_name);
}

void view_auctions() {
    if (item_count == 0) {
        printf("No auctions available.\n");
        return;
    }
    for (int i = 0; i < item_count; i++) {
        printf("Item: %s | Current Bid: $%.2f | Highest Bidder: %s | Auction Status: %s\n",
               items[i].name, items[i].current_bid, items[i].highest_bidder,
               items[i].auction_open ? "Open" : "Closed");
    }
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System:\n");
        printf("1. Start Auction\n");
        printf("2. Place Bid\n");
        printf("3. Close Auction\n");
        printf("4. View Auctions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                start_auction();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                close_auction();
                break;
            case 4:
                view_auctions();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}