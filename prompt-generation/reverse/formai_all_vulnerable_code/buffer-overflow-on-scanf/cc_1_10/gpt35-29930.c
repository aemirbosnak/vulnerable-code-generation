//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define auction item struct
typedef struct {
    char name[50];
    char description[100];
    float starting_price;
    float current_bid;
    char highest_bidder[50];
} item;

int main() {
    // initialize auction items
    item item1 = {"Antique Vase", "A beautiful, handcrafted vase from the Ming dynasty.", 100.00, 0.00, "None"};
    item item2 = {"Signed Baseball", "An autographed baseball from Babe Ruth's historic home run.", 50.00, 0.00, "None"};
    item item3 = {"Diamond Necklace", "A stunning necklace with sparkling diamonds.", 500.00, 0.00, "None"};

    // display auction items
    printf("Welcome to the Digital Auction System!\n");
    printf("We have the following items up for auction:\n\n");
    printf("1. %s\nDescription: %s\nStarting Price: $%.2f\n\n", item1.name, item1.description, item1.starting_price);
    printf("2. %s\nDescription: %s\nStarting Price: $%.2f\n\n", item2.name, item2.description, item2.starting_price);
    printf("3. %s\nDescription: %s\nStarting Price: $%.2f\n\n", item3.name, item3.description, item3.starting_price);

    // auction items
    int choice;
    float bid;
    char name[50];

    // loop until user decides to exit
    do {
        // prompt user for choice
        printf("Enter the number of the item you would like to bid on (enter 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            // case for item 1
            case 1:
                printf("Item: %s\nCurrent Bid: $%.2f\nHighest Bidder: %s\n", item1.name, item1.current_bid, item1.highest_bidder);
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid: $");
                scanf("%f", &bid);

                if (bid > item1.current_bid) {
                    item1.current_bid = bid;
                    strcpy(item1.highest_bidder, name);
                    printf("Congratulations, you are currently the highest bidder for %s!\n", item1.name);
                } else {
                    printf("Sorry, your bid is not high enough.\n");
                }
                break;

            // case for item 2
            case 2:
                printf("Item: %s\nCurrent Bid: $%.2f\nHighest Bidder: %s\n", item2.name, item2.current_bid, item2.highest_bidder);
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid: $");
                scanf("%f", &bid);

                if (bid > item2.current_bid) {
                    item2.current_bid = bid;
                    strcpy(item2.highest_bidder, name);
                    printf("Congratulations, you are currently the highest bidder for %s!\n", item2.name);
                } else {
                    printf("Sorry, your bid is not high enough.\n");
                }
                break;

            // case for item 3
            case 3:
                printf("Item: %s\nCurrent Bid: $%.2f\nHighest Bidder: %s\n", item3.name, item3.current_bid, item3.highest_bidder);
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid: $");
                scanf("%f", &bid);

                if (bid > item3.current_bid) {
                    item3.current_bid = bid;
                    strcpy(item3.highest_bidder, name);
                    printf("Congratulations, you are currently the highest bidder for %s!\n", item3.name);
                } else {
                    printf("Sorry, your bid is not high enough.\n");
                }
                break;

            // default case to exit
            default:
                printf("Thank you for participating in the auction!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}