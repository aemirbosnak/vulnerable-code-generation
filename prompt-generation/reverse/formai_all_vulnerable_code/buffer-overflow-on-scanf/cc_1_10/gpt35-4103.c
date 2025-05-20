//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define necessary structures
struct Item {
    char name[50];
    int id;
    float price;
};

struct Bid {
    int item_id;
    char bidder_name[50];
    float bid_price;
};

struct Auction {
    struct Item item;
    struct Bid highest_bid;
};

// define functions to handle auction 
void add_item();
void place_bid();
void display_items();
void display_bids();

// define main function
int main() {
    int choice;

    // create array of auctions
    struct Auction auctions[100];

    do {
        // display menu
        printf("1. Add Item\n2. Place Bid\n3. Display Items\n4. Display Bids\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handle user choice
        switch(choice) {
            case 1:
                add_item(auctions);
                break;
            case 2:
                place_bid(auctions);
                break;
            case 3:
                display_items(auctions);
                break;
            case 4:
                display_bids(auctions);
                break;
            case 5:
                printf("\nThank you for using the Digital Auction System.");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// function to add an item to the auction
void add_item(struct Auction* auctions) {
    static int id = 0;
    struct Item item;

    printf("\nEnter item name: ");
    scanf("%s", item.name);

    printf("Enter starting price: ");
    scanf("%f", &item.price);

    item.id = ++id;

    struct Auction auction = {item};
    auctions[id-1] = auction;

    printf("\nItem added successfully.\n");
}

// function to place a bid on an item
void place_bid(struct Auction* auctions) {
    int item_id;
    float bid_price;
    static int bid_count = 0;
  
    printf("\nEnter item ID: ");
    scanf("%d", &item_id);

    printf("Enter bidder name: ");
    char bidder_name[50];
    scanf("%s", bidder_name);

    printf("Enter bid price: ");
    scanf("%f", &bid_price);

    struct Bid bid = {
        item_id,
        bidder_name,
        bid_price
    };

    struct Auction* auction = &auctions[item_id - 1];

    // check if the bid price is higher than the current highest bid
    if (bid.bid_price > auction->highest_bid.bid_price) {
        auction->highest_bid = bid;
        printf("\nBid placed successfully.\n");
    } else {
        printf("\nBid amount should be higher than the highest bid amount.\n");
    }

    bid_count++;
}

// function to display all items in the auction
void display_items(struct Auction* auctions) {
    printf("\nItem List:\n");
    for (int i = 0; i < sizeof(auctions)/sizeof(auctions[0]); i++) {
        struct Item item = auctions[i].item;
        if (strlen(item.name) == 0) {
            break;
        }
        printf("\nID: %d\tName: %s\tPrice: %f\n", item.id, item.name, item.price);
    }
}

// function to display all bids
void display_bids(struct Auction* auctions) {
    printf("\nBid List:\n");
    for (int i = 0; i < sizeof(auctions)/sizeof(auctions[0]); i++) {
        struct Bid bid = auctions[i].highest_bid;
        if (bid.bid_price == 0) {
            break;
        }
        printf("\nItem ID: %d\tBidder: %s\tBid Amount: %f\n", bid.item_id, bid.bidder_name, bid.bid_price);
    }
}