//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10  // maximum number of bids allowed
#define MAX_LEN 50   // maximum length of item name

// structures for auction items and bids
struct item {
    char name[MAX_LEN];
    float current_bid;
    char highest_bidder[MAX_LEN];
};

struct bid {
    char bidder[MAX_LEN];
    float bid_amount;
};

// function prototypes
int add_item(struct item items[], int num_items);
void list_items(struct item items[], int num_items);
int place_bid(struct item items[], int num_items, int item_idx);
void list_bids(struct item items[], int num_items, int item_idx);

// main function
int main(void) {
    struct item items[MAX_BIDS];
    int num_items = 0;
    int item_idx, choice;

    printf("Welcome to the digital auction system!\n\n");

    while (1) {
        // display menu options
        printf("Menu:\n");
        printf("1. Add item\n");
        printf("2. List items\n");
        printf("3. Place bid\n");
        printf("4. List bids\n");
        printf("5. Exit\n\n");

        // get user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                num_items = add_item(items, num_items);
                break;
            case 2:
                list_items(items, num_items);
                break;
            case 3:
                printf("Enter the index of the item you want to bid on: ");
                scanf("%d", &item_idx);
                item_idx--;  // convert to zero-based index
                if (item_idx >= 0 && item_idx < num_items) {
                    place_bid(items, num_items, item_idx);
                } else {
                    printf("Invalid item index!\n");
                }
                break;
            case 4:
                printf("Enter the index of the item you want to see bids for: ");
                scanf("%d", &item_idx);
                item_idx--;  // convert to zero-based index
                if (item_idx >= 0 && item_idx < num_items) {
                    list_bids(items, num_items, item_idx);
                } else {
                    printf("Invalid item index!\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }

    return 0;
}

// function to add a new item to the auction
int add_item(struct item items[], int num_items) {
    char name[MAX_LEN];
    float starting_bid;
    
    // get item information from user
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter starting bid: ");
    scanf("%f", &starting_bid);
    
    // add item to array
    strcpy(items[num_items].name, name);
    items[num_items].current_bid = starting_bid;
    strcpy(items[num_items].highest_bidder, "");
    
    num_items++;
    printf("Item added successfully!\n");
    
    return num_items;
}

// function to list all items in the auction
void list_items(struct item items[], int num_items) {
    int i;

    printf("Current items in auction:\n\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s\tCurrent bid: %.2f\tHighest bidder: %s\n", 
            i+1, items[i].name, items[i].current_bid, items[i].highest_bidder);
    }
}

// function to place a bid on an item
int place_bid(struct item items[], int num_items, int item_idx) {
    struct bid b;
    float new_bid;

    // get bid information from user
    printf("Enter your name: ");
    scanf("%s", b.bidder);
    printf("Enter your bid amount: ");
    scanf("%f", &new_bid);

    // check if bid is higher than current high bid
    if (new_bid <= items[item_idx].current_bid) {
        printf("Your bid must be higher than the current bid!\n");
        return 0;
    }

    // update item's bid information
    items[item_idx].current_bid = new_bid;
    strcpy(items[item_idx].highest_bidder, b.bidder);
    printf("Bid placed successfully!\n");

    return 1;
}

// function to list all bids on an item
void list_bids(struct item items[], int num_items, int item_idx) {
    int i;

    printf("Bids for item %d (%s):\n\n", item_idx+1, items[item_idx].name);
    for (i = 0; i < num_items; i++) {
        if (i == item_idx) {
            printf("%s: %.2f\n", items[i].highest_bidder, items[i].current_bid);
        }
    }
}