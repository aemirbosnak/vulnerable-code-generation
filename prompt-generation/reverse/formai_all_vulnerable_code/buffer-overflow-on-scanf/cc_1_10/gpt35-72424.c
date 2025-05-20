//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>

// Define structure for product information
struct product {
  int id;
  char name[50];
  int quantity;
  float price;
};

// Declare function for displaying menu
int displayMenu();

int main() {
  // Declare variables
  int option, numProducts = 0;
  struct product products[50];

  // Display welcome message
  printf("Welcome to Mind-Bending Product Inventory System\n");

  // Loop until user chooses to exit
  do {
    // Display menu and get user option
    option = displayMenu();

    // Perform action based on user option
    switch(option) {
      case 1: // Add product
        printf("Enter product ID: ");
        scanf("%d", &products[numProducts].id);
        printf("Enter product name: ");
        scanf("%s", products[numProducts].name);
        printf("Enter product quantity: ");
        scanf("%d", &products[numProducts].quantity);
        printf("Enter product price: ");
        scanf("%f", &products[numProducts].price);
        numProducts++;
        break;
      case 2: // Remove product
        printf("Enter product ID to remove: ");
        int removeID;
        scanf("%d", &removeID);
        for (int i = 0; i < numProducts; i++) {
          if (products[i].id == removeID) {
            for (int j = i; j < numProducts - 1; j++) {
              products[j] = products[j+1];
            }
            numProducts--;
            printf("Product removed successfully.\n");
            break;
          }
          if (i == numProducts - 1) {
            printf("Product not found.\n");
          }
        }
        break;
      case 3: // View all products
        printf("ID\tName\tQuantity\tPrice\n");
        for (int i = 0; i < numProducts; i++) {
          printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
        break;
      case 4: // Search for product
        printf("Enter product ID to search: ");
        int searchID;
        scanf("%d", &searchID);
        for (int i = 0; i < numProducts; i++) {
          if (products[i].id == searchID) {
            printf("Product found:\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            break;
          }
          if (i == numProducts - 1) {
            printf("Product not found.\n");
          }
        }
        break;
      case 5: // Exit program
        printf("Exiting Mind-Bending Product Inventory System...\n");
        break;
      default:
        printf("Invalid option selected. Please try again.\n");
    }
  } while (option != 5);

  return 0;
}

// Display menu and get user option
int displayMenu() {
  int option;
  printf("\nOptions:\n");
  printf("1. Add product\n");
  printf("2. Remove product\n");
  printf("3. View all products\n");
  printf("4. Search for product\n");
  printf("5. Exit program\n");
  printf("Select an option: ");
  scanf("%d", &option);
  return option;
}