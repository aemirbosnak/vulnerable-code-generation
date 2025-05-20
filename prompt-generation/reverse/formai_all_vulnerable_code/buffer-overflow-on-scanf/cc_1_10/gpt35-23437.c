//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void displayAuctions(int auction_count, char auctions[][50], float bids[]);
int getAuctionSelection();
float getBidInput();
void runAuction(int selected_auction, float bids[], char auctions[][50]);

int main() {
  char auctions[10][50] = {"Painting by Picasso", "Signed Baseball by Babe Ruth", "Vintage Typewriter", "Original Manuscript by J.K Rowling", "First Edition of Great Expectations by Charles Dickens", "1913 Liberty Head Nickel", "Signed Michael Jordan Sneakers", "Autographed Beatles Album", "Game-Worn Tom Brady Jersey", "Gold and Diamond Rolex Watch"};
  float bids[10] = {0};

  srand(time(0));
  int auction_count = rand() % 6 + 5; // Generate a random number between 5 and 10
  printf("Welcome to the Digital Auction System!\n");
  printf("There are currently %d auctions available.\n", auction_count);

  displayMenu();

  int selection = getAuctionSelection();
  while (selection != 4) {
    runAuction(selection, bids, auctions);

    displayMenu();
    selection = getAuctionSelection();
  }

  printf("\nThank you for using the Digital Auction System!\n");

  return 0;
}

/**
 * Displays the main menu of the program
 */
void displayMenu() {
  printf("\nMAIN MENU\n");
  printf("1. View all auctions\n");
  printf("2. Place a bid\n");
  printf("3. View auction information\n");
  printf("4. Exit system\n");
}

/**
 * Displays all available auctions and their current highest bid
 */
void displayAuctions(int auction_count, char auctions[][50], float bids[]) {
  printf("\nAVAILABLE AUCTIONS:\n");

  for (int i = 0; i < auction_count; i++) {
    printf("%d. %s - Current highest bid: $%.2f\n", i+1, auctions[i], bids[i]);
  }
  printf("\n");
}

/**
 * Retrieves user's auction selection
 */
int getAuctionSelection() {
  int selection = 0;
  printf("Enter your selection (1-4): ");
  scanf("%d", &selection);

  while (selection < 1 || selection > 4) {
    printf("Invalid selection. Please enter a number between 1 and 4: ");
    scanf("%d", &selection);
  }

  return selection;
}

/**
 * Retrieves user's bid input
 */
float getBidInput() {
  float bid = 0;
  printf("Enter your bid: $");
  scanf("%f", &bid);

  while (bid <= 0) {
    printf("Invalid bid amount. Please enter a bid greater than $0: $");
    scanf("%f", &bid);
  }

  return bid;
}

/**
 * Runs an auction based on the user's selection
 */
void runAuction(int selected_auction, float bids[], char auctions[][50]) {
  switch (selected_auction) {
    case 1:
      displayAuctions(10, auctions, bids);
      break;
    case 2:
      displayAuctions(10, auctions, bids);
      printf("Enter the number of the auction you'd like to place a bid on: ");
      int bid_auction;
      scanf("%d", &bid_auction);
      bid_auction--;

      float bid = getBidInput();
      if (bid > bids[bid_auction]) {
        bids[bid_auction] = bid;
        printf("Bid successfully placed!\n");
      } else {
        printf("Your bid is not higher than the current highest bid.\n");
      }
      break;
    case 3:
      displayAuctions(10, auctions, bids);
      printf("Enter the number of the auction you'd like to view: ");
      int view_auction;
      scanf("%d", &view_auction);
      view_auction--;

      printf("\nAUCTION INFORMATION:\n");
      printf("Item: %s\n", auctions[view_auction]);
      printf("Current highest bid: $%.2f\n", bids[view_auction]);
      break;
    default:
      printf("Invalid selection.\n");
      break;
  }
}