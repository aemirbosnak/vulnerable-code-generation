//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

typedef struct Bidder {
    char name[50];
    int bid;
    struct Bidder* next;
} Bidder;

void insertBidder(Bidder** head) {
    Bidder* newBidder = malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", newBidder->name);
    printf("Enter your bid: ");
    scanf("%d", &newBidder->bid);

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void printBids(Bidder* head) {
    printf("Bids:\n");
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {
    Bidder* head = NULL;

    printf("Welcome to the Digital Auction System!\n");
    printf("Enter 'insert' to insert a bid, 'print' to see all bids, or 'exit' to exit:\n");

    char command;
    scanf("%c", &command);

    while (command != 'exit') {
        switch (command) {
            case 'insert':
                insertBidder(&head);
                break;
            case 'print':
                printBids(head);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        printf("Enter 'insert' to insert a bid, 'print' to see all bids, or 'exit' to exit:\n");
        scanf("%c", &command);
    }

    printf("Thank you for using the Digital Auction System!\n");

    return 0;
}