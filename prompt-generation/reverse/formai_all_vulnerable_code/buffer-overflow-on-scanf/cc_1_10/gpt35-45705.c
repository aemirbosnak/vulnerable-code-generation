//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_LEN 50
#define MAX_USERS 10
#define MAX_ITEMS 5

// declare structs
typedef struct {
    char name[MAX_LEN];
    int bid_amount;
} Bid;

typedef struct {
    char name[MAX_LEN];
    Bid bids[MAX_USERS];
    int num_bids;
    int highest_bid;
} Item;

// declare global variables
Item items[MAX_ITEMS];
int num_items = 0;

// declare functions
void add_item(char name[MAX_LEN]);
void add_bid(char item_name[MAX_LEN], char user[MAX_LEN], int bid_amount);
void display_item(char item_name[MAX_LEN]);
void display_all_items();

// main function
int main(void) {
    int choice, bid_amount;
    char name[MAX_LEN], item_name[MAX_LEN], user[MAX_LEN];
    
    // display menu and get user input
    do {
        printf("\nDigital Auction System Menu:\n");
        printf("1. Add new item\n");
        printf("2. Place a bid\n");
        printf("3. Display item details\n");
        printf("4. Display all items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // execute chosen option
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                add_item(name);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter your name: ");
                scanf("%s", user);
                printf("Enter your bid amount: ");
                scanf("%d", &bid_amount);
                add_bid(item_name, user, bid_amount);
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", item_name);
                display_item(item_name);
                break;
            case 4:
                display_all_items();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);   // exit loop when user chooses to exit
    
    return 0;
}

// function to add a new item to the auction system
void add_item(char name[MAX_LEN]) {
    // check if maximum number of items has been reached
    if (num_items >= MAX_ITEMS) {
        printf("Sorry, maximum number of items reached.\n");
    }
    else {
        // add new item to array and increase item count
        strcpy(items[num_items].name, name);
        items[num_items].num_bids = 0;
        items[num_items].highest_bid = 0;
        num_items++;
        printf("Item added to auction system.\n");
    }
}

// function to add a new bid to an existing item in the auction system
void add_bid(char item_name[MAX_LEN], char user[MAX_LEN], int bid_amount) {
    int i, j, item_index = -1, user_index = -1;
    
    // find index of item in array
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }
    
    // if item not found, display error message
    if (item_index == -1) {
        printf("Item not found in auction system.\n");
    }
    else {
        // find index of user's bid in item's bids array (if it exists)
        for (j = 0; j < items[item_index].num_bids; j++) {
            if (strcmp(items[item_index].bids[j].name, user) == 0) {
                user_index = j;
                break;
            }
        }
        
        // if user has already placed a bid, update it if new bid amount is higher
        if (user_index != -1) {
            if (bid_amount > items[item_index].bids[user_index].bid_amount) {
                items[item_index].bids[user_index].bid_amount = bid_amount;
                printf("Bid updated.\n");
            }
            else {
                printf("Your bid amount is not higher than your previous bid.\n");
            }
        }
        // otherwise, add new bid to item's bids array and increase bid count
        else {
            if (items[item_index].num_bids >= MAX_USERS) {
                printf("Sorry, maximum number of bids for this item reached.\n");
            }
            else {
                strcpy(items[item_index].bids[items[item_index].num_bids].name, user);
                items[item_index].bids[items[item_index].num_bids].bid_amount = bid_amount;
                items[item_index].num_bids++;
                printf("Bid placed.\n");
            }
        }
        
        // update highest bid for item
        if (bid_amount > items[item_index].highest_bid) {
            items[item_index].highest_bid = bid_amount;
        }
    }
}

// function to display details of a specified item in the auction system
void display_item(char item_name[MAX_LEN]) {
    int i, j, item_index = -1;
    
    // find index of item in array
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }
    
    // if item not found, display error message
    if (item_index == -1) {
        printf("Item not found in auction system.\n");
    }
    else {
        // display item name and highest bid
        printf("Item name: %s\n", items[item_index].name);
        printf("Highest bid: $%d\n", items[item_index].highest_bid);
        
        // display each user's name and bid amount for the item
        printf("Bids:\n");
        for (j = 0; j < items[item_index].num_bids; j++) {
            printf("%s: $%d\n", items[item_index].bids[j].name, items[item_index].bids[j].bid_amount);
        }
    }
}

// function to display details of all items in the auction system
void display_all_items() {
    int i, j;
    
    // display item name, highest bid (if any), and number of bids for each item
    for (i = 0; i < num_items; i++) {
        printf("\nItem name: %s\n", items[i].name);
        
        if (items[i].highest_bid == 0) {
            printf("No bids have been placed for this item.\n");
        }
        else {
            printf("Highest bid: $%d\n", items[i].highest_bid);
        }
        
        printf("Number of bids: %d\n", items[i].num_bids);
    }
}