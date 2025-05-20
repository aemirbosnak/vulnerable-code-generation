//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Item {
    char name[50];
    float price;
};

struct Bid {
    char name[50];
    float bidAmount;
};

int main() {
    struct Item item;
    struct Bid bid[MAX];
    int numOfBids = 0;
    int maxBids;
    float highestBid = 0.0;

    printf("Enter item name: ");
    gets(item.name);

    printf("Enter item price: ");
    scanf("%f", &item.price);

    printf("Enter max number of bids: ");
    scanf("%d", &maxBids);

    while(numOfBids < maxBids) {
        printf("Enter bidder's name: ");
        getchar();
        gets(bid[numOfBids].name);

        printf("Enter bid amount: ");
        scanf("%f", &bid[numOfBids].bidAmount);

        if(bid[numOfBids].bidAmount > highestBid) {
            highestBid = bid[numOfBids].bidAmount;
        }

        numOfBids++;
    }

    printf("\n\nAuction closed!\n\n");

    printf("Item: %s\n", item.name);
    printf("Starting Price: %.2f\n", item.price);
    printf("Highest Bid: %.2f\n", highestBid);
    printf("Winner is: %s\n", bid[numOfBids-1].name);
    
    return 0;
}