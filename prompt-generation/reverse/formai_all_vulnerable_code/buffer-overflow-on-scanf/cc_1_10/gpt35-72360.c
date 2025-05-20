//FormAI DATASET v1.0 Category: Digital Auction System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BIDS 10
#define MAX_BIDDERS 5
#define MAX_ITEM_NAME 50

struct bid{
   char bidder[MAX_BIDDERS][MAX_ITEM_NAME];
   float bidAmount[MAX_BIDDERS];
   int bidderCount;
   float maxBid;
};
typedef struct bid Bid;

void initializeBid(Bid *aBid){
   aBid -> bidderCount = 0;
   aBid -> maxBid = 0.0;
}

void addBidder(Bid *aBid, char *bidderName, float bidValue){
   if(aBid -> bidderCount == MAX_BIDS){
      printf("No more bids allowed\n");
   }
   else{
      strcpy(aBid -> bidder[aBid -> bidderCount], bidderName);
      aBid -> bidAmount[aBid -> bidderCount] = bidValue;
      aBid -> bidderCount++;

      if(bidValue > aBid -> maxBid){
         aBid -> maxBid = bidValue;
      }
      printf("Bid successfully added\n");
   }
}

void displayBids(Bid aBid){
   int i;
   printf("\nBidder Name      Bid Amount\n");
   for(i = 0; i < aBid.bidderCount; i++){
      printf("%-15s $%9.2f\n", aBid.bidder[i], aBid.bidAmount[i]);
   }
   printf("\nThe winning bid is $%.2f\n", aBid.maxBid);

}

int main(){
   Bid itemBid;
   char name[MAX_ITEM_NAME];
   float bidValue;
   int option = 1;

   initializeBid(&itemBid);

   while(option){
      printf("\n1. Add bidder\n");
      printf("2. Display bids\n");
      printf("0. Exit\n");
      printf("Enter option: ");
      scanf("%d", &option);

      switch(option){
         case 1:
            printf("\nEnter bidder name: ");
            scanf("%s", name);
            printf("Enter bid amount: $");
            scanf("%f", &bidValue);
            addBidder(&itemBid, name, bidValue);
            break;
         
         case 2:
            displayBids(itemBid);
            break;

         case 0:
            printf("\nExiting Program\n");
            option = 0;
            break;

         default:
            printf("\nInvalid option\n");
      }
   }

   return 0;
}