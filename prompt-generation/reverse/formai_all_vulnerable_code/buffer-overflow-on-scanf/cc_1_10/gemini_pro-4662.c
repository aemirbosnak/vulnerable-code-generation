//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product details
typedef struct product {
   int product_id;
   char product_name[50];
   int product_quantity;
   float product_price;
} product;

// Function to add a new product to the inventory
void add_product(product *inventory, int *num_products) {
   // Get product details from user
   printf("Enter product ID: ");
   scanf("%d", &inventory[*num_products].product_id);
   printf("Enter product name: ");
   scanf("%s", inventory[*num_products].product_name);
   printf("Enter product quantity: ");
   scanf("%d", &inventory[*num_products].product_quantity);
   printf("Enter product price: ");
   scanf("%f", &inventory[*num_products].product_price);

   // Increment the number of products in the inventory
   (*num_products)++;
}

// Function to search for a product in the inventory
int search_product(product *inventory, int num_products, int product_id) {
   // Linear search for the product
   for (int i = 0; i < num_products; i++) {
      if (inventory[i].product_id == product_id) {
         return i;
      }
   }

   // Product not found
   return -1;
}

// Function to update the quantity of a product in the inventory
void update_product_quantity(product *inventory, int num_products, int product_id, int new_quantity) {
   // Find the product in the inventory
   int index = search_product(inventory, num_products, product_id);

   // Update the quantity if the product is found
   if (index != -1) {
      inventory[index].product_quantity = new_quantity;
   }
}

// Function to delete a product from the inventory
void delete_product(product *inventory, int *num_products, int product_id) {
   // Find the product in the inventory
   int index = search_product(inventory, *num_products, product_id);

   // Delete the product if it is found
   if (index != -1) {
      // Shift the products after the deleted product to the left
      for (int i = index; i < *num_products - 1; i++) {
         inventory[i] = inventory[i + 1];
      }

      // Decrement the number of products in the inventory
      (*num_products)--;
   }
}

// Function to print the inventory
void print_inventory(product *inventory, int num_products) {
   printf("\nInventory:\n");
   printf("-----------------------------------------------------------------------------------------------------\n");
   printf("| Product ID | Product Name                       | Product Quantity | Product Price | Total Value |\n");
   printf("-----------------------------------------------------------------------------------------------------\n");
   for (int i = 0; i < num_products; i++) {
      printf("| %9d | %-30s | %15d | %12.2f | %11.2f |\n", inventory[i].product_id, inventory[i].product_name, inventory[i].product_quantity, inventory[i].product_price, inventory[i].product_quantity * inventory[i].product_price);
   }
   printf("-----------------------------------------------------------------------------------------------------\n");
}

// Main function
int main() {
   // Create an array to store the inventory
   product inventory[100];

   // Initialize the number of products in the inventory to 0
   int num_products = 0;

   // Add some sample products to the inventory
   add_product(inventory, &num_products);
   add_product(inventory, &num_products);
   add_product(inventory, &num_products);

   // Print the inventory
   print_inventory(inventory, num_products);

   // Search for a product in the inventory
   int product_id;
   printf("\nEnter product ID to search for: ");
   scanf("%d", &product_id);
   int index = search_product(inventory, num_products, product_id);
   if (index != -1) {
      printf("Product found:\n");
      printf("Product ID: %d\n", inventory[index].product_id);
      printf("Product Name: %s\n", inventory[index].product_name);
      printf("Product Quantity: %d\n", inventory[index].product_quantity);
      printf("Product Price: %.2f\n", inventory[index].product_price);
   } else {
      printf("Product not found.\n");
   }

   // Update the quantity of a product in the inventory
   int new_quantity;
   printf("\nEnter product ID to update quantity for: ");
   scanf("%d", &product_id);
   printf("Enter new quantity: ");
   scanf("%d", &new_quantity);
   update_product_quantity(inventory, num_products, product_id, new_quantity);

   // Print the updated inventory
   print_inventory(inventory, num_products);

   // Delete a product from the inventory
   printf("\nEnter product ID to delete: ");
   scanf("%d", &product_id);
   delete_product(inventory, &num_products, product_id);

   // Print the updated inventory
   print_inventory(inventory, num_products);

   return 0;
}