//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_AUCTIONS 5
#define NAME_LENGTH 30
#define ITEM_LENGTH 50

typedef struct {
    char item[ITEM_LENGTH];
    float starting_price;
    float highest_bid;
    char highest_bidder[NAME_LENGTH];
    int is_active;
} Auction;

typedef struct {
    char name[NAME_LENGTH];
    float bid_amount;
} Bidder;

Auction auctions[MAX_AUCTIONS];
Bidder bidders[MAX_BIDDERS];
int auction_count = 0;

void create_auction() {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Max auction limit reached!\n");
        return;
    }
    Auction a;
    printf("Enter the auction item: ");
    scanf("%s", a.item);
    printf("Enter the starting price: ");
    scanf("%f", &a.starting_price);
    a.highest_bid = a.starting_price;
    strcpy(a.highest_bidder, "None");
    a.is_active = 1;
    auctions[auction_count++] = a;
    printf("Auction created for item: %s\n", a.item);
}

void place_bid() {
    char bidder_name[NAME_LENGTH];
    float bid_amount;
    int auction_index;

    printf("Enter your name: ");
    scanf("%s", bidder_name);
    printf("Enter auction index (0 to %d): ", auction_count - 1);
    scanf("%d", &auction_index);

    if (auction_index < 0 || auction_index >= auction_count || !auctions[auction_index].is_active) {
        printf("Invalid auction index!\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= auctions[auction_index].highest_bid) {
        printf("Your bid must be higher than the current highest bid!\n");
        return;
    }

    auctions[auction_index].highest_bid = bid_amount;
    strcpy(auctions[auction_index].highest_bidder, bidder_name);
    printf("Bid placed! Current highest bidder for %s is %s with a bid of %.2f\n",
           auctions[auction_index].item, auctions[auction_index].highest_bidder, auctions[auction_index].highest_bid);
}

void end_auction() {
    int auction_index;
    printf("Enter auction index to end (0 to %d): ", auction_count - 1);
    scanf("%d", &auction_index);

    if (auction_index < 0 || auction_index >= auction_count || !auctions[auction_index].is_active) {
        printf("Invalid auction index!\n");
        return;
    }

    auctions[auction_index].is_active = 0;
    printf("Auction ended for item: %s. Highest bid by %s at %.2f\n",
           auctions[auction_index].item, auctions[auction_index].highest_bidder, auctions[auction_index].highest_bid);
}

void display_auctions() {
    printf("Active Auctions:\n");
    for (int i = 0; i < auction_count; i++) {
        if (auctions[i].is_active) {
            printf("Index: %d, Item: %s, Starting Price: %.2f, Current Highest Bid: %.2f, Highest Bidder: %s\n",
                   i, auctions[i].item, auctions[i].starting_price, auctions[i].highest_bid, auctions[i].highest_bidder);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System Menu:\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. End Auction\n");
        printf("4. Display Auctions\n");
        printf("0. Exit\n");
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
                end_auction();
                break;
            case 4:
                display_auctions();
                break;
            case 0:
                printf("Exiting the auction system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}