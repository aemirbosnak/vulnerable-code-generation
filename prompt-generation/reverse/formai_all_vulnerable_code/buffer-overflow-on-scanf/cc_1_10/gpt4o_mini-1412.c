//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 10
#define MAX_ITEM_NAME 50

typedef struct {
    char name[MAX_ITEM_NAME];
    float starting_price;
    float current_bid;
    int active;
} AuctionItem;

typedef struct {
    char name[50];
    float bid_amount;
} Bidder;

AuctionItem auctions[MAX_AUCTIONS];
Bidder bidders[MAX_BIDDERS];
int total_auctions = 0;
int total_bidders = 0;

void show_auctions() {
    printf("\nActive Auctions:\n");
    for (int i = 0; i < total_auctions; i++) {
        if (auctions[i].active) {
            printf("Item Name: %s, Current Bid: %.2f\n", auctions[i].name, auctions[i].current_bid);
        }
    }
}

void register_bidder() {
    if (total_bidders < MAX_BIDDERS) {
        printf("\nEnter your name to register as a bidder: ");
        scanf("%s", bidders[total_bidders].name);
        bidders[total_bidders].bid_amount = 0;
        total_bidders++;
        printf("Welcome %s! You are now registered as a bidder.\n", bidders[total_bidders - 1].name);
    } else {
        printf("Sorry! Maximum number of bidders reached.\n");
    }
}

void add_auction_item() {
    if (total_auctions < MAX_AUCTIONS) {
        printf("\nEnter item name for auction: ");
        scanf("%s", auctions[total_auctions].name);
        printf("Enter starting price for %s: ", auctions[total_auctions].name);
        scanf("%f", &auctions[total_auctions].starting_price);
        auctions[total_auctions].current_bid = auctions[total_auctions].starting_price;
        auctions[total_auctions].active = 1;
        total_auctions++;
        printf("Auction item %s added with starting price of %.2f!\n", auctions[total_auctions - 1].name, auctions[total_auctions - 1].starting_price);
    } else {
        printf("Sorry! Maximum number of auction items reached.\n");
    }
}

void place_bid() {
    show_auctions();
    int auction_index;
    printf("\nSelect auction index you want to bid on (0 to %d): ", total_auctions - 1);
    scanf("%d", &auction_index);
    
    if (auction_index >= 0 && auction_index < total_auctions && auctions[auction_index].active) {
        printf("Enter your bid amount: ");
        float bid_amount;
        scanf("%f", &bid_amount);
        
        if (bid_amount > auctions[auction_index].current_bid) {
            auctions[auction_index].current_bid = bid_amount;
            printf("Bid placed successfully! Current bid for %s is now %.2f.\n", auctions[auction_index].name, auctions[auction_index].current_bid);
            // Update the last bidder (for simplicity)
            for (int i = 0; i < total_bidders; i++) {
                if (strcmp(bidders[i].name, "unknown") == 0) { // Placeholder for a single last bidder
                    strcpy(bidders[i].name, bidders[total_bidders - 1].name);
                    bidders[i].bid_amount = auctions[auction_index].current_bid;
                    break;
                }
            }
        } else {
            printf("Bid must be higher than the current bid of %.2f!\n", auctions[auction_index].current_bid);
        }
    } else {
        printf("Invalid auction item selected.\n");
    }
}

void end_auction() {
    int auction_index;
    show_auctions();
    printf("\nSelect auction index to end (0 to %d): ", total_auctions - 1);
    scanf("%d", &auction_index);
    
    if (auction_index >= 0 && auction_index < total_auctions) {
        auctions[auction_index].active = 0;
        printf("Auction for %s has ended! Final bid: %.2f\n", auctions[auction_index].name, auctions[auction_index].current_bid);
    } else {
        printf("Invalid auction index! Cannot end auction.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Digital Auction System!\n");
    
    while (1) {
        printf("\n1. Register Bidder\n2. Add Auction Item\n3. Place Bid\n4. End Auction\n5. Show Auctions\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_bidder();
                break;
            case 2:
                add_auction_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                end_auction();
                break;
            case 5:
                show_auctions();
                break;
            case 6:
                printf("Thank you for participating! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}