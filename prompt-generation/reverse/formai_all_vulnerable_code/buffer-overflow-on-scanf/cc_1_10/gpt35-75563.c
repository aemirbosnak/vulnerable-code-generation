//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Welcome to the Digital Auction System!\n");
  printf("---------------------------------------\n");

  //initialize variables
  int num_items;
  printf("Enter the number of items up for auction: ");
  scanf("%d", &num_items);

  char item_names[num_items][20];
  int item_ids[num_items];
  float item_prices[num_items];

  //get details for each item
  for(int i=0; i<num_items; i++){
    printf("\nItem %d\n", i+1);

    //get item name
    printf("Enter the name of the item: ");
    scanf("%s", item_names[i]);

    //get item id
    printf("Enter the item ID: ");
    scanf("%d", &item_ids[i]);

    //get item starting price
    printf("Enter the item's starting price: $");
    scanf("%f", &item_prices[i]);
  }

  //start bidding process
  printf("\nBidding starts now!\n");
  printf("----------------------\n");
  int item_choice;
  float current_bid;
  int current_bidder_id;
  float highest_bid[num_items];
  int highest_bidder_id[num_items];

  for(int i=0; i<num_items; i++){
    current_bid = item_prices[i];
    current_bidder_id = 0;
    printf("\n%s ($%.2f) is now up for auction!\n", item_names[i], item_prices[i]);
    printf("Enter your bidder ID (any number): ");
    scanf("%d", &highest_bidder_id[i]);

    while(1){
      printf("\nCurrent highest bid: $%.2f\n", current_bid);
      printf("Enter your bid (or enter 0 to end bidding for this item): $");
      float new_bid;
      scanf("%f", &new_bid);

      if(new_bid == 0){
        printf("\nBidding has ended for %s ($%.2f)\n", item_names[i], current_bid);
        break;
      }

      if(new_bid > current_bid){
        printf("\nNew highest bid: $%.2f\n", new_bid);
        current_bid = new_bid;
        current_bidder_id = highest_bidder_id[i];
      }
      else{
        printf("\nBid too low, current highest bid is still $%.2f\n", current_bid);
      }
    }
    highest_bid[i] = current_bid;
    highest_bidder_id[i] = current_bidder_id;
    printf("\n");

  }

  //display results
  printf("\nAuction has ended! Here are the results:\n");
  for(int i=0; i<num_items; i++){
    printf("\n%s ($%.2f) was won by Bidder %d (item ID: %d)", item_names[i], highest_bid[i], highest_bidder_id[i], item_ids[i]);
  }
  printf("\n\nThanks for using our Digital Auction System!\n");

  return 0;
}