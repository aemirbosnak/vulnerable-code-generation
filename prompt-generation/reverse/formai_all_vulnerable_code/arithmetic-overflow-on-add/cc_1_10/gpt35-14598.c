//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_BID_LENGTH 50

struct auction_item {
    int item_number;
    char item_name[MAX_BID_LENGTH];
    int current_bid;
    int num_bids;
    char bids[MAX_BIDS][MAX_BID_LENGTH];
};

void print_auction_item(struct auction_item item) {
    printf("Item Number: %d\n", item.item_number);
    printf("Item Name: %s\n", item.item_name);
    printf("Current Bid: $%d\n", item.current_bid);
    printf("Number of Bids: %d\n", item.num_bids);
    printf("Bids:\n");
    for(int i=0; i<item.num_bids; i++) {
        printf("%s\n", item.bids[i]);
    }
}

int main() {
    struct auction_item item1 = {1, "Baseball", 10, 2, {"$5", "$7"}};
    struct auction_item item2 = {2, "Guitar", 100, 3, {"$50", "$75", "$80"}};
    
    printf("Welcome to the Digital Auction System!\n");
    printf("Here are the current items up for auction:\n");
    printf("1. Baseball\n");
    printf("2. Guitar\n");
    
    int choice;
    printf("Please enter the item number you would like to bid on: ");
    scanf("%d", &choice);
    
    struct auction_item *item;
    if(choice == 1) {
        item = &item1;
    } else if(choice == 2) {
        item = &item2;
    }
    
    printf("You have selected the following item:\n");
    print_auction_item(*item);
    
    char bid[MAX_BID_LENGTH];
    printf("Please enter your bid: $");
    scanf("%s", bid);
    
    int bid_amount = atoi(bid+1);
    if(bid_amount <= item->current_bid) {
        printf("Your bid of $%d is not higher than the current bid of $%d. Please try again.\n", bid_amount, item->current_bid);
        return 0;
    }
    
    strcpy(item->bids[item->num_bids], bid);
    item->num_bids++;
    item->current_bid = bid_amount;
    
    printf("Congratulations! Your bid of %s is the current high bid!\n", bid);
    return 0;
}