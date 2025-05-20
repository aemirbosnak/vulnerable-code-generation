//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the price for each menu item
#define PRICE_PASTRY 50
#define PRICE_COFFEE 30
#define PRICE_SANDWICH 70
#define PRICE_SMOOTHIE 90

// Initializing the struct for the menu items
typedef struct menuItem {
   char name[30];
   int quantity;
   double price;
} MenuItem;

// Initializing the struct for the order
typedef struct order {
   MenuItem pastry;
   MenuItem coffee;
   MenuItem sandwich;
   MenuItem smoothie;
   double total;
} Order;

// Function to display the menu and take the order
Order takeOrder() {
   Order newOrder = {0};

   printf("Welcome to Cafe Billing System!\n");
   printf("Today's Menu:\n");
   printf("1. Pastry - $%d\n", PRICE_PASTRY);
   printf("2. Coffee - $%d\n", PRICE_COFFEE);
   printf("3. Sandwich - $%d\n", PRICE_SANDWICH);
   printf("4. Smoothie - $%d\n", PRICE_SMOOTHIE);
   printf("\n");

   // Taking order for pastry
   printf("Enter the quantity of pastry: ");
   scanf("%d", &newOrder.pastry.quantity);
   newOrder.pastry.price = PRICE_PASTRY;
   strcpy(newOrder.pastry.name, "Pastry");

   // Taking order for coffee
   printf("Enter the quantity of coffee: ");
   scanf("%d", &newOrder.coffee.quantity);
   newOrder.coffee.price = PRICE_COFFEE;
   strcpy(newOrder.coffee.name, "Coffee");

   // Taking order for sandwich
   printf("Enter the quantity of sandwich: ");
   scanf("%d", &newOrder.sandwich.quantity);
   newOrder.sandwich.price = PRICE_SANDWICH;
   strcpy(newOrder.sandwich.name, "Sandwich");

   // Taking order for smoothie
   printf("Enter the quantity of smoothie: ");
   scanf("%d", &newOrder.smoothie.quantity);
   newOrder.smoothie.price = PRICE_SMOOTHIE;
   strcpy(newOrder.smoothie.name, "Smoothie");

   // Calculating the total price for the order
   newOrder.total = (newOrder.pastry.quantity * newOrder.pastry.price) + 
                     (newOrder.coffee.quantity * newOrder.coffee.price) + 
                     (newOrder.sandwich.quantity * newOrder.sandwich.price) + 
                     (newOrder.smoothie.quantity * newOrder.smoothie.price);

   return newOrder;
}

// Function to display the invoice for the order
void displayInvoice(Order order) {
   printf("\n===== INVOICE =====\n");
   printf("Item\t\t\tQuantity\tPrice\n");
   printf("%s\t\t\t%d\t\t$%.2lf\n", order.pastry.name, order.pastry.quantity, 
          (double)order.pastry.price);
   printf("%s\t\t\t%d\t\t$%.2lf\n", order.coffee.name, order.coffee.quantity, 
          (double)order.coffee.price);
   printf("%s\t\t%d\t\t$%.2lf\n", order.sandwich.name, order.sandwich.quantity, 
          (double)order.sandwich.price);
   printf("%s\t\t\t%d\t\t$%.2lf\n", order.smoothie.name, order.smoothie.quantity, 
          (double)order.smoothie.price);
   printf("\nTotal: $%.2lf\n", order.total);
}

int main() {
   Order newOrder = takeOrder();
   displayInvoice(newOrder);

   return 0;
}