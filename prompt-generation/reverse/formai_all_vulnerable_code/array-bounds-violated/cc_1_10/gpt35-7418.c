//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    int itemID;
    char itemName[50];
    float startingPrice;
    float currentPrice;
    char description[500];
};

struct auction{
    int auctionID;
    char auctionName[50];
    struct item auctionItem;
    char auctioneerName[50];
    char bidderName[50];
    float highestBid;
};

int main() {
    struct auction auctionArray[10];
    int option;
    int numOfAuctions = 0;
    int i;
    printf("Welcome to the Digital Auction System!\n");
    do{
        printf("\nPlease select an option:\n");
        printf("1. Create a new auction\n");
        printf("2. Bid on an existing auction\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                if(numOfAuctions >= 10){
                    printf("Sorry, you can only create up to 10 auctions.\n");
                    break;
                }
                printf("Please enter the name of the auction:\n");
                scanf("%s", auctionArray[numOfAuctions].auctionName);
                printf("Please enter the name of the auctioneer:\n");
                scanf("%s", auctionArray[numOfAuctions].auctioneerName);
                printf("Please enter the item ID:\n");
                scanf("%d", &auctionArray[numOfAuctions].auctionItem.itemID);
                printf("Please enter the item name:\n");
                scanf("%s", auctionArray[numOfAuctions].auctionItem.itemName);
                printf("Please enter the item description:\n");
                scanf("%s", auctionArray[numOfAuctions].auctionItem.description);
                printf("Please enter the starting price:\n");
                scanf("%f", &auctionArray[numOfAuctions].auctionItem.startingPrice);
                auctionArray[numOfAuctions].auctionItem.currentPrice = auctionArray[numOfAuctions].auctionItem.startingPrice;
                numOfAuctions++;
                printf("Auction created successfully!\n");
                break;
            case 2:
                printf("Please enter the auction ID:\n");
                scanf("%d", &i);
                if(i >= numOfAuctions){
                    printf("Auction not found.\n");
                    break;
                }
                printf("Please enter your name:\n");
                scanf("%s", auctionArray[i].bidderName);
                printf("Please enter your bid:\n");
                scanf("%f", &auctionArray[i].highestBid);
                if(auctionArray[i].highestBid > auctionArray[i].auctionItem.currentPrice){
                    auctionArray[i].auctionItem.currentPrice = auctionArray[i].highestBid;
                    printf("Bid successful!\n");
                }
                else{
                    printf("Bid unsuccessful. Please bid higher than the current price.\n");
                }
                break;
            case 3:
                printf("Exiting Digital Auction System...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }while(option != 3);
    return 0;
}