//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    int id;
    char name[50];
    float min_price;
    float current_price;
    time_t end_time;
} AuctionItem;

typedef struct {
    int item_id;
    char bidder_name[50];
    float bid_amount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int item_count = 0;
int bid_count = 0;

void add_auction_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Maximum auction items reached!\n");
        return;
    }
    
    AuctionItem new_item;
    new_item.id = item_count + 1; // Assign ID
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter minimum bid price: ");
    scanf("%f", &new_item.min_price);
    
    new_item.current_price = new_item.min_price;
    
    printf("Enter auction duration in seconds: ");
    int duration;
    scanf("%d", &duration);
    new_item.end_time = time(NULL) + duration;

    items[item_count++] = new_item;
    printf("Auction item added successfully!\n");
}

void display_auction_items() {
    printf("\nCurrent Auction Items:\n");
    printf("ID\tName\t\tMin Price\tCurrent Price\tEnd Time\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d\t%s\t\t%.2f\t\t%.2f\t\t%s", 
               items[i].id, 
               items[i].name, 
               items[i].min_price, 
               items[i].current_price, 
               ctime(&items[i].end_time));
    }
}

void bid_on_item() {
    int item_id;
    printf("Enter item ID to bid on: ");
    scanf("%d", &item_id);

    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID!\n");
        return;
    }

    if (time(NULL) >= items[item_id - 1].end_time) {
        printf("Auction already ended for this item!\n");
        return;
    }

    char bidder_name[50];
    float bid_amount;
    
    printf("Enter your name: ");
    scanf("%s", bidder_name);
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= items[item_id - 1].current_price) {
        printf("Bid amount must be higher than the current price (%.2f)!\n", 
               items[item_id - 1].current_price);
        return;
    }

    bids[bid_count++] = (Bid){item_id, "", bid_amount};
    strcpy(bids[bid_count - 1].bidder_name, bidder_name);
    items[item_id - 1].current_price = bid_amount; // Update current price

    printf("Bid placed successfully!\n");
}

void view_bids_on_item() {
    int item_id;
    printf("Enter item ID to view bids: ");
    scanf("%d", &item_id);

    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID!\n");
        return;
    }

    printf("\nBids for Item %d - %s:\n", item_id, items[item_id - 1].name);
    printf("Bidder Name\tBid Amount\n");
    for (int i = 0; i < bid_count; i++) {
        if (bids[i].item_id == item_id) {
            printf("%s\t\t%.2f\n", bids[i].bidder_name, bids[i].bid_amount);
        }
    }
}

void end_auction() {
    int item_id;
    printf("Enter item ID to end auction: ");
    scanf("%d", &item_id);

    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID!\n");
        return;
    }

    items[item_id - 1].end_time = time(NULL); // Mark auction as ended
    printf("Auction ended for Item %d - %s\n", item_id, items[item_id - 1].name);
    printf("Winning Bid: %.2f\n", items[item_id - 1].current_price);
}

void show_menu() {
    printf("\nDigital Auction System Menu:\n");
    printf("1. Add Auction Item\n");
    printf("2. Display Auction Items\n");
    printf("3. Bid on Item\n");
    printf("4. View Bids on Item\n");
    printf("5. End Auction\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        show_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_auction_item();
                break;
            case 2:
                display_auction_items();
                break;
            case 3:
                bid_on_item();
                break;
            case 4:
                view_bids_on_item();
                break;
            case 5:
                end_auction();
                break;
            case 6:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}