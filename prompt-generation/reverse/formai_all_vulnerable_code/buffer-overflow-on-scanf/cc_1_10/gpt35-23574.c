//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* struct to store the details of the auction item */
struct auction_item {
   char name[50];
   int base_price;
   char seller[50];
   char buyer[50];
   int current_bid;
};

/* function prototypes */
void add_item(struct auction_item items[], int *num_items);
void display_items(struct auction_item items[], int num_items);
void make_bid(struct auction_item items[], int num_items);

/* main function */
int main() {
   struct auction_item items[50];
   int num_items = 0;
   int choice;

   printf("Welcome to Digital Auction System v1.0\n");

   /* loop until user exits */
   while(1) {
      printf("\nMenu:\n");
      printf("1. Add item\n2. Display items\n3. Make a bid\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            add_item(items, &num_items);
            break;
         case 2:
            display_items(items, num_items);
            break;
         case 3:
            make_bid(items, num_items);
            break;
         case 4:
            printf("Thank you for using Digital Auction System!\n");
            exit(0);
         default:
            printf("Invalid choice. Try again.\n");
      }
   }
   return 0;
}

/* function to add an item to the auction */
void add_item(struct auction_item items[], int *num_items) {
   struct auction_item new_item;

   printf("Enter name of the item: ");
   scanf("%s", new_item.name);
   printf("Enter base price of the item: ");
   scanf("%d", &new_item.base_price);
   printf("Enter seller name: ");
   scanf("%s", new_item.seller);
   new_item.current_bid = new_item.base_price;
   strcpy(new_item.buyer, "None");

   /* add the new item to the array */
   items[*num_items] = new_item;
   (*num_items)++;
   printf("Item added successfully!\n");
}

/* function to display all the items in the auction */
void display_items(struct auction_item items[], int num_items) {
   int i;

   if(num_items == 0) {
      printf("No items to display.\n");
      return;
   }

   printf("\n%-20s%-15s%-15s%-15s%-15s\n", "Name", "Base Price", "Seller", "Buyer", "Current Bid");
   for(i=0; i<num_items; i++) {
      printf("%-20s%-15d%-15s%-15s%-15d\n", items[i].name, items[i].base_price, items[i].seller, items[i].buyer, items[i].current_bid);
   }
}

/* function to make a bid on an item */
void make_bid(struct auction_item items[], int num_items) {
   char bidder_name[50], item_name[50];
   int i, bid_amount;

   printf("Enter your name: ");
   scanf("%s", bidder_name);
   printf("Enter the name of the item you want to bid on: ");
   scanf("%s", item_name);

   /* search for the item with the given name */
   for(i=0; i<num_items; i++) {
      if(strcmp(items[i].name, item_name) == 0) {
         printf("Item found!\n");
         printf("Enter your bid amount: ");
         scanf("%d", &bid_amount);

         /* check if the bid amount is greater than the current bid */
         if(bid_amount > items[i].current_bid) {
            printf("Congratulations! You have the highest bid.\n");
            items[i].current_bid = bid_amount;
            strcpy(items[i].buyer, bidder_name);
         }
         else {
            printf("Sorry. Your bid amount is less than the current bid.\n");
         }
         return;
      }
   }
   /* item not found */
   printf("Item not found. Try again.\n");
}