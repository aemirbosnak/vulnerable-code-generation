//FormAI DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum number of bids allowed
#define MAX_BIDS 10

// Define structure for auction data
typedef struct {
    int item_id;
    char item_name[50];
    float starting_price;
    float highest_bid;
    char highest_bidder[50];
    int num_bids;
    float bids[MAX_BIDS];
    char bidders[MAX_BIDS][50];
} Auction;

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize auction data
    Auction item = {1, "Antique Vase", 100.0, 0.0, "", 0, {}, {}};
    
    // Print item details
    printf("Auction Item:\n");
    printf("Item ID: %d\n", item.item_id);
    printf("Item Name: %s\n", item.item_name);
    printf("Starting Price: $%.2f\n", item.starting_price);
    printf("\n");
    
    // Wait for bids
    char name[50];
    float bid;
    while (item.num_bids < MAX_BIDS) {
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your bid: $");
        scanf("%f", &bid);
        printf("\n");
        
        // Validate bid amount
        if (bid <= item.highest_bid) {
            printf("Invalid bid amount.\n");
            continue;
        }
        
        // Update auction data
        item.highest_bid = bid;
        strcpy(item.highest_bidder, name);
        item.bids[item.num_bids] = bid;
        strcpy(item.bidders[item.num_bids], name);
        item.num_bids++;
        
        // Print current highest bid
        printf("Current Highest Bid: $%.2f by %s\n", item.highest_bid, item.highest_bidder);
    }
    
    // Print final auction data
    printf("\nAuction Complete!\n");
    printf("Item ID: %d\n", item.item_id);
    printf("Item Name: %s\n", item.item_name);
    printf("Starting Price: $%.2f\n", item.starting_price);
    printf("Highest Bid: $%.2f by %s\n", item.highest_bid, item.highest_bidder);
    printf("Total Bids: %d\n", item.num_bids);
    printf("Bids:\n");
    for (int i = 0; i < item.num_bids; i++) {
        printf("$%.2f - %s\n", item.bids[i], item.bidders[i]);
    }
    
    return 0;
}