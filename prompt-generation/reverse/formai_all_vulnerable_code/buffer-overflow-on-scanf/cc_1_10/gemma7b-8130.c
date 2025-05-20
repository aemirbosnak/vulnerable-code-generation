//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the maximum number of items
#define MAX_ITEMS 5

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
} Bidder;

// Define the structure of an item
typedef struct Item {
    char name[20];
    int starting_price;
    int reserve_price;
    struct Item *next;
} Item;

// Function to insert a bidder into the bidding list
void insert_bidder(Bidder **head) {
    Bidder *new_bidder = (Bidder *)malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", new_bidder->name);
    printf("Enter your bid: ");
    scanf("%d", &new_bidder->bid);
    new_bidder->next = *head;
    *head = new_bidder;
}

// Function to insert an item into the item list
void insert_item(Item **head) {
    Item *new_item = (Item *)malloc(sizeof(Item));
    printf("Enter the item name: ");
    scanf("%s", new_item->name);
    printf("Enter the starting price: ");
    scanf("%d", &new_item->starting_price);
    printf("Enter the reserve price: ");
    scanf("%d", &new_item->reserve_price);
    new_item->next = *head;
    *head = new_item;
}

// Function to conduct the auction
void conduct_auction(Item *item, Bidder *bidders) {
    int highest_bid = item->starting_price;
    for (Bidder *bidder = bidders; bidder; bidder = bidder->next) {
        if (bidder->bid > highest_bid) {
            highest_bid = bidder->bid;
        }
    }
    if (highest_bid >= item->reserve_price) {
        printf("Congratulations, %s, you have won the auction for %s!", bidders->name, item->name);
    } else {
        printf("Sorry, %s, you have not won the auction for %s.", bidders->name, item->name);
    }
}

int main() {
    // Create the bidding list
    Bidder *bidders = NULL;

    // Create the item list
    Item *items = NULL;

    // Insert bidders and items into the lists
    insert_bidder(&bidders);
    insert_item(&items);

    // Conduct the auction
    conduct_auction(items, bidders);

    return 0;
}