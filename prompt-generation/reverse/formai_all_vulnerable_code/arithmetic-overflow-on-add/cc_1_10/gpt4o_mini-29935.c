//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 50
#define MAX_BIDDERS 100

typedef struct {
    int item_id;
    char item_name[50];
    float start_price;
    float current_price;
    int highest_bidder_id;
    time_t end_time;
} AuctionItem;

typedef struct {
    int bidder_id;
    char bidder_name[50];
} Bidder;

AuctionItem items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int item_count = 0;
int bidder_count = 0;

void add_auction_item(const char *item_name, float start_price, int duration) {
    if (item_count >= MAX_ITEMS) {
        printf("Auction item limit reached!\n");
        return;
    }
    items[item_count].item_id = item_count + 1;
    strcpy(items[item_count].item_name, item_name);
    items[item_count].start_price = start_price;
    items[item_count].current_price = start_price;
    items[item_count].highest_bidder_id = -1;
    items[item_count].end_time = time(NULL) + duration;
    item_count++;
    printf("Added item: %s, Start Price: %.2f, Auction Duration: %d seconds.\n",
           item_name, start_price, duration);
}

void register_bidder(const char *bidder_name) {
    if (bidder_count >= MAX_BIDDERS) {
        printf("Bidder limit reached!\n");
        return;
    }
    bidders[bidder_count].bidder_id = bidder_count + 1;
    strcpy(bidders[bidder_count].bidder_name, bidder_name);
    bidder_count++;
    printf("Registered bidder: %s\n", bidder_name);
}

int place_bid(int item_id, int bidder_id, float bid_amount) {
    if (item_id <= 0 || item_id > item_count || bidder_id <= 0 || bidder_id > bidder_count) {
        printf("Invalid item or bidder ID!\n");
        return -1;
    }
    
    AuctionItem *item = &items[item_id - 1];
    if (time(NULL) > item->end_time) {
        printf("Auction for item %d has ended.\n", item_id);
        return -1;
    }
    
    if (bid_amount <= item->current_price) {
        printf("Bid amount must be greater than the current price %.2f.\n", item->current_price);
        return -1;
    }
    
    item->current_price = bid_amount;
    item->highest_bidder_id = bidder_id;
    printf("Bid placed on item %d by bidder %s: New price is %.2f\n",
           item_id, bidders[bidder_id - 1].bidder_name, bid_amount);
    return 0;
}

void display_auction_items() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < item_count; ++i) {
        AuctionItem *item = &items[i];
        printf("Item ID: %d, Name: %s, Current Price: %.2f, Highest Bidder: %s\n",
               item->item_id, item->item_name, item->current_price,
               item->highest_bidder_id != -1 ? bidders[item->highest_bidder_id - 1].bidder_name : "No bids");
    }
}

void end_auction() {
    time_t current_time = time(NULL);
    for (int i = 0; i < item_count; ++i) {
        AuctionItem *item = &items[i];
        if (current_time > item->end_time) {
            printf("Auction for item %s ended. Final price: %.2f (Winner: %s)\n", 
                   item->item_name, item->current_price,
                   item->highest_bidder_id != -1 ? bidders[item->highest_bidder_id - 1].bidder_name : "No bids");
        }
    }
}

int main() {
    register_bidder("Alice");
    register_bidder("Bob");
    register_bidder("Eve");

    add_auction_item("Antique Vase", 100.0, 30);
    add_auction_item("Vintage Clock", 50.0, 60);
    
    place_bid(1, 1, 120.0);
    place_bid(1, 2, 130.0);
    place_bid(2, 1, 60.0);
    
    display_auction_items();

    // Simulate a delay before ending the auction
    sleep(31);
    end_auction();

    return 0;
}