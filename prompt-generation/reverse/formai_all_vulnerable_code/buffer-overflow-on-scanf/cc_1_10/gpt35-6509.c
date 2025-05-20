//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for item
struct Item {
   char name[20];
   int price;
   int qty;
};

// Function to add item to the menu
void addItem(struct Item menu[], int *count) {
   printf("\nEnter item details: \n");
   printf("Name: ");
   scanf("%s", menu[*count].name);
   printf("Price: ");
   scanf("%d", &menu[*count].price);
   printf("Quantity: ");
   scanf("%d", &menu[*count].qty);
   (*count)++;
   printf("\nItem added to the menu successfully!\n\n");
}

// Function to display the menu
void displayMenu(struct Item menu[], int count) {
   printf("\n\t\tMenu\n\n");
   printf("Name\t\tPrice\tQuantity\n\n");
   for (int i = 0; i < count; i++) {
      printf("%s\t\t%d\t%d\n", menu[i].name, menu[i].price, menu[i].qty);
   }
   printf("\n");
}

// Function to place order
void placeOrder(struct Item menu[], int count) {
   int choice, qty, total = 0;
   char ans;
   do {
      displayMenu(menu, count);
      printf("Enter your choice (1-%d): ", count);
      scanf("%d", &choice);
      printf("Enter quantity: ");
      scanf("%d", &qty);
      if (qty < 1 || qty > menu[choice-1].qty) {
         printf("\nInvalid quantity!\n\n");
         continue;
      }
      total += qty * menu[choice-1].price; 
      menu[choice-1].qty -= qty;
      printf("\nDo you want to order anything else? (y/n): ");
      scanf(" %c", &ans);
   } while (ans == 'y' || ans == 'Y');
   printf("\nTotal bill: %d\n\n", total);
}

int main() {
   struct Item menu[10];
   int count = 0, choice;
   char ans;
   
   // Menu
   printf("\tC Cafe Billing System\t\n\n");
   while (1) {
      printf("1. Add item to the menu\n");
      printf("2. Place order\n");
      printf("3. Exit\n\n");
      printf("Enter your choice (1-3): ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            if (count == 10) {
               printf("\nMenu is full!\n\n");
               continue;
            }
            addItem(menu, &count);
            break;
         case 2:
            if (count == 0) {
               printf("\nMenu is empty!\n\n");
               continue;
            }
            placeOrder(menu, count);
            break;
         case 3:
            printf("\nThank you for using the C Cafe Billing System!\n\n");
            exit(0);
         default:
            printf("\nInvalid choice!\n\n");
            break;
      }
   }
   return 0;
}