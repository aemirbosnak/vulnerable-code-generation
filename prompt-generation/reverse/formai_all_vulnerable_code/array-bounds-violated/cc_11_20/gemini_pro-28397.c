//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

int main() {

    int choice, i, id;
    char name[50];
    float price;
    int quantity;

    // Initialize the product list with some sample data.
    product inventory[] = {
        {1, "Apple", 0.50, 10},
        {2, "Orange", 0.75, 15},
        {3, "Banana", 1.00, 20},
        {4, "Grape", 1.25, 18},
        {5, "Mango", 1.50, 16}
    };

    // Main loop for the program.
    while (1) {
        // Display the menu.
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Delete a product\n");
        printf("3. Update a product\n");
        printf("4. Search for a product\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
   
        printf("\nEnter your choice: ");

        // Get the user's choice.
        scanf("%d", &choice);

        // Process the user's choice.
        switch (choice) {
            case 1:
                // Add a product.
                printf("\nEnter the product ID: ");
                scanf("%d", &id);
                printf("\nEnter the product name: ");
                scanf(" %s", name);
                printf("\nEnter the product price: ");
                scanf("%f", &price);
                printf("\nEnter the product quantity: ");
                scanf("%d", &quantity);

                // Add the new product to the inventory.
                inventory[id] = (product) {id, name, price, quantity};
                printf("\nProduct added successfully.\n");

                break;

            case 2:
                // Delete a product.
                printf("\nEnter the product ID to delete: ");
                scanf("%d", &id);

                // Delete the product from the inventory.
                inventory[id] = (product) {0, "", 0.0, 0};
                printf("\nProduct deleted successfully.\n");

                break;

            case 3:
                // Update a product.
                printf("\nEnter the product ID to update: ");
                scanf("%d", &id);

                // Get the new product details.
                printf("\nEnter the product name: ");
                scanf(" %s", name);
                printf("\nEnter the product price: ");
                scanf("%f", &price);
                printf("\nEnter the product quantity: ");
                scanf("%d", &quantity);

                // Update the product in the inventory.
                inventory[id] = (product) {id, name, price, quantity};
                printf("\nProduct updated successfully.\n");

                break;

            case 4:
                // Search for a product.
                printf("\nEnter the product name to search for: ");
                scanf(" %s", name);

                // Search for the product in the inventory.
                for (i = 0; i < 10; i++) {
                    if (strcmp(inventory[i].name, name) == 0) {
                        printf("\nProduct found:\n");
                        printf("ID: %d\n", inventory[i].id);
                        printf("Name: %s\n", inventory[i].name);
                        printf("Price: %.2f\n", inventory[i].price);
                        printf("Quantity: %d\n", inventory[i].quantity);
                    }
                }

                break;

            case 5:
                // Display all products.
                printf("\nAll products:\n");
                for (i = 0; i < 10; i++) {
                    printf("ID: %d\n", inventory[i].id);
                    printf("Name: %s\n", inventory[i].name);
                    printf("Price: %.2f\n", inventory[i].price);
                    printf("Quantity: %d\n", inventory[i].quantity);
                }

                break;

            case 6:
                // Exit the program.
                exit(0);

            default:
                // Invalid choice.
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}