//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
  char products[100][100], choice[10], search[100];
  int price[100], stock[100], qty[100], numProducts = 0, totalPrice = 0;
 
  while(1) {
    char menu[] = "Menu:\n1. Add Product\n2. View Product\n3. Search Product\n4. Buy Product\n5. Generate Bill\n6. Exit\nEnter your choice: ";
    printf("%s", menu);
    scanf("%s", choice);
    
    if(strcmp(choice, "1") == 0) { // Add Product
      char prodName[100];
      int prodPrice, prodStock;

      printf("Enter product name: ");
      scanf("%s", prodName);

      printf("Enter price: ");
      scanf("%d", &prodPrice);

      printf("Enter available stock: ");
      scanf("%d", &prodStock);

      strcpy(products[numProducts], prodName);
      price[numProducts] = prodPrice;
      stock[numProducts] = prodStock;
      qty[numProducts] = 0;

      printf("Product added successfully!\n\n");
      numProducts++;
    } 
    else if(strcmp(choice, "2") == 0) { // View Products
      printf("Product Name\tPrice\tStock\tQuantity\n");
      printf("-------------------------------------------------------\n");
      for(int i = 0; i < numProducts; i++) {
          printf("%s\t%d\t%d\t%d\n", products[i], price[i], stock[i], qty[i]);
      }
      if(numProducts == 0) {
          printf("No products found.\n\n");
      }
    }
    else if(strcmp(choice, "3") == 0) { // Search Product
      printf("Enter product name to search for: ");
      scanf("%s", search);

      int found = 0;
      for(int i = 0; i < numProducts; i++) {
        if(strcmp(search, products[i]) == 0) {
          printf("Product found!\nProduct Name\tPrice\tStock\tQuantity\n");
          printf("-------------------------------------------------------\n");
          printf("%s\t%d\t%d\t%d\n\n", products[i], price[i], stock[i], qty[i]);
          found = 1;
          break;
        }
      }
      if(!found) {
          printf("Product not found.\n\n");
      }
    }
    else if(strcmp(choice, "4") == 0) { // Buy Product
      printf("Enter product name to buy: ");
      scanf("%s", search);

      int found = 0;
      for(int i = 0; i < numProducts; i++) {
        if(strcmp(search, products[i]) == 0) {
          printf("Product found!\n");
          printf("Available Stock: %d \n",stock[i]);
          printf("Enter quantity to buy: ");
          scanf("%d", &qty[i]);

          if(qty[i] > stock[i]) {
            printf("Insufficient stock!\n\n");
            qty[i] = 0;
          }
          else {
            stock[i] -= qty[i];
            printf("Product bought successfully!\n\n");
            totalPrice += qty[i] * price[i];
            found = 1;
          }
          break;
        }
      }
      if(!found) {
          printf("Product not found.\n\n");
      }
    }
    else if(strcmp(choice, "5") == 0) { // Generate Bill
      printf("Total Price: %d\n\n", totalPrice);
    }
    else if(strcmp(choice, "6") == 0) { // Exit
      break;
    }
    else { // Invalid Choice
      printf("Invalid Choice. Try Again.\n\n");
    }
  }

  return 0;
}