//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

typedef struct Bid {
    char bidder[20];
    int amount;
    struct Bid* next;
} Bid;

Bid* createBid(char* bidder, int amount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->bidder, bidder);
    newBid->amount = amount;
    newBid->next = NULL;
    return newBid;
}

void addBid(Bid* head, Bid* newBid) {
    if (head == NULL) {
        head = newBid;
    } else {
        head->next = newBid;
        head = newBid;
    }
}

int main() {
    Bid* head = NULL;
    int i = 0;
    char bidder[20];
    int amount;

    // Simulate some bids
    for (i = 0; i < MAX_BIDS; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bidder);

        printf("Enter bid amount: ");
        scanf("%d", &amount);

        addBid(head, createBid(bidder, amount));
    }

    // Print all bids
    printf("All bids:\n");
    for (head = head->next; head; head = head->next) {
        printf("Bidder: %s, Amount: %d\n", head->bidder, head->amount);
    }

    return 0;
}