//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
// Ken Thompson-style Digital Auction System Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our struct for item information
struct Item {
    char name[50];
    char description[100];
    double startingBid;
    double currentBid;
    char highestBidder[50];
};

// Define function for displaying item information
void displayItem(struct Item item) {
    printf("\nItem: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Starting Bid: $%.2f\n", item.startingBid);
    printf("Current Bid: $%.2f\n", item.currentBid);
    printf("Highest Bidder: %s\n", item.highestBidder);
}

int main() {
    struct Item item1 = {"Baseball Card Collection", "Collection of rare baseball cards from the 1950s and 1960s", 50.00, 0.00, ""};
    struct Item item2 = {"Signed Basketball", "Signed by NBA player Michael Jordan, with certificate of authenticity", 500.00, 0.00, ""};
    struct Item item3 = {"Vintage Comic Collection", "Collection of vintage comics from the Golden Age of comic books", 100.00, 0.00, ""};

    while (1) {
        // Display auction menu and ask for user input
        printf("\n\n****** Digital Auction System ******\n\n");
        printf("1. View Current Items\n");
        printf("2. Bid On Item\n");
        printf("3. Exit\n");
        printf("\nSelect an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\nCurrent Items:\n");
                displayItem(item1);
                displayItem(item2);
                displayItem(item3);
                break;
            case 2:
                printf("\n\nEnter Item Number (1-3): ");
                int itemNum;
                scanf("%d", &itemNum);

                struct Item *selectedItem;
                if (itemNum == 1) {
                    selectedItem = &item1;
                } else if (itemNum == 2) {
                    selectedItem = &item2;
                } else if (itemNum == 3) {
                    selectedItem = &item3;
                } else {
                    printf("\nInvalid Item Number.");
                    break;
                }

                printf("\nEnter Bid Amount: ");
                double bidAmount;
                scanf("%lf", &bidAmount);

                if (bidAmount > selectedItem->currentBid) {
                    strcpy(selectedItem->highestBidder, "You");
                    selectedItem->currentBid = bidAmount;
                    printf("\nCongratulations! You are now the highest bidder for %s.\n", selectedItem->name);
                } else {
                    printf("\nYour bid must be higher than the current bid of $%.2f.\n", selectedItem->currentBid);
                }
                break;
            case 3:
                printf("\nExiting program. Goodbye!");
                exit(0);
            default:
                printf("\nInvalid Choice. Try again.");
                break;
        }
    }

    return 0;
}