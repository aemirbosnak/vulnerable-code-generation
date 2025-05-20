//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct Item {
    int id;
    char *name;
    double price;
} Item;

// Function to compare two items based on their prices
int compareItems(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    return item1->price - item2->price;
}

int main() {
    // Initialize the auction system
    int numItems = 5;  // Number of items in the auction
    Item items[] = {
        {1, "Painting", 100.0},
        {2, "Sculpture", 200.0},
        {3, "Vase", 50.0},
        {4, "Clock", 75.0},
        {5, "Jewelry", 150.0}
    };

    // Sort the items in ascending order of price
    qsort(items, numItems, sizeof(Item), compareItems);

    // Print the sorted items
    printf("Available items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s (%.2f)\n", items[i].id, items[i].name, items[i].price);
    }

    // Get user input
    int choice;
    double bid;
    while (1) {
        printf("\nChoose an item to bid on (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        // Check if the item exists
        if (choice < 1 || choice > numItems) {
            printf("Invalid choice. Please choose an item between 1 and %d.\n", numItems);
            continue;
        }

        // Get the user's bid
        printf("Enter your bid: ");
        scanf("%lf", &bid);

        // Check if the bid is valid
        if (bid <= items[choice - 1].price) {
            printf("Your bid is too low. Please bid higher than the current price (%.2f).\n", items[choice - 1].price);
            continue;
        }

        // Update the item's price
        items[choice - 1].price = bid;

        // Print the updated item
        printf("Your bid has been accepted. The current price for %s is %.2f.\n", items[choice - 1].name, items[choice - 1].price);
    }

    // Print the winners
    printf("\nAuction winners:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: %.2f\n", items[i].name, items[i].price);
    }

    return 0;
}