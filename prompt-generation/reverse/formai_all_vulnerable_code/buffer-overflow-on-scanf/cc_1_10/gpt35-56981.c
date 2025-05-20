//FormAI DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
   char name[50];
   int quantity;
   float price;
};

struct bid {
   char name[50];
   float amount;
};

int main() {
   struct item auction_item;
   strcpy(auction_item.name, "Antique Vase");
   auction_item.quantity = 1;
   auction_item.price = 500.00;

   struct bid highest_bid;
   strcpy(highest_bid.name, "Anonymous");
   highest_bid.amount = 0.00;

   printf("Welcome to the auction!\n");
   printf("Up for auction today is a beautiful %d %s for $%.2f.\n\n", auction_item.quantity, auction_item.name, auction_item.price);

   char bidder_name[50];
   float bid_amount;
   
   while (1) {
      printf("Current highest bid is $%.2f submitted by %s.\n", highest_bid.amount, highest_bid.name);
      printf("Please enter your name and bid amount (or \"exit\" to end the auction):\n");
      scanf("%s %f", bidder_name, &bid_amount);

      if (strcmp(bidder_name, "exit") == 0) {
         printf("The auction has ended.\n");
         break;
      }
      else if (bid_amount <= highest_bid.amount) {
         printf("Error: Bid amount must be greater than current highest bid.\n");
      }
      else {
         strcpy(highest_bid.name, bidder_name);
         highest_bid.amount = bid_amount;
         printf("Congratulations %s, your bid of $%.2f is the new highest bid.\n", highest_bid.name, highest_bid.amount);
      }
   }

   return 0;
}