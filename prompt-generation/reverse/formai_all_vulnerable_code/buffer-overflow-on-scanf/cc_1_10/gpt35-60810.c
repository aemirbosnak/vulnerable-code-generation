//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order {
  char item_name[50];
  int quantity;
  float price;
};

void print_bill(struct order items[], int n_items) {
  float total_amount = 0.0;
  
  printf("--------------------\n");
  printf("|  CAFE BILLING SYSTEM  |\n");
  printf("--------------------\n");
  printf("| Item Name  |  Quantity |  Price |\n");
  
  for (int i = 0; i < n_items; i++) {
    printf("| %10s | %9d | $%5.2f |\n", items[i].item_name, items[i].quantity, items[i].price);
    total_amount += (items[i].quantity * items[i].price);
  }
  
  printf("--------------------\n");
  printf("| Total Amount | $%5.2f |\n", total_amount);
  printf("--------------------\n\n");
}

int main() {
  int n_items;
  
  printf("Enter the number of items you want to order: ");
  scanf("%d", &n_items);
  
  struct order items[n_items];
  
  for (int i = 0; i < n_items; i++) {
    printf("\nItem #%d:\n", i+1);
    
    printf("Item name: ");
    scanf("%s", items[i].item_name);
    
    printf("Quantity: ");
    scanf("%d", &items[i].quantity);
    
    printf("Price: ");
    scanf("%f", &items[i].price);
  }
  
  print_bill(items, n_items);
  
  return 0;
}