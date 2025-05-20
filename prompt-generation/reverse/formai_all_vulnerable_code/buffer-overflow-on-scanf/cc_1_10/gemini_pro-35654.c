//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: retro
/* Welcome to the Retro Digital Auction System! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_ITEMS 10     // Maximum number of items
#define MIN_BID 10       // Minimum bid amount
#define MAX_BID 100      // Maximum bid amount
#define AUCTION_PERIOD 60 // Auction period (in seconds)

// Item information
struct Item {
    int id;
    char name[50];
    int starting_bid;
    int current_bid;
    int highest_bidder;
};

// Function prototypes
int menu();
void create_item(struct Item *items, int *num_items);
void display_items(struct Item *items, int num_items);
void start_auction(struct Item *items, int num_items);
void bid(struct Item *items, int num_items);
void end_auction(struct Item *items, int num_items);

// Global variables
struct Item items[MAX_ITEMS];
int num_items = 0;

int main() {
    srand(time(NULL)); // Initialize random number generator

    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                create_item(items, &num_items);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                start_auction(items, num_items);
                break;
            case 4:
                bid(items, num_items);
                break;
            case 5:
                end_auction(items, num_items);
                break;
            case 6:
                printf("Exiting the Retro Digital Auction System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

int menu() {
    int choice;

    printf("-------------------------------------------------------------------------\n");
    printf("                       Retro Digital Auction System                      \n");
    printf("-------------------------------------------------------------------------\n");
    printf("1. Create Item\n");
    printf("2. Display Items\n");
    printf("3. Start Auction\n");
    printf("4. Bid on Item\n");
    printf("5. End Auction\n");
    printf("6. Exit\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void create_item(struct Item *items, int *num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Maximum number of items reached. Please remove an item before adding a new one.\n");
        return;
    }

    printf("Enter item name: ");
    scanf(" %[^'\n]%*c", items[*num_items].name);

    printf("Enter starting bid: ");
    scanf("%d", &items[*num_items].starting_bid);

    items[*num_items].id = *num_items + 1;
    items[*num_items].current_bid = items[*num_items].starting_bid;
    items[*num_items].highest_bidder = 0;

    (*num_items)++;

    printf("Item created successfully.\n");
}

void display_items(struct Item *items, int num_items) {
    if (num_items == 0) {
        printf("No items to display.\n");
        return;
    }

    printf("-------------------------------------------------------------------------\n");
    printf("| ID | Name | Starting Bid | Current Bid | Highest Bidder |\n");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("| %2d | %s | %10d | %10d | %d |\n", items[i].id, items[i].name, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder);
    }
    printf("-------------------------------------------------------------------------\n");
}

void start_auction(struct Item *items, int num_items) {
    if (num_items == 0) {
        printf("No items to auction.\n");
        return;
    }

    printf("Starting auction for the following item(s):\n");
    display_items(items, num_items);

    // Set auction start time
    time_t start_time = time(NULL);

    // Loop until auction period expires
    while (difftime(time(NULL), start_time) < AUCTION_PERIOD) {
        bid(items, num_items);
    }

    printf("Auction period has ended.\n");
}

void bid(struct Item *items, int num_items) {
    int item_id, bid_amount;

    printf("Enter item ID to bid on: ");
    scanf("%d", &item_id);

    if (item_id < 1 || item_id > num_items) {
        printf("Invalid item ID. Please enter a valid number between 1 and %d.\n", num_items);
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);

    if (bid_amount < MIN_BID || bid_amount > MAX_BID) {
        printf("Invalid bid amount. Please enter a number between %d and %d.\n", MIN_BID, MAX_BID);
        return;
    }

    // Check if bid is higher than current bid
    if (bid_amount > items[item_id - 1].current_bid) {
        items[item_id - 1].current_bid = bid_amount;
        items[item_id - 1].highest_bidder = bid_amount;

        printf("Your bid has been placed successfully.\n");
    } else {
        printf("Your bid is lower than the current bid. Please enter a higher bid.\n");
    }
}

void end_auction(struct Item *items, int num_items) {
    if (num_items == 0) {
        printf("No items to end auction for.\n");
        return;
    }

    // Display auction results
    printf("-------------------------------------------------------------------------\n");
    printf("| ID | Name | Starting Bid | Current Bid | Highest Bidder |\n");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("| %2d | %s | %10d | %10d | %d |\n", items[i].id, items[i].name, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder);
    }
    printf("-------------------------------------------------------------------------\n");

    printf("Auction ended successfully.\n");
}