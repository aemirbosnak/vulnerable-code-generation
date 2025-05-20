//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float starting_price;
    int bid_count;
    float highest_bid;
    char highest_bidder[ITEM_NAME_LENGTH];
    time_t auction_end_time;
} AuctionItem;

void initialize_item(AuctionItem *item, char *name, float starting_price, int duration) {
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->bid_count = 0;
    item->highest_bid = starting_price;
    strcpy(item->highest_bidder, "No bids yet");
    item->auction_end_time = time(NULL) + duration;
}

void display_auction_item(AuctionItem *item) {
    printf("Item: %s\n", item->name);
    printf("Starting Price: $%.2f\n", item->starting_price);
    printf("Highest Bid: $%.2f by %s\n", item->highest_bid, item->highest_bidder);
    printf("Time Left: %ld seconds\n", item->auction_end_time - time(NULL));
    printf("------------------------------\n");
}

void place_bid(AuctionItem *item, char *bidder_name, float bid_amount) {
    if (time(NULL) >= item->auction_end_time) {
        printf("Auction for %s is over.\n", item->name);
        return;
    }

    if (bid_amount > item->highest_bid) {
        item->highest_bid = bid_amount;
        strcpy(item->highest_bidder, bidder_name);
        item->bid_count++;
        printf("Bid accepted! New highest bid of $%.2f by %s.\n", bid_amount, bidder_name);
    } else {
        printf("Bid too low. Current highest bid is $%.2f.\n", item->highest_bid);
    }
}

int main() {
    AuctionItem auction_items[MAX_ITEMS];
    int item_count = 0;
    int choice;

    while (1) {
        printf("1. Create Auction Item\n");
        printf("2. Display Auction Items\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                if (item_count >= MAX_ITEMS) {
                    printf("Max items reached!\n");
                    break;
                }
                {
                    char name[ITEM_NAME_LENGTH];
                    float starting_price;
                    int duration;

                    printf("Enter item name: ");
                    fgets(name, ITEM_NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = '\0'; // Remove newline

                    printf("Enter starting price: ");
                    scanf("%f", &starting_price);
                    printf("Enter auction duration in seconds: ");
                    scanf("%d", &duration);

                    initialize_item(&auction_items[item_count], name, starting_price, duration);
                    item_count++;
                    printf("Item created!\n");
                }
                break;
            case 2:
                for (int i = 0; i < item_count; i++) {
                    display_auction_item(&auction_items[i]);
                }
                break;
            case 3:
                if (item_count == 0) {
                    printf("No auction items available.\n");
                    break;
                }
                {
                    char bidder_name[ITEM_NAME_LENGTH];
                    float bid_amount;
                    int item_index;

                    printf("Enter your name: ");
                    fgets(bidder_name, ITEM_NAME_LENGTH, stdin);
                    bidder_name[strcspn(bidder_name, "\n")] = '\0'; // Remove newline

                    printf("Enter item index to bid on (0-%d): ", item_count - 1);
                    scanf("%d", &item_index);

                    if (item_index < 0 || item_index >= item_count) {
                        printf("Invalid item index.\n");
                    } else {
                        printf("Enter your bid amount: ");
                        scanf("%f", &bid_amount);
                        place_bid(&auction_items[item_index], bidder_name, bid_amount);
                    }
                }
                break;
            case 4:
                printf("Exiting the auction system.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}