//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

//Defining the structure of an item in the auction
typedef struct {
    char name[50];
    int basePrice;
    int currentPrice;
} Item;

//Function to print the details of an item
void printItem(Item item) {
    printf("Name: %s\n", item.name);
    printf("Base Price: $%d\n", item.basePrice);
    printf("Current Price: $%d\n", item.currentPrice);
    printf("\n");
}

//Function to initialize an item
void initItem(Item *item) {
    printf("Enter the name of the item: ");
    scanf("%s", item->name);
    printf("Enter the base price of the item: ");
    scanf("%d", &item->basePrice);
    item->currentPrice = item->basePrice;
}

//Function to place a bid on an item
void placeBid(Item *item, int bidAmount) {
    if(item->currentPrice >= bidAmount) {
        printf("Your bid is too low. Please enter a higher bid.\n");
    } else {
        item->currentPrice = bidAmount;
        printf("Your bid has been accepted. The current price is now $%d.\n", item->currentPrice);
    }
}

//Function to display the current highest bid for an item
void displayHighestBid(Item item) {
    printf("The current highest bid for %s is $%d.\n", item.name, item.currentPrice);
}

//Main function
int main() {
    Item item;
    int choice;
    int bidAmount;
    int highestBid = 0;

    //Initializing the item
    initItem(&item);

    //Auction loop
    do {
        printf("Auction Menu:\n");
        printf("1. Place a bid\n");
        printf("2. Display the current highest bid\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your bid amount: ");
                scanf("%d", &bidAmount);
                placeBid(&item, bidAmount);
                break;
            case 2:
                highestBid = item.currentPrice;
                displayHighestBid(item);
                break;
            case 3:
                printf("Thank you for participating in the auction.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}