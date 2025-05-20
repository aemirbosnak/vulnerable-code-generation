//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    int price;
    int highest_bid;
} Item;

typedef struct {
    int bidder_id;
    int bid_amount;
} Bidder;

void add_item(Item* items, int num_items, int item_id, int price) {
    if (num_items == 0) {
        items[0].item_id = item_id;
        items[0].price = price;
        items[0].highest_bid = price;
        return;
    }
    int i;
    for (i = 0; i < num_items; i++) {
        if (items[i].price < price) {
            break;
        }
    }
    items[i].item_id = item_id;
    items[i].price = price;
    items[i].highest_bid = price;
}

void add_bidder(Bidder* bidders, int num_bidders, int bidder_id, int bid_amount) {
    if (num_bidders == 0) {
        bidders[0].bidder_id = bidder_id;
        bidders[0].bid_amount = bid_amount;
        return;
    }
    int i;
    for (i = 0; i < num_bidders; i++) {
        if (bidders[i].bid_amount < bid_amount) {
            break;
        }
    }
    bidders[i].bidder_id = bidder_id;
    bidders[i].bid_amount = bid_amount;
}

void display_items(Item* items, int num_items) {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("Item %d: %d\n", i + 1, items[i].price);
    }
}

void display_bidders(Bidder* bidders, int num_bidders) {
    int i;
    for (i = 0; i < num_bidders; i++) {
        printf("Bidder %d: %d\n", i + 1, bidders[i].bid_amount);
    }
}

int main() {
    int num_items = 3;
    int num_bidders = 2;
    Item items[num_items];
    Bidder bidders[num_bidders];
    int item_id, price;
    int bidder_id, bid_amount;

    printf("Enter item IDs and prices (comma separated):\n");
    scanf("%d,%d,%d", &item_id, &price, &item_id);
    add_item(items, num_items, item_id, price);

    printf("Enter bidder IDs and bids (comma separated):\n");
    scanf("%d,%d,%d,%d", &bidder_id, &bid_amount, &bidder_id, &bid_amount);
    add_bidder(bidders, num_bidders, bidder_id, bid_amount);

    printf("Items:\n");
    display_items(items, num_items);
    printf("Bidders:\n");
    display_bidders(bidders, num_bidders);

    return 0;
}