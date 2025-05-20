//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID_SIZE 5
#define MAX_NAME_SIZE 20
#define AUCTION_SIZE 10

typedef struct {
    int bid;
    char bidderName[MAX_NAME_SIZE];
} Bid;

typedef struct {
    char itemName[MAX_NAME_SIZE];
    Bid bids[MAX_BID_SIZE];
    int bidSize;
} Auction;

Auction auctions[AUCTION_SIZE];
int auctionSize = 0;

void addAuction(char *name) {
    if (auctionSize < AUCTION_SIZE) {
        Auction auction;
        strcpy(auction.itemName, name);
        auction.bidSize = 0;
        auctions[auctionSize++] = auction;
        printf("Auction for %s has been created.\n", name);
    } else {
        printf("Maximum auction limit has been reached.\n");
    }
}

void addBid(int auctionIndex, int amount, char *bidderName) {
    if (auctionIndex >= 0 && auctionIndex < auctionSize) {
        Auction *auction = &auctions[auctionIndex];
        if (auction->bidSize < MAX_BID_SIZE) {
            Bid bid;
            bid.bid = amount;
            strcpy(bid.bidderName, bidderName);
            auction->bids[auction->bidSize++] = bid;
            printf("Bid of %d has been added to the auction of %s by %s.\n", amount, auction->itemName, bidderName);
        } else {
            printf("Maximum bid limit has been reached for the auction of %s.\n", auction->itemName);
        }
    } else {
        printf("Invalid auction index.\n");
    }
}

void listAuctions() {
    if (auctionSize > 0) {
        printf("Auctions:\n");
        for (int i = 0; i < auctionSize; i++) {
            Auction *auction = &auctions[i];
            printf("%d. %s\n", i+1, auction->itemName);
            if (auction->bidSize > 0) {
                printf("Bids:\n");
                for (int j = 0; j < auction->bidSize; j++) {
                    Bid *bid = &auction->bids[j];
                    printf("%s - $%d\n", bid->bidderName, bid->bid);
                }
            } else {
                printf("No bids.\n");
            }
        }
    } else {
        printf("No auctions available.\n");
    }
}

int main() {
    char c;
    char input[50];
    int auctionIndex, amount;
    char bidderName[MAX_NAME_SIZE];
    while (1) {
        printf("Enter command (add auction, add bid, list auctions, exit): ");
        scanf(" %[^\n]s", input);
        if (strcmp(input, "add auction") == 0) {
            printf("Enter item name: ");
            scanf(" %[^\n]s", input);
            addAuction(input);
        }
        else if (strcmp(input, "add bid") == 0) {
            printf("Enter auction index: ");
            scanf("%d", &auctionIndex);
            printf("Enter bid amount: ");
            scanf("%d", &amount);
            printf("Enter bidder name: ");
            scanf(" %[^\n]s", bidderName);
            addBid(auctionIndex-1, amount, bidderName);
        }
        else if (strcmp(input, "list auctions") == 0) {
            listAuctions();
        }
        else if (strcmp(input, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}