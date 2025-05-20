//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int auction_item_count = 0;
int auction_bid_count = 0;

// Structs
typedef struct {
    int item_number;
    char item_name[50];
    int starting_price;
    int current_bid;
    char highest_bidder[50];
} AuctionItem;

typedef struct {
    char bidder_name[50];
    int bid_amount;
    int item_number;
} AuctionBid;

// Function prototypes
void add_auction_item(AuctionItem *item_list);
void display_auction_items(AuctionItem *item_list);
void auction_items(AuctionItem *item_list, AuctionBid *bid_list, char *winner_name);
void display_auction_bids(AuctionBid *bid_list, int item_number);

// Main function
int main() {
    AuctionItem item_list[10];
    AuctionBid bid_list[100];
    char winner_name[50];
    
    int menu_option = 0;

    do {
        // Print menu and get user input
        printf("\nWelcome to our Digital Auction System!\n");
        printf("Please select an option:\n");
        printf("1. Add Auction Item\n");
        printf("2. Display Auction Items\n");
        printf("3. Auction Items\n");
        printf("4. Exit\n");
        scanf("%d", &menu_option);

        switch(menu_option) {
            case 1:
                add_auction_item(item_list);
                break;
            case 2:
                display_auction_items(item_list);
                break;
            case 3:
                auction_items(item_list, bid_list, winner_name);
                printf("\nThe winner is %s!\n", winner_name);
                break;
            case 4:
                printf("\nThank you for using our Digital Auction System!\n");
                break;
            default:
                printf("\nInvalid menu option. Please try again.\n");
        }
    } while(menu_option != 4);
    
    return 0;
}

// Function to add an auction item to the list
void add_auction_item(AuctionItem *item_list) {
    AuctionItem new_item;
    printf("\nEnter item name: ");
    scanf("%s", new_item.item_name);
    printf("Enter starting price: ");
    scanf("%d", &new_item.starting_price);
    new_item.current_bid = new_item.starting_price;
    new_item.item_number = auction_item_count;
    auction_item_count++;
    item_list[auction_item_count-1] = new_item;
    printf("\nAuction item added successfully!\n");
}

// Function to display all auction items in the list
void display_auction_items(AuctionItem *item_list) {
    printf("\nAuction Items:\n");
    for(int i = 0; i < auction_item_count; i++) {
        printf("%d. %s (%d) - Current bid: %d\n", item_list[i].item_number + 1, item_list[i].item_name, item_list[i].starting_price, item_list[i].current_bid);
    }
}

// Function to auction all items
void auction_items(AuctionItem *item_list, AuctionBid *bid_list, char *winner_name) {
    for(int i = 0; i < auction_item_count; i++) {
        printf("\nAuctioning %s...\n", item_list[i].item_name);
        int bidding_active = 1;
        while(bidding_active) {
            printf("\nEnter your bid for %s (current bid: %d): ", item_list[i].item_name, item_list[i].current_bid);
            AuctionBid new_bid;
            scanf("%s %d", new_bid.bidder_name, &new_bid.bid_amount);
            new_bid.item_number = item_list[i].item_number;
            if(new_bid.bid_amount > item_list[i].current_bid) {
                item_list[i].current_bid = new_bid.bid_amount;
                strcpy(item_list[i].highest_bidder, new_bid.bidder_name);
                bid_list[auction_bid_count] = new_bid;
                auction_bid_count++;
                printf("Bid accepted!\n");
            } else {
                printf("Bid too low. Please try again.\n");
            }
            printf("Do you want to continue bidding? (y/n)\n");
            char continue_bidding;
            scanf(" %c", &continue_bidding);
            if(continue_bidding == 'n') {
                bidding_active = 0;
            }
        }
    }
    // Find winner
    int highest_bid = -1;
    for(int i = 0; i < auction_bid_count; i++) {
        if(bid_list[i].bid_amount > highest_bid) {
            highest_bid = bid_list[i].bid_amount;
            strcpy(winner_name, bid_list[i].bidder_name);
        }
    }
}

// Function to display all bids for a specific auction item
void display_auction_bids(AuctionBid *bid_list, int item_number) {
    printf("\nBids for item %d:\n", item_number);
    for(int i = 0; i < auction_bid_count; i++) {
        if(bid_list[i].item_number == item_number) {
            printf("%s - %d\n", bid_list[i].bidder_name, bid_list[i].bid_amount);
        }
    }
}