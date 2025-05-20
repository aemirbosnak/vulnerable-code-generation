//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item struct
typedef struct Item {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int num_bids;
    time_t end_time;
} Item;

// Bid struct
typedef struct Bid {
    int item_id;
    float amount;
    time_t timestamp;
} Bid;

// User struct
typedef struct User {
    int id;
    char *username;
    float balance;
} User;

// Auction struct
typedef struct Auction {
    Item *items;
    int num_items;
    Bid *bids;
    int num_bids;
    User *users;
    int num_users;
} Auction;

// Function to create a new auction
Auction *create_auction() {
    Auction *auction = malloc(sizeof(Auction));
    auction->items = NULL;
    auction->num_items = 0;
    auction->bids = NULL;
    auction->num_bids = 0;
    auction->users = NULL;
    auction->num_users = 0;
    return auction;
}

// Function to add an item to the auction
void add_item(Auction *auction, Item *item) {
    auction->items = realloc(auction->items, (auction->num_items + 1) * sizeof(Item));
    auction->items[auction->num_items++] = *item;
}

// Function to add a bid to the auction
void add_bid(Auction *auction, Bid *bid) {
    auction->bids = realloc(auction->bids, (auction->num_bids + 1) * sizeof(Bid));
    auction->bids[auction->num_bids++] = *bid;
}

// Function to add a user to the auction
void add_user(Auction *auction, User *user) {
    auction->users = realloc(auction->users, (auction->num_users + 1) * sizeof(User));
    auction->users[auction->num_users++] = *user;
}

// Function to start the auction
void start_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];
        item->end_time = time(NULL) + 60 * 60;  // 1 hour from now
    }
}

// Function to end the auction
void end_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];
        if (item->current_bid >= item->reserve_price) {
            // Item has sold
            printf("Item %s sold for %f\n", item->name, item->current_bid);
        } else {
            // Item did not sell
            printf("Item %s did not sell\n", item->name);
        }
    }
}

// Function to run the auction
void run_auction(Auction *auction) {
    start_auction(auction);
    
    // Loop until all items have been sold or the auction has ended
    while (1) {
        time_t current_time = time(NULL);
        
        // Check if any items have ended
        for (int i = 0; i < auction->num_items; i++) {
            Item *item = &auction->items[i];
            if (item->end_time <= current_time) {
                end_auction(auction);
                return;
            }
        }
        
        // Process any new bids
        for (int i = 0; i < auction->num_bids; i++) {
            Bid *bid = &auction->bids[i];
            if (bid->timestamp > current_time) {
                // Bid is too new, ignore it
                continue;
            }
            
            // Check if the bid is valid
            Item *item = &auction->items[bid->item_id];
            if (bid->amount >= item->current_bid && bid->amount >= item->reserve_price) {
                // Bid is valid, update the item's current bid
                item->current_bid = bid->amount;
                item->num_bids++;
            }
        }
        
        // Sleep for 1 second
        sleep(1);
    }
}

// Main function
int main() {
    // Create a new auction
    Auction *auction = create_auction();
    
    // Add some items to the auction
    Item item1 = {1, "Item 1", 10.0, 0.0, 0, time(NULL) + 60 * 60};
    Item item2 = {2, "Item 2", 20.0, 0.0, 0, time(NULL) + 60 * 60};
    Item item3 = {3, "Item 3", 30.0, 0.0, 0, time(NULL) + 60 * 60};
    add_item(auction, &item1);
    add_item(auction, &item2);
    add_item(auction, &item3);
    
    // Add some users to the auction
    User user1 = {1, "User 1", 100.0};
    User user2 = {2, "User 2", 200.0};
    User user3 = {3, "User 3", 300.0};
    add_user(auction, &user1);
    add_user(auction, &user2);
    add_user(auction, &user3);
    
    // Add some bids to the auction
    Bid bid1 = {1, 15.0, time(NULL)};
    Bid bid2 = {2, 22.0, time(NULL)};
    Bid bid3 = {3, 31.0, time(NULL)};
    add_bid(auction, &bid1);
    add_bid(auction, &bid2);
    add_bid(auction, &bid3);
    
    // Run the auction
    run_auction(auction);
    
    // Free the memory used by the auction
    free(auction->items);
    free(auction->bids);
    free(auction->users);
    free(auction);
    
    return 0;
}