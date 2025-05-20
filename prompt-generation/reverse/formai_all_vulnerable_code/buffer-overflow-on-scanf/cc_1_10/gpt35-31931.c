//FormAI DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct auction_item {
  char name[50];
  int base_price;
  int current_bid;
  char highest_bidder[50];
};

int main() {
  struct auction_item item;

  printf("Welcome to our Digital Auction System! Today we have a very special item up for bid: a romantic getaway for two.\n");
  printf("The starting price for this amazing experience is $1000.\n\n");

  strcpy(item.name, "Romantic Getaway for Two");
  item.base_price = 1000;
  item.current_bid = item.base_price;
  strcpy(item.highest_bidder, "None");

  while (1) {
    char bidder_name[50];
    int bid;

    printf("Enter your bidder name: ");
    scanf("%s", bidder_name);

    printf("Enter your bid amount: ");
    scanf("%d", &bid);

    if (bid < item.current_bid) {
      printf("Sorry %s, your bid of $%d is too low. The current bid is $%d.\n", bidder_name, bid, item.current_bid);
    } else {
      printf("Congratulations %s, your bid of $%d is currently the highest!\n", bidder_name, bid);
      item.current_bid = bid;
      strcpy(item.highest_bidder, bidder_name);
    }

    printf("\nWould you like to bid again? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'n') {
      printf("The auction has ended and the winner of the Romantic Getaway for Two is %s with a winning bid of $%d.\n", item.highest_bidder, item.current_bid);
      break;
    }

    printf("\n");
  }

  return 0;
}