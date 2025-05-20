//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing details of item
typedef struct{
    char itemName[50];
    int itemId;
    int basePrice;
} Item;

// Structure for storing details of bidder
typedef struct{
    char name[50];
    int bidderId;
    int maxBid;
} Bidder;

int main(){
    int numItems, numBidders;
    printf("Enter number of items: ");
    scanf("%d", &numItems);

    Item items[numItems]; // array of items

    // Inputting details of items
    for(int i=0; i<numItems; i++){
        printf("\nEnter details for Item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].itemName);

        printf("ID: ");
        scanf("%d", &items[i].itemId);

        printf("Base Price: ");
        scanf("%d", &items[i].basePrice);
    }

    printf("\nEnter number of bidders: ");
    scanf("%d", &numBidders);

    Bidder bidders[numBidders]; // array of bidders

    // Inputting details of bidders
    for(int i=0; i<numBidders; i++){
        printf("\nEnter details for Bidder %d:\n", i+1);
        printf("Name: ");
        scanf("%s", bidders[i].name);

        printf("ID: ");
        scanf("%d", &bidders[i].bidderId);

        printf("Maximum Bid: ");
        scanf("%d", &bidders[i].maxBid);
    }

    // Auction process
    for(int i=0; i<numItems; i++){
        Item currentItem = items[i];
        printf("\n\nAuctioning Item %d - %s (ID: %d)\n", i+1, currentItem.itemName, currentItem.itemId);

        int currentBid = currentItem.basePrice;
        Bidder currentBidder;
        int numBids = 0;

        while(currentBidder.bidderId != -1){ // Auction continues until all bidders have placed bids

            printf("\nCurrent Bid: %d\n", currentBid);

            // Displaying list of bidders who can outbid the current bid
            printf("Bidders who can outbid %s: \n", currentBidder.name);
            for(int j=0; j<numBidders; j++){
                if(bidders[j].maxBid > currentBid && bidders[j].bidderId != currentBidder.bidderId){
                    printf("%s (ID: %d)\n", bidders[j].name, bidders[j].bidderId);
                }
            }

            printf("Enter Bidder ID (-1 to exit auction): ");
            scanf("%d", &currentBidder.bidderId);
            if(currentBidder.bidderId == -1){
                printf("\nNo more bids.\n");
                break;
            }

            // Finding the bidder with entered ID
            for(int j=0; j<numBidders; j++){
                if(bidders[j].bidderId == currentBidder.bidderId){
                    currentBidder = bidders[j];
                    break;
                }
            }

            printf("Enter Bid Amount: ");
            scanf("%d", &currentBid);

            if(currentBid <= currentBidder.maxBid && currentBid > currentItem.basePrice && currentBid > numBids){
                printf("New Bid Placed by: %s (ID: %d)\n", currentBidder.name, currentBidder.bidderId);
                numBids++;
            }else if(currentBid > currentBidder.maxBid){
                printf("\n%s (ID: %d) cannot place bid higher than their maximum bid.\n", currentBidder.name, currentBidder.bidderId);
            }else if(currentBid <= currentItem.basePrice){
                printf("\nBid must be higher than base price.\n");
            }else if(currentBid <= numBids){
                printf("\nBid must be higher than previous bids.\n");
            }
        }

        printf("\n\nAuction for Item %d - %s (ID: %d) has ended.\n", i+1, currentItem.itemName, currentItem.itemId);
        if(numBids > 0){
            printf("Winner: %s (ID: %d) with bid of %d.\n", currentBidder.name, currentBidder.bidderId, currentBid);
        }else{
            printf("No bids placed for this item.\n");
        }
    }

    return 0;
}