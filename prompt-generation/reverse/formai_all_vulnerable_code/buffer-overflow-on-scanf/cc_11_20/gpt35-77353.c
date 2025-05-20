//FormAI DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define ITEM_NAME_LENGTH 20

// Define struct for bidder
typedef struct {
    char name[20];
    int bid_amount;
} Bidder;

// Define struct for item
typedef struct {
    char name[ITEM_NAME_LENGTH];
    int current_bid;
    int highest_bidder_index;
} AuctionItem;

int main() {

    // Prompt user for the name of the item being auctioned
    printf("Enter the name of the item being auctioned: ");
    char item_name[ITEM_NAME_LENGTH];
    fgets(item_name, ITEM_NAME_LENGTH, stdin);

    // Remove newline character from input
    item_name[strcspn(item_name, "\n")] = 0;

    // Prompt user for the number of bidders
    printf("Enter the number of bidders: ");
    int num_bidders;
    scanf("%d", &num_bidders);

    // Remove newline character from input
    while (getchar() != '\n');

    // Define array of bidders
    Bidder bidders[MAX_BIDDERS];

    // Initialize bidders and their bids to 0
    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i+1);
        fgets(bidders[i].name, 20, stdin);
        bidders[i].name[strcspn(bidders[i].name, "\n")] = 0;
        bidders[i].bid_amount = 0;
    }

    // Define auction item
    AuctionItem item;
    strcpy(item.name, item_name);
    item.current_bid = 0;
    item.highest_bidder_index = -1;

    // Begin auction
    printf("The auction for %s has begun!\n\n", item.name);

    while (1) {

        // Print current bid and highest bidder
        printf("Current bid: $%d\n", item.current_bid);
        if (item.highest_bidder_index != -1) {
            printf("Highest bidder: %s\n", bidders[item.highest_bidder_index].name);
        }

        // Prompt user for new bid
        printf("Enter your bid (or enter -1 to end the auction): ");
        int new_bid;
        scanf("%d", &new_bid);

        // Check if auction is ending
        if (new_bid == -1) {
            break;
        }

        // Check if bid is valid
        if (new_bid <= item.current_bid) {
            printf("Your bid must be higher than the current bid of $%d.\n", item.current_bid);
            continue;
        }

        // Prompt user for bidder name
        printf("Enter your name: ");
        char bidder_name[20];
        fgets(bidder_name, 20, stdin);
        bidder_name[strcspn(bidder_name, "\n")] = 0;

        // Find bidder index
        int bidder_index = -1;
        for (int i = 0; i < num_bidders; i++) {
            if (strcmp(bidders[i].name, bidder_name) == 0) {
                bidder_index = i;
                break;
            }
        }

        // Check if bidder is valid
        if (bidder_index == -1) {
            printf("Invalid bidder name. Please try again.\n");
            continue;
        }

        // Update item bid information
        item.current_bid = new_bid;
        item.highest_bidder_index = bidder_index;
        bidders[bidder_index].bid_amount = new_bid;

        // Print confirmation message
        printf("Bid accepted! %s is now the highest bidder with a bid of $%d.\n", bidder_name, new_bid);
    }

    // Print final results
    printf("\nThe auction for %s has ended.\n", item.name);
    printf("Final bid: $%d\n", item.current_bid);
    if (item.highest_bidder_index != -1) {
        printf("Highest bidder: %s\n", bidders[item.highest_bidder_index].name);
    }

    return 0;
}