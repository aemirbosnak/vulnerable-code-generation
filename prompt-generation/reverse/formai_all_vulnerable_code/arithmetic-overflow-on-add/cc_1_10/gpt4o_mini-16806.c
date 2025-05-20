//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define TITLE_LEN 50
#define NAME_LEN 30

typedef struct {
    char bidder[NAME_LEN];
    float amount;
} Bid;

typedef struct {
    char title[TITLE_LEN];
    float starting_price;
    int bid_count;
    Bid bids[MAX_BIDS];
    time_t end_time;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auction_count = 0;

void create_auction() {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached!\n");
        return;
    }
    
    Auction new_auction;
    printf("Enter auction title: ");
    getchar();  // Clear newline from buffer
    fgets(new_auction.title, TITLE_LEN, stdin);
    new_auction.title[strcspn(new_auction.title, "\n")] = 0; // Remove newline
    printf("Enter starting price: ");
    scanf("%f", &new_auction.starting_price);
    new_auction.bid_count = 0;
    
    printf("Enter auction duration in seconds: ");
    int duration;
    scanf("%d", &duration);
    new_auction.end_time = time(NULL) + duration;
    
    auctions[auction_count++] = new_auction;
    printf("Auction created successfully!\n");
}

void place_bid() {
    char auction_title[TITLE_LEN];
    printf("Enter auction title to bid on: ");
    getchar();  // Clear newline from buffer
    fgets(auction_title, TITLE_LEN, stdin);
    auction_title[strcspn(auction_title, "\n")] = 0; // Remove newline

    for (int i = 0; i < auction_count; i++) {
        if (strcmp(auctions[i].title, auction_title) == 0) {
            if (time(NULL) > auctions[i].end_time) {
                printf("This auction has ended.\n");
                return;
            }
            
            Bid new_bid;
            printf("Enter your name: ");
            fgets(new_bid.bidder, NAME_LEN, stdin);
            new_bid.bidder[strcspn(new_bid.bidder, "\n")] = 0; // Remove newline
            printf("Enter your bid amount: ");
            scanf("%f", &new_bid.amount);
            
            if (new_bid.amount <= auctions[i].starting_price || 
                (auctions[i].bid_count > 0 && new_bid.amount <= auctions[i].bids[auctions[i].bid_count - 1].amount)) {
                printf("Your bid must be higher than the current price/best bid.\n");
                return;
            }
            
            auctions[i].bids[auctions[i].bid_count++] = new_bid;
            printf("Bid placed successfully!\n");
            return;
        }
    }
    printf("Auction not found.\n");
}

void view_auctions() {
    for (int i = 0; i < auction_count; i++) {
        printf("Auction Title: %s\n", auctions[i].title);
        printf("Starting Price: %.2f\n", auctions[i].starting_price);
        printf("Bid Count: %d\n", auctions[i].bid_count);
        if (auctions[i].bid_count > 0) {
            printf("Bids:\n");
            for (int j = 0; j < auctions[i].bid_count; j++) {
                printf("  Bidder: %s | Amount: %.2f\n", auctions[i].bids[j].bidder, auctions[i].bids[j].amount);
            }
        }
        printf("Auction Ends In: %ld seconds\n\n", auctions[i].end_time - time(NULL));
    }
}

void auction_menu() {
    int choice;
    while (1) {
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. View Auctions\n");
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
                view_auctions();
                break;
            case 4:
                printf("Exiting the auction system.\n");
                return;
            default:
                printf("Invalid option! Please enter a valid choice.\n");
                break;
        }
    }
}

int main() {
    auction_menu();
    return 0;
}