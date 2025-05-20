//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int bid;
} Bidder;

void addBidder(Bidder* bidders, int size, char* name, int bid) {
    for (int i = 0; i < size; i++) {
        if (strcmp(bidders[i].name, name) == 0) {
            bidders[i].bid = bid;
            return;
        }
    }
    strcpy(bidders[size].name, name);
    bidders[size].bid = bid;
    size++;
}

void displayBidders(Bidder* bidders, int size) {
    printf("Bidders:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: $%d\n", bidders[i].name, bidders[i].bid);
    }
}

int main() {
    srand(time(NULL));
    Bidder bidders[100];
    int size = 0;

    addBidder(bidders, size, "Alice", rand() % 100 + 1);
    addBidder(bidders, size, "Bob", rand() % 100 + 1);
    addBidder(bidders, size, "Charlie", rand() % 100 + 1);

    displayBidders(bidders, size);

    int itemPrice = rand() % 1000 + 1;
    printf("\nItem price: $%d\n", itemPrice);

    int highestBid = 0;
    char highestBidder[50] = "";

    while (1) {
        printf("\nEnter your bid (0 to quit): ");
        int bid = 0;
        scanf("%d", &bid);
        if (bid == 0) break;

        for (int i = 0; i < size; i++) {
            if (bidders[i].bid > bid) {
                bidders[i].bid = bid;
            }
        }

        if (bid > highestBid) {
            highestBid = bid;
            strcpy(highestBidder, bidders[size - 1].name);
        }

        displayBidders(bidders, size);
    }

    printf("\nHighest bid: $%d by %s\n", highestBid, highestBidder);

    return 0;
}