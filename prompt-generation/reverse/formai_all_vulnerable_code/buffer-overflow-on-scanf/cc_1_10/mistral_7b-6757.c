//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int bid;
} Bidder;

void shockingBid(Bidder *bidder, int bid) {
    printf("\n***** SHOCKING BID *****\n");
    printf("Bidder: %s\n", bidder->name);
    printf("Bid: %d\n", bid);
    printf("Prepare to be amazed!\n");
    sleep(1); // Add a suspenseful delay
    printf("The auctioneer's gavel falls!\n");
    system("aplay /path/to/sound/effect.wav"); // Play a sound effect
}

int main() {
    int numBidders, maxBid = 0;
    Bidder bidders[100];

    printf("***** WELCOME TO THE DIGITAL AUCTION *****\n");
    printf("Please enter the number of bidders: ");
    scanf("%d", &numBidders);

    for (int i = 0; i < numBidders; i++) {
        printf("\nBidder %d, please enter your name: ", i + 1);
        scanf("%s", bidders[i].name);
        printf("Your current bid is: $0\n");

        while (1) {
            printf("Enter your bid: $");
            scanf("%d", &bidders[i].bid);

            if (bidders[i].bid > maxBid) {
                maxBid = bidders[i].bid;
                shockingBid(&bidders[i], bidders[i].bid);
            } else {
                printf("Your bid is lower than the current highest bid. Try again.\n");
            }
        }
    }

    printf("\n***** THE AUCTION IS OVER *****\n");
    printf("The highest bidder is: %s\n", bidders[numBidders - 1].name);
    printf("The winning bid is: $%d\n", maxBid);

    return 0;
}