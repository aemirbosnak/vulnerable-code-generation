//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

struct product {
   int id;
   char name[50];
   int quantity;
   float price;
};

struct product inventory[MAX_PRODUCTS];

int num_products = 0;

void prompt(char *message) {
   printf("%s\n", message);
}

int validate_id(int id) {
   int i;
   for (i = 0; i < num_products; i++) {
      if (inventory[i].id == id) {
         return 0;
      }
   }
   return 1;
}

void add_product(int id, char *name, int quantity, float price) {
   inventory[num_products].id = id;
   strcpy(inventory[num_products].name, name);
   inventory[num_products].quantity = quantity;
   inventory[num_products].price = price;
   num_products++;
}

void show_all_products() {
   int i;
   printf("%-10s| %-30s| %-10s| %-10s\n", "ID", "NAME", "QUANTITY", "PRICE");
   for (i = 0; i < num_products; i++) {
      printf("%-10d| %-30s| %-10d| %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
   }
}

void search_product(char *name) {
   int i;
   for (i = 0; i < num_products; i++) {
      if (strcmp(inventory[i].name, name) == 0) {
         printf("%-10s| %-30s| %-10s| %-10s\n", "ID", "NAME", "QUANTITY", "PRICE");
         printf("%-10d| %-30s| %-10d| %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
         return;
      }
   }
   printf("Product not found.\n");
}

void remove_product(int id) {
   int i;
   for (i = 0; i < num_products; i++) {
      if (inventory[i].id == id) {
         int j;
         for (j = i; j < num_products-1; j++) {
            inventory[j] = inventory[j+1];
         }
         num_products--;
         return;
      }
   }
   printf("Product not found.\n");
}

void update_product(int id, char *name, int quantity, float price) {
   int i;
   for (i = 0; i < num_products; i++) {
      if (inventory[i].id == id) {
         strcpy(inventory[i].name, name);
         inventory[i].quantity = quantity;
         inventory[i].price = price;
         return;
      }
   }
   printf("Product not found.\n");
}

int main() {
   prompt("Welcome to the Product Inventory System");
   prompt("Please choose an option:");
   while (1) {
      prompt("1. Add product");
      prompt("2. Show all products");
      prompt("3. Search product by name");
      prompt("4. Remove product by ID");
      prompt("5. Update product by ID");
      prompt("6. Exit");
      int choice = 0;
      scanf("%d", &choice);
      fflush(stdin);
      switch(choice) {
         case 1: {
            int id;
            char name[50];
            int quantity;
            float price;
            prompt("Enter product ID:");
            scanf("%d", &id);
            fflush(stdin);
            if (validate_id(id)) {
               prompt("Enter product name:");
               gets(name);
               prompt("Enter product quantity:");
               scanf("%d", &quantity);
               fflush(stdin);
               prompt("Enter product price:");
               scanf("%f", &price);
               fflush(stdin);
               add_product(id, name, quantity, price);
               printf("Product added successfully.\n");
            } else {
               printf("Product ID already exists.\n");
            }
            break;
         }
         case 2: {
            if (num_products == 0) {
               printf("Product inventory is empty.\n");
            } else {
               show_all_products();
            }
            break;
         }
         case 3: {
            char name[50];
            prompt("Enter product name:");
            gets(name);
            search_product(name);
            break;
         }
         case 4: {
            int id;
            prompt("Enter product ID:");
            scanf("%d", &id);
            fflush(stdin);
            remove_product(id);
            break;
         }
         case 5: {
            int id;
            char name[50];
            int quantity;
            float price;
            prompt("Enter product ID:");
            scanf("%d", &id);
            fflush(stdin);
            prompt("Enter product name:");
            gets(name);
            prompt("Enter product quantity:");
            scanf("%d", &quantity);
            fflush(stdin);
            prompt("Enter product price:");
            scanf("%f", &price);
            fflush(stdin);
            update_product(id, name, quantity, price);
            break;
         }
         case 6: {
            printf("Goodbye!\n");
            exit(0);
            break;
         }
         default: {
            printf("Invalid choice. Please try again.\n");
            break;
         }
      }
   }
   return 0;
}