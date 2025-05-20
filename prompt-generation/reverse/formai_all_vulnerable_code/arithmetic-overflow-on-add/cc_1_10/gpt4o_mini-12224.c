//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define MAX_USERS 50

typedef struct {
    char name[50];
    float price;
    int active;
} Item;

typedef struct {
    char username[50];
    float bid_amount;
} Bid;

typedef struct {
    Item item;
    Bid bids[MAX_BIDS];
    int bid_count;
    time_t end_time;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auction_count = 0;

void print_banner() {
    printf("====================================\n");
    printf("           CYBERPUNK AUCTION       \n");
    printf("       [ Neon Lights & Bids ]      \n");
    printf("====================================\n");
}

void register_auction() {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Too many auctions in the system!\n");
        return;
    }
    
    Auction new_auction;
    
    printf("Enter the auction item name: ");
    scanf("%s", new_auction.item.name);
    
    printf("Set the starting price: ");
    scanf("%f", &new_auction.item.price);
    
    new_auction.item.active = 1;
    new_auction.bid_count = 0;
    new_auction.end_time = time(NULL) + 60; // Ends in 60 seconds
    
    auctions[auction_count++] = new_auction;
    
    printf("Auction for '%s' registered! Starting price: %.2f\n", 
                new_auction.item.name, new_auction.item.price);
}

void place_bid() {
    char username[50];
    int auction_index;
    
    printf("Enter your username: ");
    scanf("%s", username);
    
    printf("Enter auction index (0 to %d): ", auction_count - 1);
    scanf("%d", &auction_index);
    
    if (auction_index < 0 || auction_index >= auction_count || 
        !auctions[auction_index].item.active) {
        printf("Invalid auction!\n");
        return;
    }
    
    Auction *current_auction = &auctions[auction_index];
    
    if (time(NULL) > current_auction->end_time) {
        printf("Auction is already closed!\n");
        return;
    }
    
    float bid_amount;
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);
    
    if (bid_amount <= current_auction->item.price) {
        printf("Bid must be higher than current price: %.2f\n", 
               current_auction->item.price);
        return;
    }
    
    current_auction->bids[current_auction->bid_count].bid_amount = bid_amount;
    strcpy(current_auction->bids[current_auction->bid_count].username, username);
    current_auction->bid_count++;
    current_auction->item.price = bid_amount; // Update current price
    
    printf("Bid of %.2f placed by %s on '%s'!\n", 
            bid_amount, username, current_auction->item.name);
}

void view_auctions() {
    for (int i = 0; i < auction_count; i++) {
        Auction *current_auction = &auctions[i];
        printf("Auction %d: %s - Current Price: %.2f ", 
                i, current_auction->item.name, current_auction->item.price);
        printf(" - %s\n", current_auction->item.active ? "Active" : "Closed");
    }
}

void close_auctions() {
    time_t now = time(NULL);
    
    for (int i = 0; i < auction_count; i++) {
        if (auctions[i].item.active && now > auctions[i].end_time) {
            auctions[i].item.active = 0;
            printf("Auction for '%s' has ended!\n", auctions[i].item.name);
            if (auctions[i].bid_count > 0) {
                Bid highest_bid = auctions[i].bids[0];
                for (int j = 1; j < auctions[i].bid_count; j++) {
                    if (auctions[i].bids[j].bid_amount > highest_bid.bid_amount) {
                        highest_bid = auctions[i].bids[j];
                    }
                }
                printf("Winner: %s with a bid of %.2f\n", 
                        highest_bid.username, highest_bid.bid_amount);
            } else {
                printf("No bids were placed.\n");
            }
        }
    }
}

int main() {
    print_banner();
    
    while (1) {
        printf("\nCommands: 1. Register Auction 2. Place Bid 3. View Auctions 4. Close Auctions 5. Exit\n");
        int command;
        scanf("%d", &command);
        
        switch (command) {
            case 1: 
                register_auction();
                break;
            case 2: 
                place_bid();
                break;
            case 3: 
                view_auctions();
                break;
            case 4: 
                close_auctions();
                break;
            case 5: 
                printf("Shutting down the neon auction system...\n");
                return 0;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}