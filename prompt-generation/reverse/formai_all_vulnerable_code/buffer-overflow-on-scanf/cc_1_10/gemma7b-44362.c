//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum bid
#define MIN_BID 10

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Function to insert a bidder into the bidding list
void insertBidder(Bidder** head) {
    Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", newBidder->name);
    printf("Enter your bid: ");
    scanf("%d", &newBidder->bid);

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
        *head = newBidder;
    }
}

// Function to find the highest bidder
Bidder* findHighestBidder(Bidder* head) {
    Bidder* highestBidder = NULL;
    for (Bidder* currentBidder = head; currentBidder; currentBidder = currentBidder->next) {
        if (highestBidder == NULL || currentBidder->bid > highestBidder->bid) {
            highestBidder = currentBidder;
        }
    }
    return highestBidder;
}

// Function to start the auction
void startAuction(Bidder** head) {
    // Insert bidders into the bidding list
    insertBidder(head);
    insertBidder(head);
    insertBidder(head);

    // Find the highest bidder
    Bidder* highestBidder = findHighestBidder(*head);

    // Announce the highest bidder
    printf("The highest bidder is: %s with a bid of %d.", highestBidder->name, highestBidder->bid);
}

int main() {
    Bidder* head = NULL;
    startAuction(&head);
    return 0;
}