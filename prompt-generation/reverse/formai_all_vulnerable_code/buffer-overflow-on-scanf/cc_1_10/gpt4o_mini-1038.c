//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

typedef struct {
    int id;
    char name[50];
    float bid_amount;
} Bidder;

typedef struct {
    int id;
    char name[50];
    float starting_price;
    float current_price;
    int is_active;
} AuctionItem;

AuctionItem auction_items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];

int item_count = 0;
int bidder_count = 0;

// Function declarations
void add_item();
void view_items();
void place_bid();
void end_auction();
void show_winner(int item_id);
void display_menu();

int main() {
    int option;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                end_auction();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n---- Digital Auction System ----\n");
    printf("1. Add Auction Item\n");
    printf("2. View Auction Items\n");
    printf("3. Place a Bid\n");
    printf("4. End Auction\n");
    printf("5. Exit\n");
}

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Cannot add more items.\n");
        return;
    }
    
    AuctionItem new_item;
    new_item.id = item_count + 1;

    printf("Enter item name: ");
    scanf(" %[^\n]", new_item.name);
    printf("Enter starting price: ");
    scanf("%f", &new_item.starting_price);

    new_item.current_price = new_item.starting_price;
    new_item.is_active = 1;

    auction_items[item_count++] = new_item;
    printf("Auction item added successfully.\n");
}

void view_items() {
    printf("\n--- Auction Items ---\n");
    for (int i = 0; i < item_count; i++) {
        if (auction_items[i].is_active) {
            printf("Item ID: %d, Name: %s, Starting Price: %.2f, Current Price: %.2f\n",
                    auction_items[i].id,
                    auction_items[i].name,
                    auction_items[i].starting_price,
                    auction_items[i].current_price);
        }
    }
}

void place_bid() {
    int item_id;
    float bid_amount;

    view_items();
    printf("Enter the Item ID you want to bid on: ");
    scanf("%d", &item_id);

    if (item_id < 1 || item_id > item_count || !auction_items[item_id - 1].is_active) {
        printf("Invalid item ID.\n");
        return;
    }

    printf("Enter bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= auction_items[item_id - 1].current_price) {
        printf("Bid amount must be higher than the current price!\n");
        return;
    }

    Bidder new_bidder;
    new_bidder.id = bidder_count + 1;
    new_bidder.bid_amount = bid_amount;

    printf("Enter your name: ");
    scanf(" %[^\n]", new_bidder.name);

    bidders[bidder_count++] = new_bidder;

    auction_items[item_id - 1].current_price = bid_amount;
    printf("Bid placed successfully.\n");
}

void end_auction() {
    view_items();
    
    int item_id;
    printf("Enter the Item ID to end the auction: ");
    scanf("%d", &item_id);
    
    if (item_id < 1 || item_id > item_count || !auction_items[item_id - 1].is_active) {
        printf("Invalid item ID.\n");
        return;
    }

    auction_items[item_id - 1].is_active = 0;
    printf("Auction for item '%s' ended.\n", auction_items[item_id - 1].name);
    show_winner(item_id);
}

void show_winner(int item_id) {
    float highest_bid = 0.0;
    char winner_name[50];

    for (int i = 0; i < bidder_count; i++) {
        if (bidders[i].bid_amount > highest_bid) {
            highest_bid = bidders[i].bid_amount;
            strcpy(winner_name, bidders[i].name);
        }
    }

    if (highest_bid > 0) {
        printf("The winner for item '%s' is %s with a bid of %.2f.\n",
               auction_items[item_id - 1].name,
               winner_name, highest_bid);
    } else {
        printf("No bids were placed for item '%s'. Auction closed without a winner.\n",
               auction_items[item_id - 1].name);
    }
}