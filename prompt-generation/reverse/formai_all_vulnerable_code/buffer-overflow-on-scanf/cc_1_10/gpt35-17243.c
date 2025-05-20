//FormAI DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_AUCTIONS 100
#define MAX_BIDDERS 20

// Structure to hold auction information
struct Auction {
    int auctionId;
    char itemName[20];
    float startingBid;
    float currentBid;
    char sellerName[20];
    char auctionStatus[20];
};

// Structure to hold bidder information
struct Bidder {
    int bidderId;
    char bidderName[20];
    float maxBidAmount;
    float currentBid;
};

// Declare arrays to hold auctions and bidders
struct Auction auctions[MAX_AUCTIONS];
struct Bidder bidders[MAX_BIDDERS];

// Declare counters to keep track of number of auctions and bidders
int auctionCount = 0;
int bidderCount = 0;

// Function to display list of active auctions
void displayAuctions() {
    printf("\nActive Auctions\n---------------------------\n");
    printf("Auction ID\tItem Name\tCurrent Bid\n");
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].auctionStatus, "active") == 0) {
            printf("%d\t\t%s\t\t%.2f\n", auctions[i].auctionId, auctions[i].itemName, auctions[i].currentBid);
        }
    }
}

// Function to display list of bidders
void displayBidders() {
    printf("\nList of Bidders\n---------------------------\n");
    printf("Bidder ID\tBidder Name\n");
    for (int i = 0; i < bidderCount; i++) {
        printf("%d\t\t%s\n", bidders[i].bidderId, bidders[i].bidderName);
    }
}

// Function to start a new auction
void startAuction() {
    if (auctionCount < MAX_AUCTIONS) {
        struct Auction newAuction;
        newAuction.auctionId = auctionCount + 1;
        printf("\nEnter details for new auction:\n");
        printf("Item Name: ");
        scanf("%s", newAuction.itemName);
        printf("Starting Bid: ");
        scanf("%f", &newAuction.startingBid);
        newAuction.currentBid = newAuction.startingBid;
        printf("Seller Name: ");
        scanf("%s", newAuction.sellerName);
        strcpy(newAuction.auctionStatus, "active");
        auctions[auctionCount] = newAuction;
        auctionCount++;
        printf("\nNew auction started successfully!\n");
    } else {
        printf("\nUnable to start a new auction, Maximum limit reached!\n");
    }
}

// Function to place a bid
void placeBid() {
    int auctionId, bidderId;
    bool found = false;
    printf("\nEnter Auction ID: ");
    scanf("%d", &auctionId);
    for (int i = 0; i < auctionCount; i++) {
        if (auctions[i].auctionId == auctionId) {
            found = true;
            if (strcmp(auctions[i].auctionStatus, "active") == 0) {
                printf("Enter Bidder ID: ");
                scanf("%d", &bidderId);
                for (int j = 0; j < bidderCount; j++) {
                    if (bidders[j].bidderId == bidderId) {
                        printf("Enter Bid Amount: ");
                        scanf("%f", &bidders[j].currentBid);
                        if (bidders[j].currentBid > auctions[i].currentBid && bidders[j].currentBid <= bidders[j].maxBidAmount) {
                            printf("\nBid placed successfully!\n");
                            auctions[i].currentBid = bidders[j].currentBid;
                        } else {
                            printf("\nBid amount is less than current bid or exceeds bidder's max bid amount.\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("\nBidder not found!\n");
                }
            } else {
                printf("\nAuction already closed.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("\nAuction not found!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nDigital Auction System\n---------------------------\n");
        printf("1. Display Active Auctions\n");
        printf("2. Display List of Bidders\n");
        printf("3. Start a New Auction\n");
        printf("4. Place a Bid\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayAuctions();
                break;
                
            case 2:
                displayBidders();
                break;
                
            case 3:
                startAuction();
                break;
                
            case 4:
                placeBid();
                break;
                
            case 5:
                printf("\nGoodbye!\n");
                break;
                
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}