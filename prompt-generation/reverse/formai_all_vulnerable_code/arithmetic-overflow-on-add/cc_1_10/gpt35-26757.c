//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 5
#define MAX_ITEMS 10

// Item struct
typedef struct Item {
    char name[20];
    double start_price;
    double current_price;
    int bidder_id;
    int sold;
} Item;

// Bidder struct
typedef struct Bidder {
    char name[20];
    double balance;
    int item_ids[MAX_ITEMS];
    int num_items;
} Bidder;

// Auction struct
typedef struct Auction {
    Item items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];
    int num_bidders;
    int num_items;
} Auction;

// Function declarations
void add_bidder(Auction *auction, char *name, double balance);
void add_item(Auction *auction, char *name, double start_price);
void show_items(Auction auction);
void show_bidders(Auction auction);
void place_bid(Auction *auction, int item_id, int bidder_id, double bid_amount);
void get_highest_bidder(Auction auction, int item_id);

int main() {
    Auction auction;
    auction.num_bidders = 0;
    auction.num_items = 0;
    int choice, item_id, bidder_id;
    double price;
    char name[20];

    while(1) {
        printf("\n1. Add Bidder\n2. Add Item\n3. Show Items\n4. Show Bidders\n5. Place Bid\n6. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter bidder name: ");
                scanf("%s", name);
                printf("Enter starting balance: ");
                scanf("%lf", &price);
                add_bidder(&auction, name, price);
                break;
            case 2:
                printf("\nEnter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%lf", &price);
                add_item(&auction, name, price);
                break;
            case 3:
                show_items(auction);
                break;
            case 4:
                show_bidders(auction);
                break;
            case 5:
                printf("\nEnter item id: ");
                scanf("%d", &item_id);
                printf("Enter bidder id: ");
                scanf("%d", &bidder_id);
                printf("Enter bid amount: ");
                scanf("%lf", &price);
                place_bid(&auction, item_id, bidder_id, price);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

// Function to add a new bidder to the auction
void add_bidder(Auction *auction, char *name, double balance) {
    if(auction->num_bidders >= MAX_BIDDERS) {
        printf("\nCannot add more bidders!\n");
        return;
    }

    Bidder bidder;
    strcpy(bidder.name, name);
    bidder.balance = balance;
    bidder.num_items = 0;
    auction->bidders[auction->num_bidders++] = bidder;

    printf("\nBidder added successfully!\n");
}

// Function to add a new item to the auction
void add_item(Auction *auction, char *name, double start_price) {
    if(auction->num_items >= MAX_ITEMS) {
        printf("\nCannot add more items!\n");
        return;
    }

    Item item;
    strcpy(item.name, name);
    item.start_price = start_price;
    item.current_price = start_price;
    item.bidder_id = -1;
    item.sold = 0;

    auction->items[auction->num_items++] = item;

    printf("\nItem added successfully!\n");
}

// Function to print all items in the auction with their current prices
void show_items(Auction auction) {
    printf("\nITEMS\n");
    printf("ID   NAME               CURRENT PRICE   BIDDER ID\n");
    printf("------------------------------------------------\n");

    for(int i = 0; i < auction.num_items; i++) {
        printf("%-4d %-18s %-15.2lf", i, auction.items[i].name, auction.items[i].current_price);

        if(auction.items[i].bidder_id != -1) {
            printf("%-5d", auction.items[i].bidder_id);
        }
        else {
            printf("        ");
        }

        printf("\n");
    }

    printf("\n");
}

// Function to print all bidders in the auction with their names and balances
void show_bidders(Auction auction) {
    printf("\nBIDDERS\n");
    printf("ID   NAME               BALANCE\n");
    printf("--------------------------------\n");

    for(int i = 0; i < auction.num_bidders; i++) {
        printf("%-4d %-18s %-15.2lf\n", i, auction.bidders[i].name, auction.bidders[i].balance);
    }

    printf("\n");
}

// Function to place a bid on an item
void place_bid(Auction *auction, int item_id, int bidder_id, double bid_amount) {
    if(item_id >= auction->num_items) {
        printf("\nInvalid item ID!\n");
        return;
    }

    if(bidder_id >= auction->num_bidders) {
        printf("\nInvalid bidder ID!\n");
        return;
    }

    Item *item = &auction->items[item_id];
    Bidder *bidder = &auction->bidders[bidder_id];

    if(item->sold) {
        printf("\nItem already sold!\n");
        return;
    }

    if(bid_amount <= item->current_price) {
        printf("\nBid amount must be greater than current price!\n");
        return;
    }

    if(bid_amount > bidder->balance) {
        printf("\nInsufficient balance!\n");
        return;
    }

    if(item->bidder_id != -1) {
        // Refund the previous bidder's balance
        Bidder *prev_bidder = &auction->bidders[item->bidder_id];
        prev_bidder->balance += item->current_price;
    }

    // Update the item's current price and bidder ID
    item->current_price = bid_amount;
    item->bidder_id = bidder_id;

    // Deduct the bidder's balance
    bidder->balance -= bid_amount;

    // Add the item to the bidder's list
    bidder->item_ids[bidder->num_items++] = item_id;

    printf("\nBid placed successfully!\n");
}

// Function to get the highest bidder for a given item
void get_highest_bidder(Auction auction, int item_id) {
    if(item_id >= auction.num_items) {
        printf("\nInvalid item ID!\n");
        return;
    }

    Item item = auction.items[item_id];

    if(item.sold) {
        printf("\nItem already sold!\n");
        return;
    }

    if(item.bidder_id == -1) {
        printf("\nNo bids placed for this item yet!\n");
        return;
    }

    Bidder bidder = auction.bidders[item.bidder_id];
    printf("\nHighest bidder for %s is %s with a bid of %.2lf\n", item.name, bidder.name, item.current_price);
}