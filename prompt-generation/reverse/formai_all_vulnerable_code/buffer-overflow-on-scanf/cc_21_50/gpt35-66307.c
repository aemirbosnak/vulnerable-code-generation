//FormAI DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20   //Maximum number of items that can be up for auction
#define MAX_BIDDERS 50 //Maximum number of bidders allowed

// Item structure to hold information about the item to be auctioned
typedef struct {
  char name[50];     //Name of the item
  int min_bid;       //Minimum bid required to buy the item
  int current_bid;   //Current bid for the item
  char bidder_name[50]; //Name of the bidder who has placed the current bid for the item
} Auction_Item;

// Bidder structure to hold information about the bidders in the auction
typedef struct {
  char name[50];     //Name of the bidder
  int budget;        //Budget of the bidder
} Bidder;

int main() {
  
  Auction_Item items[MAX_ITEMS]; //Array to hold the items
  Bidder bidders[MAX_BIDDERS];   //Array to hold the bidders
  
  int num_items = 0;   //Number of items in the auction
  int num_bidders = 0; //Number of bidders in the auction
  
  while (1) {
    printf("\nWelcome to the Digital Auction System\n");
    printf("1. Add item to auction\n");
    printf("2. Add bidder to auction\n");
    printf("3. List all items up for auction\n");
    printf("4. List all bidders in the auction\n");
    printf("5. Place bid on an item\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      
      // Add an item to the auction
      case 1: {
        if (num_items == MAX_ITEMS) {
          printf("Sorry, the maximum number of items allowed for auction is %d\n", MAX_ITEMS);
        } else {
          printf("Enter item name: ");
          scanf("%s", items[num_items].name);
          printf("Enter minimum bid: ");
          scanf("%d", &items[num_items].min_bid);
          items[num_items].current_bid = items[num_items].min_bid;
          strcpy(items[num_items].bidder_name, "None");
          num_items++;
          printf("Item added to auction!\n");
        }
        break;
      }
      
      // Add a bidder to the auction
      case 2: {
        if (num_bidders == MAX_BIDDERS) {
          printf("Sorry, the maximum number of bidders allowed in the auction is %d\n", MAX_BIDDERS);
        } else {
          printf("Enter bidder name: ");
          scanf("%s", bidders[num_bidders].name);
          printf("Enter bidder budget: ");
          scanf("%d", &bidders[num_bidders].budget);
          num_bidders++;
          printf("Bidder added to auction!\n");
        }
        break;
      }
      
      // List all items up for auction
      case 3: {
        if (num_items == 0) {
          printf("There are currently no items up for auction\n");
        } else {
          printf("\n------------------------\n");
          printf("Items up for Auction:\n");
          for (int i = 0; i < num_items; i++) {
            printf("------------------------\n");
            printf("Item %d\n", i+1);
            printf("Name: %s\n", items[i].name);
            printf("Minimum Bid: $%d\n", items[i].min_bid);
            printf("Current Bid: $%d\n", items[i].current_bid);
            printf("Bidder: %s\n", items[i].bidder_name);
          }
          printf("------------------------\n");
        }
        break;
      }
      
      // List all bidders in the auction
      case 4: {
        if (num_bidders == 0) {
          printf("There are currently no bidders in the auction\n");
        } else {
          printf("\n------------------------\n");
          printf("Bidders in the Auction:\n");
          for (int i = 0; i < num_bidders; i++) {
            printf("------------------------\n");
            printf("Bidder %d\n", i+1);
            printf("Name: %s\n", bidders[i].name);
            printf("Budget: $%d\n", bidders[i].budget);
          }
          printf("------------------------\n");
        }
        break;
      }
      
      // Place a bid on an item
      case 5: {
        if (num_items == 0) {
          printf("There are currently no items up for auction\n");
        } else if (num_bidders == 0) {
          printf("There are currently no bidders in the auction\n");
        } else {
          printf("Enter the item number you wish to bid on: ");
          int item_num;
          scanf("%d", &item_num);
          
          if (item_num > num_items || item_num < 1) {
            printf("Invalid item number\n");
          } else {
            printf("Enter your bidder number: ");
            int bidder_num;
            scanf("%d", &bidder_num);
            
            if (bidder_num > num_bidders || bidder_num < 1) {
              printf("Invalid bidder number\n");
            } else {
              printf("Enter your bid amount: ");
              int bid_amount;
              scanf("%d", &bid_amount);
              
              if (bid_amount <= items[item_num-1].current_bid) {
                printf("Bid amount must be greater than the current bid of $%d\n", items[item_num-1].current_bid);
              } else if (bid_amount > bidders[bidder_num-1].budget) {
                printf("Sorry, your bid exceeds your budget of $%d\n", bidders[bidder_num-1].budget);
              } else {
                items[item_num-1].current_bid = bid_amount;
                strcpy(items[item_num-1].bidder_name, bidders[bidder_num-1].name);
                printf("Congratulations! You are now the highest bidder for %s with a bid of $%d\n", items[item_num-1].name, items[item_num-1].current_bid);
              }
            }
          }
        }
        break;
      }
      
      // Exit the program
      case 6: {
        printf("Goodbye!\n");
        exit(0);
      }

      //Invalid choice
      default: {
         printf("Invalid choice\n");
         break;
      }
    }
  }

  return 0;
}