//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Struct to hold auction items
typedef struct item{
    char name[50];
    float price;
    char description[100];
} item;

//Struct to hold bids
typedef struct bid{
    char bidder[50];
    float amount;
} bid;

//Function to add new items to the auction
void addItem(item* items, int* count){
    printf("Enter item name: ");
    scanf("%s",items[*count].name);
    printf("Enter item price: ");
    scanf("%f",&(items[*count].price));
    printf("Enter item description: ");
    scanf("%s",items[*count].description);
    (*count)++;
}

//Function to display all items in the auction
void displayItems(item* items, int* count){
    printf("Items currently in auction:\n");
    for(int i=0; i<*count; i++){
        printf("%d. %s - $%.2f - %s\n", i+1, items[i].name, items[i].price, items[i].description);
    }
}

//Function to place a bid on an item
void placeBid(item* items, bid* bids, int* count, int* bidCount){
    int choice;
    displayItems(items, count);
    printf("Enter item number to bid on: ");
    scanf("%d",&choice);
    printf("Enter your name: ");
    scanf("%s",bids[*bidCount].bidder);
    printf("Enter bid amount: ");
    scanf("%f",&(bids[*bidCount].amount));
    //Check if bid is higher than current price and update price if so
    if(bids[*bidCount].amount > items[choice-1].price){
        items[choice-1].price = bids[*bidCount].amount;
    }
    (*bidCount)++;
}

//Function to display all bids on an item
void displayBids(item* items, bid* bids, int* count, int* bidCount){
    int choice;
    displayItems(items, count);
    printf("Enter item number to view bids: ");
    scanf("%d",&choice);
    printf("Bids for %s:\n", items[choice-1].name);
    for(int i=0; i<*bidCount; i++){
        if(strcmp(items[choice-1].name, bids[i].bidder) == 0){
            printf("%s: %.2f\n",bids[i].bidder,bids[i].amount);
        }
    }
}

//Function to end the auction and display the winning bidder
void endAuction(item* items, bid* bids, int* count, int* bidCount){
    printf("Auction has ended!\n");
    float highestBid = 0;
    int winningBidIndex = -1;
    for(int i=0; i<*bidCount; i++){
        if(bids[i].amount > highestBid){
            highestBid = bids[i].amount;
            winningBidIndex = i;
        }
    }
    if(winningBidIndex != -1){
        printf("Winner: %s with a bid of $%.2f on %s\n", bids[winningBidIndex].bidder, bids[winningBidIndex].amount, items[winningBidIndex].name);
    }else{
        printf("No bids were made in this auction.\n");
    }
}

int main(){
    item items[10];
    bid bids[100];
    int count = 0, bidCount = 0, choice;
    printf("Welcome to the digital auction system!\n");
    do{
        printf("1. Add item\n2. Display items\n3. Place bid\n4. Display bids\n5. End auction\n6. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addItem(items, &count);
                break;
            case 2:
                displayItems(items, &count);
                break;
            case 3:
                placeBid(items, bids, &count, &bidCount);
                break;
            case 4:
                displayBids(items, bids, &count, &bidCount);
                break;
            case 5:
                endAuction(items, bids, &count, &bidCount);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 6);
    return 0;
}