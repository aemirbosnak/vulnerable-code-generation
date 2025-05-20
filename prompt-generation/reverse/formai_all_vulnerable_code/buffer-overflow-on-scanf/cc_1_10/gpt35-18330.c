//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of items that can be auctioned
#define MAX_BIDS 10 // Maximum number of bids on an item
#define ITEM_NAME_MAX_LENGTH 50 // Maximum length of the item name
#define USER_NAME_MAX_LENGTH 20 // Maximum length of the user name

// Struct to hold the details of a bid
typedef struct {
    char username[USER_NAME_MAX_LENGTH];
    float amount;
} Bid;

// Struct to hold the details of an auction item
typedef struct {
    char name[ITEM_NAME_MAX_LENGTH];
    Bid bids[MAX_BIDS];
    int num_bids;
    float minimum_bid;
} Item;

// Global variables
Item items[MAX_ITEMS];
int num_items = 0;

// Declare functions
void print_item(Item item);
void add_item();
void display_items();
void place_bid(int item_index, char* username, float amount);

int main() {
    int choice;
    char username[USER_NAME_MAX_LENGTH];
    int selected_item_index;
    float amount;

    printf("Welcome to the Digital Auction System!\n");

    // Menu loop
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Place bid\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter the item index: ");
                scanf("%d", &selected_item_index);
                printf("Enter your bid amount: ");
                scanf("%f", &amount);
                place_bid(selected_item_index, username, amount);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Print the details of an item
void print_item(Item item) {
    printf("Item name: %s\n", item.name);
    printf("Minimum bid: $%.2f\n", item.minimum_bid);
    printf("Number of bids: %d\n", item.num_bids);

    if (item.num_bids > 0) {
        printf("Bids:\n");
        for (int i = 0; i < item.num_bids; i++) {
            printf("%s - $%.2f\n", item.bids[i].username, item.bids[i].amount);
        }
    } else {
        printf("No bids.\n");
    }
}

// Add a new item to the auction
void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
        return;
    }

    char name[ITEM_NAME_MAX_LENGTH];
    float minimum_bid;

    printf("Enter the item name: ");
    scanf("%s", name);
    printf("Enter the minimum bid: ");
    scanf("%f", &minimum_bid);

    Item item;
    strncpy(item.name, name, ITEM_NAME_MAX_LENGTH);
    item.minimum_bid = minimum_bid;
    item.num_bids = 0;

    items[num_items] = item;
    num_items++;

    printf("Item added successfully.\n");
}

// Display all items in the auction
void display_items() {
    if (num_items == 0) {
        printf("No items.\n");
        return;
    }

    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Index: %d\n", i);
        print_item(items[i]);
        printf("\n");
    }
}

// Place a bid on an item
void place_bid(int item_index, char* username, float amount) {
    if (item_index < 0 || item_index >= num_items) {
        printf("Invalid item index.\n");
        return;
    }

    Item* item = &items[item_index];

    if (amount <= item->minimum_bid) {
        printf("Bid must be greater than the minimum bid of $%.2f.\n", item->minimum_bid);
        return;
    }

    int num_bids = item->num_bids;

    if (num_bids >= MAX_BIDS) {
        printf("Maximum number of bids for this item reached.\n");
        return;
    }

    Bid bid;
    strncpy(bid.username, username, USER_NAME_MAX_LENGTH);
    bid.amount = amount;

    item->bids[num_bids] = bid;
    item->num_bids++;

    printf("Bid placed successfully.\n");
}