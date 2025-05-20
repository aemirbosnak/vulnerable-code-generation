//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 100
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    double starting_price;
    double current_bid;
    char highest_bidder[USER_NAME_LENGTH];
    time_t end_time;
    int is_active;
} AuctionItem;

typedef struct {
    char username[USER_NAME_LENGTH];
    double balance;
} Bidder;

AuctionItem auctions[MAX_AUCTIONS];
Bidder bidders[MAX_BIDDERS];
int auction_count = 0;
int bidder_count = 0;

void add_bidder() {
    if(bidder_count >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached.\n");
        return;
    }
    
    printf("Enter username for new bidder: ");
    scanf("%s", bidders[bidder_count].username);
    
    bidders[bidder_count].balance = 1000.00; // Default balance
    printf("Bidder added: %s with balance: %.2f\n", bidders[bidder_count].username, bidders[bidder_count].balance);
    bidder_count++;
}

void create_auction() {
    if(auction_count >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.\n");
        return;
    }
    
    AuctionItem *item = &auctions[auction_count];
    
    printf("Enter item name: ");
    scanf(" %[^\n]", item->name);
    
    printf("Enter starting price: ");
    scanf("%lf", &item->starting_price);
    
    item->current_bid = item->starting_price;
    item->is_active = 1;
    strncpy(item->highest_bidder, "None", USER_NAME_LENGTH);

    time(&item->end_time);
    item->end_time += 60; // Auction ends in 60 seconds
    
    printf("Auction created for item: %s, Starting Price: %.2f\n", item->name, item->starting_price);
    auction_count++;
}

void place_bid() {
    char username[USER_NAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    
    int found_bidder = -1;
    for(int i = 0; i < bidder_count; i++) {
        if(strcmp(bidders[i].username, username) == 0) {
            found_bidder = i;
            break;
        }
    }
    
    if(found_bidder == -1) {
        printf("Bidder not found.\n");
        return;
    }
    
    printf("Available Auctions:\n");
    for(int i = 0; i < auction_count; i++) {
        if(auctions[i].is_active) {
            printf("%d. Item: %s, Current Bid: %.2f\n", i + 1, auctions[i].name, auctions[i].current_bid);
        }
    }
    
    int auction_index;
    printf("Select auction number to bid on: ");
    scanf("%d", &auction_index);
    auction_index--; // Adjust for zero-based indexing

    if(auction_index < 0 || auction_index >= auction_count || !auctions[auction_index].is_active) {
        printf("Invalid auction number.\n");
        return;
    }

    double bid_amount;
    printf("Enter your bid (must be greater than %.2f): ", auctions[auction_index].current_bid);
    scanf("%lf", &bid_amount);
    
    if(bid_amount <= auctions[auction_index].current_bid) {
        printf("Bid must be higher than the current bid!\n");
        return;
    }
    
    if(bid_amount > bidders[found_bidder].balance) {
        printf("Insufficient balance to place this bid.\n");
        return;
    }

    bidders[found_bidder].balance -= bid_amount;
    auctions[auction_index].current_bid = bid_amount;
    strncpy(auctions[auction_index].highest_bidder, bidders[found_bidder].username, USER_NAME_LENGTH);
    
    printf("Bid placed successfully. New bid: %.2f by %s\n", bid_amount, bidders[found_bidder].username);
}

void close_auction(int index) {
    auctions[index].is_active = 0;
    printf("Auction for item '%s' has ended. Winner: %s with bid: %.2f\n", auctions[index].name,
           auctions[index].highest_bidder, auctions[index].current_bid);
}

void check_auctions() {
    time_t now;
    time(&now); 
    for(int i = 0; i < auction_count; i++) {
        if(auctions[i].is_active && difftime(now, auctions[i].end_time) >= 0) {
            close_auction(i);
        }
    }
}

void show_bidder_balances() {
    for(int i = 0; i < bidder_count; i++) {
        printf("Bidder: %s, Balance: %.2f\n", bidders[i].username, bidders[i].balance);
    }
}

int main() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Add Bidder\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. Show Bidder Balances\n");
        printf("5. Check Auctions\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_bidder();
                break;
            case 2:
                create_auction();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                show_bidder_balances();
                break;
            case 5:
                check_auctions();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }

    } while(choice != 0);

    return 0;
}