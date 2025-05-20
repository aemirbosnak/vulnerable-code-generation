//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>

struct product {
   int id;
   char name[50];
   float price;
   int quantity;
} products[100];

int count = 0;

void addProduct() {
   struct product p;
   printf("Enter product ID: ");
   scanf("%d", &p.id);
   printf("Enter product name: ");
   scanf("%s", p.name);
   printf("Enter product price: ");
   scanf("%f", &p.price);
   printf("Enter product quantity: ");
   scanf("%d", &p.quantity);
   products[count] = p;
   count++;
   printf("Product has been added to the warehouse.\n");
}

void displayProducts() {
   if (count == 0) {
      printf("There are no products in the warehouse.\n");
      return;
   }
   printf("ID\tName\tPrice\tQuantity\n");
   for (int i = 0; i < count; i++) {
      printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
   }
}

void updateProduct() {
   int id;
   printf("Enter the ID of the product you want to update: ");
   scanf("%d", &id);
   for (int i = 0; i < count; i++) {
      if (products[i].id == id) {
         printf("Enter new product name: ");
         scanf("%s", products[i].name);
         printf("Enter new product price: ");
         scanf("%f", &products[i].price);
         printf("Enter new product quantity: ");
         scanf("%d", &products[i].quantity);
         printf("Product has been updated.\n");
         return;
      }
   }
   printf("Product not found.\n");
}

void removeProduct() {
   int id;
   printf("Enter the ID of the product you want to remove: ");
   scanf("%d", &id);
   for (int i = 0; i < count; i++) {
      if (products[i].id == id) {
         for (int j = i; j < count - 1; j++) {
            products[j] = products[j + 1];
         }
         count--;
         printf("Product has been removed from the warehouse.\n");
         return;
      }
   }
   printf("Product not found.\n");
}

int main() {
   int choice;
   while (1) {
      printf("Enter your choice:\n");
      printf("1. Add product\n");
      printf("2. Display products\n");
      printf("3. Update product\n");
      printf("4. Remove product\n");
      printf("5. Exit\n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            addProduct();
            break;
         case 2:
            displayProducts();
            break;
         case 3:
            updateProduct();
            break;
         case 4:
            removeProduct();
            break;
         case 5:
            return 0;
         default:
            printf("Invalid choice. Please try again.\n");
      }
   }
}