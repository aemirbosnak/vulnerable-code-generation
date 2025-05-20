//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

void placeBid(struct Bidder** head, int bid, char* name) {
    struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

int main() {
    struct Bidder* head = NULL;
    int currentBid = 0;
    char name[20];

    // Auction loop
    while (1) {
        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter your bid: ");
        scanf("%d", &currentBid);

        placeBid(&head, currentBid, name);

        // Check if the current bid is the highest bid
        if (currentBid > MAX_BID) {
            printf("Congratulations, you have won the auction!\n");
            break;
        }

        printf("The current highest bid is: $%d\n", head->bid);
    }

    return 0;
}