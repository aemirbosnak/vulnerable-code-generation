//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_USERS 10
#define ITEM_NAME_LENGTH 50
#define USERNAME_LENGTH 20

typedef struct {
    char username[USERNAME_LENGTH];
    float bid;
} Bid;

typedef struct {
    char item_name[ITEM_NAME_LENGTH];
    Bid bids[MAX_BIDS];
    int bid_count;
    float starting_price;
    float highest_bid;
    char highest_bidder[USERNAME_LENGTH];
    time_t end_time;
} Auction;

void initialize_auction(Auction *auction, const char *item_name, float starting_price, int duration) {
    strcpy(auction->item_name, item_name);
    auction->starting_price = starting_price;
    auction->highest_bid = starting_price;
    auction->bid_count = 0;
    auction->end_time = time(NULL) + duration;
    printf("\033[1;36m[INFO]\033[0m Auction for '%s' has begun! Starting Price: $%.2f\n", item_name, starting_price);
}

int place_bid(Auction *auction, const char *username, float bid_amount) {
    if (time(NULL) > auction->end_time) {
        printf("\033[1;31m[ERROR]\033[0m Auction has ended for '%s'!\n", auction->item_name);
        return -1;
    }
    if (bid_amount <= auction->highest_bid) {
        printf("\033[1;33m[WARNING]\033[0m Your bid must be higher than the current highest bid of $%.2f!\n", auction->highest_bid);
        return -1;
    }

    strcpy(auction->bids[auction->bid_count].username, username);
    auction->bids[auction->bid_count].bid = bid_amount;
    auction->highest_bid = bid_amount;
    strcpy(auction->highest_bidder, username);
    auction->bid_count++;

    printf("\033[1;32m[INFO]\033[0m New bid placed by %s: $%.2f\n", username, bid_amount);
    return 0;
}

void display_auction_status(Auction *auction) {
    printf("\n\033[1;34m[Auction Status]\033[0m\n");
    printf("Item: %s\n", auction->item_name);
    printf("Starting Price: $%.2f\n", auction->starting_price);
    printf("Current Highest Bid: $%.2f by %s\n", auction->highest_bid, auction->highest_bidder);
    printf("Time Remaining: %ld seconds\n", auction->end_time - time(NULL));
}

void end_auction(Auction *auction) {
    printf("\033[1;35m[INFO]\033[0m Auction for '%s' has ended!\n", auction->item_name);
    if (auction->bid_count > 0) {
        printf("The item was sold for: $%.2f to %s\n", auction->highest_bid, auction->highest_bidder);
    } else {
        printf("No bids were placed. Auction failed!\n");
    }
}

int main() {
    Auction auction;
    char username[USERNAME_LENGTH];
    float bid_amount;
    int duration;

    printf("\033[1;33mWelcome to the Neon District Digital Auction System!\033[0m\n");
    printf("Enter item name: ");
    fgets(auction.item_name, ITEM_NAME_LENGTH, stdin);
    auction.item_name[strcspn(auction.item_name, "\n")] = 0; // Remove the trailing newline

    printf("Enter starting price: $");
    scanf("%f", &auction.starting_price);
    
    printf("Enter auction duration (in seconds): ");
    scanf("%d", &duration);

    initialize_auction(&auction, auction.item_name, auction.starting_price, duration);

    while (time(NULL) < auction.end_time) {
        display_auction_status(&auction);
        printf("Enter your username: ");
        scanf("%s", username);

        printf("Enter your bid: $");
        scanf("%f", &bid_amount);
        
        place_bid(&auction, username, bid_amount);
    }

    end_auction(&auction);
    return 0;
}