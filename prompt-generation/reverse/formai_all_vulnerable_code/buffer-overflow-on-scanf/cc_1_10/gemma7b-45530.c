//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the maximum number of items
#define MAX_ITEMS 5

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Define the structure of an item
typedef struct Item {
    char name[20];
    int starting_price;
    int current_price;
    struct Item* next;
} Item;

// Function to add a bidder to the list
void add_bidder(Bidder** head) {
    Bidder* new_bidder = (Bidder*)malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", new_bidder->name);
    new_bidder->bid = 0;
    new_bidder->next = *head;
    *head = new_bidder;
}

// Function to add an item to the list
void add_item(Item** head) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    printf("Enter the name of the item: ");
    scanf("%s", new_item->name);
    printf("Enter the starting price of the item: ");
    scanf("%d", &new_item->starting_price);
    new_item->current_price = new_item->starting_price;
    new_item->next = *head;
    *head = new_item;
}

// Function to bid on an item
void bid(Item* item, Bidder* bidders) {
    printf("Enter your bid: ");
    int bid = atoi(scanf("%d"));
    for (Bidder* bidder = bidders; bidder; bidder = bidder->next) {
        if (bid > bidder->bid && bidder->name[0] != 'A') {
            bidder->bid = bid;
            printf("You are the highest bidder!\n");
        }
    }
}

// Function to start the auction
void start_auction(Item* item, Bidder* bidders) {
    printf("The auction for item '%s' has begun!\n", item->name);
    printf("Current price: $%d\n", item->current_price);
    bid(item, bidders);
    printf("The auction has ended.\n");
    printf("The winner is: %s\n", bidders->name);
    printf("The final price is: $%d\n", item->current_price);
}

int main() {
    // Create the list of bidders
    Bidder* bidders = NULL;
    add_bidder(&bidders);

    // Create the list of items
    Item* items = NULL;
    add_item(&items);

    // Start the auction
    start_auction(items, bidders);

    return 0;
}