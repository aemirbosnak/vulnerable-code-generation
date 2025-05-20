//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_USERS 10
#define MAX_ITEM_NAME 50

typedef struct {
    char username[50];
    float bid_price;
    time_t timestamp;
} Bid;

typedef struct {
    char item_name[MAX_ITEM_NAME];
    float starting_price;
    float current_price;
    int total_bids;
    Bid bids[MAX_BIDS];
} Auction;

Auction auction;

void init_auction(const char *item_name, float starting_price) {
    strncpy(auction.item_name, item_name, MAX_ITEM_NAME);
    auction.starting_price = starting_price;
    auction.current_price = starting_price;
    auction.total_bids = 0;
}

void place_bid(const char *username, float bid_price) {
    if (auction.total_bids >= MAX_BIDS) {
        printf("Max number of bids reached!\n");
        return;
    }
    
    if (bid_price <= auction.current_price) {
        printf("Bid must be higher than the current price of %.2f\n", auction.current_price);
        return;
    }
    
    Bid new_bid;
    strncpy(new_bid.username, username, 50);
    new_bid.bid_price = bid_price;
    new_bid.timestamp = time(NULL);
    
    auction.bids[auction.total_bids++] = new_bid;
    auction.current_price = bid_price;
    printf("Bid placed by %s: %.2f\n", username, bid_price);
}

void display_auction_details() {
    printf("Auction Item: %s\n", auction.item_name);
    printf("Starting Price: %.2f\n", auction.starting_price);
    printf("Current Price: %.2f\n", auction.current_price);
    printf("Total Bids: %d\n", auction.total_bids);
    
    if (auction.total_bids > 0) {
        printf("Bids:\n");
        for (int i = 0; i < auction.total_bids; i++) {
            printf("  %s: %.2f at %s", auction.bids[i].username, auction.bids[i].bid_price, ctime(&auction.bids[i].timestamp));
        }
    } else {
        printf("No bids yet.\n");
    }
}

int main() {
    char item_name[MAX_ITEM_NAME];
    float starting_price;
    
    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the name of the item for auction: ");
    fgets(item_name, MAX_ITEM_NAME, stdin);
    item_name[strcspn(item_name, "\n")] = '\0'; // Remove newline character

    printf("Enter the starting price for the auction: ");
    scanf("%f", &starting_price);
    init_auction(item_name, starting_price);

    int choice;
    do {
        printf("\n1. Place a bid\n2. Display auction details\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char username[50];
            float bid_price;
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your bid price: ");
            scanf("%f", &bid_price);
            place_bid(username, bid_price);
        } else if (choice == 2) {
            display_auction_details();
        } else if (choice != 3) {
            printf("Invalid option, please try again!\n");
        }
    } while (choice != 3);

    printf("Thank you for using the Digital Auction System!\n");
    return 0;
}