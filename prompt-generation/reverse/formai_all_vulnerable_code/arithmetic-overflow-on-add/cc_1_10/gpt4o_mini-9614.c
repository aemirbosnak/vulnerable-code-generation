//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    double bid_amount;
} Bidder;

typedef struct {
    int id;
    char item_name[MAX_NAME_LENGTH];
    double starting_price;
    double current_price;
    int highest_bidder;
    time_t auction_end_time;
    int is_active;
} Item;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];
int bidder_count = 0;
int item_count = 0;

void list_items();
void register_bidder();
void place_bid(int item_id);
void start_auction();
void print_auction_status(int item_id);

int main() {
    int choice;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Register Bidder\n");
        printf("2. List Items\n");
        printf("3. Start Auction\n");
        printf("4. Place Bid\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_bidder();
                break;
            case 2:
                list_items();
                break;
            case 3:
                start_auction();
                break;
            case 4: {
                int item_id;
                printf("Enter Item ID to place a bid: ");
                scanf("%d", &item_id);
                place_bid(item_id);
                break;
            }
            case 5:
                printf("Exiting the Auction System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void register_bidder() {
    if (bidder_count >= MAX_BIDDERS) {
        printf("Bidder registration is full.\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", bidders[bidder_count].name);
    bidders[bidder_count].id = bidder_count + 1;
    bidders[bidder_count].bid_amount = 0;
    printf("Registered Bidder ID: %d, Name: %s\n", bidders[bidder_count].id, bidders[bidder_count].name);
    bidder_count++;
}

void list_items() {
    if (item_count == 0) {
        printf("No items available for auction.\n");
        return;
    }
    printf("Available Items:\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item ID: %d, Name: %s, Starting Price: %.2f, Current Price: %.2f\n",
               items[i].id, items[i].item_name, items[i].starting_price, items[i].current_price);
    }
}

void start_auction() {
    if (item_count >= MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
        return;
    }
    printf("Enter Item Name: ");
    scanf("%s", items[item_count].item_name);
    printf("Enter Starting Price: ");
    scanf("%lf", &items[item_count].starting_price);
    
    items[item_count].id = item_count + 1;
    items[item_count].current_price = items[item_count].starting_price;
    items[item_count].highest_bidder = 0;
    items[item_count].is_active = 1;
    
    time(&items[item_count].auction_end_time);
    items[item_count].auction_end_time += 60; // Set auction duration to 60 seconds
    
    printf("Item ID: %d has been started for auction.\n", items[item_count].id);
    item_count++;
}

void place_bid(int item_id) {
    if (item_id < 1 || item_id > item_count) {
        printf("Invalid Item ID.\n");
        return;
    }

    if (!items[item_id - 1].is_active) {
        printf("The auction for Item ID: %d has ended.\n", item_id);
        return;
    }

    time_t current_time;
    time(&current_time);
    if (current_time > items[item_id - 1].auction_end_time) {
        printf("The auction for Item ID: %d has ended.\n", item_id);
        items[item_id - 1].is_active = 0;
        return;
    }

    double bid_amount;
    printf("Enter your bid: ");
    scanf("%lf", &bid_amount);

    if (bid_amount <= items[item_id - 1].current_price) {
        printf("Bid must be higher than the current price: %.2f\n", items[item_id - 1].current_price);
        return;
    }

    int bidder_id;
    printf("Enter your Bidder ID: ");
    scanf("%d", &bidder_id);

    if (bidder_id < 1 || bidder_id > bidder_count) {
        printf("Invalid Bidder ID.\n");
        return;
    }

    items[item_id - 1].current_price = bid_amount;
    items[item_id - 1].highest_bidder = bidder_id;
    printf("Bid placed successfully!\n");
    print_auction_status(item_id);
}

void print_auction_status(int item_id) {
    printf("Current status of Item ID: %d\n", item_id);
    printf("Highest Bid: %.2f by Bidder ID: %d\n", items[item_id - 1].current_price, items[item_id - 1].highest_bidder);
}