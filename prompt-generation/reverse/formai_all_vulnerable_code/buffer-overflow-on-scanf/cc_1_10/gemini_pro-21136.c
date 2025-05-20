//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct item {
    int id;
    char name[50];
    float starting_price;
    float current_bid;
    int highest_bidder;
} item_t;

// Function to compare items by current bid
int compare_items(const void *a, const void *b) {
    item_t *item1 = (item_t *)a;
    item_t *item2 = (item_t *)b;

    return item2->current_bid - item1->current_bid;
}

// Function to conduct the auction
void conduct_auction(item_t *items, int num_items) {
    // Sort the items in descending order of current bid
    qsort(items, num_items, sizeof(item_t), compare_items);

    // Iterate over the sorted items and conduct the auction for each item
    for (int i = 0; i < num_items; i++) {
        item_t *item = &items[i];

        // Print the item details
        printf("Item ID: %d\n", item->id);
        printf("Item Name: %s\n", item->name);
        printf("Starting Price: %.2f\n", item->starting_price);
        printf("Current Bid: %.2f\n", item->current_bid);

        // Get the highest bid from the user
        float bid;
        printf("Enter your bid: ");
        scanf("%f", &bid);

        // Check if the bid is valid
        if (bid < item->current_bid) {
            printf("Invalid bid. Bid must be higher than the current bid.\n");
            continue;
        }

        // Update the current bid and highest bidder
        item->current_bid = bid;
        item->highest_bidder = i + 1;

        // Print the updated bid details
        printf("Current Bid: %.2f\n", item->current_bid);
        printf("Highest Bidder: %d\n\n", item->highest_bidder);
    }
}

int main() {
    // Initialize the items
    item_t items[] = {
        {1, "Painting", 100.0f, 100.0f, 0},
        {2, "Sculpture", 200.0f, 200.0f, 0},
        {3, "Vase", 50.0f, 50.0f, 0},
        {4, "Clock", 75.0f, 75.0f, 0},
        {5, "Book", 25.0f, 25.0f, 0}
    };

    int num_items = sizeof(items) / sizeof(items[0]);

    // Conduct the auction
    conduct_auction(items, num_items);

    return 0;
}