//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
/*
 * A unique C Product Inventory System example program in a Sherlock Holmes style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 64

// Product structure
typedef struct {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  int quantity;
  float price;
} Product;

// Inventory structure
typedef struct {
  Product *products;
  int num_products;
} Inventory;

// Function prototypes
void print_menu();
void print_product(Product *product);
void print_inventory(Inventory *inventory);
int add_product(Inventory *inventory, char *name, char *description, int quantity, float price);
int remove_product(Inventory *inventory, char *name);
int update_product(Inventory *inventory, char *name, int quantity, float price);

int main() {
  Inventory inventory = {NULL, 0};
  char input[256];
  char *token;
  char *name;
  char *description;
  int quantity;
  float price;
  int option;

  // Initialize the inventory
  inventory.products = malloc(sizeof(Product) * 10);
  inventory.num_products = 0;

  // Print the menu
  print_menu();

  // Get user input
  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    if (token == NULL) {
      continue;
    }

    // Parse the input
    option = atoi(token);
    switch (option) {
      case 1:
        // Add product
        name = strtok(NULL, " ");
        description = strtok(NULL, " ");
        quantity = atoi(strtok(NULL, " "));
        price = atof(strtok(NULL, " "));
        add_product(&inventory, name, description, quantity, price);
        break;
      case 2:
        // Remove product
        name = strtok(NULL, " ");
        remove_product(&inventory, name);
        break;
      case 3:
        // Update product
        name = strtok(NULL, " ");
        quantity = atoi(strtok(NULL, " "));
        price = atof(strtok(NULL, " "));
        update_product(&inventory, name, quantity, price);
        break;
      case 4:
        // Print inventory
        print_inventory(&inventory);
        break;
      case 5:
        // Exit
        free(inventory.products);
        return 0;
      default:
        printf("Invalid option.\n");
        break;
    }
  }

  return 0;
}

void print_menu() {
  printf("Sherlock Holmes Product Inventory System\n");
  printf("---------------------------------------\n");
  printf("1. Add product\n");
  printf("2. Remove product\n");
  printf("3. Update product\n");
  printf("4. Print inventory\n");
  printf("5. Exit\n");
}

void print_product(Product *product) {
  printf("Name: %s\n", product->name);
  printf("Description: %s\n", product->description);
  printf("Quantity: %d\n", product->quantity);
  printf("Price: $%.2f\n", product->price);
}

void print_inventory(Inventory *inventory) {
  for (int i = 0; i < inventory->num_products; i++) {
    printf("Product %d:\n", i + 1);
    print_product(&inventory->products[i]);
    printf("\n");
  }
}

int add_product(Inventory *inventory, char *name, char *description, int quantity, float price) {
  Product *new_product = malloc(sizeof(Product));
  strcpy(new_product->name, name);
  strcpy(new_product->description, description);
  new_product->quantity = quantity;
  new_product->price = price;
  inventory->products[inventory->num_products++] = *new_product;
  return 0;
}

int remove_product(Inventory *inventory, char *name) {
  int i;
  for (i = 0; i < inventory->num_products; i++) {
    if (strcmp(inventory->products[i].name, name) == 0) {
      break;
    }
  }
  if (i == inventory->num_products) {
    printf("Product not found.\n");
    return -1;
  }
  for (int j = i + 1; j < inventory->num_products; j++) {
    inventory->products[j - 1] = inventory->products[j];
  }
  inventory->num_products--;
  return 0;
}

int update_product(Inventory *inventory, char *name, int quantity, float price) {
  int i;
  for (i = 0; i < inventory->num_products; i++) {
    if (strcmp(inventory->products[i].name, name) == 0) {
      break;
    }
  }
  if (i == inventory->num_products) {
    printf("Product not found.\n");
    return -1;
  }
  inventory->products[i].quantity = quantity;
  inventory->products[i].price = price;
  return 0;
}