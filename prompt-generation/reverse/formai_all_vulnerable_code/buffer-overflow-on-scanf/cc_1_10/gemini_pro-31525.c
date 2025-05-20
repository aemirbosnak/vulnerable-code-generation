//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item struct to store item details
typedef struct Item {
    int id;
    char name[50];
    float starting_price;
    float current_price;
    int highest_bidder_id;
} Item;

// Bidder struct to store bidder details
typedef struct Bidder {
    int id;
    char name[50];
    float balance;
} Bidder;

// Function to compare bids
int compare_bids(const void *a, const void *b) {
    return ((Bidder *)a)->balance - ((Bidder *)b)->balance;
}

// Main function
int main() {
    // Initialize the items and bidders
    Item items[] = {
        {1, "iPhone 13 Pro Max", 1000.0f, 1000.0f, 0},
        {2, "MacBook Pro 16-inch", 2000.0f, 2000.0f, 0},
        {3, "Apple Watch Series 7", 300.0f, 300.0f, 0},
    };
    Bidder bidders[] = {
        {1, "John Doe", 5000.0f},
        {2, "Jane Smith", 3000.0f},
        {3, "Peter Jones", 2000.0f},
    };

    // Sort the bidders in descending order of balance
    qsort(bidders, sizeof(bidders) / sizeof(Bidder), sizeof(Bidder), compare_bids);

    // Start the auction
    int auction_end = 0;
    while (!auction_end) {
        // Print the current status of each item
        printf("----------------------------------------------------\n");
        printf("Current Status of Items:\n");
        for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
            printf("Item ID: %d\n", items[i].id);
            printf("Item Name: %s\n", items[i].name);
            printf("Starting Price: %.2f\n", items[i].starting_price);
            printf("Current Price: %.2f\n", items[i].current_price);
            printf("Highest Bidder ID: %d\n", items[i].highest_bidder_id);
            printf("------------------------\n");
        }

        // Get the next bid from the highest bidder
        Bidder highest_bidder = bidders[0];
        float bid_amount;
        printf("Highest Bidder: %s\n", highest_bidder.name);
        printf("Current Balance: %.2f\n", highest_bidder.balance);
        printf("Enter your bid amount: ");
        scanf("%f", &bid_amount);

        // Check if the bid is valid
        if (bid_amount > highest_bidder.balance) {
            printf("Invalid bid! Your bid amount cannot exceed your balance.\n");
            continue;
        } else if (bid_amount <= items[0].current_price) {
            printf("Invalid bid! Your bid amount must be greater than the current price.\n");
            continue;
        }

        // Update the item and bidder details
        items[0].current_price = bid_amount;
        items[0].highest_bidder_id = highest_bidder.id;
        highest_bidder.balance -= bid_amount;

        // Check if the auction should end
        if (highest_bidder.balance <= 0) {
            auction_end = 1;
        }
    }

    // Print the results of the auction
    printf("----------------------------------------------------\n");
    printf("Auction Results:\n");
    for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
        printf("Item ID: %d\n", items[i].id);
        printf("Item Name: %s\n", items[i].name);
        printf("Winning Bid: %.2f\n", items[i].current_price);
        printf("Winning Bidder ID: %d\n", items[i].highest_bidder_id);
        printf("------------------------\n");
    }

    return 0;
}