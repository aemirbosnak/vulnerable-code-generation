//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID_COUNT 5 // maximum number of bids allowed
#define MAX_BID_AMOUNT 1000 // maximum bid amount allowed
#define MAX_NAME_LENGTH 20 // maximum length of a bidder's name

// struct representing a single bid
typedef struct {
    char name[MAX_NAME_LENGTH];
    int amount;
} Bid;

// struct representing the auction
typedef struct {
    Bid bids[MAX_BID_COUNT];
    int highestBid;
    int count;
} Auction;

// function to add a bid to the auction
void addBid(Auction *auction, char *name, int amount) {
    // check if bid is valid (not exceeding maximum amount and not exceeding number of allowed bids)
    if (amount <= MAX_BID_AMOUNT && auction->count < MAX_BID_COUNT) {
        Bid newBid = {name, amount};
        auction->bids[auction->count] = newBid;
        auction->count++;
        
        // update the highest bid if necessary
        if (amount > auction->highestBid) {
            auction->highestBid = amount;
        }
        
        printf("%s has made a bid of %d\n", name, amount);
    } else {
        printf("%s's bid is invalid\n", name);
    }
}

// function to print the current status of the auction
void printStatus(Auction *auction) {
    printf("Highest bid: %d\n", auction->highestBid);
    printf("Bids:\n");
    for (int i = 0; i < auction->count; i++) {
        printf("%s: %d\n", auction->bids[i].name, auction->bids[i].amount);
    }
}

int main() {
    // initialize the auction
    Auction auction = {{}, 0, 0};
    
    // prompt for bids until user enters "quit"
    char name[MAX_NAME_LENGTH];
    int amount;
    while (strcmp(name, "quit") != 0) {
        printf("Enter bidder name (or 'quit' to end): ");
        scanf("%s", name);
        if (strcmp(name, "quit") != 0) {
            printf("Enter bid amount: ");
            scanf("%d", &amount);
            addBid(&auction, name, amount);
        }
    }
    
    // print final status of auction
    printf("Auction closed\n");
    printStatus(&auction);
    
    return 0;
}