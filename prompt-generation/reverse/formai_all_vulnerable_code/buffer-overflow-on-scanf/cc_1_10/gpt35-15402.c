//FormAI DATASET v1.0 Category: Product Inventory System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

typedef struct Product {
   int id;
   char name[50];
   double price;
   int qty;
} Product;

Product products[MAX_PRODUCTS];

int count = 0;

void addProduct() {
   if (count >= MAX_PRODUCTS) {
      printf("Inventory is full\n");
   }
   else {
      Product newProduct;

      printf("Enter Product ID: ");
      scanf("%d", &newProduct.id);

      printf("Enter Product Name: ");
      scanf("%s", newProduct.name);

      printf("Enter Product Price: ");
      scanf("%lf", &newProduct.price);

      printf("Enter Product Quantity: ");
      scanf("%d", &newProduct.qty);

      products[count++] = newProduct;

      printf("\nProduct added successfully!\n");
   }
}

void displayProducts() {
   if (count == 0) {
      printf("No products in inventory\n");
   }
   else {
      printf("\nID    Name                 Price          Quantity\n");
      printf("------------------------------------------------------\n");

      for (int i = 0; i < count; i++) {
         printf("%-5d %-20s $%-12.2lf %-8d\n", products[i].id, products[i].name, products[i].price, products[i].qty);
      }
   }
}

void searchProduct() {
   int pid = -1;

   printf("Enter Product ID to search: ");
   scanf("%d", &pid);

   for (int i = 0; i < count; i++) {
      if (products[i].id == pid) {
         printf("\nID: %d\n", products[i].id);
         printf("Name: %s\n", products[i].name);
         printf("Price: $%.2lf\n", products[i].price);
         printf("Quantity: %d\n\n", products[i].qty);
         return;
      }
   }

   printf("Product not found\n\n");
}

void removeProduct() {
   int pid = -1;

   printf("Enter Product ID to remove: ");
   scanf("%d", &pid);

   for (int i = 0; i < count; i++) {
      if (products[i].id == pid) {
         for (int j = i; j < count - 1; j++) {
            products[j] = products[j + 1];
         }

         count--;
         printf("\nProduct removed successfully!\n\n");
         return;
      }
   }

   printf("Product not found\n\n");
}

int main() {
   int choice = -1;

   while (choice != 0) {
      printf("Product Inventory System\n");
      printf("----------------------------\n");
      printf("1. Add Product\n");
      printf("2. Display Products\n");
      printf("3. Search Product\n");
      printf("4. Remove Product\n");
      printf("0. Exit\n\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 0:
            printf("Exiting program...\n");
            break;
         case 1:
            addProduct();
            break;
         case 2:
            displayProducts();
            break;
         case 3:
            searchProduct();
            break;
         case 4:
            removeProduct();
            break;
         default:
            printf("Invalid choice\n");
            break;
      }
   }

   return 0;
}