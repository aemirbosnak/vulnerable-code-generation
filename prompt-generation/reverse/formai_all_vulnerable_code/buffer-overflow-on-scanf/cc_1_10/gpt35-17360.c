//FormAI DATASET v1.0 Category: Digital Auction System ; Style: introspective
/* 
   A Digital Auction System using C programming language. 
   This program is an example of what the backend architecture of an auction system can look like.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50

// Struct for storing information about an item
typedef struct {
    char name[50];
    int starting_bid;
    int current_bid;
    char highest_bidder[50];
} Item;

// Struct for storing information about a user/bidder
typedef struct {
    char name[50];
    int balance;
    int num_bids_made;
} Bidder;

// Global variables
Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int num_items = 0;
int num_bidders = 0;

// Function for adding a new item to the auction
void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Maximum number of items reached. No more can be added.\n");
        return;
    }
    
    Item new_item;
    printf("Enter the name of the item: ");
    fgets(new_item.name, 50, stdin);
    printf("Enter the starting bid: ");
    scanf("%d", &new_item.starting_bid);
    new_item.current_bid = new_item.starting_bid;
    strcpy(new_item.highest_bidder, "None");
    getchar(); // Consume the newline character left behind by scanf
    
    items[num_items] = new_item;
    num_items++;
    printf("Item successfully added to the auction.\n");
}

// Function for displaying all items currently in the auction
void view_items() {
    printf("%-25s %-15s %-15s\n", "ITEM", "CURRENT BID", "HIGHEST BIDDER");
    for (int i = 0; i < num_items; i++) {
        printf("%-25s %-15d %-15s\n", items[i].name, items[i].current_bid, items[i].highest_bidder);
    }
}

// Function for adding a new bidder to the auction
void add_bidder() {
    if (num_bidders == MAX_BIDDERS) {
        printf("Maximum number of bidders reached. No more can be added.\n");
        return;
    }
    
    Bidder new_bidder;
    printf("Enter the name of the bidder: ");
    fgets(new_bidder.name, 50, stdin);
    printf("Enter the starting balance: ");
    scanf("%d", &new_bidder.balance);
    getchar(); // Consume the newline character left behind by scanf
    
    bidders[num_bidders] = new_bidder;
    num_bidders++;
    printf("Bidder successfully added to the auction.\n");
}

// Function for displaying all bidders currently in the auction
void view_bidders() {
    printf("%-25s %-15s %-15s\n", "BIDDER", "BALANCE", "BIDS MADE");
    for (int i = 0; i < num_bidders; i++) {
        printf("%-25s %-15d %-15d\n", bidders[i].name, bidders[i].balance, bidders[i].num_bids_made);
    }
}

// Function for a bidder to place a bid on an item
void place_bid() {
    if (num_items == 0) {
        printf("No items currently in the auction.\n");
        return;
    }
    
    char item_name[50];
    printf("Enter the name of the item: ");
    fgets(item_name, 50, stdin);
    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        printf("Item not found.\n");
        return;
    }
    
    int bidder_index = -1;
    char bidder_name[50];
    printf("Enter your name: ");
    fgets(bidder_name, 50, stdin);
    for (int i = 0; i < num_bidders; i++) {
        if (strcmp(bidder_name, bidders[i].name) == 0) {
            bidder_index = i;
            break;
        }
    }
    if (bidder_index == -1) {
        printf("Bidder not found.\n");
        return;
    }
    
    if (items[item_index].current_bid >= bidders[bidder_index].balance) {
        printf("You do not have enough balance to place a bid.\n");
        return;
    }
    
    int new_bid;
    printf("Enter your bid: ");
    scanf("%d", &new_bid);
    getchar(); // Consume the newline character left behind by scanf
    
    if (new_bid <= items[item_index].current_bid) {
        printf("Your bid must be higher than the current bid.\n");
        return;
    }
    
    items[item_index].current_bid = new_bid;
    strcpy(items[item_index].highest_bidder, bidder_name);
    bidders[bidder_index].balance -= new_bid;
    bidders[bidder_index].num_bids_made++;
    
    printf("Bid successfully placed.\n");
}

int main() {
    int choice;
    
    do {
        printf("\n-- DIGITAL AUCTION SYSTEM --\n");
        printf("1. Add item to the auction\n");
        printf("2. View all items in the auction\n");
        printf("3. Add bidder to the auction\n");
        printf("4. View all bidders in the auction\n");
        printf("5. Place a bid on an item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left behind by scanf
        
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                add_bidder();
                break;
            case 4:
                view_bidders();
                break;
            case 5:
                place_bid();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}