//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bid {
    char bidder_name[50];
    float bid_amount;
} Bid;

typedef struct _auction_item {
    char item_name[50];
    Bid highest_bid;
} AuctionItem;

AuctionItem all_items[10];
int num_items = 0;

void add_item() {
    AuctionItem new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.item_name);
    printf("Enter starting bid amount: ");
    scanf("%f", &new_item.highest_bid.bid_amount);
    strcpy(new_item.highest_bid.bidder_name, "None");
    all_items[num_items] = new_item;
    num_items++;
}

void show_items() {
    printf("Available items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Highest Bid: %.2f by %s\n", i+1, all_items[i].item_name, all_items[i].highest_bid.bid_amount, all_items[i].highest_bid.bidder_name);
    }
}

void place_bid() {
    int item_num;
    printf("Enter item number to bid on: ");
    scanf("%d", &item_num);
    item_num--;
    if (item_num < 0 || item_num >= num_items) {
        printf("Invalid item number.\n");
        return;
    }
    float new_bid;
    printf("Enter bid amount: ");
    scanf("%f", &new_bid);
    if (new_bid <= all_items[item_num].highest_bid.bid_amount) {
        printf("Bid amount too low.\n");
        return;
    }
    Bid new_bidder;
    printf("Enter bidder name: ");
    scanf("%s", new_bidder.bidder_name);
    new_bidder.bid_amount = new_bid;
    all_items[item_num].highest_bid = new_bidder;
    printf("Bid placed successfully.\n");
}

int main() {
    int choice = 0;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Show Available Items\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                show_items();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}