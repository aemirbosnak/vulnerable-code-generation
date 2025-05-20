//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5
#define MAX_BID_VALUE 1000

int current_item_index = -1;
int current_bid_index = -1;
int current_bid_value = -1;

char* items[MAX_ITEMS] = {"Vintage Watch", "Artwork", "Antique Vase", "Rare Coin", "Signed Baseball"};

struct Bid {
    char bidder_name[50];
    int bid_value;
};

struct Item {
    char item_name[50];
    struct Bid bids[MAX_BIDDERS];
};

struct Item auction_items[MAX_ITEMS];

bool is_item_valid(int item_index) {
    if(item_index < 0 || item_index > current_item_index) {
        printf("Invalid item selected. Please choose again.\n");
        return false;
    }

    if(current_bid_index >= 0) {
        printf("You cannot switch items during a bid.\n");
        return false;
    }

    return true;
}

bool is_bid_valid(int item_index, int bid_value) {
    if(bid_value > MAX_BID_VALUE) {
        printf("The bid value exceeds the maximum bid amount.\n");
        return false;
    }

    if(bid_value <= auction_items[item_index].bids[current_bid_index].bid_value) {
        printf("The bid value must be higher than the current bid value.\n");
        return false;
    }

    return true;
}

void print_items() {
    printf("Current Items in Auction:\n");
    for(int i = 0; i <= current_item_index; i++) {
        printf("[%d] %s\n", i, items[i]);
    }
}

void print_bids(int item_index) {
    printf("Bids for %s:\n", items[item_index]);
    for(int i = 0; i <= current_bid_index; i++) {
        printf("%s: %d\n", auction_items[item_index].bids[i].bidder_name, auction_items[item_index].bids[i].bid_value);
    }
}

void place_bid(int item_index, char* bidder_name, int bid_value) {
    if(is_bid_valid(item_index, bid_value)) {
        struct Bid new_bid;
        strcpy(new_bid.bidder_name, bidder_name);
        new_bid.bid_value = bid_value;

        auction_items[item_index].bids[++current_bid_index] = new_bid;
        current_bid_value = bid_value;

        printf("Bid placed successfully.\n");
    }
}

int main() {
    printf("Welcome to the Digital Auction System!\n");

    bool is_running = true;
    while(is_running) {
        printf("Please choose an action:\n");
        printf("[1] View current items in auction\n");
        printf("[2] Place a bid\n");
        printf("[3] Quit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_items();
                break;

            case 2:
                printf("Please choose an item to bid on:\n");
                print_items();

                int item_choice;
                scanf("%d", &item_choice);

                if(is_item_valid(item_choice)) {
                    printf("Enter your name: ");
                    char bidder_name[50];
                    scanf("%s", bidder_name);

                    printf("Enter your bid value: ");
                    int bid_value;
                    scanf("%d", &bid_value);

                    place_bid(item_choice, bidder_name, bid_value);
                }

                break;

            case 3:
                is_running = false;
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}