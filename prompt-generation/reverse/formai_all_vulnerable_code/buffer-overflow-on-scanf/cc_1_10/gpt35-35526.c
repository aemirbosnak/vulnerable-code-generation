//FormAI DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InventoryItem {
  char name[50];
  int quantity;
  float price;
};

int main() {
  int inventorySize;
  
  printf("Enter number of inventory items: ");
  scanf("%d", &inventorySize);
  
  struct InventoryItem *inventory = (struct InventoryItem*) malloc(inventorySize * sizeof(struct InventoryItem));
  
  for (int i = 0; i < inventorySize; i++) {
    printf("\nItem %d:\n", i+1);
    
    printf("Enter product name: ");
    scanf("%s", inventory[i].name);
    
    printf("Enter quantity: ");
    scanf("%d", &inventory[i].quantity);
    
    printf("Enter price: ");
    scanf("%f", &inventory[i].price);
  }
  
  printf("\n");
  
  printf("Current Inventory\n");
  printf("~~~~~~~~~~~~~~~~~\n");
  
  float totalValue = 0;
  
  for (int i = 0; i < inventorySize; i++) {
    printf("%s\t\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    totalValue += inventory[i].price * inventory[i].quantity;
  }
  
  printf("~~~~~~~~~~~~~~~~~\n");
  printf("Total Value: $%.2f\n", totalValue);
  
  printf("\n");
  
  char searchName[50];
  
  printf("Enter item name to search for: ");
  scanf("%s", searchName);
  
  printf("\n");
  
  for (int i = 0; i < inventorySize; i++) {
    if (strcmp(searchName, inventory[i].name) == 0) {
      printf("Item Found:\n");
      printf("Name: %s\n", inventory[i].name);
      printf("Quantity: %d\n", inventory[i].quantity);
      printf("Price: $%.2f\n", inventory[i].price);
      printf("\n");
      break;
    }
    else if (i == inventorySize - 1) {
      printf("Item not found.\n\n");
    }
  }
  
  free(inventory);
  
  return 0;
}