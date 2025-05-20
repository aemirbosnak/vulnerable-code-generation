//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000 // maximum bidding amount
#define TOTAL_ITEMS 5 // total number of items up for auction

// struct to hold item information
typedef struct Item {
    char name[30];
    int starting_bid;
    int current_bid;
    char bidder_name[30];
} Item;

void get_bidding_details(Item *item); // function to get bidding details for an item
void display_items(Item *items); // function to display all items
void display_item_details(Item item); // function to display details of a specific item
void print_separator(); // function to print a separator line

int main() {
    Item items[TOTAL_ITEMS];
    strcpy(items[0].name, "Painting");
    items[0].starting_bid = 100;
    items[0].current_bid = 0;
    strcpy(items[1].name, "Antique Vase");
    items[1].starting_bid = 200;
    items[1].current_bid = 0;
    strcpy(items[2].name, "Rare Book");
    items[2].starting_bid = 150;
    items[2].current_bid = 0;
    strcpy(items[3].name, "Gold Watch");
    items[3].starting_bid = 500;
    items[3].current_bid = 0;
    strcpy(items[4].name, "Diamond Ring");
    items[4].starting_bid = 1000;
    items[4].current_bid = 0;

    display_items(items);

    int choice;
    printf("Enter item number to bid on (or 0 to exit): ");
    scanf("%d", &choice);
    while (choice != 0) {
        Item item = items[choice-1];
        get_bidding_details(&item);
        items[choice-1] = item;
        display_item_details(item);
        display_items(items);

        printf("Enter item number to bid on (or 0 to exit): ");
        scanf("%d", &choice);
    }
    return 0;
}

void get_bidding_details(Item *item) {
    srand(time(NULL));
    int random_number = rand() % 50;
    printf("Minimum bid is %d\n", item->starting_bid + random_number);

    printf("Enter your name: ");
    scanf("%s", item->bidder_name);

    printf("Enter your bid amount (max %d): ", MAX_BID);
    scanf("%d", &item->current_bid);

    while (item->current_bid < item->starting_bid + random_number || item->current_bid > MAX_BID) {
        printf("Invalid bid. Enter your bid amount (max %d): ", MAX_BID);
        scanf("%d", &item->current_bid);
    }
}

void display_items(Item *items) {
    print_separator();
    printf("Items for Auction:\n");
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        printf("%d. %s\n", i+1, items[i].name);
    }
    print_separator();
}

void display_item_details(Item item) {
    print_separator();
    printf("Details for %s:\n", item.name);
    printf("Starting bid: %d\n", item.starting_bid);
    printf("Current bid: %d\n", item.current_bid);
    printf("Bidder name: %s\n", item.bidder_name);
    print_separator();
}

void print_separator() {
    printf("-------------------------\n");
}