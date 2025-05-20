//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100 /* Maximum number of auction items */
#define MAX_NAME 30 /* Maximum length of item and bidder names */

/* Structure for auction item */
typedef struct {
    char name[MAX_NAME];
    char description[MAX_NAME];
    int starting_bid;
    int current_bid;
    char highest_bidder[MAX_NAME];
    int num_bids;
} AuctionItem;

/* Function prototypes */
void init(AuctionItem* items, int num_items);
void print_items(AuctionItem* items, int num_items);
void place_bid(AuctionItem* item, char* bidder_name, int bid_amount);

/* Main function */
int main() {
    AuctionItem items[MAX_ITEMS];
    int num_items;

    /* Prompt user for number of items */
    printf("Enter number of auction items: ");
    scanf("%d", &num_items);

    /* Initialize items */
    init(items, num_items);

    /* Print items */
    print_items(items, num_items);

    /* Place bids */
    char bidder_name[MAX_NAME];
    int bid_amount, item_index;
    while (1) {
        /* Prompt user for bidder name and bid amount */
        printf("Enter bidder name (or 'quit' to exit): ");
        scanf("%s", bidder_name);
        if (strcmp(bidder_name, "quit") == 0) {
            break;
        }
        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);

        /* Prompt user for item index */
        printf("Enter item index (1-%d): ", num_items);
        scanf("%d", &item_index);

        /* Place bid */
        place_bid(&items[item_index-1], bidder_name, bid_amount);
    }

    /* Print items */
    printf("\nFinal auction results:\n");
    print_items(items, num_items);

    return 0;
}

/* Initialize auction items */
void init(AuctionItem* items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        /* Prompt user for item name, description, and starting bid */
        printf("Enter name for item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter description for item %d: ", i+1);
        scanf("%s", items[i].description);
        printf("Enter starting bid for item %d: ", i+1);
        scanf("%d", &items[i].starting_bid);

        /* Initialize current bid, highest bidder, and number of bids */
        items[i].current_bid = items[i].starting_bid;
        strcpy(items[i].highest_bidder, "none");
        items[i].num_bids = 0;
    }
}

/* Print auction items */
void print_items(AuctionItem* items, int num_items) {
    printf("\nAuction items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s: %s (starting bid: %d, current bid: %d, highest bidder: %s, number of bids: %d)\n",
            i+1, items[i].name, items[i].description, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder, items[i].num_bids);
    }
}

/* Place bid on auction item */
void place_bid(AuctionItem* item, char* bidder_name, int bid_amount) {
    if (bid_amount <= item->current_bid) {
        printf("Bid amount must be greater than current bid.\n");
        return;
    }

    item->current_bid = bid_amount;
    strcpy(item->highest_bidder, bidder_name);
    item->num_bids++;

    printf("Bid placed successfully.\n");
}