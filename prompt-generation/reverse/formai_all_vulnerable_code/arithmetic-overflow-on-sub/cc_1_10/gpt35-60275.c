//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDDERS 10
#define AUCTION_ITEMS 5

int highest_bids[AUCTION_ITEMS] = {0};
char *auction_items[AUCTION_ITEMS] = {"Painting", "Watch", "Ring", "Car", "Guitar"};
int num_bidders = 0;

void display_auction_items() {
    printf("\nAuction Items Available Today:\n");
    for (int i=0; i<AUCTION_ITEMS; i++) {
        printf("%d. %s\n", i+1, auction_items[i]);
    }
}

int select_auction_item() {
    int selected_item;
    printf("\nEnter the number of the item you'd like to bid on: ");
    scanf("%d", &selected_item);
    return selected_item-1;
}

int make_bid(int selected_item) {
    int current_bid;
    printf("\nEnter your bid for the %s: ", auction_items[selected_item]);
    scanf("%d", &current_bid);
    if (current_bid > highest_bids[selected_item]) {
        highest_bids[selected_item] = current_bid;
        return 1;
    } else {
        return 0;
    }
}

void display_results() {
    printf("\n\nThe auction has ended! Here are the final bids:\n");
    for (int i=0; i<AUCTION_ITEMS; i++) {
        printf("%s: %d\n", auction_items[i], highest_bids[i]);
    }
    printf("\n\nThank you for participating!");
}

int main() {
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Digital Auction System!\n");
    printf("We have %d unique auction items up for bid today.\n", AUCTION_ITEMS);
    
    while (num_bidders < MAX_BIDDERS) {
        display_auction_items();
        
        int selected_item = select_auction_item();
        if (selected_item < 0 || selected_item >= AUCTION_ITEMS) {
            printf("\nInvalid item selection. Please try again.\n\n");
            continue;
        }
        
        if (make_bid(selected_item)) {
            printf("\nCongratulations! You're currently the highest bidder for the %s.\n\n", auction_items[selected_item]);
        } else {
            printf("\nSorry, your bid was not high enough for the %s. Please try again.\n\n", auction_items[selected_item]);
        }
        
        num_bidders++;
        if (num_bidders == MAX_BIDDERS) {
            printf("\nMaximum number of bidders reached, ending auction.\n");
        } else {
            printf("There are still %d spots available for the auction.\n", MAX_BIDDERS - num_bidders);
            printf("Next bid starts in 5 seconds.\n\n");
            sleep(5);
        }
    }
    
    display_results();
    
    return 0;
}