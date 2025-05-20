//FormAI DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
   int itemNumber;
   char itemName[30];
   double itemPrice;
};

struct Bid {
   int bidNumber;
   int itemNumber;
   char bidderName[30];
   double bidPrice;
};

void printMenu() {
   printf("\n\nMAIN MENU\n");
   printf("1. Add an item\n");
   printf("2. List all items\n");
   printf("3. Add a bid\n");
   printf("4. List all bids\n");
   printf("5. Exit\n");
}

void addItem(struct Item items[], int *count) {
   int itemNumber;
   char itemName[30];
   double itemPrice;

   printf("\nEnter item number: ");
   scanf("%d", &itemNumber);

   printf("Enter item name: ");
   scanf("%s", itemName);

   printf("Enter item price: ");
   scanf("%lf", &itemPrice);

   items[*count].itemNumber = itemNumber;
   strcpy(items[*count].itemName, itemName);
   items[*count].itemPrice = itemPrice;

   (*count)++;
}

void listItems(struct Item items[], int count) {
   int i;

   printf("\n\nITEMS\n");
   printf("Item No.\tItem Name\tItem Price\n");
   for (i = 0; i < count; i++) {
      printf("%d\t\t%s\t\t%.2lf\n", items[i].itemNumber, items[i].itemName, items[i].itemPrice);
   }
}

void addBid(struct Bid bids[], int *count, struct Item items[], int itemCount) {
   int bidNumber, itemNumber, i;
   char bidderName[30];
   double bidPrice;

   printf("\nEnter bid number: ");
   scanf("%d", &bidNumber);

   printf("Enter item number: ");
   scanf("%d", &itemNumber);

   for (i = 0; i < itemCount; i++) {
      if (items[i].itemNumber == itemNumber) {
         printf("Item Name: %s\n", items[i].itemName);
         break;
      }
   }

   if (i == itemCount) {
      printf("Invalid item number\n");
      return;
   }

   printf("Enter bidder name: ");
   scanf("%s", bidderName);

   printf("Enter bid price: ");
   scanf("%lf", &bidPrice);

   bids[*count].bidNumber = bidNumber;
   bids[*count].itemNumber = itemNumber;
   strcpy(bids[*count].bidderName, bidderName);
   bids[*count].bidPrice = bidPrice;

   (*count)++;
}

void listBids(struct Bid bids[], int count) {
   int i;

   printf("\n\nBIDS\n");
   printf("Bid No.\t\tItem No.\tBidder Name\tBid Price\n");
   for (i = 0; i < count; i++) {
      printf("%d\t\t%d\t\t%s\t\t%.2lf\n", bids[i].bidNumber, bids[i].itemNumber, bids[i].bidderName, bids[i].bidPrice);
   }
}

int main() {
   int choice;
   struct Item items[10];
   struct Bid bids[50];
   int itemCount = 0, bidCount = 0;

   do {
      printMenu();
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            addItem(items, &itemCount);
            break;
         case 2:
            listItems(items, itemCount);
            break;
         case 3:
            addBid(bids, &bidCount, items, itemCount);
            break;
         case 4:
            listBids(bids, bidCount);
            break;
         case 5:
            printf("\nThanks for using the program!\n");
            break;
         default:
            printf("\nInvalid choice!\n");
            break;
      }
   } while (choice != 5);

   return 0;
}