//FormAI DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
   char name[20];
   int id;
   float price;
} product;

void addProduct(product **storePtr, int *countPtr) {
   if (*countPtr >= MAX_PRODUCTS) {
      printf("Inventory is full!\n");
      return;
   }
   product *newProduct = (product *) malloc(sizeof(product));
   if (!newProduct) {
      printf("Memory allocation failed!\n");
      return;
   }
   printf("Enter product name: ");
   scanf("%s", newProduct->name);
   printf("Enter product ID: ");
   scanf("%d", &newProduct->id);
   printf("Enter the price of the product: ");
   scanf("%f", &newProduct->price);
   (*storePtr)[*countPtr] = *newProduct;
   *countPtr += 1;
   free(newProduct);
   printf("Added product to inventory.\n");
}

void displayProducts(product *store, int count) {
    if (count == 0) {
        printf("\nNo products in inventory.\n\n");
        return;
    }
    printf("\n%-20s%-10s%-10s\n", "Product Name", "Product ID", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-10d%-10.2f\n", store[i].name, store[i].id, store[i].price);   
    }
    printf("\n");
}

void removeProduct(product **storePtr, int *countPtr, int id) {
    if (*countPtr == 0) {
        printf("No products in inventory.\n");
        return;
    }
    int index = -1;
    for (int i = 0; i < *countPtr; i++) {
        if ((*storePtr)[i].id == id) {
            index = i;
        }
    }
    if (index < 0) {
        printf("Product not found in inventory.\n");
        return;
    }
    for (int i = index; i < (*countPtr - 1); i++) {
        (*storePtr)[i] = (*storePtr)[i + 1];
    }
    (*countPtr)--;
    printf("Removed product from inventory.\n");
}

int main() {
    product *store = (product *) calloc(MAX_PRODUCTS, sizeof(product));
    if (!store) {
        printf("Memory allocation failed!\n");
        return 0;
    }
    int count = 0;
    while (1) {
        int choice = 0;
        printf("1. Add product to inventory\n");
        printf("2. Display products in inventory\n");
        printf("3. Remove product from inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(&store, &count);
                break;
            case 2:
                displayProducts(store, count);
                break;
            case 3:
                printf("Enter product ID to remove: ");
                int id;
                scanf("%d", &id);
                removeProduct(&store, &count, id);
                break;
            case 4:
                free(store);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}