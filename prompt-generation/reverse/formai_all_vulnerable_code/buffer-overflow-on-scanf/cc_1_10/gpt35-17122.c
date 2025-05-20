//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Struct to hold auction item information
typedef struct {
    char item_name[50];
    int starting_price;
    int current_bid;
    char highest_bidder[50];
    int time_left;
} Auction_Item;

// Function to print the details of an item
void print_item(Auction_Item item) {
    printf("Item Name: %s\n", item.item_name);
    printf("Starting Price: %d\n", item.starting_price);
    printf("Current Bid: %d\n", item.current_bid);
    printf("Highest Bidder: %s\n", item.highest_bidder);
    printf("Time Left: %d seconds\n", item.time_left);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create auction item array
    Auction_Item auction_items[3];

    // Initialize auction item details
    strcpy(auction_items[0].item_name, "Vintage Rolex watch");
    auction_items[0].starting_price = 1000;
    auction_items[0].current_bid = 0;
    strcpy(auction_items[0].highest_bidder, "none");
    auction_items[0].time_left = 60;

    strcpy(auction_items[1].item_name, "Signed Michael Jordan jersey");
    auction_items[1].starting_price = 500;
    auction_items[1].current_bid = 0;
    strcpy(auction_items[1].highest_bidder, "none");
    auction_items[1].time_left = 120;

    strcpy(auction_items[2].item_name, "Original Picasso sketch");
    auction_items[2].starting_price = 5000;
    auction_items[2].current_bid = 0;
    strcpy(auction_items[2].highest_bidder, "none");
    auction_items[2].time_left = 180;

    // Loop through auction items and print details
    for(int i = 0; i < 3; i++) {
        printf("Item %d:\n", i+1);
        print_item(auction_items[i]);
        printf("\n");
    }

    // Auction loop for each item
    for(int i = 0; i < 3; i++) {
        // Reinitialize time left for the item
        auction_items[i].time_left = rand() % 60 + 60;

        // Print details of the item
        printf("Item Name: %s\n", auction_items[i].item_name);
        printf("Starting Price: %d\n", auction_items[i].starting_price);
        printf("Current Bid: %d\n", auction_items[i].current_bid);
        printf("Highest Bidder: %s\n", auction_items[i].highest_bidder);
        printf("Time Left: %d seconds\n", auction_items[i].time_left);

        // Prompt user for bid
        int bid_amount;
        printf("Enter your bid amount: ");
        scanf("%d", &bid_amount);

        // Check if bid is higher than current bid and starting bid
        if(bid_amount > auction_items[i].current_bid && bid_amount >= auction_items[i].starting_price) {
            auction_items[i].current_bid = bid_amount;
            printf("Congratulations! You are the highest bidder.\n");
        } else {
            printf("Error: Bid amount must be higher than current bid and starting price.\n");
        }

        // Print updated details of the item
        printf("Updated Details:\n");
        print_item(auction_items[i]);
        printf("\n");
    }

    return 0;
}