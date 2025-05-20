//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

typedef struct {
    int id;
    char name[50];
    int price;
    bool availability;
} Item;

typedef struct {
    int id;
    char name[50];
} Bidder;

int countItems = 0;
int countBidders = 0;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];

void addItem(){
     // Function to add a new item to the auction system
    Item item;
    printf("Enter Item Name: ");
    scanf("%s", item.name);
    printf("Enter Item Price: ");
    scanf("%d", &item.price);
    item.availability = true;
    item.id = countItems + 1;
    items[countItems] = item;
    countItems++;
}

void removeItem(){
    // Function to remove an item from the auction system
    int id;
    printf("Enter the Item ID which you want to remove: ");
    scanf("%d", &id);
    for(int i = 0; i < countItems; i++){
        if(items[i].id == id){
            items[i].availability = false;
            printf("Item removed successfully!\n");
            break;
        }
    }
}

void addItemBid(){
    // Function to add a bid to an item
    int itemId, bidderId, amount;
    printf("Enter Item ID: ");
    scanf("%d", &itemId);
    printf("Enter Bidder ID: ");
    scanf("%d", &bidderId);
    printf("Enter Bid Amount: ");
    scanf("%d", &amount);
    for(int i = 0; i < countItems; i++){
        if(items[i].id == itemId){
            if(amount > items[i].price){
                items[i].price = amount;
                printf("Bid added successfully!\n");
                break;
            }
            else{
                printf("Bid amount should be greater than current price of item!\n");
                break;
            }
        }
    }
}

void addBidder(){
    // Function to add a new bidder to the auction system
    Bidder bidder;
    printf("Enter Bidder Name: ");
    scanf("%s", bidder.name);
    bidder.id = countBidders + 1;
    bidders[countBidders] = bidder;
    countBidders++;
}

void displayItems(){
    // Function to display all available items in the auction system
    printf("ID\tName\tPrice\n");
    for(int i=0; i<countItems; i++){
        if(items[i].availability){
            printf("%d\t%s\t%d\n", items[i].id, items[i].name, items[i].price);
        }
    }
}

void displayBidders(){
    // Function to display all the bidders in the auction system
    printf("ID\tName\n");
    for(int i=0; i<countBidders; i++){
        printf("%d\t%s\n", bidders[i].id, bidders[i].name);
    }
}

void displayHighestBids(){
    // Function to display the highest bid for each item
    printf("ID\tName\tHighest Bid\n");
    for(int i=0; i<countItems; i++){
        if(items[i].availability){
            printf("%d\t%s\t%d\n", items[i].id, items[i].name, items[i].price);
        }
    }
}

int main(){
    int choice;
    while(true){
        printf("\n***************** Digital Auction System *****************\n");
        printf("1. Add Item to Auction\n");
        printf("2. Remove Item to Auction\n");
        printf("3. Add Bid for Item\n");
        printf("4. Add Bidder\n");
        printf("5. Display Available Items\n");
        printf("6. Display Bidders\n");
        printf("7. Display Highest Bids\n");
        printf("8. Exit\n");
        printf("***********************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                addItem();
                break;
            }
            case 2: {
                removeItem();
                break;
            }
            case 3: {
                addItemBid();
                break;
            }
            case 4: {
                addBidder();
                break;
            }
            case 5: {
                displayItems();
                break;
            }
            case 6: {
                displayBidders();
                break;
            }
            case 7: {
                displayHighestBids();
                break;
            }
            case 8: {
                printf("\nThanks! Have a nice day!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice! Try again!\n");
            }
        }
    }
    return 0;
}