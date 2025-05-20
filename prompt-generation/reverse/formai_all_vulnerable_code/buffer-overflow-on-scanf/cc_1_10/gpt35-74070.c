//FormAI DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
   char name[50];
   int quantity;
   float price;
};

struct product inventory[100];
int num_products = 0;

void addProduct() {
   struct product p;
   printf("Enter product name: ");
   scanf("%s", p.name);
   printf("Enter quantity: ");
   scanf("%d", &p.quantity);
   printf("Enter price: ");
   scanf("%f", &p.price);
   inventory[num_products++] = p;
}

void editProduct() {
   int index;
   printf("Enter index of product to edit: ");
   scanf("%d", &index);
   printf("Enter new product name: ");
   scanf("%s", inventory[index].name);
   printf("Enter new quantity: ");
   scanf("%d", &inventory[index].quantity);
   printf("Enter new price: ");
   scanf("%f", &inventory[index].price);
}

void deleteProduct() {
   int index;
   printf("Enter index of product to delete: ");
   scanf("%d", &index);
   for (int i = index; i < num_products - 1; i++) {
      inventory[i] = inventory[i+1];
   }
   num_products--;
}

void viewProducts() {
   printf("%-25s%-10s%-10s\n", "Name", "Quantity", "Price");
   for (int i = 0; i < num_products; i++) {
      printf("%-25s%-10d%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
   }
}

int main() {
   int option;
   printf("Product Inventory System\n");
   printf("------------------------\n");
   while (1) {
      printf("\n1. Add Product\n");
      printf("2. Edit Product\n");
      printf("3. Delete Product\n");
      printf("4. View Products\n");
      printf("5. Exit\n");
      printf("------------------------\n");
      printf("Enter your choice: ");
      scanf("%d", &option);
      switch (option) {
         case 1:
            addProduct();
            break;
         case 2:
            editProduct();
            break;
         case 3:
            deleteProduct();
            break;
         case 4:
            viewProducts();
            break;
         case 5:
            exit(0);
         default:
            printf("Invalid choice!\n");
            break;
      }
   }
   return 0;
}