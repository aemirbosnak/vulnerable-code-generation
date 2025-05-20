//FormAI DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define global array of products, with an initial size of 10
Product inventory[10];

// Define global variable to keep track of the number of products in the inventory
int num_products = 0;

int main() {
    int choice;
    do {
        // Display menu options
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add New Product\n");
        printf("2. Update Product Information\n");
        printf("3. Search for Product\n");
        printf("4. Display Entire Inventory\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        // Process choice
        switch(choice) {
            case 1: // Add new product
                if(num_products >= 10) {
                    printf("Error: Maximum number of products reached.\n\n");
                    break;
                }
                Product new_product;
                printf("Enter product name: ");
                scanf("%s", new_product.name);
                printf("Enter product quantity: ");
                scanf("%d", &new_product.quantity);
                printf("Enter product price: ");
                scanf("%f", &new_product.price);
                inventory[num_products] = new_product;
                num_products++;
                printf("Product added to inventory.\n\n");
                break;
            case 2: // Update product information
                if(num_products == 0) {
                    printf("Error: No products in inventory.\n\n");
                    break;
                }
                char search_name[50];
                printf("Enter product name to update: ");
                scanf("%s", search_name);
                int i;
                for(i = 0; i < num_products; i++) {
                    if(strcmp(inventory[i].name, search_name) == 0) {
                        printf("Enter new quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter new price: ");
                        scanf("%f", &inventory[i].price);
                        printf("Product information updated.\n\n");
                        break;
                    }
                }
                if(i == num_products) {
                    printf("Error: Product not found.\n\n");
                }
                break;
            case 3: // Search for product
                if(num_products == 0) {
                    printf("Error: No products in inventory.\n\n");
                    break;
                }
                char search_name2[50];
                printf("Enter product name to search for: ");
                scanf("%s", search_name2);
                int j;
                for(j = 0; j < num_products; j++) {
                    if(strcmp(inventory[j].name, search_name2) == 0) {
                        printf("Name: %s, Quantity: %d, Price: %.2f\n\n", inventory[j].name, inventory[j].quantity, inventory[j].price);
                        break;
                    }
                }
                if(j == num_products) {
                    printf("Error: Product not found.\n\n");
                }
                break;
            case 4: // Display entire inventory
                if(num_products == 0) {
                    printf("No products in inventory.\n\n");
                    break;
                }
                printf("Inventory:\n");
                for(int k = 0; k < num_products; k++) {
                    printf("Name: %s, Quantity: %d, Price: %.2f\n", inventory[k].name, inventory[k].quantity, inventory[k].price);
                }
                printf("\n");
                break;
            case 5: // Quit program
                printf("Thank you for using the Product Inventory System. Goodbye!\n");
                break;
            default: // Invalid choice
                printf("Error: Invalid menu choice.\n\n");
                break;
        }
    } while(choice != 5);

    return 0;
}