//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char *name;
    int price;
} Item;

typedef struct {
    int id;
    char *name;
    int balance;
} Customer;

typedef struct {
    int id;
    Item *item;
    Customer *customer;
    int price;
} Bid;

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the auction items
    Item items[] = {
        {1, "A painting of a melting clock", 100},
        {2, "A sculpture of a lobster phone", 200},
        {3, "A pair of shoes made of cheese", 300},
        {4, "A book of poems written by a dog", 400},
        {5, "A set of golf clubs made of chocolate", 500}
    };

    // Create the customers
    Customer customers[] = {
        {1, "Alice", 1000},
        {2, "Bob", 2000},
        {3, "Carol", 3000},
        {4, "Dave", 4000},
        {5, "Eve", 5000}
    };

    // Create the bids
    Bid bids[] = {
        {1, &items[0], &customers[0], 110},
        {2, &items[1], &customers[1], 210},
        {3, &items[2], &customers[2], 310},
        {4, &items[3], &customers[3], 410},
        {5, &items[4], &customers[4], 510}
    };

    // Print the auction items
    printf("Welcome to the Surrealist Digital Auction!\n");
    printf("Here are the items up for auction:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (%d)\n", items[i].id, items[i].name, items[i].price);
    }

    // Get the user's input
    int item_id, customer_id, price;
    printf("Enter the ID of the item you want to bid on: ");
    scanf("%d", &item_id);
    printf("Enter your customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter the price you want to bid: ");
    scanf("%d", &price);

    // Check if the user's input is valid
    if (item_id < 1 || item_id > 5) {
        printf("Invalid item ID.\n");
        return 1;
    }
    if (customer_id < 1 || customer_id > 5) {
        printf("Invalid customer ID.\n");
        return 1;
    }
    if (price < items[item_id - 1].price) {
        printf("Your bid is too low.\n");
        return 1;
    }

    // Create a new bid
    Bid bid = {6, &items[item_id - 1], &customers[customer_id - 1], price};

    // Add the new bid to the list of bids
    bids[5] = bid;

    // Print the winning bid
    int winning_bid_id = -1;
    for (int i = 0; i < 6; i++) {
        if (bids[i].price > bids[winning_bid_id].price) {
            winning_bid_id = i;
        }
    }
    printf("The winning bid is:\n");
    printf("Item: %s\n", bids[winning_bid_id].item->name);
    printf("Customer: %s\n", bids[winning_bid_id].customer->name);
    printf("Price: %d\n", bids[winning_bid_id].price);

    return 0;
}