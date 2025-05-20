//FormAI DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Auction item structure
typedef struct auction_item {
    char name[50];
    char description[100];
    float starting_bid;
    float current_bid;
    char current_bidder[50];
} AuctionItem;

// Function to display auction item details
void display_item(AuctionItem item) {
    printf("Auction Item: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Starting Bid: %.2f\n", item.starting_bid);
    printf("Current Bid: %.2f\n", item.current_bid);
    printf("Current Bidder: %s\n", item.current_bidder);
}

int main() {
    AuctionItem item;
    char choice[10];

    printf("Enter Auction Item Name:");
    fgets(item.name, 50, stdin);

    printf("Enter Auction Item Description:");
    fgets(item.description, 100, stdin);

    printf("Enter Starting Bid:");
    scanf("%f", &item.starting_bid);
    getchar();

    item.current_bid = item.starting_bid;

    printf("Starting Auction for: %s\n", item.name);
    display_item(item);

    do {
        printf("Enter Bid (Enter 'exit' to end auction):");
        fgets(choice, 10, stdin);

        if (strcmp(choice, "exit\n") == 0) {
            printf("Auction Ended!\n");
            break;
        }

        float bid = atof(choice);

        if (bid > item.current_bid) {
            printf("New Bid Accepted!\n");

            item.current_bid = bid;

            printf("Current Bid: %.2f\n", item.current_bid);

            printf("Enter Bidder Name:");
            fgets(item.current_bidder, 50, stdin);
        } else {
            printf("Bid Rejected. Enter Bid Amount above Current Bid %.2f\n", item.current_bid);
        }

    } while(1);

    printf("Final Auction Details:\n");
    display_item(item);
    
    return 0;
}