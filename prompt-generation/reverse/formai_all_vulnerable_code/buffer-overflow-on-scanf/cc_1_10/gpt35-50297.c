//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char itemName[30];
    char itemDesc[50];
    int startBid;
    int currentBid;
    char bidder[20];
} AuctionItem;

int main()
{
    AuctionItem item1 = {"Signed Sherlock Holmes", "A signed copy of Sherlock Holmes by Arthur Conan Doyle", 100, 100, ""};
    
    // Auction starts
    printf("\n\nWelcome to the Digital Auction System\n\n");
    
    // Display the item for auction
    printf("Item for Auction: %s\n", item1.itemName);
    printf("Description: %s\n", item1.itemDesc);
    printf("Starting bid: $%d\n\n", item1.startBid);
    
    // Ask for user input
    char choice[5];
    printf("Do you want to make a bid? (y/n): ");
    scanf("%s", choice);
    printf("\n");
    
    while(strcmp(choice, "y") == 0) {
        char bidderName[20];
        int bidAmount;
        printf("Enter your name: ");
        scanf("%s", bidderName);
        printf("Enter your bid amount: ");
        scanf("%d", &bidAmount);
        if(bidAmount > item1.currentBid) {
            item1.currentBid = bidAmount;
            strcpy(item1.bidder, bidderName);
            printf("\nBid accepted! New highest bid is $%d by %s.\n\n", item1.currentBid, item1.bidder);
        } else {
            printf("\nSorry, your bid of $%d is not high enough. Highest bid is currently $%d.\n\n", bidAmount, item1.currentBid);
        }
        printf("Do you want to make another bid? (y/n): ");
        scanf("%s", choice);
        printf("\n");
    }
    
    // Auction ends
    printf("Auction ended. Highest bid for %s is $%d by %s.\n", item1.itemName, item1.currentBid, item1.bidder);
    
    return 0;
}