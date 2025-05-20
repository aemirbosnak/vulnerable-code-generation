//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10 // Maximum number of bids per item
#define MAX_ITEMS 5 // Maximum number of items in auction
#define DEFAULT_DURATION 10 // Default duration of auction in minutes

struct item {
    int id;
    char name[50];
    int starting_price;
    int bids[MAX_BIDS];
    int current_bid;
    int highest_bidder;
    time_t end_time;
};

struct item auction_inventory[MAX_ITEMS]; // Array to keep track of all auction items
int num_items = 0; // Number of items currently in auction

void add_item() {
    if(num_items == MAX_ITEMS) {
        printf("Maximum number of items reached!\n");
        return;
    }

    struct item new_item;

    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter starting price: ");
    scanf("%d", &new_item.starting_price);

    new_item.id = num_items + 1; // Assign unique id to item

    // Initialize bids array to -1 (no bids yet)
    for(int i = 0; i < MAX_BIDS; i++) {
        new_item.bids[i] = -1;
    }

    // Set current_bid to starting_price
    new_item.current_bid = new_item.starting_price;

    // Set highest_bidder to -1 (no bids yet)
    new_item.highest_bidder = -1;

    // Calculate end time of auction
    new_item.end_time = time(NULL) + DEFAULT_DURATION * 60;

    auction_inventory[num_items++] = new_item;

    printf("Item added to auction!\n");
}

void bid_item() {
    int item_id, bid_amount;
    printf("Enter item id: ");
    scanf("%d", &item_id);

    // Search for item with given id
    int item_index = -1;
    for(int i = 0; i < num_items; i++) {
        if(auction_inventory[i].id == item_id) {
            item_index = i;
            break;
        }
    }

    if(item_index == -1) {
        printf("Item not found!\n");
        return;
    }

    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);

    struct item *current_item = &auction_inventory[item_index];

    if(current_item->current_bid >= bid_amount) {
        printf("Bid must be higher than the current bid!\n");
    }
    else if(current_item->highest_bidder == 0) {
        printf("You cannot bid on your own item!\n");
    }
    else if(time(NULL) > current_item->end_time) {
        printf("Auction has ended!\n");
    }
    else {
        // Shift bids array to add new bid at the beginning
        for(int i = MAX_BIDS - 1; i > 0; i--) {
            current_item->bids[i] = current_item->bids[i - 1];
        }

        current_item->bids[0] = bid_amount;
        current_item->current_bid = bid_amount;
        current_item->highest_bidder = 0;

        printf("Bid accepted!\n");
    }
}

void print_items() {
    printf("Items currently in auction:\n");
    for(int i = 0; i < num_items; i++) {
        struct item current_item = auction_inventory[i];

        printf("Item #%d: %s\n", current_item.id, current_item.name);
        printf("Starting price: %d\n", current_item.starting_price);
        printf("Current bid: %d\n", current_item.current_bid);

        if(current_item.highest_bidder == -1) {
            printf("No bids yet\n");
        }
        else if(current_item.highest_bidder == 0) {
            printf("Highest bidder: You\n");
        }
        else {
            printf("Highest bidder: Bidder #%d\n", current_item.highest_bidder);
        }

        printf("Time remaining: %ld seconds\n", current_item.end_time - time(NULL));
        printf("\n");
    }
}

void end_auction() {
    int item_id;
    printf("Enter item id: ");
    scanf("%d", &item_id);

    // Search for item with given id
    int item_index = -1;
    for(int i = 0; i < num_items; i++) {
        if(auction_inventory[i].id == item_id) {
            item_index = i;
            break;
        }
    }

    if(item_index == -1) {
        printf("Item not found!\n");
        return;
    }

    struct item *current_item = &auction_inventory[item_index];

    if(current_item->highest_bidder == -1) {
        printf("No bids on item!\n");
    }
    else {
        printf("Auction ended for item %d\n", current_item->id);
        printf("Item name: %s\n", current_item->name);
        printf("Winner: Bidder #%d\n", current_item->highest_bidder);
        printf("Price: %d\n", current_item->current_bid);
    }

    // Remove item from inventory
    for(int i = item_index; i <= num_items - 2; i++) {
        auction_inventory[i] = auction_inventory[i + 1];
    }
    num_items--;

    printf("Item removed from auction!\n");
}

int main() {
    int choice;
    while(1) {
        printf("1. Add item to auction\n");
        printf("2. Bid on item\n");
        printf("3. View auction items\n");
        printf("4. End auction for item\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_item(); break;
            case 2: bid_item(); break;
            case 3: print_items(); break;
            case 4: end_auction(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}