//FormAI DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <string.h>

/*This program will help you keep track of your product inventory.
You will be able to add, search, edit and delete products in your inventory.*/

struct product {
  char name[50];
  int id;
  float price;
  int quantity;
  char category[20];
} inventory[100];

int num_products = 0;

void print_menu() { //prints menu options for user
  printf("Product Inventory Menu\n");
  printf("1. Add Product\n");
  printf("2. Search Product\n");
  printf("3. Edit Product\n");
  printf("4. Delete Product\n");
  printf("5. Print Inventory\n");
  printf("6. Exit\n");
}

void add_product() { //function to add a product to inventory
  printf("Enter product name: ");
  scanf("%s", inventory[num_products].name);
  printf("Enter product ID: ");
  scanf("%d", &inventory[num_products].id);
  printf("Enter product price: ");
  scanf("%f", &inventory[num_products].price);
  printf("Enter product quantity: ");
  scanf("%d", &inventory[num_products].quantity);
  printf("Enter product category: ");
  scanf("%s", inventory[num_products].category);
  printf("Product %s added to inventory!\n", inventory[num_products].name);
  num_products++; //increment the number of products stored in the inventory
}

void search_product() { //function to search for a product by ID or name
  int id;
  char name[50];
  printf("Enter the product ID or name you want to search for: ");
  char user_choice;
  scanf("%c", &user_choice);
  if(user_choice == '\n'){ //consume newline character
    scanf("%c", &user_choice);
  }
  if(user_choice == 'n') {
    scanf("%s", name);
    for(int i=0; i<num_products; i++) {
      if(strcmp(name, inventory[i].name) == 0) {
        printf("Product %s found in inventory. ID: %d, Price: $%.2f, Quantity: %d, Category: %s\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity, inventory[i].category);
        return;
      }
    }
    printf("Product %s not found in inventory.\n", name);
  } else if (user_choice == 'i') {
    scanf("%d", &id);
    for(int i=0; i<num_products; i++) {
      if(id == inventory[i].id) {
        printf("Product %s found in inventory. ID: %d, Price: $%.2f, Quantity: %d, Category: %s\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity, inventory[i].category);
        return;
      }
    }
    printf("Product with ID %d not found in inventory.\n", id);
  } else {
    printf("Invalid input! Please enter 'i' for ID search or 'n' for name search.\n");
  }
}

void edit_product() { //function to edit a product
  int id;
  printf("Enter the ID of the product you want to edit: ");
  scanf("%d", &id);
  for(int i=0; i<num_products; i++) {
    if(id == inventory[i].id) {
      printf("Enter new product name: ");
      scanf("%s", inventory[i].name);
      printf("Enter new product price: ");
      scanf("%f", &inventory[i].price);
      printf("Enter new product quantity: ");
      scanf("%d", &inventory[i].quantity);
      printf("Enter new product category: ");
      scanf("%s", inventory[i].category);
      printf("Product with ID %d edited successfully!\n", id);
      return;
    }
  }
  printf("Product with ID %d not found in inventory.\n", id);
}

void delete_product() { //function to delete a product
  int id;
  printf("Enter the ID of the product you want to delete: ");
  scanf("%d", &id);
  for(int i=0; i<num_products; i++) {
    if(id == inventory[i].id) {
      for(int j=i; j<num_products-1; j++) {
        //shift all elements after the deleted product to the left
        strcpy(inventory[j].name, inventory[j+1].name);
        inventory[j].id = inventory[j+1].id;
        inventory[j].price = inventory[j+1].price;
        inventory[j].quantity = inventory[j+1].quantity;
        strcpy(inventory[j].category, inventory[j+1].category);
      }
      num_products--; //decrement the number of products in the inventory
      printf("Product with ID %d deleted successfully!\n", id);
      return;
    }
  }
  printf("Product with ID %d not found in inventory.\n", id);
}

void print_inventory() { //function to print list of all products in inventory
  if(num_products == 0) {
    printf("Inventory is empty!\n");
    return;
  }
  printf("Product Inventory:\n");
  printf("ID\tName\tPrice\tQuantity\tCategory\n");
  for(int i=0; i<num_products; i++) {
    printf("%d\t%s\t$%.2f\t%d\t\t%s\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity, inventory[i].category);
  }
}

int main() {
  int choice;
  do {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        add_product();
        break;
      case 2:
        search_product();
        break;
      case 3:
        edit_product();
        break;
      case 4:
        delete_product();
        break;
      case 5:
        print_inventory();
        break;
      case 6:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid input! Please enter a number between 1 and 6.\n");
        break;
    }
  } while (choice != 6);
  return 0;
}