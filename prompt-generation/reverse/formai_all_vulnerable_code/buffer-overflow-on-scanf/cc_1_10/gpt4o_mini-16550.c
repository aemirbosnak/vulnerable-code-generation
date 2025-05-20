//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BIDDERS 100
#define MAX_ITEM_LENGTH 50
#define BUFFER_SIZE 256

typedef struct {
    char name[50];
    double bid_amount;
} Bidder;

typedef struct {
    char item[MAX_ITEM_LENGTH];
    double starting_price;
    Bidder bidders[MAX_BIDDERS];
    int bidder_count;
    int is_active;
} Auction;

void initialize_auction(Auction *auction, const char *item, double price) {
    strncpy(auction->item, item, MAX_ITEM_LENGTH);
    auction->starting_price = price;
    auction->bidder_count = 0;
    auction->is_active = 1;
}

void place_bid(Auction *auction) {
    if (!auction->is_active) {
        printf("The auction for %s is no longer active.\n", auction->item);
        return;
    }

    if (auction->bidder_count >= MAX_BIDDERS) {
        printf("Maximum bidders reached. Cannot accept more bids.\n");
        return;
    }

    Bidder new_bidder;
    printf("Enter your name: ");
    fgets(new_bidder.name, sizeof(new_bidder.name), stdin);
    new_bidder.name[strcspn(new_bidder.name, "\n")] = 0; // Remove the newline character
    
    printf("Enter your bid amount: ");
    scanf("%lf", &new_bidder.bid_amount);
    getchar(); // Consume the newline character left by scanf

    if (new_bidder.bid_amount <= auction->starting_price) {
        printf("Bid must be greater than starting price of %.2lf.\n", auction->starting_price);
        return;
    }

    for (int i = 0; i < auction->bidder_count; i++) {
        if (strcmp(auction->bidders[i].name, new_bidder.name) == 0) {
            printf("You have already placed a bid. Please try again!\n");
            return;
        }
    }

    auction->bidders[auction->bidder_count++] = new_bidder;
    printf("%s placed a bid of %.2lf on %s.\n", new_bidder.name, new_bidder.bid_amount, auction->item);
}

void end_auction(Auction *auction) {
    auction->is_active = 0;
    if (auction->bidder_count == 0) {
        printf("No bids were placed for %s. Auction ended with no sale!\n", auction->item);
    } else {
        Bidder highest_bidder = auction->bidders[0];
        for (int i = 1; i < auction->bidder_count; i++) {
            if (auction->bidders[i].bid_amount > highest_bidder.bid_amount) {
                highest_bidder = auction->bidders[i];
            }
        }
        printf("The auction for %s has ended. The highest bidder is %s with a bid of %.2lf.\n",
               auction->item, highest_bidder.name, highest_bidder.bid_amount);
    }
}

void display_auction_status(const Auction *auction) {
    printf("\nAuction Item: %s\n", auction->item);
    printf("Starting Price: %.2lf\n", auction->starting_price);
    printf("Status: %s\n", auction->is_active ? "Active" : "Ended");
    printf("Bids placed: %d\n", auction->bidder_count);
    for (int i = 0; i < auction->bidder_count; i++) {
        printf("Bidder %d: %s with bid %.2lf\n", i + 1, auction->bidders[i].name, auction->bidders[i].bid_amount);
    }
}

int main() {
    Auction auction;
    char item[MAX_ITEM_LENGTH];
    double starting_price;

    printf("Welcome to the Digital Auction System!\n");

    printf("Enter the name of the item for auction: ");
    fgets(item, sizeof(item), stdin);
    item[strcspn(item, "\n")] = 0; // Removing newline character

    printf("Enter the starting price for the item: ");
    scanf("%lf", &starting_price);
    getchar(); // Consume newline character

    initialize_auction(&auction, item, starting_price);

    while (auction.is_active) {
        display_auction_status(&auction);

        printf("What would you like to do?\n");
        printf("1. Place a bid\n");
        printf("2. End auction\n");
        printf("3. Show auction status\n");
        printf("Enter your choice (1, 2, or 3): ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                place_bid(&auction);
                break;
            case 2:
                end_auction(&auction);
                break;
            case 3:
                display_auction_status(&auction);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}