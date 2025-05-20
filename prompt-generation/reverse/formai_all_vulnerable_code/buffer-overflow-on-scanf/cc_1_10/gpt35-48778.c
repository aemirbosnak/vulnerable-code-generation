//FormAI DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_BIDDERS 20

struct product {
  int id;
  char name[50];
  float base_price;
  int bid_count;
  float highest_bid;
  char highest_bidder[50];
};

struct bidder {
  int id;
  char name[50];
  float budget;
  int num_bids;
  float total_spent;
};

void print_product(struct product p) {
  printf("\nID:%d\nName:%s\nBase Price:%.2f\nBid Count:%d\nHighest Bid:%.2f\nHighest Bidder:%s\n", p.id, p.name, p.base_price, p.bid_count, p.highest_bid, p.highest_bidder);
}

void print_user(struct bidder b) {
  printf("\nID:%d\nName:%s\nBudget:%.2f\nNum Bids:%d\nTotal Spent:%.2f\n", b.id, b.name, b.budget, b.num_bids, b.total_spent);
}

int main() {
  struct product products[MAX_PRODUCTS];
  struct bidder bidders[MAX_BIDDERS];
  int num_products = 0;
  int num_bidders = 0;
  int choice = 0;
  int product_index = 0;
  int bidder_index = 0;

  while (choice != 6) {
    printf("\n****** Welcome to the Digital Auction System ******\n");
    printf("1. Add Product\n2. List Products\n3. Add Bidder\n4. List Bidders\n5. Auction\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (num_products == MAX_PRODUCTS) {
          printf("\nError: Maximum number of products reached.\n");
          break;
        }
        printf("\nEnter product details:\n");
        printf("ID: ");
        scanf("%d", &products[num_products].id);

        printf("Name: ");
        scanf("%s", products[num_products].name);

        printf("Base Price: ");
        scanf("%f", &products[num_products].base_price);

        products[num_products].bid_count = 0;
        products[num_products].highest_bid = products[num_products].base_price;

        num_products++;
        break;
      case 2:
        printf("\n********** Product List **********\n");
        for (int i = 0; i < num_products; i++) {
          printf("\nProduct %d:", i+1);
          print_product(products[i]);
        }
        break;
      case 3:
        if (num_bidders == MAX_BIDDERS) {
          printf("\nError: Maximum number of bidders reached.\n");
          break;
        }
        printf("\nEnter bidder details:\n");
        printf("ID: ");
        scanf("%d", &bidders[num_bidders].id);

        printf("Name: ");
        scanf("%s", bidders[num_bidders].name);

        printf("Budget: ");
        scanf("%f", &bidders[num_bidders].budget);

        bidders[num_bidders].num_bids = 0;
        bidders[num_bidders].total_spent = 0;

        num_bidders++;
        break;
      case 4:
        printf("\n********** Bidder List **********\n");
        for (int i = 0; i < num_bidders; i++) {
          printf("\nBidder %d:", i+1);
          print_user(bidders[i]);
        }
        break;
      case 5:
        if (num_products == 0) {
          printf("\nError: No products available for auction.\n");
          break;
        }
        printf("\nEnter product ID to start auction: ");
        scanf("%d", &product_index);

        if (product_index < 1 || product_index > num_products) {
          printf("\nError: Invalid product ID.\n");
          break;
        }

        printf("\n********** Auction for %s **********\n", products[product_index-1].name);

        while (1) {
          printf("\n********** Bid Status **********\n");
          print_product(products[product_index-1]);
          printf("\n********** Bidder List **********\n");
          for (int i = 0; i < num_bidders; i++) {
            printf("\nBidder %d:", i+1);
            print_user(bidders[i]);
          }

          printf("\nEnter bidder ID to place bid or 0 to end auction: ");
          scanf("%d", &bidder_index);

          if (bidder_index == 0) {
            break;
          }

          if (bidder_index < 1 || bidder_index > num_bidders) {
            printf("\nError: Invalid bidder ID.\n");
            continue;
          }

          printf("\nEnter bid amount: ");
          float bid_amount;
          scanf("%f", &bid_amount);

          if (bid_amount > bidders[bidder_index-1].budget) {
            printf("\nError: Bid amount is higher than bidder's budget.\n");
            continue;
          }

          if (bid_amount <= products[product_index-1].highest_bid) {
            printf("\nError: Bid amount should be higher than current highest bid.\n");
            continue;
          }

          // Update product data
          products[product_index-1].bid_count++;
          products[product_index-1].highest_bid = bid_amount;
          strcpy(products[product_index-1].highest_bidder, bidders[bidder_index-1].name);

          // Update bidder data
          bidders[bidder_index-1].budget -= bid_amount;
          bidders[bidder_index-1].num_bids++;
          bidders[bidder_index-1].total_spent += bid_amount;

          printf("\nBid placed successfully.\n");
        }

        // Check if product was sold
        if (strcmp(products[product_index-1].highest_bidder, "") != 0) {
          printf("\n********** Auction for %s ended successfully **********\n", products[product_index-1].name);
          printf("\nHighest bid: %.2f\nHighest bidder: %s\n", products[product_index-1].highest_bid, products[product_index-1].highest_bidder);

          // Transfer funds
          for (int i = 0; i < num_bidders; i++) {
            if (strcmp(bidders[i].name, products[product_index-1].highest_bidder) == 0) {
              bidders[i].budget += products[product_index-1].highest_bid;
            }
          }
        }
        else {
          printf("\n********** Auction for %s ended with no bids **********\n", products[product_index-1].name);
        }

        // Reset product data
        products[product_index-1].bid_count = 0;
        products[product_index-1].highest_bid = products[product_index-1].base_price;
        strcpy(products[product_index-1].highest_bidder, "");

        break;
      case 6:
        printf("\nThank you for using the Digital Auction System. Goodbye!\n");
        break;
      default:
        printf("\nError: Invalid choice.\n");
    }
  }

  return 0;
}