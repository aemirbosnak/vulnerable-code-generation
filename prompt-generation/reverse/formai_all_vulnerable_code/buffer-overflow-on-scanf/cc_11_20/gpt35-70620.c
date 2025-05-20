//FormAI DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Auction {
    char name[50];
    double currentPrice;
    int minutesLeft;
    char highestBidder[50];
};

int main() {
    struct Auction auctions[MAX_ITEMS];
    int itemCount = 0;

    int choice = 0;
    do {
        // Display menu
        printf("\n--------------------------------\n");
        printf("    DIGITAL AUCTION SYSTEM\n");
        printf("--------------------------------\n");
        printf("1) Add Auction Item\n");
        printf("2) View Auction Items\n");
        printf("3) Bid on Auction Item\n");
        printf("4) Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process menu choice
        switch (choice) {
            case 1: {
                // Add Auction Item
                struct Auction newItem;

                printf("\nEnter item name: ");
                scanf("%s", newItem.name);
                printf("Enter starting price: ");
                scanf("%lf", &newItem.currentPrice);
                printf("Enter number of minutes left in auction: ");
                scanf("%d", &newItem.minutesLeft);

                // Add item to array
                auctions[itemCount] = newItem;
                itemCount++;

                printf("\nItem added successfully!\n");
                break;
            }
            case 2: {
                // View Auction Items
                printf("\n------------ AUCTION ITEMS ------------\n");
                for (int i = 0; i < itemCount; i++) {
                    printf("Item Name: %s\n", auctions[i].name);
                    printf("Current Price: $%.2lf\n", auctions[i].currentPrice);
                    printf("Time Left: %d minutes\n", auctions[i].minutesLeft);
                    printf("Highest Bidder: %s\n", auctions[i].highestBidder);
                    printf("----------------------------------------\n");
                }
                break;
            }
            case 3: {
                // Bid on Auction Item
                char itemName[50];
                printf("\nEnter name of item you wish to bid on: ");
                scanf("%s", itemName);

                int itemIndex = -1;
                for (int i = 0; i < itemCount; i++) {
                    if (strcmp(auctions[i].name, itemName) == 0) {
                        itemIndex = i;
                        break;
                    }
                }

                if (itemIndex == -1) {
                    printf("\nItem not found!\n");
                } else {
                    double newBid;
                    printf("Enter your new bid: ");
                    scanf("%lf", &newBid);

                    if (newBid < auctions[itemIndex].currentPrice) {
                        printf("\nBid must be higher than current price!\n");
                    } else {
                        strcpy(auctions[itemIndex].highestBidder, "You");
                        auctions[itemIndex].currentPrice = newBid;
                        printf("\nBid accepted!\n");
                    }
                }
                break;
            }
            case 4: {
                // Quit program
                printf("\nExiting program...\n");
                break;
            }
            default: {
                // Handle invalid choice
                printf("\nInvalid choice! Try again.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}