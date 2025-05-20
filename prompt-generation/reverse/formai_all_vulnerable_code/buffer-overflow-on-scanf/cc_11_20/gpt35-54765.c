//FormAI DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[20];
    int bid;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Digital Auction System!\n");

    while(1) {
        printf("\nEnter the name of the item to be auctioned (or END to quit): ");
        char itemName[20];
        scanf("%s", itemName);

        if(strcmp(itemName, "END") == 0) {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter the starting bid for %s: ", itemName);
        int startingBid;
        scanf("%d", &startingBid);

        items[numItems].bid = startingBid;
        strcpy(items[numItems].name, itemName);

        numItems++;

        printf("%s has been added to the auction with a starting bid of %d.\n", itemName, startingBid);
    }

    if(numItems == 0) {
        printf("No items were added to the auction. Goodbye!\n");
        return 0;
    }

    printf("\nThe auction is starting!\n");

    while(numItems > 0) {
        printf("\nThe following items are up for bidding:\n");
        for(int i=0; i<numItems; i++) {
            printf("%d. %s - Current bid: %d\n", i+1, items[i].name, items[i].bid);
        }

        printf("\nEnter the number of the item you would like to bid on (or 0 to end the auction): ");
        int choice;
        scanf("%d", &choice);

        if(choice == 0)
            break;

        if(choice < 1 || choice > numItems) {
            printf("Invalid choice.\n");
            continue;
        }

        int bidAmount;
        printf("Enter your bid for %s: ", items[choice-1].name);
        scanf("%d", &bidAmount);

        if(bidAmount <= items[choice-1].bid) {
            printf("Your bid must be higher than the current bid of %d.\n", items[choice-1].bid);
        }
        else {
            items[choice-1].bid = bidAmount;
            printf("Your bid of %d has been accepted.\n", bidAmount);
        }

        int highestBid = -1;
        int highestBidIndex = -1;

        for(int i=0; i<numItems; i++) {
            if(items[i].bid > highestBid) {
                highestBid = items[i].bid;
                highestBidIndex = i;
            }
        }

        if(highestBidIndex != -1) {
            printf("\nThe current highest bid is %d for %s.\n", highestBid, items[highestBidIndex].name);
            printf("Would anyone like to bid higher? (y/n): ");
            char yesNo[2];
            scanf("%s", yesNo);

            if(strcmp(yesNo, "y") == 0) {
                continue;
            }
            else {
                printf("Sold to the highest bidder for %d: %s!\n", highestBid, items[highestBidIndex].name);

                for(int i=highestBidIndex; i<numItems-1; i++) {
                    items[i] = items[i+1];
                }

                numItems--;
            }
        }
    }

    printf("\nThe auction has ended. Thank you for using the Digital Auction System!\n");

    return 0;
}