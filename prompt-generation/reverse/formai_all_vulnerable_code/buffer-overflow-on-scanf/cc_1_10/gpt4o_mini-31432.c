//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define TITLE_LENGTH 100
#define NAME_LENGTH 100

typedef struct {
    char bidder[NAME_LENGTH];
    float amount;
} Bid;

typedef struct {
    char title[TITLE_LENGTH];
    float starting_price;
    float current_price;
    Bid bids[MAX_BIDS];
    int bid_count;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auction_count = 0;

void create_auction() {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Max auction limit reached.\n");
        return;
    }

    Auction new_auction;
    printf("Enter auction title: ");
    getchar(); // clear newline from the buffer
    fgets(new_auction.title, TITLE_LENGTH, stdin);
    new_auction.title[strcspn(new_auction.title, "\n")] = 0; // remove newline
    printf("Enter starting price: ");
    scanf("%f", &new_auction.starting_price);
    
    new_auction.current_price = new_auction.starting_price;
    new_auction.bid_count = 0;

    auctions[auction_count++] = new_auction;
    printf("Auction created successfully!\n");
}

void place_bid() {
    char title[TITLE_LENGTH];
    printf("Enter auction title to bid on: ");
    getchar(); // clear newline from the buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    int found = -1;
    for (int i = 0; i < auction_count; i++) {
        if (strcmp(auctions[i].title, title) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Auction not found.\n");
        return;
    }

    Auction *auction = &auctions[found];
    if (auction->bid_count >= MAX_BIDS) {
        printf("Max bids for this auction reached.\n");
        return;
    }

    Bid new_bid;
    printf("Enter your name: ");
    fgets(new_bid.bidder, NAME_LENGTH, stdin);
    new_bid.bidder[strcspn(new_bid.bidder, "\n")] = 0; // remove newline

    printf("Enter your bid amount: ");
    scanf("%f", &new_bid.amount);

    if (new_bid.amount <= auction->current_price) {
        printf("Bid must be higher than the current price: %.2f\n", auction->current_price);
        return;
    }

    auction->bids[auction->bid_count++] = new_bid;
    auction->current_price = new_bid.amount;
    printf("Bid placed successfully!\n");
}

void display_auction_details() {
    char title[TITLE_LENGTH];
    printf("Enter auction title to display: ");
    getchar(); // clear newline from the buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    int found = -1;
    for (int i = 0; i < auction_count; i++) {
        if (strcmp(auctions[i].title, title) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Auction not found.\n");
        return;
    }

    Auction auction = auctions[found];
    printf("Auction Title: %s\n", auction.title);
    printf("Starting Price: %.2f\n", auction.starting_price);
    printf("Current Price: %.2f\n", auction.current_price);
    printf("Bids:\n");
    
    for (int i = 0; i < auction.bid_count; i++) {
        printf("Bidder: %s, Amount: %.2f\n", auction.bids[i].bidder, auction.bids[i].amount);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n----- Digital Auction System -----\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auction Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_auction();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                display_auction_details();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}