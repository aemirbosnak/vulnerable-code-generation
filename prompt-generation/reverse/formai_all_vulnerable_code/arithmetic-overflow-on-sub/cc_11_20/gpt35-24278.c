//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[20];
  int quantity;
  float price;
  int bidder_id;
};

int main() {
  int num_items;
  printf("Enter the number of items: ");
  scanf("%d", &num_items);
  
  struct Item *items = malloc(num_items * sizeof(struct Item));
  
  for (int i = 0; i < num_items; i++) {
    printf("Enter the name of item %d: ", i+1);
    scanf("%s", items[i].name);
    
    printf("Enter the quantity of item %d: ", i+1);
    scanf("%d", &items[i].quantity);
    
    printf("Enter the price of item %d: ", i+1);
    scanf("%f", &items[i].price);
    
    items[i].bidder_id = 0;
  }
  
  int num_bidders;
  printf("Enter the number of bidders: ");
  scanf("%d", &num_bidders);
  
  char **bidders = malloc(num_bidders * sizeof(char*));
  for (int i = 0; i < num_bidders; i++) {
    bidders[i] = malloc(20 * sizeof(char));
    printf("Enter the name of bidder %d: ", i+1);
    scanf("%s", bidders[i]);
  }
  
  int selected_item = -1;
  
  while (selected_item != 0) {
    printf("\n");
    printf("Select an item to bid on (0 to exit):\n");
    for (int i = 0; i < num_items; i++) {
      printf("%d - %s\n", i+1, items[i].name);
    }
    
    scanf("%d", &selected_item);
    
    if (selected_item != 0 && selected_item <= num_items) {
      printf("Item selected: %s\n", items[selected_item-1].name);
      printf("Enter your bid for %s: ", items[selected_item-1].name);
      
      float bid;
      scanf("%f", &bid);
      
      if (bid > items[selected_item-1].price && items[selected_item-1].quantity > 0) {
        items[selected_item-1].price = bid;
        items[selected_item-1].bidder_id = rand() % num_bidders + 1;
        printf("Bid accepted!");
      } else {
        printf("Bid not accepted.");
      }
    }
  }
  
  printf("\n\nAuction Results:\n");
  for (int i = 0; i < num_items; i++) {
    if (items[i].bidder_id != 0) {
      printf("%s sold to %s for $%.2f\n", items[i].name, bidders[items[i].bidder_id-1], items[i].price);
    } else {
      printf("%s not sold.\n", items[i].name);
    }
  }
  
  free(items);
  for (int i = 0; i < num_bidders; i++) {
    free(bidders[i]);
  }
  free(bidders);
  
  return 0;
}