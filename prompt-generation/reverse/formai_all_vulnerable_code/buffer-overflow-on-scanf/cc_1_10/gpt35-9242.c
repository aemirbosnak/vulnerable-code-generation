//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct auctions{
    int auctionID;
    char itemName[50];
    int currentBid;
    char highestBidder[50];
};

int main(){
    int numAuctions, choice, tempAucID, tempBid;
    char tempItem[50], tempBidder[50];
    printf("Enter the number of auctions: ");
    scanf("%d", &numAuctions);
    
    struct auctions auctionList[numAuctions];
    
    for(int i=0; i<numAuctions; i++){
        printf("\n\nEnter the auction ID: ");
        scanf("%d", &auctionList[i].auctionID);
        
        printf("Enter the item name: ");
        scanf("%s", auctionList[i].itemName);
        
        printf("Enter the current bid: ");
        scanf("%d", &auctionList[i].currentBid);
        
        printf("Enter the highest bidder: ");
        scanf("%s", auctionList[i].highestBidder);
    }
    
    while(1){
        printf("\n\n1. Place bid");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            printf("\nEnter the auction ID you want to place a bid on: ");
            scanf("%d", &tempAucID);
            
            for(int i=0; i<numAuctions; i++){
                if(auctionList[i].auctionID == tempAucID){
                    printf("\nCurrent bid for this item is: %d", auctionList[i].currentBid);
                    printf("\nHighest bidder for this item is: %s", auctionList[i].highestBidder);
                    
                    printf("\nEnter your bid: ");
                    scanf("%d", &tempBid);
                    if(tempBid > auctionList[i].currentBid){
                        auctionList[i].currentBid = tempBid;
                        printf("\nBid placed successfully.");
                        
                        printf("\nEnter your name: ");
                        scanf("%s", tempBidder);
                        strcpy(auctionList[i].highestBidder, tempBidder);
                        break;
                    }
                    else{
                        printf("\nYour bid is lower than the current bid.");
                        break;
                    }
                }
                else{
                    printf("\nInvalid auction ID entered.");
                }
            }
        }
        else if(choice == 2){
            exit(0);
        }
        else{
            printf("\nInvalid choice entered.");
        }
    }
    
    return 0;
}