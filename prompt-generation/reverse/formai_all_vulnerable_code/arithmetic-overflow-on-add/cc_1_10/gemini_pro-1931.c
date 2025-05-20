//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10

typedef struct {
    int id;
    char name[50];
    float reserve_price;
    float current_bid;
    int num_bids;
    time_t end_time;
} Item;

typedef struct {
    int id;
    char name[50];
    float bid_amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];

int num_items = 0;
int num_bids = 0;

void add_item(char *name, float reserve_price, time_t end_time) {
    items[num_items].id = num_items;
    strcpy(items[num_items].name, name);
    items[num_items].reserve_price = reserve_price;
    items[num_items].current_bid = 0.0;
    items[num_items].num_bids = 0;
    items[num_items].end_time = end_time;
    num_items++;
}

void add_bid(int item_id, char *name, float bid_amount) {
    bids[num_bids].id = num_bids;
    strcpy(bids[num_bids].name, name);
    bids[num_bids].bid_amount = bid_amount;
    num_bids++;
}

void print_items() {
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s\n", items[i].id, items[i].name);
        printf("Reserve price: %.2f\n", items[i].reserve_price);
        printf("Current bid: %.2f\n", items[i].current_bid);
        printf("Number of bids: %d\n", items[i].num_bids);
        printf("End time: %s\n", ctime(&items[i].end_time));
        printf("\n");
    }
}

void print_bids() {
    for (int i = 0; i < num_bids; i++) {
        printf("Bid %d: %s\n", bids[i].id, bids[i].name);
        printf("Bid amount: %.2f\n\n", bids[i].bid_amount);
    }
}

int main() {
    // Add some items to the auction
    add_item("Painting", 100.0, time(NULL) + 86400);
    add_item("Sculpture", 200.0, time(NULL) + 172800);
    add_item("Vase", 50.0, time(NULL) + 259200);

    // Print the items
    print_items();

    // Add some bids to the auction
    add_bid(0, "John", 110.0);
    add_bid(1, "Mary", 210.0);
    add_bid(2, "Bob", 60.0);

    // Print the bids
    print_bids();

    return 0;
}