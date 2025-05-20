//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the maximum number of items
#define MAX_ITEMS 5

// Define the structure of a bidder
typedef struct bidder {
    char name[20];
    int bid;
    struct bidder* next;
} bidder;

// Define the structure of an item
typedef struct item {
    char name[20];
    int starting_price;
    int current_price;
    struct item* next;
} item;

// Function to add a bidder to the bidding list
void add_bidder(bidder** head) {
    // Allocate memory for the new bidder
    bidder* new_bidder = (bidder*)malloc(sizeof(bidder));

    // Get the bidder's name and bid
    printf("Enter your name: ");
    scanf("%s", new_bidder->name);

    printf("Enter your bid: ");
    scanf("%d", &new_bidder->bid);

    // Add the new bidder to the list
    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

// Function to add an item to the auction
void add_item(item** head) {
    // Allocate memory for the new item
    item* new_item = (item*)malloc(sizeof(item));

    // Get the item's name and starting price
    printf("Enter the item name: ");
    scanf("%s", new_item->name);

    printf("Enter the starting price: ");
    scanf("%d", &new_item->starting_price);

    // Add the new item to the list
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Function to start the auction
void start_auction(item** head, bidder** head_bidder) {
    // Iterate over the items
    for (item* item = *head; item != NULL; item = item->next) {
        // Iterate over the bidders
        for (bidder* bidder = *head_bidder; bidder != NULL; bidder = bidder->next) {
            // Place the bidder's bid on the item
            if (bidder->bid > item->current_price) {
                item->current_price = bidder->bid;
            }
        }

        // Print the item's current price
        printf("Item: %s, Current Price: %d\n", item->name, item->current_price);
    }

    // Print the winner of the auction
    printf("The winner of the auction is: %s\n", (*head_bidder)->name);
}

int main() {
    // Create the bidding list
    bidder* head_bidder = NULL;

    // Create the auction items
    item* head_item = NULL;

    // Add bidders and items to the auction
    add_bidder(&head_bidder);
    add_item(&head_item);
    add_bidder(&head_bidder);
    add_item(&head_item);

    // Start the auction
    start_auction(&head_item, &head_bidder);

    return 0;
}