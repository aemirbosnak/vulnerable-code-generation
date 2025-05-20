//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 50
#define NAME_LENGTH 100
#define DESCRIPTION_LENGTH 255

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float starting_price;
    time_t end_time;
    float highest_bid;
    char highest_bidder[NAME_LENGTH];
    int is_active;
} AuctionItem;

typedef struct {
    char bidder[NAME_LENGTH];
    float bid_amount;
} Bid;

AuctionItem items[MAX_ITEMS];
int item_count = 0;

void create_auction_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Error: Maximum item limit reached.\n");
        return;
    }

    AuctionItem new_item;
    printf("Enter item name: ");
    getchar(); // clear previous input
    fgets(new_item.name, NAME_LENGTH, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0; // remove newline

    printf("Enter item description: ");
    fgets(new_item.description, DESCRIPTION_LENGTH, stdin);
    new_item.description[strcspn(new_item.description, "\n")] = 0; // remove newline

    printf("Enter starting price: ");
    scanf("%f", &new_item.starting_price);

    printf("Enter duration in minutes for auction: ");
    int duration;
    scanf("%d", &duration);
    new_item.end_time = time(NULL) + (duration * 60);
    new_item.highest_bid = 0;
    new_item.is_active = 1;
    strcpy(new_item.highest_bidder, "");

    items[item_count++] = new_item;
    printf("Auction item created successfully!\n");
}

void list_auction_items() {
    printf("Current Auction Items:\n");
    for (int i = 0; i < item_count; i++) {
        AuctionItem item = items[i];
        if (item.is_active) {
            printf("Item %d: %s\nDescription: %s\nStarting Price: %.2f\n",
                    i + 1, item.name, item.description, item.starting_price);
            printf("Highest Bid: %.2f by %s\n", item.highest_bid, item.highest_bidder);
            printf("Time Remaining: %ld seconds\n", item.end_time - time(NULL));
            printf("-----------------------------\n");
        }
    }
}

void place_bid() {
    int item_index;
    printf("Enter the item index you want to bid on: ");
    scanf("%d", &item_index);
    if (item_index < 1 || item_index > item_count || !items[item_index - 1].is_active) {
        printf("Invalid item index.\n");
        return;
    }

    AuctionItem *item = &items[item_index - 1];
    if (time(NULL) > item->end_time) {
        printf("Auction for this item has ended.\n");
        return;
    }

    float bid_amount;
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);
    if (bid_amount <= item->highest_bid) {
        printf("Bid must be higher than the current highest bid.\n");
        return;
    }

    item->highest_bid = bid_amount;
    printf("Enter your name: ");
    getchar(); // clear previous input
    fgets(item->highest_bidder, NAME_LENGTH, stdin);
    item->highest_bidder[strcspn(item->highest_bidder, "\n")] = 0; // remove newline

    printf("Bid placed successfully.\n");
}

void end_auction() {
    for (int i = 0; i < item_count; i++) {
        if (time(NULL) > items[i].end_time) {
            items[i].is_active = 0;
            printf("Auction for item '%s' has ended. Highest bid: %.2f by %s.\n",
                   items[i].name, items[i].highest_bid, items[i].highest_bidder);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("Digital Auction System\n");
        printf("1. Create Auction Item\n");
        printf("2. List Auction Items\n");
        printf("3. Place Bid\n");
        printf("4. End Auctions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_auction_item();
                break;
            case 2:
                list_auction_items();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                end_auction();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}