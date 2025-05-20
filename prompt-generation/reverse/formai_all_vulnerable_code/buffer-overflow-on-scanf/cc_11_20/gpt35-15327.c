//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct product inventory[MAX_PRODUCTS];
    int numProducts = 0;

    int choice = 0;
    while (choice != 5) {
        printf("Product Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Update a product\n");
        printf("3. Delete a product\n");
        printf("4. View all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numProducts < MAX_PRODUCTS) {
                    // Add a new product
                    printf("Enter product name: ");
                    scanf("%s", inventory[numProducts].name);
                    printf("Enter product price: ");
                    scanf("%f", &inventory[numProducts].price);
                    printf("Enter product quantity: ");
                    scanf("%d", &inventory[numProducts].quantity);
                    inventory[numProducts].id = numProducts + 1;
                    numProducts++;
                } else {
                    printf("Error: Maximum number of products reached\n");
                }
                break;
            case 2:
                // Update an existing product
                printf("Enter product ID: ");
                int productId;
                scanf("%d", &productId);
                if (productId > 0 && productId <= numProducts) {
                    printf("Enter new product name: ");
                    scanf("%s", inventory[productId-1].name);
                    printf("Enter new product price: ");
                    scanf("%f", &inventory[productId-1].price);
                    printf("Enter new product quantity: ");
                    scanf("%d", &inventory[productId-1].quantity);
                } else {
                    printf("Error: Invalid product ID\n");
                }
                break;
            case 3:
                // Delete an existing product
                printf("Enter product ID: ");
                int deleteId;
                scanf("%d", &deleteId);
                if (deleteId > 0 && deleteId <= numProducts) {
                    for (int i = deleteId - 1; i < numProducts - 1; i++) {
                        inventory[i] = inventory[i+1];
                    }
                    numProducts--;
                } else {
                    printf("Error: Invalid product ID\n");
                }
                break;
            case 4:
                // View all products
                printf("Product ID\tName\tPrice\tQuantity\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%d\t\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;
            case 5:
                // Exit the program
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }
    }

    return 0;
}