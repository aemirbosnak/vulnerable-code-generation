//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items and bids
#define MAX_ITEMS 100
#define MAX_BIDS 1000

// Define the item and bid structures
typedef struct {
    char name[50];
    float price;
    int quantity;
} item_t;

typedef struct {
    int item_id;
    float amount;
} bid_t;

// Initialize the items and bids arrays
item_t items[MAX_ITEMS];
bid_t bids[MAX_BIDS];

// Initialize the number of items and bids
int num_items = 0;
int num_bids = 0;

// Function to add an item to the auction
void add_item(char *name, float price, int quantity) {
    // Check if the number of items has reached the maximum
    if (num_items == MAX_ITEMS) {
        printf("Error: The maximum number of items has been reached.\n");
        return;
    }

    // Add the item to the array
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].quantity = quantity;

    // Increment the number of items
    num_items++;
}

// Function to add a bid to the auction
void add_bid(int item_id, float amount) {
    // Check if the number of bids has reached the maximum
    if (num_bids == MAX_BIDS) {
        printf("Error: The maximum number of bids has been reached.\n");
        return;
    }

    // Add the bid to the array
    bids[num_bids].item_id = item_id;
    bids[num_bids].amount = amount;

    // Increment the number of bids
    num_bids++;
}

// Function to print the items in the auction
void print_items() {
    printf("Items in the auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf(" - %s - $%.2f (%d units available)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Function to print the bids in the auction
void print_bids() {
    printf("Bids in the auction:\n");
    for (int i = 0; i < num_bids; i++) {
        printf(" - Item ID: %d - Bid amount: $%.2f\n", bids[i].item_id, bids[i].amount);
    }
}

// Function to start the auction
void start_auction() {
    // Set the current time
    time_t start_time = time(NULL);

    // Run the auction for 60 seconds
    while (difftime(time(NULL), start_time) < 60) {
        // Print the items and bids
        print_items();
        print_bids();

        // Allow the user to place a bid
        int item_id;
        float amount;
        printf("Enter the item ID and bid amount (item ID - bid amount): ");
        scanf("%d %f", &item_id, &amount);

        // Add the bid to the auction
        add_bid(item_id, amount);
    }
}

// Function to end the auction
void end_auction() {
    // Print the winning bids
    printf("Winning bids:\n");
    for (int i = 0; i < num_items; i++) {
        // Find the highest bid for the item
        float highest_bid = 0;
        int winning_bid_id = -1;
        for (int j = 0; j < num_bids; j++) {
            if (bids[j].item_id == i && bids[j].amount > highest_bid) {
                highest_bid = bids[j].amount;
                winning_bid_id = j;
            }
        }

        // Print the winning bid
        if (winning_bid_id != -1) {
            printf(" - Item: %s - Winning bid: $%.2f (Bidder ID: %d)\n", items[i].name, highest_bid, bids[winning_bid_id].item_id);
        } else {
            printf(" - Item: %s - No bids received\n", items[i].name);
        }
    }
}

// Main function
int main() {
    // Add some items to the auction
    add_item("Painting", 100.00, 1);
    add_item("Sculpture", 200.00, 1);
    add_item("Vase", 50.00, 2);

    // Start the auction
    start_auction();

    // End the auction
    end_auction();

    return 0;
}