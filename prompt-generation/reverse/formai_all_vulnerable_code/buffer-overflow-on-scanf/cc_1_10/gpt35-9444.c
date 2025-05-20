//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTION_ITEMS 10 // Maximum number of items that can be auctioned
#define MAX_NAME_LENGTH 20 // Maximum length of an item name
#define STARTING_BID_AMOUNT 100 // Starting bid amount for an item

// Declaration of struct to represent an auction item
typedef struct {
    char name[MAX_NAME_LENGTH];
    int current_bid;
} AuctionItem;

// Declaration of array to hold auction items
AuctionItem auction_items[MAX_AUCTION_ITEMS];

// Declaration of function to get user input for item names
void get_item_names() {
    for (int i = 0; i < MAX_AUCTION_ITEMS; i++) {
        printf("Enter name for item %d: ", i+1);
        scanf("%s", auction_items[i].name);
        auction_items[i].current_bid = STARTING_BID_AMOUNT;
    }
}

// Declaration of function to display current auction status
void display_auction_status() {
    printf("\n============================\n");
    printf("Current Auction Status:\n");
    printf("============================\n");
    for (int i = 0; i < MAX_AUCTION_ITEMS; i++) {
        printf("Item %d: %s, Current Bid: %d\n", i+1, auction_items[i].name, auction_items[i].current_bid);
    }
    printf("============================\n\n");
}

// Declaration of function to get user input for placing a bid
void place_bid() {
    int item_number, bid_amount;

    printf("Enter the item number for which you want to place a bid: ");
    scanf("%d", &item_number);

    if (item_number < 1 || item_number > MAX_AUCTION_ITEMS) {
        printf("\nInvalid item number. Please try again.\n");
        return;
    }

    printf("\nEnter your bid amount: ");
    scanf("%d", &bid_amount);

    if (bid_amount <= auction_items[item_number-1].current_bid) {
        printf("\nYour bid amount is not higher than the current bid. Please try again with a higher bid.\n");
        return;
    }

    auction_items[item_number-1].current_bid = bid_amount;
    printf("\nCongratulations! Your bid of %d has been accepted for %s.\n", bid_amount, auction_items[item_number-1].name);
}

// The main function that will run the auction
int main() {
    printf("Welcome to the Digital Auction System!\n");

    get_item_names();

    display_auction_status();

    int input = 0;

    while (input != 3) {
        printf("Enter 1 to place a bid, 2 to display current auction status, or 3 to exit: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                place_bid();
                break;
            case 2:
                display_auction_status();
                break;
            case 3:
                printf("\nThank you for participating in the auction!\n");
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}