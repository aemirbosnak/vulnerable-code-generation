//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float starting_price;
    float current_price;
    char highest_bidder[MAX_NAME_LENGTH];
    int duration; // in seconds
    time_t end_time;
    int bids_count;
} AuctionItem;

typedef struct {
    char bidder_name[MAX_NAME_LENGTH];
    float bid_amount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];

int item_count = 0;

void addItem(char *name, float starting_price, int duration) {
    if (item_count >= MAX_ITEMS) {
        printf("Maximum items reached!\n");
        return;
    }
    AuctionItem new_item;
    strcpy(new_item.name, name);
    new_item.starting_price = starting_price;
    new_item.current_price = starting_price;
    strcpy(new_item.highest_bidder, "None");
    new_item.duration = duration;
    new_item.end_time = time(NULL) + duration;
    new_item.bids_count = 0;

    items[item_count++] = new_item;
    printf("Auction item '%s' added with starting price %.2f and duration %d seconds.\n",
           new_item.name, starting_price, duration);
}

void placeBid(char *item_name, char *bidder_name, float bid_amount) {
    for (int i = 0; i < item_count; i++) {
        AuctionItem *item = &items[i];

        if (strcmp(item->name, item_name) == 0) {
            if (time(NULL) > item->end_time) {
                printf("The auction for '%s' has already ended.\n", item_name);
                return;
            }

            if (bid_amount <= item->current_price) {
                printf("Bid must be higher than the current price of %.2f.\n", item->current_price);
                return;
            }

            strcpy(item->highest_bidder, bidder_name);
            item->current_price = bid_amount;
            item->bids_count++;

            printf("Bid placed by '%s' for item '%s': %.2f\n", bidder_name, item_name, bid_amount);
            return;
        }
    }
    printf("Auction item '%s' not found.\n", item_name);
}

void endAuction(AuctionItem *item) {
    if (time(NULL) > item->end_time) {
        printf("The auction for '%s' has ended.\n", item->name);
        printf("Highest Bidder: '%s' with bid: %.2f\n", item->highest_bidder, item->current_price);
    }
}

void displayAuctions() {
    printf("\nCurrent Auctions:\n");
    for (int i = 0; i < item_count; i++) {
        AuctionItem *item = &items[i];
        printf("Item: %s\n", item->name);
        printf("Starting Price: %.2f\n", item->starting_price);
        printf("Current Price: %.2f\n", item->current_price);
        printf("Highest Bidder: %s\n", item->highest_bidder);
        printf("Auction Ends In: %ld seconds\n", item->end_time - time(NULL));
        printf("-----------------------------\n");
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float price;
    int duration;
    
    while (1) {
        printf("Auction System Menu:\n");
        printf("1. Add Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Auctions\n");
        printf("4. End Auctions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%f", &price);
                printf("Enter duration (in seconds): ");
                scanf("%d", &duration);
                addItem(name, price, duration);
                break;
                
            case 2:
                printf("Enter item name to bid on: ");
                scanf("%s", name);
                printf("Enter your name: ");
                char bidder_name[MAX_NAME_LENGTH];
                scanf("%s", bidder_name);
                printf("Enter bid amount: ");
                float bid_amount;
                scanf("%f", &bid_amount);
                placeBid(name, bidder_name, bid_amount);
                break;

            case 3:
                displayAuctions();
                break;
                
            case 4:
                for (int i = 0; i < item_count; i++) {
                    endAuction(&items[i]);
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}