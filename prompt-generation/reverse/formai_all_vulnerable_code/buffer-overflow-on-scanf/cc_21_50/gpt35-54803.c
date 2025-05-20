//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 50

// Define structure to represent a product
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

int main() {
    // Initialize array of products
    Product inventory[MAX_PRODUCTS];
    int num_products = 0;

    // Display menu options to user
    while (1) {
        printf("---Product Inventory System---\n");
        printf("1. Add a product\n");
        printf("2. List all products\n");
        printf("3. Search for a product\n");
        printf("4. Update a product\n");
        printf("5. Delete a product\n");
        printf("6. Exit\n");
        printf("Enter an option: ");
        int option;
        scanf("%d", &option);

        // Process user's option
        switch (option) {
            case 1:
                // Add a product to inventory
                if (num_products == MAX_PRODUCTS) {
                    printf("Error: inventory is full\n");
                    break;
                }
                printf("--Add Product--\n");
                printf("Enter product name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter product quantity: ");
                int quantity;
                scanf("%d", &quantity);
                printf("Enter product price: ");
                float price;
                scanf("%f", &price);
                // Find next available ID for product
                int id = 1;
                for (int i = 0; i < num_products; i++) {
                    if (inventory[i].id >= id) {
                        id = inventory[i].id + 1;
                    }
                }
                // Add product to inventory
                inventory[num_products].id = id;
                strcpy(inventory[num_products].name, name);
                inventory[num_products].quantity = quantity;
                inventory[num_products].price = price;
                num_products++;
                printf("Product added successfully\n");
                break;
            case 2:
                // List all products in inventory
                printf("--List all Products--\n");
                printf("ID\tName\t\tQuantity\tPrice\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 3:
                // Search for a product by name
                printf("--Search for Product--\n");
                printf("Enter product name: ");
                scanf("%s", name);
                for (int i = 0; i < num_products; i++) {
                    if (strcmp(inventory[i].name, name) == 0) {
                        printf("Product found:\n");
                        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                        break;
                    }
                }
                break;
            case 4:
                // Update a product by ID
                printf("--Update Product--\n");
                printf("Enter product ID: ");
                int update_id;
                scanf("%d", &update_id);
                for (int i = 0; i < num_products; i++) {
                    if (inventory[i].id == update_id) {
                        printf("Enter new product name (or enter '-' to keep current name): ");
                        scanf("%s", name);
                        if (strcmp(name, "-") != 0) {
                            strcpy(inventory[i].name, name);
                        }
                        printf("Enter new product quantity (-1 to keep current quantity): ");
                        scanf("%d", &quantity);
                        if (quantity != -1) {
                            inventory[i].quantity = quantity;
                        }
                        printf("Enter new product price (-1 to keep current price): ");
                        scanf("%f", &price);
                        if (price != -1) {
                            inventory[i].price = price;
                        }
                        printf("Product updated successfully\n");
                        break;
                    }
                }
                break;
            case 5:
                // Delete a product by ID
                printf("--Delete Product--\n");
                printf("Enter product ID: ");
                int delete_id;
                scanf("%d", &delete_id);
                for (int i = 0; i < num_products; i++) {
                    if (inventory[i].id == delete_id) {
                        for (int j = i; j < num_products; j++) {
                            inventory[j] = inventory[j+1];
                        }
                        num_products--;
                        printf("Product deleted successfully\n");
                        break;
                    }
                }
                break;
            case 6:
                // Exit program
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again\n");
        }
    }

    return 0;
}