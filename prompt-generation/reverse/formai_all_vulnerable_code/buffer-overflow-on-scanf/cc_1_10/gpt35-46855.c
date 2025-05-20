//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_BID_AMOUNT 1000000

typedef struct {
    char bidder_name[50];
    int bid_amount;
} Bid;

typedef struct {
    int item_id;
    char item_name[50];
    int current_bid_index;
    Bid current_bids[MAX_BIDS];
} AuctionItem;

void start_auction(AuctionItem *auction_items, int num_items);
void display_auction_items(AuctionItem *auction_items, int num_items);
void display_item(AuctionItem *item);
void add_bid(AuctionItem *item, char *bidder_name, int bid_amount);
void display_bids(Bid *bids, int num_bids);

int main() {
    AuctionItem items[] = {
        {1, "Painting", 0},
        {2, "Jewelry", 0},
        {3, "Electronics", 0},
    };
    int num_items = sizeof(items)/sizeof(items[0]);

    start_auction(items, num_items);

    return 0;
}

void start_auction(AuctionItem *auction_items, int num_items) {
    int choice;
    int item_choice;
    char bidder_name[50];
    int bid_amount;

    while (1) {
        printf("\nAUCTION SYSTEM\n");
        printf("1. Display Auction Items\n");
        printf("2. Place Bid\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_auction_items(auction_items, num_items);
                break;
            case 2:
                printf("\nEnter Item ID: ");
                scanf("%d", &item_choice);
                AuctionItem *item = NULL;
                for (int i=0; i<num_items; i++) {
                    if (auction_items[i].item_id == item_choice) {
                        item = &auction_items[i];
                        break;
                    }
                }
                if (item) {
                    display_item(item);
                    printf("\nEnter your name: ");
                    scanf("%s", &bidder_name);
                    printf("Enter your bid amount: ");
                    scanf("%d", &bid_amount);
                    if (bid_amount > item->current_bids[item->current_bid_index-1].bid_amount || item->current_bid_index == 0) {
                        add_bid(item, bidder_name, bid_amount);
                        printf("Bid placed successfully.");
                    } else {
                        printf("Your bid amount must be greater than current highest bid amount.\n");
                    }
                } else {
                    printf("Invalid item id.\n");
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
}

void display_auction_items(AuctionItem *auction_items, int num_items) {
    printf("\nAUCTION ITEMS\n");
    for (int i=0; i<num_items; i++) {
        display_item(&auction_items[i]);
    }
}

void display_item(AuctionItem *item) {
    printf("Item ID: %d\n", item->item_id);
    printf("Item Name: %s\n", item->item_name);
    if (item->current_bid_index == 0) {
        printf("No bids placed yet.\n");
    } else {
        printf("Highest Bid: %s, %d\n", item->current_bids[item->current_bid_index-1].bidder_name, item->current_bids[item->current_bid_index-1].bid_amount);
        printf("All Bids:\n");
        display_bids(item->current_bids, item->current_bid_index);
    }
}

void add_bid(AuctionItem *item, char *bidder_name, int bid_amount) {
    if (item->current_bid_index == MAX_BIDS) {
        printf("No more bids can be placed on this item.\n");
    } else if (bid_amount > MAX_BID_AMOUNT) {
        printf("Your bid amount is too high. Maximum bid amount allowed is %d.\n", MAX_BID_AMOUNT);
    } else {
        Bid new_bid;
        strcpy(new_bid.bidder_name, bidder_name);
        new_bid.bid_amount = bid_amount;
        item->current_bids[item->current_bid_index] = new_bid;
        item->current_bid_index++;
    }
}

void display_bids(Bid *bids, int num_bids) {
    for (int i=0; i<num_bids; i++) {
        printf("\t%s, %d\n", bids[i].bidder_name, bids[i].bid_amount);
    }
}