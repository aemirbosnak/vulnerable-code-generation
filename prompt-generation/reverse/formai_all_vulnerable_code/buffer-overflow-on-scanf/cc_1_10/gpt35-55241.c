//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct auction_item {
    char name[50];
    int current_bid;
    int min_bid;
};

int main() {
    struct auction_item items[5];
    int num_items = 5;
    char input[10];
    int user_bid, bid_index, i;
    int user_satisfied = 0;
    
    // prompt user to input auction item names and minimum bids
    for(i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        fgets(items[i].name, 50, stdin);
        printf("Enter the minimum bid for %s: ", items[i].name);
        scanf("%d", &items[i].min_bid);
        getchar(); // remove leftover newline character
        items[i].current_bid = items[i].min_bid;
    }
    
    // start the auction
    printf("The auction has started!\n");
    while(!user_satisfied) {
        // display current bids for each item
        printf("\nCurrent Bids:\n");
        for(i = 0; i < num_items; i++) {
            printf("%d. %s - Current Bid: %d\n", i+1, items[i].name, items[i].current_bid);
        }
        
        // ask user which item they want to bid on
        printf("\nWhich item would you like to bid on (1-%d)? Enter 0 to exit: ", num_items);
        fgets(input, 10, stdin);
        bid_index = atoi(input) - 1; // convert user input to array index
        if(bid_index < 0 || bid_index >= num_items) {
            user_satisfied = 1;
            continue;
        }
        
        // ask user to enter bid amount
        printf("Enter your bid for %s (minimum bid is %d): ", items[bid_index].name, items[bid_index].min_bid);
        scanf("%d", &user_bid);
        getchar(); // remove leftover newline character
        
        // check if bid is valid
        if(user_bid < items[bid_index].min_bid || user_bid <= items[bid_index].current_bid) {
            printf("Invalid bid.\n");
            continue;
        }
        
        // update current bid for item
        items[bid_index].current_bid = user_bid;
        printf("Bid accepted.\n");
    }
    
    // print final bids for each item
    printf("\nFinal Bids:\n");
    for(i = 0; i < num_items; i++) {
        printf("%s - Final Bid: %d\n", items[i].name, items[i].current_bid);
    }
    
    return 0;
}