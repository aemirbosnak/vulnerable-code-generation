//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 1000

typedef struct {
    int item_id;
    char *item_name;
    float starting_bid;
    float current_bid;
    int num_bids;
    time_t auction_end;
} Item;

typedef struct {
    int bid_id;
    int item_id;
    float bid_amount;
    time_t bid_time;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0;
int num_bids = 0;

void add_item(int item_id, char *item_name, float starting_bid, time_t auction_end) {
    items[num_items].item_id = item_id;
    items[num_items].item_name = strdup(item_name);
    items[num_items].starting_bid = starting_bid;
    items[num_items].current_bid = starting_bid;
    items[num_items].num_bids = 0;
    items[num_items].auction_end = auction_end;
    num_items++;
}

void add_bid(int bid_id, int item_id, float bid_amount, time_t bid_time) {
    bids[num_bids].bid_id = bid_id;
    bids[num_bids].item_id = item_id;
    bids[num_bids].bid_amount = bid_amount;
    bids[num_bids].bid_time = bid_time;
    num_bids++;
}

void print_items() {
    for (int i = 0; i < num_items; i++) {
        printf("Item ID: %d\n", items[i].item_id);
        printf("Item Name: %s\n", items[i].item_name);
        printf("Starting Bid: %.2f\n", items[i].starting_bid);
        printf("Current Bid: %.2f\n", items[i].current_bid);
        printf("Number of Bids: %d\n", items[i].num_bids);
        printf("Auction End: %s\n", ctime(&items[i].auction_end));
        printf("\n");
    }
}

void print_bids() {
    for (int i = 0; i < num_bids; i++) {
        printf("Bid ID: %d\n", bids[i].bid_id);
        printf("Item ID: %d\n", bids[i].item_id);
        printf("Bid Amount: %.2f\n", bids[i].bid_amount);
        printf("Bid Time: %s\n", ctime(&bids[i].bid_time));
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Add some items to the auction
    add_item(1, "iPhone 13 Pro Max", 1000.00, time(NULL) + 86400);
    add_item(2, "MacBook Air M2", 1200.00, time(NULL) + 86400);
    add_item(3, "Apple Watch Series 8", 400.00, time(NULL) + 86400);

    // Simulate some bids
    for (int i = 0; i < 100; i++) {
        int item_id = rand() % num_items;
        float bid_amount = items[item_id].current_bid + (rand() % 100) / 100.0;
        add_bid(i, item_id, bid_amount, time(NULL));
    }

    // Print the items and bids
    print_items();
    print_bids();

    return 0;
}