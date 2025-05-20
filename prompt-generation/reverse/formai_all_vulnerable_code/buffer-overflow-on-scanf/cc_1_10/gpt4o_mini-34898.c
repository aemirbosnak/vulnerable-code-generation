//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double starting_price;
    double current_price;
    int highest_bidder;
} AuctionItem;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double balance;
} Bidder;

AuctionItem auction_items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int item_count = 0;
int bidder_count = 0;

void register_bidder();
void create_auction_item();
void place_bid();
void view_auction_status();

int main() {
    int choice;

    do {
        printf("\n=== Digital Auction System ===\n");
        printf("1. Register Bidder\n");
        printf("2. Create Auction Item\n");
        printf("3. Place Bid\n");
        printf("4. View Auction Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_bidder();
                break;
            case 2:
                create_auction_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                view_auction_status();
                break;
            case 5:
                printf("Exiting. Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void register_bidder() {
    if (bidder_count >= MAX_BIDDERS) {
        printf("Maximum bidder limit reached.\n");
        return;
    }
    
    Bidder new_bidder;
    new_bidder.id = bidder_count + 1;
    printf("Enter your name: ");
    scanf(" %[^\n]", new_bidder.name);
    printf("Enter your balance: ");
    scanf("%lf", &new_bidder.balance);
    
    bidders[bidder_count++] = new_bidder;
    printf("Bidder registered successfully! ID: %d\n", new_bidder.id);
}

void create_auction_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Maximum auction item limit reached.\n");
        return;
    }

    AuctionItem new_item;
    new_item.id = item_count + 1;
    printf("Enter item name: ");
    scanf(" %[^\n]", new_item.name);
    printf("Enter starting price: ");
    scanf("%lf", &new_item.starting_price);
    new_item.current_price = new_item.starting_price;
    new_item.highest_bidder = 0;

    auction_items[item_count++] = new_item;
    printf("Auction item created successfully! ID: %d\n", new_item.id);
}

void place_bid() {
    int item_id, bidder_id;
    double bid_amount;

    printf("Enter auction item ID: ");
    scanf("%d", &item_id);
    printf("Enter your bidder ID: ");
    scanf("%d", &bidder_id);
    printf("Enter bid amount: ");
    scanf("%lf", &bid_amount);

    if (item_id <= 0 || item_id > item_count) {
        printf("Invalid auction item ID.\n");
        return;
    }

    if (bidder_id <= 0 || bidder_id > bidder_count) {
        printf("Invalid bidder ID.\n");
        return;
    }

    AuctionItem *item = &auction_items[item_id - 1];
    Bidder *bidder = &bidders[bidder_id - 1];

    if (bid_amount <= item->current_price) {
        printf("Bid amount must be higher than the current price (%.2f).\n", item->current_price);
        return;
    }

    if (bidder->balance < bid_amount) {
        printf("Insufficient balance to place this bid.\n");
        return;
    }

    // Process the bid
    item->current_price = bid_amount;
    item->highest_bidder = bidder_id - 1; // Store bidder index
    bidder->balance -= bid_amount; // Deduct from bidder's balance

    printf("Bid placed successfully! New current price for '%s': %.2f\n", item->name, item->current_price);
}

void view_auction_status() {
    printf("\n=== Auction Status ===\n");
    for (int i = 0; i < item_count; i++) {
        AuctionItem item = auction_items[i];
        printf("Auction Item ID: %d\n", item.id);
        printf("Name: %s\n", item.name);
        printf("Starting Price: %.2f\n", item.starting_price);
        printf("Current Price: %.2f\n", item.current_price);
        if (item.highest_bidder != -1) {
            printf("Highest Bidder ID: %d\n", item.highest_bidder + 1);
        } else {
            printf("No bids placed yet.\n");
        }
        printf("---------------------------\n");
    }
}