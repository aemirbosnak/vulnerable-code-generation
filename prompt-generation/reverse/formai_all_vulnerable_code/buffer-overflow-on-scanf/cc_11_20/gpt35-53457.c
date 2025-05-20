//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BIDDERS 5
#define NUM_ITEMS 3

#define MAX_BID 1000

struct Bid {
    int bidder_id;
    int item_id;
    int price;
};

struct Item {
    int id;
    char name[50];
    int starting_bid;
    int current_bid;
    int winning_bidder;
};

int main() {
    srand(time(0)); // Seed random number generator
    
    struct Item items[NUM_ITEMS] = { // Initialize items
        {1, "Painting", 500, 500, -1},
        {2, "Vase", 200, 200, -1},
        {3, "Statue", 300, 300, -1}
    };
    
    struct Bid bids[NUM_BIDDERS] = { // Initialize bidders
        {0, 0, 0},
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 0},
        {4, 0, 0}
    };
    
    int auction_over = 0;
    while (!auction_over) {
        printf("Current items and bids:\n");
        for (int i = 0; i < NUM_ITEMS; i++) {
            printf("%d. %s - current bid: %d\n", items[i].id, items[i].name, items[i].current_bid);
        }
        
        printf("Enter bidder ID (0-4) and item ID (1-3) separated by a space to place bid: ");
        int bidder_id, item_id;
        scanf("%d %d", &bidder_id, &item_id);
        
        if (bidder_id < 0 || bidder_id >= NUM_BIDDERS || item_id < 1 || item_id > NUM_ITEMS) {
            printf("Invalid bidder ID or item ID!\n");
            continue;
        }
        
        int max_bid = bids[bidder_id].price + rand() % (MAX_BID - bids[bidder_id].price + 1); // Generate random bid
        if (max_bid > items[item_id - 1].current_bid) { // Check if bid is higher than current bid
            items[item_id - 1].current_bid = max_bid;
            items[item_id - 1].winning_bidder = bidder_id;
            bids[bidder_id].item_id = item_id;
            bids[bidder_id].price = max_bid;
            printf("Bid accepted! Bidder %d bid %d for item %d.\n", bidder_id, max_bid, item_id);
        } else {
            printf("Bid too low! You must bid at least %d for this item.\n", items[item_id - 1].current_bid + 1);
        }
        
        // Check if auction is over
        int all_items_sold = 1;
        for (int i = 0; i < NUM_ITEMS; i++) {
            if (items[i].winning_bidder == -1) {
                all_items_sold = 0;
                break;
            }
        }
        if (all_items_sold) {
            auction_over = 1;
        }
    }
    
    printf("Auction over! Winning bids:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d. %s - winning bid: %d, bidder ID: %d\n", items[i].id, items[i].name, items[i].current_bid, items[i].winning_bidder);
    }
    
    return 0;
}