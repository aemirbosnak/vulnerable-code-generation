//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
};

void insertBidder(struct Bidder **head) {
    struct Bidder *newBidder = (struct Bidder *)malloc(sizeof(struct Bidder));
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

void printBids(struct Bidder *head) {
    struct Bidder *current = head;
    while (current) {
        printf("%s bid: %d\n", current->name, current->bid);
        current = current->next;
    }
}

int main() {
    struct Bidder *head = NULL;
    int numBids = 0;

    while (1) {
        printf("Enter 'add' to add a bidder, 'print' to print bids, or 'exit' to exit: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            insertBidder(&head);
            numBids++;
        } else if (strcmp(command, "print") == 0) {
            printBids(head);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("Thank you for bidding!\n");
    return 0;
}