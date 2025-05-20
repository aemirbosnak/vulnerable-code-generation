//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BIDS 10
#define MAX_NAME_LENGTH 20

struct Bid {
    char name[MAX_NAME_LENGTH];
    double amount;
};

struct Auction {
    char itemName[MAX_NAME_LENGTH];
    double startingPrice;
    double highestBid;
    char highestBidder[MAX_NAME_LENGTH];
    int numBids;
    struct Bid bids[MAX_BIDS];
};

void printAuction(struct Auction a) {
    printf("Item name: %s\n", a.itemName);
    printf("Starting price: $%.2lf\n", a.startingPrice);
    printf("Highest bid: $%.2lf\n", a.highestBid);
    printf("Bidder name: %s\n", a.highestBidder);
    printf("Number of bids: %d\n", a.numBids);
    printf("Bids:\n");
    for (int i = 0; i < a.numBids; i++) {
        printf("%s bid $%.2lf\n", a.bids[i].name, a.bids[i].amount);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}

bool isValidBid(double bid, struct Auction a) {
    if (bid <= a.highestBid || bid < a.startingPrice) {
        return false;
    } else {
        return true;
    }
}

bool hasBidderBidBefore(char *name, struct Auction a) {
    for (int i = 0; i < a.numBids; i++) {
        if (strcmp(name, a.bids[i].name) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    struct Auction laptopAuction = {
        "Laptop",
        500.00,
        500.00,
        "Starting bidder",
        0,
        {}
    };

    srand(time(NULL)); // using current time as seed for random number generation

    printf("Welcome to the digital auction system!\n");

    while (true) {
        printAuction(laptopAuction);
        printf("Enter bidder name (or 'exit' to quit): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        clearInputBuffer();

        if (hasBidderBidBefore(name, laptopAuction)) {
            printf("Sorry, you have already bid on this item.\n");
            continue;
        }

        printf("Enter bid amount: ");
        double bid;
        scanf("%lf", &bid);
        clearInputBuffer();

        if (isValidBid(bid, laptopAuction)) {
            printf("Congratulations, %s! Your bid of $%.2lf is the new highest bid.\n", name, bid);
            laptopAuction.highestBid = bid;
            strcpy(laptopAuction.highestBidder, name);
            strcpy(laptopAuction.bids[laptopAuction.numBids].name, name);
            laptopAuction.bids[laptopAuction.numBids].amount = bid;
            laptopAuction.numBids++;
        } else {
            printf("Sorry, your bid was not high enough.\n");
        }

        if (rand() % 10 == 0) {
            double newStartingPrice = laptopAuction.highestBid * 1.1;
            printf("Attention bidders! The starting price for the %s has been increased to $%.2lf.\n", laptopAuction.itemName, newStartingPrice);
            laptopAuction.startingPrice = newStartingPrice;
        }
    }

    return 0;
}