//FormAI DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare global variables
int num_items;
char item_names[10][30];
int item_bids[10];
int item_winners[10];
char bidder_names[10][30];

// Declare function prototypes
void print_menu();
int validate_bid(int bid, int item);
void end_auction();

int main() {
    // Define local variables
    int choice, item, bid, bids_placed = 0;
    char bidder[30];
    
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize item_bids and item_winners arrays to -1
    for(int i = 0; i < 10; i++) {
        item_bids[i] = -1;
        item_winners[i] = -1;
    }
    
    printf("Welcome to the Digital Auction System!\n");
    
    // Get number of items for auction
    printf("\nEnter the number of items for auction (maximum 10): ");
    scanf("%d", &num_items);
    
    // Get item names from user
    printf("\nPlease enter the names of the items for auction:\n");
    for(int i = 0; i < num_items; i++) {
        printf("%d. ", i+1);
        scanf("%s", item_names[i]);
    }
    
    // Display menu and process user input
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the number of the item you wish to bid on: ");
                scanf("%d", &item);
                if(item < 1 || item > num_items) {
                    printf("\nInvalid item number. Please try again.\n");
                    continue;
                }
                printf("\nEnter your name: ");
                scanf("%s", bidder);
                printf("\nEnter your bid amount: ");
                scanf("%d", &bid);
                if(validate_bid(bid, item-1)) {
                    printf("\nBid accepted.\n");
                    strcpy(bidder_names[bids_placed], bidder);
                    item_bids[item-1] = bid;
                    bids_placed++;
                }
                else {
                    printf("\nInvalid bid amount. Please try again.\n");
                    continue;
                }
                break;
            case 2:
                end_auction();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 2);
    
    return 0;
}

// Function to print the menu options
void print_menu() {
    printf("\nPlease select an option:\n");
    printf("1. Place a bid\n");
    printf("2. End auction\n");
    printf("Choice: ");
}

// Function to validate bid amount
int validate_bid(int bid, int item) {
    if(bid < 0) {
        return 0;
    }
    if(bid > item_bids[item]) {
        return 1;
    }
    return 0;
}

// Function to end the auction
void end_auction() {
    int highest_bid = -1, winner_index = -1, num_winners = 0;
    printf("\nAuction has ended.\n");
    for(int i = 0; i < num_items; i++) {
        if(item_bids[i] > highest_bid) {
            highest_bid = item_bids[i];
            winner_index = i;
        }
    }
    printf("\nThe winner of item %d is %s with a bid of %d.\n", winner_index+1, bidder_names[winner_index], highest_bid);
    
    // Check for tie bids
    for(int i = 0; i < num_items; i++) {
        if(item_bids[i] == highest_bid) {
            item_winners[num_winners] = i;
            num_winners++;
        }
    }
    if(num_winners > 1) {
        printf("\nThere was a tie for highest bid on the following items: ");
        for(int i = 0; i < num_winners; i++) {
            printf("%s ", item_names[item_winners[i]]);
        }
    }
}