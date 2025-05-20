//FormAI DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// structure defining the auction
struct Auction {
  char itemName[100];
  float basePrice;
  int bids;
  char bidderName[100];
  float bidAmount;
  struct tm* closingTime;
};

int main() {
  // create an auction object
  struct Auction myAuction;
  
  // set the initial values
  strcpy(myAuction.itemName, "Painting");
  myAuction.basePrice = 100.0;
  myAuction.bids = 0;
  strcpy(myAuction.bidderName, "");
  myAuction.bidAmount = 0.0;
  
  // set the closing time for the auction
  time_t currentTime;
  time(&currentTime);
  struct tm* closingTime = localtime(&currentTime); // set closing time to the current time
  closingTime->tm_min += 2; // set the closing time to two minutes from now
  myAuction.closingTime = closingTime;
  
  // print the initial values
  printf("Item Name: %s\n", myAuction.itemName);
  printf("Base Price: %.2f\n", myAuction.basePrice);
  printf("Bids: %d\n", myAuction.bids);
  printf("Bidder Name: %s\n", myAuction.bidderName);
  printf("Bid Amount: %.2f\n", myAuction.bidAmount);
  printf("Closing Time: %s", asctime(myAuction.closingTime));
  
  // start the auction
  printf("\nThe auction has started!\n");
  while (difftime(mktime(localtime(&currentTime)), mktime(myAuction.closingTime)) < 0) { // while the auction is still open
    char bidderName[100];
    float bidAmount;
    printf("\nEnter your name: ");
    scanf("%s", bidderName);
    printf("Enter your bid: ");
    scanf("%f", &bidAmount);
    if (bidAmount > myAuction.bidAmount) { // if the bid is higher than the current bid
      myAuction.bidAmount = bidAmount;
      strcpy(myAuction.bidderName, bidderName);
      myAuction.bids++;
      printf("Bid accepted!\n");
      printf("Bids: %d\n", myAuction.bids);
      printf("Bidder Name: %s\n", myAuction.bidderName);
      printf("Bid Amount: %.2f\n", myAuction.bidAmount);
    } else {
      printf("Bid not accepted.\n");
    }
    time(&currentTime); // check the current time
  }
  
  // end the auction
  printf("\nThe auction has closed.\n");
  printf("Winning Bidder Name: %s\n", myAuction.bidderName);
  printf("Winning Bid Amount: %.2f\n", myAuction.bidAmount);
  
  return 0;
}