//FormAI DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for bids
typedef struct Bid {
    char bidder_name[50];
    int bid_amount;
} Bid;

// Struct for auction items
typedef struct AuctionItem {
    char item_name[50];
    int current_bid;
    Bid highest_bid;
} AuctionItem;

// Display main menu
void display_menu() {
    printf("~~~ Welcome to the Romantic Auction ~~~\n\n");
    printf("1. View Auction Items\n");
    printf("2. Add Auction Item\n");
    printf("3. Place Bid\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

// Display auction items currently available
void view_items(AuctionItem *items, int num_items) {
    printf("\n~~~ Available Auction Items ~~~\n\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s (Current bid: $%d)\n", i+1, items[i].item_name, items[i].current_bid);
        if (items[i].highest_bid.bidder_name[0] != '\0') {
            printf("   Current highest bidder: %s\n", items[i].highest_bid.bidder_name);
        }
        printf("\n");
    }
    printf("\n");
}

// Add new auction item to the system
void add_item(AuctionItem *items, int *num_items) {
    AuctionItem new_item;

    printf("\n~~~ Add New Auction Item ~~~\n\n");
    printf("Enter item name: ");
    scanf("%s", new_item.item_name);
    new_item.current_bid = 0;
    new_item.highest_bid.bidder_name[0] = '\0';
    new_item.highest_bid.bid_amount = 0;

    items[*num_items] = new_item;
    (*num_items)++;

    printf("\nItem added successfully!\n\n");
}

// Place bid on an auction item
void place_bid(AuctionItem *items, int num_items) {
    int item_choice;
    int bid_amount;
    char bidder_name[50];

    printf("\n~~~ Place a Bid ~~~\n\n");
    printf("Select an item to bid on (enter item number): ");
    scanf("%d", &item_choice);
    item_choice--;

    if (item_choice >= 0 && item_choice < num_items) {
        printf("Enter your name: ");
        scanf("%s", bidder_name);
        printf("Enter bid amount: $");
        scanf("%d", &bid_amount);

        if (bid_amount > items[item_choice].current_bid) {
            Bid new_bid;
            strcpy(new_bid.bidder_name, bidder_name);
            new_bid.bid_amount = bid_amount;

            items[item_choice].highest_bid = new_bid;
            items[item_choice].current_bid = bid_amount;

            printf("\nBid of $%d on item %d by %s was successful!\n\n", bid_amount, item_choice+1, bidder_name);
        } else {
            printf("\nBid amount must be higher than current bid.\n\n");
        }
    } else {
        printf("\nItem choice invalid.\n\n");
    }
}

int main() {
    int num_items = 0;
    AuctionItem items[20];

    // Initial items in the auction
    AuctionItem item1 = {"Romantic Dinner for Two", 150, {"John", 150}};
    AuctionItem item2 = {"Dreamy Getaway for Two", 500, {"Amanda", 500}};
    AuctionItem item3 = {"Couple's Photo Session", 100, {"Stephanie", 100}};

    items[0] = item1;
    items[1] = item2;
    items[2] = item3;

    num_items = 3;

    int choice = 0;

    while (choice != 4) {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                view_items(items, num_items);
                break;
            case 2:
                add_item(items, &num_items);
                break;
            case 3:
                place_bid(items, num_items);
                break;
            case 4:
                printf("\nGoodbye! Thank you for visiting the Romantic Auction.\n");
                break;
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
    }

    return 0;
}