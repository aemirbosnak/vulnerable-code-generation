//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare global variables for the auction system
char* item = NULL;
int startingPrice = 0;
int bidPrice = 0;
char* highestBidder = NULL;
int highestBid = 0;

//Function to place a bid on an item
void placeBid(int newBidPrice, char* bidder) {
  if(newBidPrice > highestBid) {
    highestBid = newBidPrice;
    strcpy(highestBidder, bidder);
    printf("%s has placed a bid of $%d on %s.\n", bidder, newBidPrice, item);
  }
  else {
    printf("Sorry, your bid is lower than the highest bid.\n");
  }
}

int main() {
  //Initialize variables
  int choice = 0;
  char bidder[20];

  //Prompt user to enter item information
  printf("Welcome to the Digital Auction System!\n");
  printf("Please enter the item name: ");
  scanf("%s", item);
  printf("Please enter the starting price: $");
  scanf("%d", &startingPrice);

  //Set highestBid to startingPrice and highestBidder to "None"
  highestBid = startingPrice;
  highestBidder = "None";

  //Display item information and available options to user
  printf("\nThe item for auction is:\n");
  printf("Item: %s\n", item);
  printf("Starting Price: $%d\n", startingPrice);
  printf("Current Highest Bid: $%d by %s.\n", highestBid, highestBidder);
  printf("Please select an option below:\n");
  printf("1. Place Bid\n");
  printf("2. Exit\n");

  //Loop through the menu until user exits
  while(1) {
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter bidder name: ");
        scanf("%s", bidder);
        printf("Enter bid price: $");
        scanf("%d", &bidPrice);
        placeBid(bidPrice, bidder);
        break;

      case 2:
        printf("Thank you for using the Digital Auction System!\n");
        exit(0);

      default:
        printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}