//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct bidder {
    char name[50];
    int bid;
    struct bidder *next;
} bidder;

bidder *head = NULL;
bidder *current = NULL;
bidder *winner = NULL;

void addBidder(char *name, int bid) {
    bidder *newBidder = (bidder *)malloc(sizeof(bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (head == NULL) {
        head = newBidder;
        current = newBidder;
    } else {
        current->next = newBidder;
        current = newBidder;
    }
}

void findWinner() {
    bidder *temp = head;
    int maxBid = 0;

    while (temp != NULL) {
        if (temp->bid > maxBid) {
            maxBid = temp->bid;
            winner = temp;
        }
        temp = temp->next;
    }
}

void printWinner() {
    if (winner != NULL) {
        printf("\nThe winner is: %s with a bid of: %d", winner->name, winner->bid);
    } else {
        printf("\nNo bidders found.");
    }
}

int main() {
    char name[50];
    int bid;
    int choice;

    while (1) {
        printf("\n1. Register Bid\n2. Show Winner\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid: ");
                scanf("%d", &bid);
                addBidder(name, bid);
                break;
            case 2:
                findWinner();
                printWinner();
                break;
            case 3:
                if (head != NULL) {
                    bidder *temp = head;
                    while (temp != NULL) {
                        bidder *next = temp->next;
                        free(temp);
                        temp = next;
                    }
                    head = NULL;
                    current = NULL;
                    winner = NULL;
                }
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}