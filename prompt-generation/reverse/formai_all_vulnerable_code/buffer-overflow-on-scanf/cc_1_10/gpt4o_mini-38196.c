//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define ITEM_NAME_LEN 50
#define USER_NAME_LEN 30

typedef struct {
    int id;
    char name[ITEM_NAME_LEN];
    double starting_price;
    double current_price;
    int active;
    time_t end_time;
} AuctionItem;

typedef struct {
    int item_id;
    char username[USER_NAME_LEN];
    double bid_amount;
    time_t bid_time;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0, num_bids = 0;

void add_auction_item(const char *name, double starting_price, int duration) {
    if (num_items >= MAX_ITEMS) {
        printf("Max items reached!\n");
        return;
    }
    
    AuctionItem new_item;
    new_item.id = num_items + 1;
    strcpy(new_item.name, name);
    new_item.starting_price = starting_price;
    new_item.current_price = starting_price;
    new_item.active = 1;
    new_item.end_time = time(NULL) + duration;

    items[num_items++] = new_item;

    printf("Auction item added: %s (ID: %d)\n", new_item.name, new_item.id);
}

void place_bid(int item_id, const char *username, double amount) {
    if (item_id < 1 || item_id > num_items) {
        printf("Invalid auction item ID!\n");
        return;
    }

    AuctionItem *item = &items[item_id - 1];
    if (!item->active) {
        printf("Auction for %s is no longer active.\n", item->name);
        return;
    }

    if (amount <= item->current_price) {
        printf("Your bid must be higher than the current price of %.2f\n", item->current_price);
        return;
    }

    time_t current_time = time(NULL);
    if (current_time > item->end_time) {
        printf("Bidding for %s has ended.\n", item->name);
        item->active = 0; // Deactivate item
        return;
    }

    // Record the bid
    if (num_bids >= MAX_BIDS) {
        printf("Max bids reached!\n");
        return;
    }

    Bid new_bid;
    new_bid.item_id = item_id;
    strcpy(new_bid.username, username);
    new_bid.bid_amount = amount;
    new_bid.bid_time = current_time;

    bids[num_bids++] = new_bid;
    
    item->current_price = amount;
    printf("%s placed a bid of %.2f on %s (Current highest bid: %.2f)\n", username, amount, item->name, item->current_price);
}

void show_auction_items() {
    printf("\nAuction Items:\n");
    for (int i = 0; i < num_items; i++) {
        AuctionItem item = items[i];
        if (item.active) {
            printf("ID: %d, Name: %s, Starting Price: %.2f, Current Price: %.2f, Ends In: %ld seconds\n",
                   item.id, item.name, item.starting_price, item.current_price, (item.end_time - time(NULL)));
        } else {
            printf("ID: %d, Name: %s, Auction ended. Final Price: %.2f\n", item.id, item.name, item.current_price);
        }
    }
}

void end_auctions() {
    time_t current_time = time(NULL);
    for (int i = 0; i < num_items; i++) {
        AuctionItem *item = &items[i];
        if (item->active && current_time > item->end_time) {
            item->active = 0;
            printf("Auction for %s ended. Final price: %.2f\n", item->name, item->current_price);
        }
    }
}

int main() {
    int command;
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Show Auction Items\n");
        printf("4. End Auctions\n");
        printf("5. Exit\n");
        printf("Enter your command: ");
        scanf("%d", &command);

        switch (command) {
            case 1: {
                char name[ITEM_NAME_LEN];
                double starting_price;
                int duration;

                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%lf", &starting_price);
                printf("Enter auction duration (seconds): ");
                scanf("%d", &duration);

                add_auction_item(name, starting_price, duration);
                break;
            }
            case 2: {
                int item_id;
                char username[USER_NAME_LEN];
                double amount;

                printf("Enter item ID: ");
                scanf("%d", &item_id);
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your bid amount: ");
                scanf("%lf", &amount);

                place_bid(item_id, username, amount);
                break;
            }
            case 3:
                show_auction_items();
                break;
            case 4:
                end_auctions();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
        }
    }
    return 0;
}