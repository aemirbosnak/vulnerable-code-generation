//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bidder {
    int bid;
    char name[50];
};

int main() {
    struct bidder bidders[10];
    int numBidders = 0;
    int highestBid = 0;
    
    printf("Welcome to the Digital Auction System!\n");
    
    while (1) {
        int choice;
        
        printf("\nEnter 1 to bid on an item\nEnter 2 to view current bids\nEnter 3 to exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter your bid: ");
                scanf("%d", &bidders[numBidders].bid);
                printf("\nEnter your name: ");
                scanf("%s", bidders[numBidders].name);
                
                if (numBidders < 10) {
                    numBidders++;
                }
                else {
                    printf("\nSorry, maximum number of bidders reached.\n");
                    break;
                }
                
                if (bidders[numBidders].bid > highestBid) {
                    highestBid = bidders[numBidders].bid;
                }
                else {
                    printf("\nYour bid is not the highest.\n");
                }
                break;
                
            case 2:
                printf("\nCurrent bids:\n");
                
                for (int i = 0; i < numBidders; i++) {
                    printf("%s: %d\n", bidders[i].name, bidders[i].bid);
                }
                break;
                
            case 3:
                printf("\nThank you for using the Digital Auction System!\n");
                break;
                
            default:
                printf("\nInvalid choice.\n");
        }
    }
    
    return 0;
}