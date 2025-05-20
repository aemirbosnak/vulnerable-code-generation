//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define MAX_USERS 50
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_LENGTH];
    Bid bids[MAX_BIDS];
    int bidCount;
} AuctionItem;

AuctionItem auction;

void initializeAuction(const char *itemName) {
    strcpy(auction.itemName, itemName);
    auction.bidCount = 0;
    printf("Auction initialized for %s. Let's start bidding!\n", auction.itemName);
}

void placeBid(char *username, float amount) {
    if (auction.bidCount >= MAX_BIDS) {
        printf("Maximum bids reached. Cannot place more bids.\n");
        return;
    }

    for (int i = 0; i < auction.bidCount; i++) {
        if (strcmp(auction.bids[i].username, username) == 0) {
            printf("You have already placed a bid, please increase your bid amount instead.\n");
            return;
        }
    }

    Bid newBid;
    strcpy(newBid.username, username);
    newBid.bidAmount = amount;
    auction.bids[auction.bidCount] = newBid;
    auction.bidCount++;

    printf("Bid placed successfully by %s: $%.2f\n", username, amount);
}

void displayHighestBid() {
    if (auction.bidCount == 0) {
        printf("No bids placed yet for %s.\n", auction.itemName);
        return;
    }

    float highestBid = auction.bids[0].bidAmount;
    char highestBidder[MAX_LENGTH];
    strcpy(highestBidder, auction.bids[0].username);

    for (int i = 1; i < auction.bidCount; i++) {
        if (auction.bids[i].bidAmount > highestBid) {
            highestBid = auction.bids[i].bidAmount;
            strcpy(highestBidder, auction.bids[i].username);
        }
    }

    printf("The highest bid for %s is $%.2f by %s.\n", auction.itemName, highestBid, highestBidder);
}

void listBidders() {
    if (auction.bidCount == 0) {
        printf("No bids placed yet for %s.\n", auction.itemName);
        return;
    }

    printf("Bidders for %s:\n", auction.itemName);
    for (int i = 0; i < auction.bidCount; i++) {
        printf("%s: $%.2f\n", auction.bids[i].username, auction.bids[i].bidAmount);
    }
}

int main() {
    char itemName[MAX_LENGTH];
    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the name of the item for auction: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    initializeAuction(itemName);

    while (1) {
        printf("\nOptions:\n");
        printf("1. Place a Bid\n");
        printf("2. Show Highest Bid\n");
        printf("3. List All Bidders\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        if (choice == 4) {
            printf("Thank you for using the Digital Auction System! Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: {
                char username[MAX_LENGTH];
                float amount;

                printf("Enter your username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline character

                printf("Enter your bid amount: $");
                scanf("%f", &amount);
                getchar(); // Consume newline character

                if (amount <= 0) {
                    printf("Bid amount must be greater than zero.\n");
                } else {
                    placeBid(username, amount);
                }
                break;
            }
            case 2:
                displayHighestBid();
                break;
            case 3:
                listBidders();
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}