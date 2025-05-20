//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_AUCTIONS 10
#define MAX_BID_LENGTH 50

typedef struct {
    char username[50];
    float bid_amount;
    time_t bid_time;
} Bid;

typedef struct {
    char item_name[100];
    float starting_price;
    time_t end_time;
    int bid_count;
    Bid bids[MAX_BIDS];
    int active;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auction_count = 0;

void create_auction() {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Maximum auction limit reached.\n");
        return;
    }

    Auction new_auction;
    printf("Enter item name for auction: ");
    scanf(" %[^\n]%*c", new_auction.item_name);
    printf("Enter starting price: ");
    scanf("%f", &new_auction.starting_price);
    
    time_t now;
    time(&now);
    new_auction.end_time = now + 60; // Auction lasts for 60 seconds
    new_auction.bid_count = 0;
    new_auction.active = 1;

    auctions[auction_count++] = new_auction;
    printf("Auction for %s created successfully!\n", new_auction.item_name);
}

void place_bid() {
    char username[50];
    float bid_amount;
    
    printf("Enter your username: ");
    scanf(" %[^\n]%*c", username);
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    for (int i = 0; i < auction_count; i++) {
        if (auctions[i].active) {
            Auction *auction = &auctions[i];
            if (bid_amount > auction->starting_price && (auction->bid_count == 0 || bid_amount > auction->bids[auction->bid_count - 1].bid_amount)) {
                Bid new_bid;
                strcpy(new_bid.username, username);
                new_bid.bid_amount = bid_amount;
                new_bid.bid_time = time(NULL);

                auction->bids[auction->bid_count++] = new_bid;
                auction->starting_price = bid_amount; // Update the current highest bid

                printf("Bid placed successfully for auction: %s\n", auction->item_name);
                return;
            } else {
                printf("Bid must be higher than the current price: %.2f\n", auction->starting_price);
                return;
            }
        }
    }
    printf("No active auction found to place a bid.\n");
}

void close_auctions() {
    time_t now;
    time(&now);
    for (int i = 0; i < auction_count; i++) {
        if (auctions[i].active && auctions[i].end_time < now) {
            auctions[i].active = 0;
            printf("Auction for %s has been closed.\n", auctions[i].item_name);
            if (auctions[i].bid_count > 0) {
                Bid winning_bid = auctions[i].bids[auctions[i].bid_count - 1];
                printf("Winning bid: %s with amount %.2f\n", winning_bid.username, winning_bid.bid_amount);
            } else {
                printf("No bids were placed for this auction.\n");
            }
        }
    }
}

void show_active_auctions() {
    printf("Active Auctions:\n");
    for (int i = 0; i < auction_count; i++) {
        if (auctions[i].active) {
            printf("Item: %s | Current Price: %.2f | Bids: %d\n", auctions[i].item_name, 
                   auctions[i].starting_price, auctions[i].bid_count);
        }
    }
}

int main() {
    int choice;
    do {
        printf("Digital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Show Active Auctions\n");
        printf("4. Close Auctions\n");
        printf("5. Exit\n");
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
                show_active_auctions();
                break;
            case 4:
                close_auctions();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}