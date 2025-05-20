//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store auction item data
typedef struct {
    char name[50];
    char description[100];
    int current_bid;
    int min_bid_increase;
    int num_bids;
} AuctionItem;

// Function to display the current auction item and bidding details
void display_auction_item(AuctionItem item) {
    printf("\n=====CURRENT AUCTION ITEM=====\n");
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Current Bid: %d\n", item.current_bid);
    printf("Minimum Bid Increase: %d\n", item.min_bid_increase);
    printf("Number of Bids: %d\n", item.num_bids);
    printf("==============================\n");
}

int main() {
    // Initialize auction item
    AuctionItem item;
    strcpy(item.name, "Baseball Card");
    strcpy(item.description, "1952 Mickey Mantle Topps Rookie Card");
    item.current_bid = 1000;
    item.min_bid_increase = 100;
    item.num_bids = 0;
    
    int choice;
    
    do {
        // Display auction item details
        display_auction_item(item);
        
        // Prompt user for bidding choice
        printf("\nEnter 1 to place a bid, 2 to quit: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter your bid amount: ");
                int bid_amount;
                scanf("%d", &bid_amount);
                
                // Check if bid amount is higher than current bid plus minimum bid increase
                if (bid_amount >= (item.current_bid + item.min_bid_increase)) {
                    item.current_bid = bid_amount;
                    item.num_bids++;
                    printf("Bid placed successfully!\n");
                }
                else {
                    printf("Bid not placed. Please enter a bid that is at least %d higher than the current bid.\n", item.min_bid_increase);
                }
                break;
                
            case 2:
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice.\n");
                break;
        }
        
    } while(choice != 2);
    
    return 0;
}