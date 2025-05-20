//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char name[50];
    float bid;
} Bidder;

typedef struct {
    char name[50];
    float price;
    int num_bidders;
    Bidder bidders[10];
} Item;

// Function prototypes
void welcome_message();
void add_item(Item *items, int *num_items);
void display_items(const Item *items, int num_items);
void place_bid(Item *items, int num_items);
void determine_winner(const Item *items, int num_items);

// Main function
int main() {
    // Welcome message
    welcome_message();

    // Initialize the auction
    Item items[10];
    int num_items = 0;

    // Add items to the auction
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // Display the items in the auction
    printf("Welcome to the auction! Here are the items up for bid:\n");
    display_items(items, num_items);

    // Allow users to place bids
    place_bid(items, num_items);

    // Determine the winners of the auction
    determine_winner(items, num_items);

    return 0;
}

// Function definitions
void welcome_message() {
    printf("Welcome to the most awesome digital auction system ever! Get ready to bid on some amazing items!\n");
}

void add_item(Item *items, int *num_items) {
    char name[50];
    float price;
    printf("Enter the name of the item: ");
    scanf("%s", name);
    printf("Enter the starting price of the item: ");
    scanf("%f", &price);
    strcpy(items[*num_items].name, name);
    items[*num_items].price = price;
    items[*num_items].num_bidders = 0;
    (*num_items)++;
}

void display_items(const Item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%.2f\n", items[i].name, items[i].price);
    }
}

void place_bid(Item *items, int num_items) {
    char item_name[50];
    float bid;
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);
    printf("Enter your bid: ");
    scanf("%f", &bid);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            if (bid > items[i].price) {
                items[i].bidders[items[i].num_bidders].bid = bid;
                strcpy(items[i].bidders[items[i].num_bidders].name, "You");
                items[i].num_bidders++;
                items[i].price = bid;
                printf("Your bid has been placed!\n");
            } else {
                printf("Your bid is too low. Please try again.\n");
            }
        }
    }
}

void determine_winner(const Item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].num_bidders > 0) {
            printf("The winner of the %s is %s with a bid of $%.2f!\n", items[i].name, items[i].bidders[items[i].num_bidders - 1].name, items[i].price);
        } else {
            printf("No one bid on the %s.\n", items[i].name);
        }
    }
}