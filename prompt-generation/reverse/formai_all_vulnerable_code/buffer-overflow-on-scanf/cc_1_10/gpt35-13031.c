//FormAI DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 20

struct product {
   int id;
   char name[50];
   int quantity;
   float price;
};

void add_product(struct product products[], int* count);
void display_products(struct product products[], int count);
void sell_product(struct product products[], int count);

int main() {
   struct product products[MAX_PRODUCTS];
   int choice, count = 0;
   
   do {
      printf("Welcome to Product Inventory System!\n");
      printf("1. Add a product\n");
      printf("2. Display all products\n");
      printf("3. Sell a product\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            add_product(products, &count);
            break;
         case 2:
            display_products(products, count);
            break;
         case 3:
            sell_product(products, count);
            break;
         case 4:
            printf("Thanks for using Product Inventory System. Goodbye!\n");
            break;
         default:
            printf("Invalid choice. Please try again.\n");
            break;
      }
      printf("\n");
   } while (choice != 4);
   
   return 0;
}

void add_product(struct product products[], int* count) {
   if (*count == MAX_PRODUCTS) {
      printf("Sorry, Product Inventory System can only hold %d products.\n", MAX_PRODUCTS);
   } else {
      printf("Enter product details:\n");
      printf("Product ID: ");
      scanf("%d", &products[*count].id);
      printf("Product Name: ");
      scanf("%s", products[*count].name);
      printf("Product Quantity: ");
      scanf("%d", &products[*count].quantity);
      printf("Product Price: ");
      scanf("%f", &products[*count].price);
      printf("Product Added Successfully!\n");
      (*count)++;
   }
}

void display_products(struct product products[], int count) {
   if (count == 0) {
      printf("Sorry, Product Inventory System is currently empty.\n");
   } else {
      printf("ID\tName\tQuantity\tPrice\n");
      for (int i = 0; i < count; i++) {
         printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
      }
   }
}

void sell_product(struct product products[], int count) {
   int id, index = -1;
   
   if (count == 0) {
      printf("Sorry, Product Inventory System is currently empty.\n");
   } else {
      printf("Enter product ID to sell: ");
      scanf("%d", &id);
      
      for (int i = 0; i < count; i++) {
         if (products[i].id == id) {
            index = i;
            break;
         }
      }
      
      if (index == -1) {
         printf("Sorry, product with ID %d not found in Product Inventory System.\n", id);
      } else {
         if (products[index].quantity == 0) {
            printf("Sorry, product with ID %d is out of stock.\n", id);
         } else {
            printf("Selling %s with ID %d for %.2f. Enjoy your purchase!\n", products[index].name, products[index].id, products[index].price);
            products[index].quantity--;
         }
      }
   }
}