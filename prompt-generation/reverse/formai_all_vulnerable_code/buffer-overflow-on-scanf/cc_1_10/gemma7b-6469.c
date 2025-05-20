//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
    char bidder_name[50];
    int bid_amount;
    struct Bid* next;
} Bid;

void insertBid(Bid* head, char* bidder_name, int bid_amount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->bidder_name, bidder_name);
    newBid->bid_amount = bid_amount;
    newBid->next = NULL;

    if (head == NULL) {
        head = newBid;
    } else {
        newBid->next = head;
        head = newBid;
    }
}

int main() {
    Bid* head = NULL;
    char bidder_name[50];
    int bid_amount;
    int i;

    // Simulate some bids
    for (i = 0; i < 10; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bidder_name);

        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);

        insertBid(head, bidder_name, bid_amount);
    }

    // Print the bids
    for (head = head; head != NULL; head = head->next) {
        printf("Bidder name: %s\n", head->bidder_name);
        printf("Bid amount: %d\n", head->bid_amount);
    }

    return 0;
}