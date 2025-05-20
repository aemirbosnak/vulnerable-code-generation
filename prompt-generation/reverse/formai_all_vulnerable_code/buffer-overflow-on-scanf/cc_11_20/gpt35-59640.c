//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Auction {
    char itemName[50];
    int currentBid;
    char highestBidder[30];
} Auction;

int main() {
    Auction auctionList[10];
    int menuChoice, numOfAuctions = 0;

    while(1) {
        printf("Digital Auction System\n");
        printf("-----------------------\n");
        printf("1. Add new item for auction\n");
        printf("2. List all items in auction\n");
        printf("3. Bid for an item\n");
        printf("4. Quit\n");
        printf("Choice: ");
        scanf("%d", &menuChoice);
        printf("\n");

        switch(menuChoice) {
            case 1: {
                if(numOfAuctions >= 10) {
                    printf("Maximum auction limit reached.\n\n");
                    break;
                }
                Auction newAuction;
                printf("Enter item name: ");
                scanf("%s", newAuction.itemName);
                printf("Enter starting bid: ");
                scanf("%d", &newAuction.currentBid);
                strcpy(newAuction.highestBidder, "No bids yet");
                auctionList[numOfAuctions++] = newAuction;
                printf("Item added successfully.\n\n");
                break;
            }
            case 2: {
                if(numOfAuctions == 0) {
                    printf("No items available for auction.\n\n");
                    break;
                }
                printf("List of items in auction:\n");
                for(int i=0; i<numOfAuctions; i++) {
                    printf("Item #%d -> Name: %s, Current Bid: $%d, Highest Bidder: %s\n", (i+1), auctionList[i].itemName, auctionList[i].currentBid, auctionList[i].highestBidder);
                }
                printf("\n");
                break;
            }
            case 3: {
                if(numOfAuctions == 0) {
                    printf("No items available for auction.\n\n");
                    break;
                }
                char itemName[50];
                printf("Enter item name to bid for: ");
                scanf("%s", itemName);

                int index = -1;
                for(int i=0; i<numOfAuctions; i++) {
                    if(strcmp(auctionList[i].itemName, itemName) == 0) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("No such item available for auction.\n\n");
                    break;
                }
                printf("Current bid for item %s: $%d\n", itemName, auctionList[index].currentBid);

                int newBid;
                printf("Enter your new bid: $");
                scanf("%d", &newBid);

                if(newBid > auctionList[index].currentBid) {
                    strcpy(auctionList[index].highestBidder, "You");
                    auctionList[index].currentBid = newBid;
                    printf("Bid successful. You are currently the highest bidder for %s.\n\n", itemName);
                } else {
                    printf("Your bid must be higher than the current bid.\n\n");
                }
                break;
            }
            case 4: {
                printf("Thank you for using our digital auction system!\n");
                exit(0);
            }
            default: {
                printf("Invalid input.\n\n");
                break;
            }
        }
    }
    return 0;
}