//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int bid;
} Bid;

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
    Bid bids[MAX_BIDS];
    int num_bids;
} Item;

// Function prototypes
void print_welcome();
void add_item(Item *items, int *num_items);
void print_items(const Item *items, int num_items);
void add_bid(Item *items, int num_items, const char *item_name, const char *bidder_name, int bid);
void print_bids(const Item *item);
void find_winner(const Item *items, int num_items, Item **winner_item, Bid **winning_bid);

int main() {
    // Print welcome message
    print_welcome();

    // Create an array of items
    Item items[MAX_ITEMS];

    // Initialize the number of items to 0
    int num_items = 0;

    // Add some items to the array
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // Print the list of items
    print_items(items, num_items);

    // Get bids from users
    char bidder_name[MAX_NAME_LEN];
    int bid;
    char item_name[MAX_NAME_LEN];
    while (true) {
        printf("Enter your name: ");
        scanf("%s", bidder_name);

        printf("Enter the name of the item you want to bid on: ");
        scanf("%s", item_name);

        printf("Enter your bid: ");
        scanf("%d", &bid);

        add_bid(items, num_items, item_name, bidder_name, bid);

        printf("Do you want to continue bidding? (y/n) ");
        char answer;
        scanf(" %c", &answer);
        if (tolower(answer) == 'n') {
            break;
        }
    }

    // Find the winner of each item
    Item *winner_item;
    Bid *winning_bid;
    for (int i = 0; i < num_items; i++) {
        find_winner(&items[i], 1, &winner_item, &winning_bid);

        printf("The winner of %s is %s with a bid of %d\n", winner_item->name, winning_bid->name, winning_bid->bid);
    }

    return 0;
}

void print_welcome() {
    printf("Welcome to the Digital Auction System!\n");
    printf("This system allows you to bid on items and find out who has won each item.\n");
    printf("To get started, please add some items to the auction.\n");
}

void add_item(Item *items, int *num_items) {
    char name[MAX_NAME_LEN];
    int price;

    printf("Enter the name of the item: ");
    scanf("%s", name);

    printf("Enter the starting price of the item: ");
    scanf("%d", &price);

    strcpy(items[*num_items].name, name);
    items[*num_items].price = price;
    items[*num_items].num_bids = 0;

    (*num_items)++;
}

void print_items(const Item *items, int num_items) {
    printf("The following items are up for auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - Starting price: %d\n", items[i].name, items[i].price);
    }
}

void add_bid(Item *items, int num_items, const char *item_name, const char *bidder_name, int bid) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            if (items[i].num_bids < MAX_BIDS) {
                strcpy(items[i].bids[items[i].num_bids].name, bidder_name);
                items[i].bids[items[i].num_bids].bid = bid;
                items[i].num_bids++;
            } else {
                printf("Sorry, there are no more bids allowed for this item.\n");
            }
            break;
        }
    }
}

void print_bids(const Item *item) {
    printf("The current bids for %s are:\n", item->name);
    for (int i = 0; i < item->num_bids; i++) {
        printf("%s - %d\n", item->bids[i].name, item->bids[i].bid);
    }
}

void find_winner(const Item *items, int num_items, Item **winner_item, Bid **winning_bid) {
    *winning_bid = NULL;

    for (int i = 0; i < num_items; i++) {
        if (items[i].num_bids > 0) {
            if (*winning_bid == NULL || items[i].bids[items[i].num_bids - 1].bid > (*winning_bid)->bid) {
                *winner_item = &items[i];
                *winning_bid = &items[i].bids[items[i].num_bids - 1];
            }
        }
    }
}