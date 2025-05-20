//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of an item in the auction
typedef struct {
    char name[50];
    int bid_amount;
} Item;

// Function to compare two items based on their bid amount
int compare_items(const void* a, const void* b) {
    const Item* item_a = (const Item*)a;
    const Item* item_b = (const Item*)b;
    if (item_a->bid_amount > item_b->bid_amount) {
        return -1;
    } else if (item_a->bid_amount < item_b->bid_amount) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the items in the auction
void print_items(Item* items, int num_items) {
    printf("Items in the auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - Bid amount: %d\n", items[i].name, items[i].bid_amount);
    }
}

// Function to get the bid amount from the user
int get_bid_amount() {
    int bid_amount;
    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);
    return bid_amount;
}

// Function to conduct the auction
void conduct_auction(Item* items, int num_items) {
    // Sort the items based on their bid amount
    qsort(items, num_items, sizeof(Item), compare_items);

    // Print the items in the auction
    print_items(items, num_items);

    // Conduct the auction for each item
    for (int i = 0; i < num_items; i++) {
        printf("Auction for %s:\n", items[i].name);
        int bid_amount = get_bid_amount();
        if (bid_amount > items[i].bid_amount) {
            items[i].bid_amount = bid_amount;
        }
    }
}

// Main function
int main() {
    // Initialize the items in the auction
    Item items[] = {{"Laptop", 1000}, {"Smartphone", 500}, {"Tablet", 800}};
    int num_items = sizeof(items) / sizeof(Item);

    // Conduct the auction
    conduct_auction(items, num_items);

    // Print the final bid amounts for each item
    printf("\nFinal bid amounts:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - Bid amount: %d\n", items[i].name, items[i].bid_amount);
    }

    return 0;
}