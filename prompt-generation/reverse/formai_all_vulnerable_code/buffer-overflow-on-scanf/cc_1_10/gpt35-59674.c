//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Auction {
  char itemName[50];
  int itemId;
  char itemDescription[100];
  int startingBid;
  int currentBid;
  char bidder[50];
  int timeLeft;
};

struct Auction auctions[10];
int noOfAuctions = 0;

void createAuction() {
  if (noOfAuctions >= 10) {
    printf("Cannot create any more auctions.\n");
    return;
  }

  int itemId = rand() % 1000 + 1;
  printf("Enter the item name: ");
  scanf("%s", auctions[noOfAuctions].itemName);
  auctions[noOfAuctions].itemId = itemId;
  printf("Enter the item description: ");
  scanf("%s", auctions[noOfAuctions].itemDescription);
  printf("Enter the starting bid: ");
  scanf("%d", &auctions[noOfAuctions].startingBid);
  auctions[noOfAuctions].currentBid = auctions[noOfAuctions].startingBid;
 	strcpy(auctions[noOfAuctions].bidder, "NO BIDDERS YET");
  auctions[noOfAuctions].timeLeft = rand() % 60 + 1;
  printf("Auction created with id %d\n", itemId);

  noOfAuctions++;
}

void bid(int itemId, char bidderName[50], int amount) {
  int auctionIndex = -1;
  for (int i = 0; i < noOfAuctions; i++) {
    if (auctions[i].itemId == itemId) {
      auctionIndex = i;
      break;
    }
  }

  if (auctionIndex == -1) {
    printf("No auction found with item id %d\n", itemId);
    return;
  }

  if (amount <= auctions[auctionIndex].currentBid) {
    printf("Bid amount should be greater than the current bid of %d\n", auctions[auctionIndex].currentBid);
    return;
  }

  auctions[auctionIndex].currentBid = amount;
 	strcpy(auctions[auctionIndex].bidder, bidderName);
 	printf("%s is now the highest bidder on item %d with a bid of %d\n", bidderName, auctions[auctionIndex].itemId, auctions[auctionIndex].currentBid);
}

void printTimeRemaining(int time) {
  int minutes = time / 60;
  int seconds = time % 60;
  printf("%02d:%02d", minutes, seconds);
}

void printAuctions() {
  printf("----------------------------------------------------------------------------------------------------\n");
  printf("| Item ID  | Item Name                    | Item Description                   | Current Bid | Bidder            | Time Left |\n");
  printf("----------------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < noOfAuctions; i++) {
    printf("| %08d | %-28s | %-32s | %11d | %-17s | ", auctions[i].itemId, auctions[i].itemName, auctions[i].itemDescription, auctions[i].currentBid, auctions[i].bidder);
    printTimeRemaining(auctions[i].timeLeft);
    printf(" |\n");
  }
  printf("----------------------------------------------------------------------------------------------------\n");
}

void decrementTime() {
  for (int i = 0; i < noOfAuctions; i++) {
    auctions[i].timeLeft--;
    if (auctions[i].timeLeft == 0) {
      printf("\nThe auction for item %08d has ended.\n", auctions[i].itemId);
      printf("%s has won the item with a bid of %d\n", auctions[i].bidder, auctions[i].currentBid);
      for (int j = i; j < noOfAuctions - 1; j++) {
        auctions[j] = auctions[j+1];
      }
      noOfAuctions--;
      i--;
    }
  }
}

int main() {
  srand(time(NULL));

  while (1) {
    printf("Digital Auction System\n\n");
    printf("1. Create Auction\n");
    printf("2. Bid\n");
    printf("3. Print Auctions\n");
    printf("4. Exit\n");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        createAuction();
        break;
      case 2: {
        int itemId, amount;
        char bidderName[50];
        printf("Enter the item id you want to bid on: ");
        scanf("%d", &itemId);
        printf("Enter your name: ");
        scanf("%s", bidderName);
        printf("Enter your bid amount: ");
        scanf("%d", &amount);
        bid(itemId, bidderName, amount);
        break;
      }
      case 3:
        printAuctions();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }

    decrementTime();
    sleep(1);
    system("clear");
  }

  return 0;
}