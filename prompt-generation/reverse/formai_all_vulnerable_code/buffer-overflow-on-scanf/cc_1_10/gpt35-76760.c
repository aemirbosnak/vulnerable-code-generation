//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int item_number;
    char item_name[20];
    float starting_bid;
    float current_bid;
    char bidder_name[20];
} Item;

Item items[10]; // an array to store 10 auction items

int main() {
    // initialize the auction items
    items[0].item_number = 1;
    strcpy(items[0].item_name, "Antique Vase");
    items[0].starting_bid = 100.00;

    items[1].item_number = 2;
    strcpy(items[1].item_name, "Rare Stamp Collection");
    items[1].starting_bid = 200.00;

    items[2].item_number = 3;
    strcpy(items[2].item_name, "Limited Edition Watch");
    items[2].starting_bid = 300.00;

    items[3].item_number = 4;
    strcpy(items[3].item_name, "Vintage Car");
    items[3].starting_bid = 10000.00;

    items[4].item_number = 5;
    strcpy(items[4].item_name, "Top-of-the-line Smartphone");
    items[4].starting_bid = 700.00;

    items[5].item_number = 6;
    strcpy(items[5].item_name, "Signed Sports Memorabilia");
    items[5].starting_bid = 500.00;

    items[6].item_number = 7;
    strcpy(items[6].item_name, "Designer Handbag");
    items[6].starting_bid = 400.00;

    items[7].item_number = 8;
    strcpy(items[7].item_name, "Artwork by Famous Artist");
    items[7].starting_bid = 1000.00;

    items[8].item_number = 9;
    strcpy(items[8].item_name, "Rare Gemstone");
    items[8].starting_bid = 5000.00;

    items[9].item_number = 10;
    strcpy(items[9].item_name, "Luxury Vacation Package");
    items[9].starting_bid = 2000.00;

    printf("Welcome to the Digital Auction System\n");
    printf("We have 10 items up for auction today:\n");

    // print out the list of items
    for (int i=0; i<10; i++) {
        printf("%d: %s - Starting bid: $%.2f\n", items[i].item_number, items[i].item_name, items[i].starting_bid);
    }

    int item_choice;
    float bid_amount;

    // loop through the auction items
    for (int i=0; i<10; i++) {
        printf("\n");
        printf("Auctioning item %d: %s\n", items[i].item_number, items[i].item_name);
        printf("Starting bid: $%.2f\n", items[i].starting_bid);
        printf("Current bid: $%.2f\n", items[i].current_bid);

        // ask for bid on the item
        printf("Enter your bid for this item (or 0 to pass): ");
        scanf("%f", &bid_amount);

        // if bid is below current bid or starting bid
        if (bid_amount < items[i].starting_bid || bid_amount < items[i].current_bid) {
            printf("Bid must be higher than current bid and starting bid.\n");
            printf("Item %d: %s - Base bid: $%.2f, Current bid: $%.2f\n", items[i].item_number, items[i].item_name, items[i].starting_bid, items[i].current_bid);
            printf("Enter your bid for this item (or 0 to pass): ");
            scanf("%f", &bid_amount);
        }

        // if bid is acceptable
        if (bid_amount >= items[i].starting_bid && bid_amount > items[i].current_bid) {
            printf("\nCongrats, you are the highest bidder!\n");
            printf("Current bid for %s: $%.2f\n", items[i].item_name, bid_amount);
            printf("Please enter your name: ");
            char bidder_name[20];
            scanf("%s", bidder_name);
            strcpy(items[i].bidder_name, bidder_name);
            items[i].current_bid = bid_amount;
        }
    }

    // print out the final results
    printf("\n");
    printf("Final Results:\n");
    for (int i=0; i<10; i++) {
        printf("%s - Highest bid: $%.2f by %s\n", items[i].item_name, items[i].current_bid, items[i].bidder_name);
    }

    return 0;
}