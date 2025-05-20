//FormAI DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
   char name[100];
   int id;
   int qty;
   float price;
} Product;

int menu() {
   int choice;
   printf("\n1. Add new product");
   printf("\n2. Display all products");
   printf("\n3. Search product by ID");
   printf("\n4. Search product by name");
   printf("\n5. Update quantity of product");
   printf("\n6. Delete product"); 
   printf("\n7. Exit"); 
   printf("\nEnter your choice: ");
   scanf("%d", &choice);
   return choice;
}

void addProduct(Product* products, int size) {
   printf("\nEnter product details-\n");
   printf("Name: ");
   scanf("%s", products[size].name);
   printf("ID: ");
   scanf("%d", &products[size].id);
   printf("Quantity: ");
   scanf("%d", &products[size].qty);
   printf("Price: ");
   scanf("%f", &products[size].price);
   printf("Product added successfully!\n");
}

void displayProducts(Product* products, int size) {
   printf("\n%-10s %-20s %-15s %6s\n", "ID", "Name", "Quantity", "Price");
   for(int i=0; i<size; i++)
      printf("%-10d %-20s %-15d %6.2f\n", products[i].id, products[i].name, products[i].qty, products[i].price);
}

void searchByID(Product* products, int size) {
   int id, idx=-1;
   printf("\nEnter ID to search: ");
   scanf("%d", &id);
   for(int i=0; i<size; i++) {
      if(products[i].id == id) {
         idx = i;
         break;
      }
   }
   if(idx!=-1) {
      printf("\n%-10s %-20s %-15s %6s\n", "ID", "Name", "Quantity", "Price");
      printf("%-10d %-20s %-15d %6.2f\n", products[idx].id, products[idx].name, products[idx].qty, products[idx].price);
   }
   else {
      printf("\nProduct not found!\n");
   }
}

void searchByName(Product* products, int size) {
   char name[100];
   int found=0;
   printf("\nEnter name to search: ");
   scanf("%s", name);
   printf("\n%-10s %-20s %-15s %6s\n", "ID", "Name", "Quantity", "Price");
   for(int i=0; i<size; i++) {
      if(strcmp(products[i].name, name)==0) {
         printf("%-10d %-20s %-15d %6.2f\n", products[i].id, products[i].name, products[i].qty, products[i].price);
         found=1;
      }
   }
   if(!found) {
      printf("\nProduct not found!\n");
   }
}

void updateQty(Product* products, int size) {
   int id, qty;
   printf("\nEnter ID of product to update quantity: ");
   scanf("%d", &id);
   for(int i=0; i<size; i++) {
      if(products[i].id == id) {
         printf("\nEnter new quantity: ");
         scanf("%d", &qty);
         products[i].qty = qty;
         printf("Quantity updated successfully!\n");
         return;
      }
   }
   printf("\nProduct not found!\n");
}

void deleteProduct(Product* products, int* size) {
   int id, idx=-1;
   printf("\nEnter ID of product to delete: ");
   scanf("%d", &id);
   for(int i=0; i<*size; i++) {
      if(products[i].id == id) {
         idx = i;
         break;
      }
   }
   if(idx!=-1) {
      for(int i=idx; i<*size-1; i++) {
         strcpy(products[i].name, products[i+1].name);
         products[i].id = products[i+1].id;
         products[i].qty = products[i+1].qty;
         products[i].price = products[i+1].price;
      }
      (*size)--;
      printf("\nProduct deleted successfully!\n");
   }
   else {
      printf("\nProduct not found!\n");
   }
}

int main() {
   Product* products = malloc(sizeof(Product));
   int size=0, choice;
   do {
      choice = menu();
      switch(choice) {
         case 1: 
            products = realloc(products, (size+1)*sizeof(Product));
            addProduct(products, size);
            size++;
            break;
         case 2: 
            displayProducts(products, size);
            break;
         case 3: 
            searchByID(products, size);
            break;
         case 4: 
            searchByName(products, size);
            break;
         case 5:
            updateQty(products, size);
            break;
         case 6:
            deleteProduct(products, &size);
            break;
         case 7:
            printf("\nExiting program...\n");
            break;
         default:
            printf("\nInvalid choice!\n");
            break;
      }
   } while(choice!=7);
   
   free(products);
   return 0;
}