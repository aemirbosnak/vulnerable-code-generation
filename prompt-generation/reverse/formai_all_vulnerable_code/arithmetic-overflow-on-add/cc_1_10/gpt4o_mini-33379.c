//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESC_LENGTH 200
#define MAX_NAME_LENGTH 30

typedef struct {
    char bidder[MAX_NAME_LENGTH];
    float amount;
} Bid;

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    float starting_price;
    int bid_count;
    Bid bids[MAX_BIDS];
    time_t end_time;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auction_count = 0;

void create_auction();
void place_bid();
void display_auctions();
void display_auction_details(int index);
int find_auction(char *title);
void display_winner(int index);

int main() {
    int choice;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auctions\n");
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
                display_auctions();
                break;
            case 4:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void create_auction() {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Unable to create new auction. Maximum auctions reached.\n");
        return;
    }

    Auction new_auction;
    printf("Enter auction title: ");
    scanf(" %[^\n]s", new_auction.title);
    printf("Enter auction description: ");
    scanf(" %[^\n]s", new_auction.description);
    printf("Enter starting price: ");
    scanf("%f", &new_auction.starting_price);
    
    new_auction.bid_count = 0;
    new_auction.end_time = time(NULL) + 24 * 3600; // Auction lasts for 24 hours

    auctions[auction_count++] = new_auction;
    printf("Auction created successfully!\n");
}

void place_bid() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter auction title to bid on: ");
    scanf(" %[^\n]s", title);

    int index = find_auction(title);
    if (index == -1) {
        printf("Auction not found!\n");
        return;
    }

    if (time(NULL) > auctions[index].end_time) {
        printf("Auction has ended. No more bids can be placed.\n");
        return;
    }

    Bid new_bid;
    printf("Enter your name: ");
    scanf(" %[^\n]s", new_bid.bidder);
    printf("Enter your bid amount: ");
    scanf("%f", &new_bid.amount);

    if (new_bid.amount <= auctions[index].starting_price) {
        printf("Bid must be higher than the starting price of %.2f\n", auctions[index].starting_price);
        return;
    }
    
    if (auctions[index].bid_count < MAX_BIDS) {
        auctions[index].bids[auctions[index].bid_count++] = new_bid;
        auctions[index].starting_price = new_bid.amount; // Update starting price
        printf("Bid placed successfully!\n");
    } else {
        printf("Maximum number of bids reached for this auction.\n");
    }
}

void display_auctions() {
    if (auction_count == 0) {
        printf("No auctions available.\n");
        return;
    }

    printf("\nAvailable Auctions:\n");
    for (int i = 0; i < auction_count; i++) {
        printf("Title: %s, Starting Price: %.2f\n", auctions[i].title, auctions[i].starting_price);
    }
}

int find_auction(char *title) {
    for (int i = 0; i < auction_count; i++) {
        if (strcmp(auctions[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

void display_winner(int index) {
    if (auctions[index].bid_count == 0) {
        printf("No bids placed for auction: %s\n", auctions[index].title);
        return;
    }

    Bid highest_bid = auctions[index].bids[0];
    for (int i = 1; i < auctions[index].bid_count; i++) {
        if (auctions[index].bids[i].amount > highest_bid.amount) {
            highest_bid = auctions[index].bids[i];
        }
    }
    printf("The winner of auction '%s' is %s with a bid of %.2f\n", auctions[index].title, highest_bid.bidder, highest_bid.amount);
}