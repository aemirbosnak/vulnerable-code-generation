//FormAI DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10 // Maximum number of bids per item

typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    char bidder[50];
    float amount;
} Bid;

int main() {
    Item items[3] = { // Example items
        {"Smartphone", 200.00},
        {"Laptop", 500.00},
        {"Watch", 100.00}
    };
    Bid bids[MAX_BIDS];
    int numBids[MAX_BIDS]; // Number of bids for each item
    int totalBids = 0; // Total number of bids

    // Print out available items
    printf("Available items for auction:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
        numBids[i] = 0;
    }

    // Start auction
    int choice;
    char name[50];
    float amount;
    while (1) {
        printf("Enter the number of the item you want to bid on (0 to exit): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) break; // Exit if user enters 0 or invalid choice

        // Get bidder name and bid amount
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your bid amount: ");
        scanf("%f", &amount);

        // Check if bid is higher than current highest bid
        int index = choice - 1;
        int highest = -1;
        for (int i = 0; i < numBids[index]; i++) {
            if (bids[index * MAX_BIDS + i].amount > highest) {
                highest = bids[index * MAX_BIDS + i].amount;
            }
        }
        if (amount <= highest) {
            printf("Your bid must be higher than $%.2f.\n", highest);
            continue;
        }

        // Add bidder and bid to array
        Bid newBid;
        strcpy(newBid.bidder, name);
        newBid.amount = amount;
        bids[index * MAX_BIDS + numBids[index]] = newBid;
        numBids[index]++;
        totalBids++;

        // Print out highest bid so far
        printf("Current highest bid: $%.2f\n", amount);
    }

    // Print out final bids for each item
    printf("\nAuction results:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s:\n", items[i].name);
        if (numBids[i] == 0) {
            printf("No bids.\n");
        } else {
            for (int j = 0; j < numBids[i]; j++) {
                printf("%d. %s - $%.2f\n", j + 1, bids[i * MAX_BIDS + j].bidder, bids[i * MAX_BIDS + j].amount);
            }
        }
    }
    printf("Total bids: %d\n", totalBids);

    return 0;
}