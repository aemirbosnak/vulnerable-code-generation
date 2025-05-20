//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Declare structs
typedef struct item {
    int item_id;
    char item_name[50];
    int starting_bid;
    int current_bid;
    bool sold;
} Item;

typedef struct bidder {
    int bidder_id;
    char bidder_name[50];
    int balance;
} Bidder;

// Declare function prototypes
void display_items(Item items[], int num_items);
void display_bidders(Bidder bidders[], int num_bidders);
void bid_on_item(Bidder *bidder, Item *item);
int generate_winner(Item items[], int num_items, Bidder bidders[], int num_bidders);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize items and bidders
    Item items[5] = {
        {1, "Neural Implant", 5000, 5000, false},
        {2, "Hoverbike", 10000, 10000, false},
        {3, "Cyberdeck", 7500, 7500, false},
        {4, "Cybernetic Arm", 6000, 6000, false},
        {5, "Nanofiber Clothing", 2500, 2500, false}
    };
    
    Bidder bidders[3] = {
        {1, "Neo", 15000},
        {2, "Trinity", 10000},
        {3, "Morpheus", 7500}
    };
    
    // Display items and bidders
    display_items(items, 5);
    display_bidders(bidders, 3);
    
    // Allow bidders to bid on items
    for (int i = 0; i < 3; i++) {
        Bidder *bidder = &bidders[i];
        printf("\n%s, it's your turn to bid.\n", bidder->bidder_name);
        for (int j = 0; j < 5; j++) {
            Item *item = &items[j];
            if (!item->sold) {
                bid_on_item(bidder, item);
            }
        }
    }
    
    // Generate winner and display results
    int winner_id = generate_winner(items, 5, bidders, 3);
    for (int i = 0; i < 5; i++) {
        if (items[i].sold) {
            printf("\n%s sold to %s for %d credits.", items[i].item_name, bidders[winner_id].bidder_name, items[i].current_bid);
        } else {
            printf("\n%s was not sold.", items[i].item_name);
        }
    }
    
    return 0;
}

// Display all items and their bids
void display_items(Item items[], int num_items) {
    printf("ITEMS:\n");
    for (int i = 0; i < num_items; i++) {
        Item item = items[i];
        printf("%s (Starting bid: %d credits, Current bid: %d credits)\n", item.item_name, item.starting_bid, item.current_bid);
    }
}

// Display all bidders and their balances
void display_bidders(Bidder bidders[], int num_bidders) {
    printf("\nBIDDERS:\n");
    for (int i = 0; i < num_bidders; i++) {
        Bidder bidder = bidders[i];
        printf("%s (Balance: %d credits)\n", bidder.bidder_name, bidder.balance);
    }
}

// Allow bidder to bid on an item
void bid_on_item(Bidder *bidder, Item *item) {
    if (item->sold) {
        return;
    }
    
    printf("\n%s, how much do you want to bid on %s? (Current bid: %d credits, Balance: %d credits) ", bidder->bidder_name, item->item_name, item->current_bid, bidder->balance);
    int bid_amount;
    scanf("%d", &bid_amount);
    
    if (bid_amount < item->current_bid || bid_amount > bidder->balance) {
        printf("Invalid bid.\n");
        return;
    }
    
    item->current_bid = bid_amount;
    bidder->balance -= bid_amount;
    
    printf("Bid accepted.\n");
}

// Generate random winner for each item
int generate_winner(Item items[], int num_items, Bidder bidders[], int num_bidders) {
    int winner_ids[num_items];
    for (int i = 0; i < num_items; i++) {
        if (!items[i].sold) {
            int highest_bid = 0;
            for (int j = 0; j < num_bidders; j++) {
                if (bidders[j].balance >= items[i].current_bid && items[i].current_bid > highest_bid) {
                    highest_bid = items[i].current_bid;
                    winner_ids[i] = j;
                }
            }
            if (highest_bid == 0) {
                winner_ids[i] = -1;
            } else {
                bidders[winner_ids[i]].balance -= items[i].current_bid;
                items[i].sold = true;
            }
        }
    }
    
    // Choose random winner from those who won an item
    int winner_id = winner_ids[rand() % num_items];
    
    return winner_id;
}