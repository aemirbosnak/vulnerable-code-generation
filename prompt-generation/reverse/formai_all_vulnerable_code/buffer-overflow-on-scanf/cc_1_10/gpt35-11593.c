//FormAI DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BIDS 10

/* Structure to store bid information */
typedef struct {
    char name[50];
    float amount;
} bidInfo;

int getBidIndex(bidInfo* bids, int* numBids, char* name) {
    /* Return the index of the bid from given name */
    int i;
    for (i = 0; i < *numBids; i++) {
        if (strcmp(bids[i].name, name) == 0)
            return i;
    }
    return -1;
}

float getMaxBid(bidInfo* bids, int* numBids) {
    /* Return the maximum bid amount from the list of bids */
    int i;
    float maxBid = 0.0;
    for (i = 0; i < *numBids; i++) {
        if (bids[i].amount > maxBid)
            maxBid = bids[i].amount;
    }
    return maxBid;
}

int main() {
    /* Initialize bid information */
    bidInfo bids[MAX_BIDS];
    int numBids = 0, i, index;
    float maxBid;
    char name[MAX_BIDS];

    /* Enter the initial bid */
    printf("Enter the name of the bidder: ");
    scanf("%s", name);
    printf("Enter the initial bid amount: ");
    scanf("%f", &bids[numBids].amount);
    strcpy(bids[numBids].name, name);
    numBids++;

    /* Enter subsequent bids until the user stops entering */
    while (1) {
        printf("Do you want to enter another bid? (y/n): ");
        scanf("%s", name);
        if (strcmp(name, "n") == 0 || strcmp(name, "N") == 0)
            break;
        printf("Enter the name of the bidder: ");
        scanf("%s", name);
        index = getBidIndex(bids, &numBids, name);
        if (index == -1) {
            /* Bidder doesn't exist, add new bid */
            printf("Enter the bid amount: ");
            scanf("%f", &bids[numBids].amount);
            strcpy(bids[numBids].name, name);
            numBids++;
        } else {
            /* Bidder already exists, update the bid amount */
            printf("Enter the new bid amount: ");
            scanf("%f", &bids[index].amount);
        }
    }

    /* Calculate the final winning bid */
    maxBid = getMaxBid(bids, &numBids);
    printf("The winning bid is %.2f.\n", maxBid);

    return 0;
}