//FormAI DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Auction {
    char itemID[10];
    char itemName[50];
    int startingBid;
    int currentBid;
    char bidder[50];
    char status[10];
} Auction;

void createAuction(Auction *auction) {
    printf("Enter Item ID: ");
    scanf("%s", auction->itemID);
    printf("Enter Item Name: ");
    scanf("%s", auction->itemName);
    printf("Enter Starting Bid: ");
    scanf("%d", &auction->startingBid);
    printf("Auction Created Successfully!\n");
}

int bidAuction(Auction *auction, char bidder[50], int bid) {
    if (bid <= auction->currentBid) {
        printf("Bid must be greater than the current highest bid of %d\n", auction->currentBid);
        return 0;
    } else if (bid < auction->startingBid) {
        printf("Bid must be greater than or equal to the starting bid of %d\n", auction->startingBid);
        return 0;
    } else {
        auction->currentBid = bid;
        strcpy(auction->bidder, bidder);
        printf("Bid Placed Successfully!\n");
        return 1;
    }
}

void printAuction(Auction auction) {
    printf("\nItem ID: %s\nItem Name: %s\nStarting Bid: %d\nCurrent Bid: %d\nCurrent Highest Bidder: %s\nStatus: %s\n", auction.itemID, auction.itemName, auction.startingBid, auction.currentBid, auction.bidder, auction.status);
}

int main(void) {
    int choice, i, index, auctionCount = 0, bid;
    char bidder[50];
    Auction auctions[100];
    srand(time(NULL));
    do {
        printf("\n1. Create Auction\n2. Bid on Auction\n3. Print All Auctions\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAuction(&auctions[auctionCount]);
                auctions[auctionCount].currentBid = auctions[auctionCount].startingBid;
                strcpy(auctions[auctionCount].status, "Active");
                auctionCount++;
                break;
            case 2:
                if (auctionCount == 0) {
                    printf("There are no auctions to bid on\n");
                } else {
                    printf("Enter the Item ID: ");
                    char itemID[10];
                    scanf("%s", itemID);
                    for (i = 0; i < auctionCount; i++) {
                        if (strcmp(auctions[i].itemID, itemID) == 0) {
                            index = i;
                            break;
                        }
                    }
                    if (i == auctionCount) {
                        printf("Invalid Item ID\n");
                    } else {
                        printf("Enter your name: ");
                        scanf("%s", bidder);
                        printf("Enter your bid: ");
                        scanf("%d", &bid);
                        if (bidAuction(&auctions[index], bidder, bid)) {
                            strcpy(auctions[index].status, "Active");
                            for (i = 0; i < auctionCount; i++) {
                                if (i != index && strcmp(auctions[index].itemName, auctions[i].itemName) == 0) {
                                    int randomBid = rand() % (bid + 1 - auctions[i].startingBid) + auctions[i].startingBid;
                                    bidAuction(&auctions[i], "RandomBidder", randomBid);
                                }
                            }
                        }
                    }
                }
                break;
            case 3:
                if (auctionCount == 0) {
                    printf("There are no auctions to print\n");
                } else {
                    for (i = 0; i < auctionCount; i++) {
                        printAuction(auctions[i]);
                    }
                }
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}