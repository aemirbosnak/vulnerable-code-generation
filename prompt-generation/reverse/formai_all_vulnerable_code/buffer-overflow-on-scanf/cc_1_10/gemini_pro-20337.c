//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the structures
typedef struct {
    char name[50];
    int bid;
} Bidder;

typedef struct {
    char item[50];
    int highest_bid;
    Bidder highest_bidder;
} AuctionItem;

// Declare the functions
void print_welcome_message();
void print_menu();
void process_bid(AuctionItem *item, Bidder *bidder);
void process_end_auction(AuctionItem *item);
void print_results(AuctionItem *items, int num_items);

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Define the auction items
    AuctionItem items[] = {
        {"Painting 1", 0, {"", 0}},
        {"Painting 2", 0, {"", 0}},
        {"Painting 3", 0, {"", 0}}
    };
    
    // Print welcome message 
    print_welcome_message();
    
    // Main Auction LOOP
    int choice = 0;
    while (choice != 3) {
        // Print Menu
        print_menu();
        
        // Get user choice
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Process bid
                process_bid(items, NULL);
                break;
            case 2:
                // Print results
                print_results(items, sizeof(items) / sizeof(AuctionItem));
                break;
            case 3:
                // End auction
                process_end_auction(items);
                break;
            default:
                printf("Invalid choice. Please enter a valid number.\n");
        }
    }
    
    //Congrats message
    printf("\nCongrats to all the winners and Thank you for your Participation\n");
    return 0;
}


// Function to print welcome message
void print_welcome_message() {
    printf("\nWelcome to the Digital Auction System!\n");
    printf("--------------------------------------\n\n");
}


// Function to print menu
void print_menu() {
    printf("\nPlease select an option:\n");
    printf("1. Place a bid\n");
    printf("2. View current bids\n");
    printf("3. End auction\n");
    printf("Enter your choice: ");
}


// Function to process a bid
void process_bid(AuctionItem *items, Bidder *bidder) {
    // Get the item name
    char item_name[50];
    printf("Enter the item name: ");
    scanf("%s", item_name);

    // Get the bidder name
    char bidder_name[50];
    printf("Enter your name: ");
    scanf("%s", bidder_name);

    // Get the bid amount
    int bid_amount;
    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);

    // Find the item
    AuctionItem *item = NULL;
    for (int i = 0; i < sizeof(items) / sizeof(AuctionItem); i++) {
        if (strcmp(items[i].item, item_name) == 0) {
            item = &items[i];
            break;
        }
    }

    // If the item was not found, print an error message
    if (item == NULL) {
        printf("Item not found.\n");
        return;
    }

    // If the bid amount is higher than the current highest bid, update the highest bid
    if (bid_amount > item->highest_bid) {
        item->highest_bid = bid_amount;
        item->highest_bidder.bid = bid_amount;
        strcpy(item->highest_bidder.name, bidder_name);
        printf("Your bid has been placed successfully.\n");
    } else {
        printf("Your bid is lower than the current highest bid.\n");
    }
}


// Function to process end of auction
void process_end_auction(AuctionItem *items) {
    // Print the results
    print_results(items, sizeof(items) / sizeof(AuctionItem));

    // Free the memory allocated for each bidder
    for (int i = 0; i < sizeof(items) / sizeof(AuctionItem); i++) {
        free(items[i].highest_bidder.name);
    }
}


// Function to print results
void print_results(AuctionItem *items, int num_items) {
    printf("\nAuction Results:\n");
    printf("------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item: %s\n", items[i].item);
        printf("Highest Bid: %d\n", items[i].highest_bid);
        printf("Highest Bidder: %s\n", items[i].highest_bidder.name);
        printf("\n------------------\n");
    }
}