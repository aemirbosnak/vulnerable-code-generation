//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: satisfied
/*
 * C Digital Auction System Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for items to be auctioned off
typedef struct {
    char name[50];
    int price;
    int quantity;
} Item;

// Define struct for bidders
typedef struct {
    char name[50];
    int bid;
} Bidder;

// Function to read in items from file
void read_items(Item *items, int *num_items) {
    FILE *fp;
    char line[100];
    int i = 0;

    // Open file for reading
    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read in items from file
    while (fgets(line, 100, fp) != NULL) {
        if (sscanf(line, "%s %d %d", items[i].name, &items[i].price, &items[i].quantity) != 3) {
            printf("Error reading from file\n");
            return;
        }
        i++;
    }
    *num_items = i;

    // Close file
    fclose(fp);
}

// Function to read in bidders from file
void read_bidders(Bidder *bidders, int *num_bidders) {
    FILE *fp;
    char line[100];
    int i = 0;

    // Open file for reading
    fp = fopen("bidders.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read in bidders from file
    while (fgets(line, 100, fp) != NULL) {
        if (sscanf(line, "%s %d", bidders[i].name, &bidders[i].bid) != 2) {
            printf("Error reading from file\n");
            return;
        }
        i++;
    }
    *num_bidders = i;

    // Close file
    fclose(fp);
}

// Function to place bids
void place_bids(Item *items, int num_items, Bidder *bidders, int num_bidders) {
    int i, j;

    // Loop through items
    for (i = 0; i < num_items; i++) {
        // Loop through bidders
        for (j = 0; j < num_bidders; j++) {
            // Check if bidder has enough money
            if (bidders[j].bid >= items[i].price) {
                // Bidder has enough money, place bid
                printf("Bidder %s has placed a bid of $%d on item %s\n", bidders[j].name, items[i].price, items[i].name);
                // Update bidder's balance
                bidders[j].bid -= items[i].price;
                // Update item's quantity
                items[i].quantity--;
                // Check if item has sold out
                if (items[i].quantity == 0) {
                    printf("Item %s has sold out\n", items[i].name);
                }
                break;
            }
        }
    }
}

int main() {
    // Define variables
    Item items[10];
    int num_items = 0;
    Bidder bidders[10];
    int num_bidders = 0;

    // Read in items from file
    read_items(items, &num_items);

    // Read in bidders from file
    read_bidders(bidders, &num_bidders);

    // Place bids
    place_bids(items, num_items, bidders, num_bidders);

    return 0;
}