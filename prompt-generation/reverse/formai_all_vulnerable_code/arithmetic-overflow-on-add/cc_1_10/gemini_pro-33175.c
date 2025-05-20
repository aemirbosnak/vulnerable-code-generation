//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store auction item details
typedef struct {
    int id;             // Unique ID of the item
    char name[50];       // Name of the item
    float reserve_price; // Minimum price for the item to be sold
    float current_bid;  // Current highest bid for the item
    char owner[50];      // Name of the current owner of the item
    int is_sold;        // Flag to indicate if the item is sold or not
} AuctionItem;

// Structure to store bid details
typedef struct {
    int item_id;       // ID of the item being bid on
    char bidder[50];    // Name of the bidder
    float bid_amount;  // Amount of the bid
    time_t bid_time;   // Time at which the bid was placed
} Bid;

// Function to compare two bids based on bid amount and time
int compare_bids(const void *a, const void *b) {
    Bid *bid1 = (Bid *)a;
    Bid *bid2 = (Bid *)b;

    if (bid1->bid_amount > bid2->bid_amount) {
        return -1;
    } else if (bid1->bid_amount < bid2->bid_amount) {
        return 1;
    } else {
        return bid1->bid_time - bid2->bid_time;
    }
}

// Function to process a new bid
void process_bid(AuctionItem *item, Bid *bid) {
    if (bid->bid_amount >= item->reserve_price) {
        if (bid->bid_amount > item->current_bid) {
            item->current_bid = bid->bid_amount;
            strcpy(item->owner, bid->bidder);
        }
    }
}

// Function to start the auction
void start_auction(AuctionItem *items, int num_items) {
    // Loop through all items and print their details
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Reserve Price: %.2f\n", items[i].reserve_price);
        printf("Current Bid: %.2f\n", items[i].current_bid);
        printf("Owner: %s\n", items[i].owner);
        printf("\n");
    }

    // Get current time
    time_t start_time = time(NULL);

    // Set auction end time to 10 minutes from now
    time_t end_time = start_time + 600;

    // Loop until the auction end time is reached
    while (time(NULL) < end_time) {
        // Get user input for bid details
        int item_id;
        char bidder[50];
        float bid_amount;

        printf("Enter Item ID: ");
        scanf("%d", &item_id);

        printf("Enter Bidder Name: ");
        scanf("%s", bidder);

        printf("Enter Bid Amount: ");
        scanf("%f", &bid_amount);

        // Create a new bid
        Bid bid = {
            .item_id = item_id,
            .bidder = bidder,
            .bid_amount = bid_amount,
            .bid_time = time(NULL)
        };

        // Find the auction item corresponding to the bid
        AuctionItem *item = NULL;
        for (int i = 0; i < num_items; i++) {
            if (items[i].id == item_id) {
                item = &items[i];
                break;
            }
        }

        // If the item was found, process the bid
        if (item != NULL) {
            process_bid(item, &bid);
        } else {
            printf("Invalid Item ID\n");
        }
    }
}

// Function to end the auction
void end_auction(AuctionItem *items, int num_items) {
    // Loop through all items and print their details
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Reserve Price: %.2f\n", items[i].reserve_price);
        printf("Current Bid: %.2f\n", items[i].current_bid);
        printf("Owner: %s\n", items[i].owner);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of auction items
    AuctionItem items[] = {
        {
            .id = 1,
            .name = "Painting",
            .reserve_price = 100.0f,
            .current_bid = 0.0f,
            .owner = "",
            .is_sold = 0
        },
        {
            .id = 2,
            .name = "Sculpture",
            .reserve_price = 200.0f,
            .current_bid = 0.0f,
            .owner = "",
            .is_sold = 0
        },
        {
            .id = 3,
            .name = "Vase",
            .reserve_price = 50.0f,
            .current_bid = 0.0f,
            .owner = "",
            .is_sold = 0
        }
    };

    // Start the auction
    start_auction(items, 3);

    // End the auction
    end_auction(items, 3);

    return 0;
}