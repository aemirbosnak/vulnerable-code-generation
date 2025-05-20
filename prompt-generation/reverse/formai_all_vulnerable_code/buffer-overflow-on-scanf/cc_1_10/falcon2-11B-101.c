//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int bid;
} Bidder;

typedef struct {
    int id;
    char name[50];
    int price;
} Item;

Bidder bidder[MAX_BIDDERS];
Item item[MAX_ITEMS];

int main() {
    srand(time(NULL)); // seed random number generator

    int numBidders, numItems;
    printf("Enter number of bidders: ");
    scanf("%d", &numBidders);

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numBidders; i++) {
        printf("Enter bidder %d's name: ", i + 1);
        scanf("%s", bidder[i].name);
    }

    for (int i = 0; i < numItems; i++) {
        printf("Enter item %d's name: ", i + 1);
        scanf("%s", item[i].name);
    }

    int currentPrice = 0;
    int winnerId = -1;

    for (int i = 0; i < numItems; i++) {
        int currentBidderId = rand() % numBidders;
        int currentBidderPrice = rand() % 1000;

        printf("Bidder %d has bid $%d on item %d\n",
               currentBidderId + 1, currentBidderPrice, i + 1);

        if (currentBidderPrice > currentPrice) {
            currentPrice = currentBidderPrice;
            winnerId = currentBidderId;
        }
    }

    printf("Winner is bidder %d with a bid of $%d\n", winnerId + 1, currentPrice);

    return 0;
}