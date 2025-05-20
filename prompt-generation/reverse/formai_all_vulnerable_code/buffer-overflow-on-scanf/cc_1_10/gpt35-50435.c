//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct bid {
    int amount;
    char bidder_name[20];
};

struct auction_item {
    char name[30];
    char seller_name[20];
    int starting_price;
    int current_bid;
    struct bid highest_bid;
};

void print_item(struct auction_item *item) {
    printf("Name: %s\n", item->name);
    printf("Seller: %s\n", item->seller_name);
    printf("Starting price: $%d\n", item->starting_price);
    printf("Current bid: $%d\n", item->current_bid);
    if (item->highest_bid.amount > 0) {
        printf("Highest bidder: %s\n", item->highest_bid.bidder_name);
        printf("Highest bid: $%d\n", item->highest_bid.amount);
    } else {
        printf("No bids yet.\n");
    }
}

void auction(struct auction_item *item) {
    printf("\n------------ AUCTION ------------\n");
    printf("Item: %s\n", item->name);
    printf("Starting price: $%d\n", item->starting_price);

    struct bid b;
    printf("Enter your name: ");
    scanf("%s", b.bidder_name);
    printf("Enter your bid amount: $");
    scanf("%d", &b.amount);

    if (b.amount < item->starting_price) {
        printf("Bid must be at least $%d.\n", item->starting_price);
        return;
    }

    if (b.amount > item->current_bid) {
        item->highest_bid = b;
        item->current_bid = b.amount;
        printf("You are the highest bidder! Current highest bid: $%d\n", item->current_bid);
    } else {
        printf("Sorry, your bid is not high enough.\n");
    }
}

int main() {
    struct auction_item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter seller name: ");
    scanf("%s", item.seller_name);
    printf("Enter starting price: $");
    scanf("%d", &item.starting_price);
    item.current_bid = item.starting_price;
    item.highest_bid.amount = 0;

    while (1) {
        print_item(&item);
        printf("Enter your choice:\n");
        printf("1. Bid\n");
        printf("2. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            auction(&item);
        } else {
            break;
        }
    }

    printf("Auction ended.\n");
    return 0;
}