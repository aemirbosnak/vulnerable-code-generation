//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 5
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float startingPrice;
    float highestBid;
    char highestBidder[NAME_LENGTH];
} AuctionItem;

void displayItems(AuctionItem items[], int count) {
    printf("\nItems for Auction:\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d: %s | Starting Price: %.2f | Highest Bid: %.2f by %s\n", 
                i + 1, items[i].name, items[i].startingPrice, 
                items[i].highestBid, items[i].highestBidder);
    }
}

void bid(AuctionItem *item) {
    char bidder[NAME_LENGTH];
    float bidAmount;

    printf("Enter your name, noble knight: ");
    scanf("%s", bidder);
    printf("Enter your bid for %s (current highest bid is %.2f): ", item->name, item->highestBid);
    scanf("%f", &bidAmount);

    if (bidAmount > item->highestBid) {
        item->highestBid = bidAmount;
        strcpy(item->highestBidder, bidder);
        printf("Congratulations, %s! Your bid of %.2f is now the highest.\n", bidder, bidAmount);
    } else {
        printf("Alas, %s! Your bid of %.2f is not high enough.\n", bidder, bidAmount);
    }
}

void auction(AuctionItem items[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStarting auction for: %s\n", items[i].name);
        items[i].highestBid = items[i].startingPrice;
        strcpy(items[i].highestBidder, "No bids yet");

        for (int j = 0; j < MAX_BIDS; j++) {
            printf("\nRound %d for %s:\n", j + 1, items[i].name);
            bid(&items[i]);
            // Display current state of auction item
            printf("Current highest bid for %s is %.2f by %s\n", items[i].name, items[i].highestBid, items[i].highestBidder);
        }
    }
}

int main() {
    AuctionItem items[MAX_ITEMS] = {
        {"The Golden Chalice", 50.0, 0.0, ""},
        {"Sword of the Ancients", 150.0, 0.0, ""},
        {"Royal Robes", 80.0, 0.0, ""},
        {"Enchanted Amulet", 200.0, 0.0, ""},
        {"Mystic Potion", 40.0, 0.0, ""},
        {"Giant's Hammer", 300.0, 0.0, ""},
        {"Dragon Scale Shield", 500.0, 0.0, ""},
        {"Wizard's Staff", 120.0, 0.0, ""},
        {"Elven Bow", 90.0, 0.0, ""},
        {"Crystal Ball", 75.0, 0.0, ""}
    };

    printf("Welcome to the Great Castle Auction!\n");
    printf("Where noble knights bid for glorious treasures!\n");
    
    displayItems(items, MAX_ITEMS);
    auction(items, MAX_ITEMS);

    printf("\nThe auction has concluded!\n");
    displayItems(items, MAX_ITEMS);

    return 0;
}