//FormAI DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_NAME_LENGTH 20
#define ITEM_NAME_LENGTH 30

// Data structure to hold information about an auction item
struct AuctionItem {
    char name[ITEM_NAME_LENGTH];
    double current_bid;
    int current_bidder;
    int num_bids;
    int bidder_ids[MAX_BIDDERS];
    double bid_values[MAX_BIDDERS];
};

// Function to display the menu options and get user input
int display_menu() {
    printf("\n1. Add Item\n");
    printf("2. Bid on Item\n");
    printf("3. Display Items\n");
    printf("4. Quit\n\n");
    printf("Please enter your choice: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to add a new item to the auction
void add_item(struct AuctionItem *items, int *num_items) {
    if (*num_items == MAX_BIDDERS) {
        printf("Sorry, the maximum number of items has been reached.\n");
        return;
    }

    printf("Please enter the name of the item: ");
    scanf("%s", items[*num_items].name);

    items[*num_items].current_bid = 0;
    items[*num_items].current_bidder = -1;
    items[*num_items].num_bids = 0;

    (*num_items)++;
    printf("Item added successfully!\n");
}

// Function to print the current bid status of an item
void print_item(struct AuctionItem item) {
    printf("%s\n", item.name);
    printf("---------------------------\n");
    printf("Current Bid: $%.2f\n", item.current_bid);

    if (item.current_bidder == -1) {
        printf("No bids yet!\n");
    } else {
        printf("Current Bidder: %d\n", item.current_bidder);
    }
}

// Function to display all the auction items
void display_items(struct AuctionItem *items, int num_items) {
    if (num_items == 0) {
        printf("No items in the auction!\n");
        return;
    }

    printf("\nCurrent Auction Items:\n");
    printf("---------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d. ", i+1);
        print_item(items[i]);
        printf("\n");
    }
}

// Function to determine the index of an item given its name
int find_item_index(struct AuctionItem *items, int num_items, char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to place a bid on an item
void bid_on_item(struct AuctionItem *items, int num_items) {
    if (num_items == 0) {
        printf("No items to bid on!\n");
        return;
    }

    char item_name[ITEM_NAME_LENGTH];
    printf("Please enter the name of the item you would like to bid on: ");
    scanf("%s", item_name);

    int item_index = find_item_index(items, num_items, item_name);
    if (item_index == -1) {
        printf("Item not found!\n");
        return;
    }

    double bid_value;
    printf("Please enter your bid: $");
    scanf("%lf", &bid_value);

    int bidder_id;
    printf("Please enter your bidder ID (between 1 and %d): ", MAX_BIDDERS);
    scanf("%d", &bidder_id);

    if (bidder_id < 1 || bidder_id > MAX_BIDDERS) {
        printf("Invalid bidder ID! Please try again.\n");
        return;
    }

    if (items[item_index].current_bid >= bid_value) {
        printf("Sorry, your bid must be higher than the current bid.\n");
        return;
    }

    items[item_index].current_bid = bid_value;
    items[item_index].current_bidder = bidder_id;
    items[item_index].bidder_ids[items[item_index].num_bids] = bidder_id;
    items[item_index].bid_values[items[item_index].num_bids] = bid_value;
    items[item_index].num_bids++;

    printf("Bid placed successfully!\n");
}

int main() {
    int num_items = 0;
    struct AuctionItem items[MAX_BIDDERS];

    while (1) {
        int choice = display_menu();

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                bid_on_item(items, num_items);
                break;
            case 3:
                display_items(items, num_items);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}