//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
#define WELCOME "Welcome to the Digital Auction System!"
#define ITEM_NAME "Enter item name: "
#define ITEM_QTY "Enter item quantity: "
#define ITEM_PRICE "Enter item price: "
#define ITEM_SOLD "Item sold!"

// Menu options
#define OPTION_ADD_ITEM 1
#define OPTION_REMOVE_ITEM 2
#define OPTION_LIST_ITEMS 3
#define OPTION_BID_ITEM 4
#define OPTION_EXIT 5

// Item struct
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item;

// Global array of items
item items[100];

// Global variables
int num_items = 0;
int highest_bid = 0;
char highest_bidder[50];

// Function to add an item to the array
void add_item() {
    printf(ITEM_NAME);
    scanf("%s", items[num_items].name);
    printf(ITEM_QTY);
    scanf("%d", &items[num_items].quantity);
    printf(ITEM_PRICE);
    scanf("%f", &items[num_items].price);
    num_items++;
}

// Function to remove an item from the array
void remove_item() {
    char name[50];
    int i;
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i] = items[num_items - 1];
            num_items--;
            break;
        }
    }
}

// Function to list all items in the array
void list_items() {
    int i;
    printf("Name\tQuantity\tPrice\n");
    for (i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to bid on an item
void bid_item() {
    char name[50];
    float bid;
    int i;
    printf("Enter the name of the item to bid on: ");
    scanf("%s", name);
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Current price: %.2f\n", items[i].price);
            printf("Enter your bid: ");
            scanf("%f", &bid);
            if (bid > items[i].price) {
                highest_bid = bid;
                strcpy(highest_bidder, name);
            }
            break;
        }
    }
}

// Function to print the highest bid
void print_highest_bid() {
    if (highest_bid > 0) {
        printf("%s has the highest bid of %.2f on %s\n", highest_bidder, highest_bid, items[highest_bid].name);
    } else {
        printf("No bids yet.\n");
    }
}

// Main function
int main() {
    int choice;
    do {
        // Print welcome message
        puts(WELCOME);
        // Print menu options
        printf("1. Add item\n2. Remove item\n3. List items\n4. Bid on item\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Call the appropriate function based on the user's choice
        switch (choice) {
            case OPTION_ADD_ITEM:
                add_item();
                break;
            case OPTION_REMOVE_ITEM:
                remove_item();
                break;
            case OPTION_LIST_ITEMS:
                list_items();
                break;
            case OPTION_BID_ITEM:
                bid_item();
                break;
            case OPTION_EXIT:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != OPTION_EXIT);
    // Print the highest bid
    print_highest_bid();
    return 0;
}