//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Item structure
typedef struct {
    int id;
    char name[50];
    float starting_price;
    float current_bid;
    time_t start_time;
    time_t end_time;
} Item;

// Bid structure
typedef struct {
    int item_id;
    float bid_amount;
    char bidder_name[50];
    time_t bid_time;
} Bid;

// Function to create a new item
Item* create_item(int id, char name[], float starting_price, time_t start_time, time_t end_time) {
    Item* item = (Item*) malloc(sizeof(Item));
    item->id = id;
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->current_bid = starting_price;
    item->start_time = start_time;
    item->end_time = end_time;
    return item;
}

// Function to create a new bid
Bid* create_bid(int item_id, float bid_amount, char bidder_name[], time_t bid_time) {
    Bid* bid = (Bid*) malloc(sizeof(Bid));
    bid->item_id = item_id;
    bid->bid_amount = bid_amount;
    strcpy(bid->bidder_name, bidder_name);
    bid->bid_time = bid_time;
    return bid;
}

// Function to display an item's details
void show_item_details(Item* item) {
    printf("Item ID: %d\n", item->id);
    printf("Item Name: %s\n", item->name);
    printf("Starting Price: %.2f\n", item->starting_price);
    printf("Current Bid: %.2f\n", item->current_bid);
    printf("Start Time: %s", ctime(&item->start_time));
}

// Function to display a bid's details
void show_bid_details(Bid* bid) {
    printf("Item ID: %d\n", bid->item_id);
    printf("Bid Amount: %.2f\n", bid->bid_amount);
    printf("Bidder Name: %s\n", bid->bidder_name);
    printf("Bid Time: %s", ctime(&bid->bid_time));
}

int main() {
    // Create some items
    Item* item1 = create_item(1, "Macbook Pro", 2000.00, time(NULL), time(NULL) + 3600);
    Item* item2 = create_item(2, "iPhone X", 1000.00, time(NULL), time(NULL) + 1800);
    Item* item3 = create_item(3, "Samsung TV", 1500.00, time(NULL), time(NULL) + 7200);

    // Display the items
    printf("Auction Items\n");
    printf("-------------------\n");
    show_item_details(item1);
    show_item_details(item2);
    show_item_details(item3);

    // Place some bids
    Bid* bid1 = create_bid(1, 2200.00, "John", time(NULL));
    item1->current_bid = bid1->bid_amount;
    Bid* bid2 = create_bid(2, 1200.00, "Jane", time(NULL));
    item2->current_bid = bid2->bid_amount;
    Bid* bid3 = create_bid(3, 1600.00, "Tom", time(NULL));
    item3->current_bid = bid3->bid_amount;

    // Display the bids
    printf("Bids Placed\n");
    printf("-------------------\n");
    show_bid_details(bid1);
    show_bid_details(bid2);
    show_bid_details(bid3);

    // Update some bids
    Bid* updated_bid1 = create_bid(1, 2300.00, "John", time(NULL));
    if (updated_bid1->bid_amount > item1->current_bid) {
        item1->current_bid = updated_bid1->bid_amount;
    }
    Bid* updated_bid2 = create_bid(2, 1500.00, "Jane", time(NULL));
    if (updated_bid2->bid_amount > item2->current_bid) {
        item2->current_bid = updated_bid2->bid_amount;
    }

    // Display the updated bids
    printf("Updated Bids\n");
    printf("-------------------\n");
    show_bid_details(updated_bid1);
    show_bid_details(updated_bid2);

    // Determine the current winning bid for each item
    printf("Winning Bids\n");
    printf("-------------------\n");
    printf("Item: %s, Winning Bid: %.2f\n", item1->name, item1->current_bid);
    printf("Item: %s, Winning Bid: %.2f\n", item2->name, item2->current_bid);
    printf("Item: %s, Winning Bid: %.2f\n", item3->name, item3->current_bid);

    // Determine if any items have sold
    if (time(NULL) > item1->end_time) {
        printf("Item %s has sold for %.2f to %s\n", item1->name, item1->current_bid, updated_bid1->bidder_name);
    }
    if (time(NULL) > item2->end_time) {
        printf("Item %s has sold for %.2f to %s\n", item2->name, item2->current_bid, updated_bid2->bidder_name);
    }
    if (time(NULL) > item3->end_time) {
        printf("Item %s has not sold\n", item3->name);
    }

    // Free memory
    free(item1);
    free(item2);
    free(item3);
    free(bid1);
    free(bid2);
    free(bid3);
    free(updated_bid1);
    free(updated_bid2);

    return 0;
}