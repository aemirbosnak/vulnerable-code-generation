//FormAI DATASET v1.0 Category: Digital Auction System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Function prototypes 
void showBanner();
void showMenu();
void auctionItem();
void bidItem();

//Global variables
char itemName[20];
int itemValue, highestBid = 0, highestBidder;
int bidderCount = 0;

//Main function
int main(){
    int choice;
    showBanner();
    do{
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                auctionItem();
                break;
            case 2:
                bidItem();
                break;
            case 3:
                printf("\nGoodbye! Stay safe out there.\n");
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }while(choice!= 3);
    return 0;
}

void showBanner(){
    printf("=====================================================\n");
    printf("=                                                   =\n");
    printf("         DIGITAL AUCTION SYSTEM - POST-APOCALYPSE EDITION            \n");
    printf("=                                                   =\n");
    printf("=====================================================\n\n");
}

void showMenu(){
    printf("Please choose an option:\n");
    printf("1. Auction an item\n");
    printf("2. Bid on an item\n");
    printf("3. Exit the program\n");
}

void auctionItem(){
    printf("\nEnter item name: ");
    scanf("%s", itemName);
    printf("Enter item value (in gold coins): ");
    scanf("%d", &itemValue);
    printf("Item auctioned successfully!\n");
}

void bidItem(){
    printf("\nCurrent item for bidding: %s\n", itemName);
    printf("Current highest bid: %d\n", highestBid);
    printf("Enter your bid (in gold coins): ");
    int newBid;
    scanf("%d", &newBid);
    if(newBid <= highestBid){
        printf("Your bid must be higher than the current highest bid.\n");
        return;
    }
    highestBid = newBid;
    highestBidder = ++bidderCount;
    printf("Bid accepted. You are now the highest bidder.\n");
}