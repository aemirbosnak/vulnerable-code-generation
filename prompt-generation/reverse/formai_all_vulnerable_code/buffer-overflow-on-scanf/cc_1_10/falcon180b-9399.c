//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int bid;
} Bidder;

void addBid(Bidder* bidders, int numBidders, char* name, int bid) {
    int i;
    for (i = 0; i < numBidders; i++) {
        if (strcmp(bidders[i].name, name) == 0) {
            bidders[i].bid = bid;
            return;
        }
    }
    strcpy(bidders[numBidders].name, name);
    bidders[numBidders].bid = bid;
    numBidders++;
}

void printBidders(Bidder* bidders, int numBidders) {
    int i;
    printf("Bidders:\n");
    for (i = 0; i < numBidders; i++) {
        printf("%s: $%d\n", bidders[i].name, bidders[i].bid);
    }
}

void auction(char* item, Bidder* bidders, int numBidders) {
    int i, highestBid = 0, highestBidder = -1;
    printf("Auction for %s:\n", item);
    printBidders(bidders, numBidders);
    while (1) {
        printf("Enter your bid (0 to quit): $");
        scanf("%d", &i);
        if (i == 0) break;
        addBid(bidders, numBidders, "You", i);
        printBidders(bidders, numBidders);
        if (i > highestBid) {
            highestBid = i;
            highestBidder = numBidders - 1;
        }
    }
    printf("Highest bid: $%d by %s\n", highestBid, bidders[highestBidder].name);
}

int main() {
    Bidder bidders[100];
    int numBidders = 0;
    char item[50];
    printf("Enter item name: ");
    scanf("%s", item);
    while (1) {
        printf("Enter bidder name (0 to start auction): ");
        scanf("%s", item);
        if (strcmp(item, "0") == 0) break;
        addBid(bidders, numBidders, item, 0);
        numBidders++;
    }
    auction(item, bidders, numBidders);
    return 0;
}