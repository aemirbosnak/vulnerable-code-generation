//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *name;
    float price;
} Item;

// Function to compare two items by price
int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item1->price - item2->price);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of items
    Item items[] = {
        {1, "Item 1", 10.0},
        {2, "Item 2", 20.0},
        {3, "Item 3", 30.0},
        {4, "Item 4", 40.0},
        {5, "Item 5", 50.0},
    };

    // Sort the items by price
    qsort(items, sizeof(items) / sizeof(Item), sizeof(Item), compare_items);

    // Print the items
    printf("Items for auction:\n");
    for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
        printf("%d. %s: $%.2f\n", items[i].id, items[i].name, items[i].price);
    }

    // Get the user's input
    int item_id;
    float bid;
    printf("Enter the ID of the item you want to bid on: ");
    scanf("%d", &item_id);
    printf("Enter your bid: ");
    scanf("%f", &bid);

    // Check if the item ID is valid
    int found = 0;
    for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
        if (items[i].id == item_id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid item ID.\n");
        return 1;
    }

    // Check if the bid is valid
    if (bid <= items[item_id - 1].price) {
        printf("Your bid is too low.\n");
        return 1;
    }

    // Check if the bid is the highest
    int highest_bid = 0;
    for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
        if (items[i].id == item_id && items[i].price > bid) {
            highest_bid = 1;
            break;
        }
    }

    if (highest_bid) {
        printf("Your bid is not the highest.\n");
        return 1;
    }

    // Update the item's price
    items[item_id - 1].price = bid;

    // Print the winning bid
    printf("Congratulations! You have won the auction for %s with a bid of $%.2f.\n", items[item_id - 1].name, items[item_id - 1].price);

    return 0;
}