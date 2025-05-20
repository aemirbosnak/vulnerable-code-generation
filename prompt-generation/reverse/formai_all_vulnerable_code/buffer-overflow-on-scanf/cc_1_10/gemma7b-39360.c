//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[50];
    int bid;
    struct Bidder *next;
} Bidder;

void insertBidder(Bidder **head) {
    Bidder *newBidder = (Bidder *)malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", newBidder->name);
    printf("Enter your bid: ");
    scanf("%d", &newBidder->bid);
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void printBids(Bidder *head) {
    while (head) {
        printf("Name: %s, Bid: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {
    Bidder *head = NULL;
    int auctionEnd = 0;

    while (!auctionEnd) {
        insertBidder(&head);
        printf("Would you like to continue bidding? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N') {
            auctionEnd = 1;
        }
    }

    printBids(head);

    return 0;
}