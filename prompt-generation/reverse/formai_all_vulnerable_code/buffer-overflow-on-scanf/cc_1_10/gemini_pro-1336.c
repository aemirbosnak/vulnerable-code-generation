//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct item {
    int item_id;
    char item_name[50];
    float item_price;
} item;

// Function to compare two bids
int compare_bids(const void *a, const void *b) {
    return ((*(item *)b).item_price - (*(item *)a).item_price);
}

int main() {
    // Declare variables
    int num_items, num_bids;
    item *items, *bids;

    // Get number of items and bids
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter number of bids: ");
    scanf("%d", &num_bids);

    // Allocate memory for items and bids
    items = (item *)malloc(sizeof(item) * num_items);
    bids = (item *)malloc(sizeof(item) * num_bids);

    // Get item details
    printf("Enter item details:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Enter item ID: ");
        scanf("%d", &items[i].item_id);
        printf("Enter item name: ");
        scanf("%s", items[i].item_name);
        printf("Enter item price: ");
        scanf("%f", &items[i].item_price);
    }

    // Get bid details
    printf("Enter bid details:\n");
    for (int i = 0; i < num_bids; i++) {
        printf("Bid %d:\n", i + 1);
        printf("Enter item ID: ");
        scanf("%d", &bids[i].item_id);
        printf("Enter bid price: ");
        scanf("%f", &bids[i].item_price);
    }

    // Sort bids in descending order of bid price
    qsort(bids, num_bids, sizeof(item), compare_bids);

    // Match bids to items
    for (int i = 0; i < num_bids; i++) {
        for (int j = 0; j < num_items; j++) {
            if (bids[i].item_id == items[j].item_id) {
                if (bids[i].item_price >= items[j].item_price) {
                    // Bid is accepted
                    printf("Bid %d accepted for item %s at price %.2f\n", i + 1, items[j].item_name, bids[i].item_price);
                } else {
                    // Bid is rejected
                    printf("Bid %d rejected for item %s as bid price %.2f is less than item price %.2f\n", i + 1, items[j].item_name, bids[i].item_price, items[j].item_price);
                }
                break;
            }
        }
    }

    // Free allocated memory
    free(items);
    free(bids);

    return 0;
}