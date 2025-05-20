//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  int id;
  char name[50];
  int price;
} item;

typedef struct bid {
  int item_id;
  char bidder_name[50];
  int bid_amount;
} bid;

int find_item_index(item* items, int item_count, int item_id) {
  int i;
  for(i=0;i<item_count;i++) {
    if(items[i].id == item_id) {
      return i;
    }
  }
  return -1;
}

int find_bid_index(bid* bids, int bid_count, int item_id, char* bidder_name) {
  int i;
  for(i=0;i<bid_count;i++) {
    if(bids[i].item_id == item_id && strcmp(bids[i].bidder_name,bidder_name) == 0) {
      return i;
    }
  }
  return -1;
}

void add_item(item* items, int* item_count, int id, char* name, int price) {
  item i;
  i.id = id;
  strcpy(i.name,name);
  i.price = price;
  items[*item_count] = i;
  *item_count += 1;
}

void add_bid(bid* bids, int* bid_count, int item_id, char* bidder_name, int bid_amount) {
  bid b;
  b.item_id = item_id;
  strcpy(b.bidder_name,bidder_name);
  b.bid_amount = bid_amount;
  bids[*bid_count] = b;
  *bid_count += 1;
}

void print_item(item i) {
  printf("%d|%s|%d\n",i.id,i.name,i.price);
}

void print_bid(bid b) {
  printf("%d|%s|%d\n",b.item_id,b.bidder_name,b.bid_amount);
}

int main() {
  item items[50];
  int item_count = 0;
  bid bids[50];
  int bid_count = 0;
  int option = 0;
  while(1) {
    printf("Digital Auction System\n");
    printf("1. Add Item\n");
    printf("2. Add Bid\n");
    printf("3. List Items\n");
    printf("4. List Bids\n");
    printf("5. Exit\n");
    scanf("%d",&option);
    switch(option) {
      case 1: {
        int id;
        char name[50];
        int price;
        printf("Enter Item ID: ");
        scanf("%d",&id);
        printf("Enter Item Name: ");
        scanf("%s",name);
        printf("Enter Item Price: ");
        scanf("%d",&price);
        add_item(items,&item_count,id,name,price);
        break;
      }
      case 2: {
        int item_id;
        char bidder_name[50];
        int bid_amount;
        printf("Enter Item ID: ");
        scanf("%d",&item_id);
        printf("Enter Bidder Name: ");
        scanf("%s",bidder_name);
        printf("Enter Bid Amount: ");
        scanf("%d",&bid_amount);
        int item_index = find_item_index(items,item_count,item_id);
        if(item_index == -1) {
          printf("Item not found.\n");
        }
        else {
          int bid_index = find_bid_index(bids,bid_count,item_id,bidder_name);
          if(bid_index == -1 || bid_amount > bids[bid_index].bid_amount) {
            add_bid(bids,&bid_count,item_id,bidder_name,bid_amount);
          }
          else {
            printf("Bid amount is not higher than current bid amount.\n");
          }
        }
        break;
      }
      case 3: {
        printf("ID|Name|Price\n");
        int i;
        for(i=0;i<item_count;i++) {
          print_item(items[i]);
        }
        break;
      }
      case 4: {
        printf("Item ID|Bidder Name|Bid Amount\n");
        int i;
        for(i=0;i<bid_count;i++) {
          print_bid(bids[i]);
        }
        break;
      }
      case 5: {
        printf("Exiting...\n");
        exit(0);
      }
      default: {
        printf("Invalid option.\n");
        break;
      }
    }
  }
  return 0;
}