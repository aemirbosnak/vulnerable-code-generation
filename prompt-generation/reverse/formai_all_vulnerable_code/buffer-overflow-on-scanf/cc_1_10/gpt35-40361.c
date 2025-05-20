//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item{
   int itemId;
   char itemName[50];
   int minBid;
};
typedef struct item Item;

struct bidder{
   int bidderId;
   char bidderName[50];
   int bidderBid;
};
typedef struct bidder Bidder;

void displayItems(Item items[], int size){
   printf("ITEM ID\tITEM NAME\tMINIMUM BID\n");
   for(int i=0; i<size; i++){
      printf("%d\t%s\t\t%d\n", items[i].itemId, items[i].itemName, items[i].minBid);
   }
}

int getBidderIndex(Bidder bidders[], int size, int id){
   for(int i=0; i<size; i++){
      if(bidders[i].bidderId == id){
         return i;
      }
   }
   return -1;
}

void displayBidders(Bidder bidders[], int size){
   printf("BIDDER ID\tBIDDER NAME\tBID AMOUNT\n");
   for(int i=0; i<size; i++){
      printf("%d\t\t%s\t\t%d\n", bidders[i].bidderId, bidders[i].bidderName, bidders[i].bidderBid);
   }
}

void bidItem(Item items[], int itemIndex, Bidder bidders[], int bidderIndex){
   int bid;
   printf("Enter bid amount: ");
   scanf("%d", &bid);
   if(bid > bidders[bidderIndex].bidderBid){
      printf("Bid accepted!\n");
      items[itemIndex].minBid = bid;
      bidders[bidderIndex].bidderBid = bid;
   }
   else{
      printf("Bid amount too low.\n");
   }
}

void showBids(Item item, Bidder bidders[], int size){
   printf("BIDS FOR %s (Minimum bid: %d)\n", item.itemName, item.minBid);
   displayBidders(bidders, size);
}

void auction(Item items[], int size, Bidder bidders[], int numBidders){
   int choice, itemId, bidderId, itemIndex, bidderIndex;
   while(1){
      printf("1. Display items\n2. Bid for an item\n3. Show bids for an item\n4. Exit auction\n");
      printf("Enter choice: ");
      scanf("%d", &choice);
      switch(choice){
         case 1:
            displayItems(items, size);
            break;
         case 2:
            printf("Enter Item ID: ");
            scanf("%d", &itemId);
            printf("Enter Bidder ID: ");
            scanf("%d", &bidderId);
            itemIndex = itemId-1;
            bidderIndex = getBidderIndex(bidders, numBidders, bidderId);
            if(itemIndex >= 0 && itemIndex < size && bidderIndex != -1){
               bidItem(items, itemIndex, bidders, bidderIndex);
            }
            else{
               printf("Invalid details entered.\n");
            }
            break;
         case 3:
            printf("Enter Item ID: ");
            scanf("%d", &itemId);
            itemIndex = itemId-1;
            if(itemIndex >= 0 && itemIndex < size){
               showBids(items[itemIndex], bidders, numBidders);
            }
            else{
               printf("Invalid Item ID entered.\n");
            }
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid option selected.\n");
      }
   }
}

int main(){
   Item items[3] = {{1, "Sword", 100}, {2, "Shield", 50}, {3, "Armor", 500}};
   Bidder bidders[5] = {{1, "Knight", 0}, {2, "Rogue", 0}, {3, "Mage", 0}, {4, "Barbarian", 0}, {5, "Archer", 0}};
   int numBidders = 5;
   printf("Welcome to the Medieval Auction System!\n");
   auction(items, 3, bidders, numBidders);
   return 0;
}