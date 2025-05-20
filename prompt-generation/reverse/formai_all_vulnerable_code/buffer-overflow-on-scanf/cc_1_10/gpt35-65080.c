//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 10
#define MAX_BID_AMOUNT 10000

struct Item {
    char name[50];
    int starting_price;
    int current_bid;
    int num_bids;
    char bidder_names[MAX_BIDS][50];
};

int main() {
    struct Item sword = {"Sword of King Arthur", 100, 0, 0};
    struct Item shield = {"Shield of Lancelot", 200, 0, 0};
    struct Item armor = {"Armor of Richard the Lionhearted", 500, 0, 0};
    
    struct Item items[3] = {sword, shield, armor};
    
    int bidder_count = 0;
    char bidder_names[MAX_BIDS][50];
    int bidder_amounts[MAX_BIDS];
    
    srand(time(NULL));
    int current_item_index = rand() % 3;
    struct Item current_item = items[current_item_index];
    
    printf("Welcome to the Medieval Auction House!\n");
    printf("You will be bidding on %s\n", current_item.name);
    printf("The starting price is %d.\n", current_item.starting_price);
    
    while (1) {
        char bidder_name[50];
        printf("\nWhat is your name? ");
        scanf("%s", bidder_name);
        
        // check if bidder has already made a bid
        int bidder_index = -1;
        for (int i = 0; i < bidder_count; i++) {
            if (strcmp(bidder_names[i], bidder_name) == 0) {
                bidder_index = i;
                break;
            }
        }
        
        if (bidder_index == -1) {
            // add new bidder
            strcpy(bidder_names[bidder_count], bidder_name);
            bidder_index = bidder_count;
            bidder_count++;
        }
        
        int bid_amount;
        printf("How much do you bid? ");
        scanf("%d", &bid_amount);
        
        if (bid_amount > MAX_BID_AMOUNT) {
            printf("Your bid is too high! The maximum bid amount is %d.\n", MAX_BID_AMOUNT);
            continue;
        }
        
        if (bid_amount <= current_item.current_bid) {
            printf("Your bid must be higher than the current bid of %d.\n", current_item.current_bid);
            continue;
        }
        
        if (current_item.num_bids >= MAX_BIDS) {
            printf("Sorry, there are already %d bids on this item and we cannot accept any more.\n", MAX_BIDS);
            continue;
        }
        
        current_item.current_bid = bid_amount;
        strcpy(current_item.bidder_names[current_item.num_bids], bidder_name);
        current_item.num_bids++;
        bidder_amounts[bidder_index] = bid_amount;
        
        printf("Your bid of %d has been recorded.\n", bid_amount);
        
        if (current_item.current_bid >= current_item.starting_price * 2) {
            break; // item sold
        }
        
        printf("The current bid is %d.\n", current_item.current_bid);
    }
    
    printf("\nSold! The %s has been sold to %s for %d.\n", current_item.name, 
        current_item.bidder_names[current_item.num_bids - 1], current_item.current_bid);
    
    printf("\nHere is a summary of the bids:\n");
    for (int i = 0; i < bidder_count; i++) {
        printf("%s bid %d.\n", bidder_names[i], bidder_amounts[i]);
    }
    
    return 0;
}