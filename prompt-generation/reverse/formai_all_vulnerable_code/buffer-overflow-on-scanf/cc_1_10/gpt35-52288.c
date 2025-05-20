//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>

// Define a struct for products
struct product {
  char name[20];
  int quantity;
  float price;
} inventory[100];

// Declare functions
int addProduct(int index);
int searchProduct(char *name, int index);
void listProducts(int index);

int main() {
  int choice, count = 0;
  char name[20];

  printf("Welcome to our C Product Inventory System!\n\n");

  do {
    printf("What would you like to do?\n");
    printf("1. Add product\n");
    printf("2. Search product\n");
    printf("3. List all products\n");
    printf("4. Exit\n\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        count = addProduct(count);
        break;
      case 2:
        printf("Enter the name of the product to search: ");
        scanf("%s", name);
        searchProduct(name, count);
        break;
      case 3:
        listProducts(count);
        break;
      case 4:
        printf("Thank you for using our C Product Inventory System!\n\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
    }
  } while(choice != 4);

  return 0;
}

int addProduct(int index) {
  char name[20];
  int quantity;
  float price;

  printf("Enter the name of the product: ");
  scanf("%s", name);
  printf("Enter the quantity of the product: ");
  scanf("%d", &quantity);
  printf("Enter the price of the product: ");
  scanf("%f", &price);

  inventory[index].quantity = quantity;
  inventory[index].price = price;
  strcpy(inventory[index].name, name);

  printf("%s has been added to the inventory!\n", name);

  return index + 1;
}

int searchProduct(char *name, int index) {
  int i;

  for(i = 0; i < index; i++) {
    if(strcmp(name, inventory[i].name) == 0) {
      printf("%s\nQuantity: %d\nPrice: %.2f\n\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
      return 1;
    }
  }

  printf("Product not found in the inventory.\n\n");

  return 0;
}

void listProducts(int index) {
  int i;

  printf("Product\tQuantity\tPrice\n");

  for(i = 0; i < index; i++) {
    printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }

  printf("\n");
}