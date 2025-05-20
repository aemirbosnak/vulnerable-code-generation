//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 1000
#define MAX_BIDDERS 100

typedef struct {
    int id;
    char name[50];
    int balance;
} bidder;

typedef struct {
    int id;
    char name[50];
    int starting_price;
    int current_price;
    int winning_bidder_id;
} item;

bidder bidders[MAX_BIDDERS];
item items[MAX_ITEMS];
int num_bidders = 0;
int num_items = 0;

void add_bidder(bidder b) {
    bidders[num_bidders++] = b;
}

void add_item(item i) {
    items[num_items++] = i;
}

void print_bidders() {
    for (int i = 0; i < num_bidders; i++) {
        printf("Bidder %d: %s ($%d)\n", bidders[i].id, bidders[i].name, bidders[i].balance);
    }
}

void print_items() {
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s ($%d)\n", items[i].id, items[i].name, items[i].current_price);
    }
}

int main() {
    // Initialize the auction system
    bidder b1 = { 1, "Alice", 1000 };
    add_bidder(b1);
    bidder b2 = { 2, "Bob", 500 };
    add_bidder(b2);
    item i1 = { 1, "Painting", 100, 100, -1 };
    add_item(i1);
    item i2 = { 2, "Vase", 50, 50, -1 };
    add_item(i2);

    // Print the bidders and items
    printf("Bidders:\n");
    print_bidders();
    printf("Items:\n");
    print_items();

    // Start the auction
    int auction_running = 1;
    while (auction_running) {
        // Get the next bid
        int bidder_id, item_id, bid_amount;
        printf("Enter bidder ID: ");
        scanf("%d", &bidder_id);
        printf("Enter item ID: ");
        scanf("%d", &item_id);
        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);

        // Check if the bid is valid
        if (bidder_id < 1 || bidder_id > num_bidders) {
            printf("Invalid bidder ID.\n");
            continue;
        }
        if (item_id < 1 || item_id > num_items) {
            printf("Invalid item ID.\n");
            continue;
        }
        if (bid_amount <= items[item_id - 1].current_price) {
            printf("Bid amount must be greater than the current price.\n");
            continue;
        }

        // Update the current price of the item
        items[item_id - 1].current_price = bid_amount;

        // Update the winning bidder ID
        items[item_id - 1].winning_bidder_id = bidder_id;

        // Print the current status of the auction
        printf("Current status of the auction:\n");
        print_items();

        // Check if the auction is over
        int all_items_sold = 1;
        for (int i = 0; i < num_items; i++) {
            if (items[i].winning_bidder_id == -1) {
                all_items_sold = 0;
                break;
            }
        }
        if (all_items_sold) {
            auction_running = 0;
        }
    }

    // Print the results of the auction
    printf("Results of the auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: won by bidder %d for $%d\n", items[i].id, items[i].winning_bidder_id, items[i].current_price);
    }

    return 0;
}