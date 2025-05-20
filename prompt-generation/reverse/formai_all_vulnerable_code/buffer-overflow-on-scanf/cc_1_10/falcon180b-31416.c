//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int bid;
    int id;
} Bidder;

void displayBidders(Bidder bidders[], int n) {
    printf("Bidders:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - $%d\n", i+1, bidders[i].name, bidders[i].bid);
    }
}

int compareBids(const void *a, const void *b) {
    Bidder *bidA = (Bidder *)a;
    Bidder *bidB = (Bidder *)b;
    return bidB->bid - bidA->bid;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter number of bidders: ");
    scanf("%d", &n);
    Bidder bidders[n];
    for (int i = 0; i < n; i++) {
        printf("Enter name of bidder %d: ", i+1);
        scanf("%s", bidders[i].name);
        printf("Enter initial bid of bidder %d: ", i+1);
        scanf("%d", &bidders[i].bid);
        bidders[i].id = i+1;
    }
    int itemPrice = 1000;
    int highestBid = 0;
    int highestBidderId = 0;
    while (highestBid < itemPrice) {
        displayBidders(bidders, n);
        printf("\nEnter your bid: ");
        int bid;
        scanf("%d", &bid);
        for (int i = 0; i < n; i++) {
            if (bidders[i].bid == bid) {
                highestBid = bid;
                highestBidderId = i+1;
                break;
            }
        }
        if (highestBid < itemPrice) {
            printf("Current highest bid: $%d by bidder %d\n", highestBid, highestBidderId);
        }
    }
    printf("\nHighest bid: $%d by bidder %d\n", highestBid, highestBidderId);
    return 0;
}