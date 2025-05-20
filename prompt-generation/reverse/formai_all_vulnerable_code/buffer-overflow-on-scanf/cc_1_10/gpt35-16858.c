//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for the program
#define BID_START 100
#define BID_INCREMENT 10
#define MAX_BID 1000

// define a struct to hold the details of an auction item
struct AuctionItem {
    char name[50];
    int currentBid;
};

// function to initialize an auction item
void initializeAuctionItem(struct AuctionItem* item, char* name) {
    strcpy(item->name, name);
    item->currentBid = BID_START;
}

// function to print the details of an auction item
void printAuctionItem(struct AuctionItem item) {
    printf("%s is currently at %d\n", item.name, item.currentBid);
}

int main() {
    // initialize the auction item
    struct AuctionItem item;
    initializeAuctionItem(&item, "Painting");

    // seed the random number generator
    srand(time(0));

    // get user input (if they want to bid or not)
    int wantToBid;
    printf("Do you want to bid on %s? (1 for yes, 0 for no)\n", item.name);
    scanf("%d", &wantToBid);

    // if the user wants to bid, start the auction process
    if (wantToBid) {
        int bid;
        do {
            // print the current bid
            printAuctionItem(item);

            // get the user's bid
            printf("Enter your bid (must be at least %d and less than or equal to %d): ", item.currentBid + BID_INCREMENT, MAX_BID);
            scanf("%d", &bid);

            // generate a random number to represent the bid from someone else
            int otherBid = rand() % (MAX_BID - item.currentBid) + item.currentBid + BID_INCREMENT;

            // print the other bid
            printf("The current high bid from someone else is %d\n", otherBid);

            // compare the bids and update the high bid if needed
            if (bid > item.currentBid && bid > otherBid) {
                item.currentBid = bid;
                printf("Congratulations, you are the highest bidder at %d\n", item.currentBid);
            } else {
                printf("Sorry, your bid was not high enough. The current high bid is %d\n", item.currentBid);
            }
        } while (item.currentBid < MAX_BID);

        printf("The auction for %s is now closed. The final bid was %d\n", item.name, item.currentBid);
    } else { // if the user doesn't want to bid
        printf("Okay, maybe next time.\n");
    }

    return 0;
}