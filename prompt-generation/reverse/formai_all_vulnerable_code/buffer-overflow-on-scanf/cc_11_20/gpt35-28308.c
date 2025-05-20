//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>

// defining maximum number of products in inventory
#define MAX_PRODUCTS 100

// defining product struct
struct Product {
    int id;
    char name[50];
    int quantity;
};

int main() {
    // initializing inventory with empty products
    struct Product inventory[MAX_PRODUCTS] = {0};
    int numProducts = 0;

    // user menu
    int choice;
    do {
        printf("\n\n");
        printf("Warehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product Quantity\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // add product to inventory
                if (numProducts >= MAX_PRODUCTS) {
                    printf("Inventory is full!");
                    break;
                }
                struct Product product;
                printf("Enter product id: ");
                scanf("%d", &product.id);
                printf("Enter product name: ");
                scanf("%s", product.name);
                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);
                inventory[numProducts] = product;
                numProducts++;
                printf("Product added successfully!\n");
                break;
            }
            case 2: {
                // remove product from inventory
                int productID;
                printf("Enter product id: ");
                scanf("%d", &productID);
                int i = 0;
                for (; i < numProducts; i++) {
                    if (inventory[i].id == productID) {
                        break;
                    }
                }
                if (i == numProducts) {
                    printf("Product not found in inventory!\n");
                    break;
                }
                for (; i < numProducts - 1; i++) {
                    inventory[i] = inventory[i+1];
                }
                numProducts--;
                printf("Product removed successfully!\n");
                break;
            }
            case 3: {
                // update product quantity in inventory
                int productID;
                printf("Enter product id: ");
                scanf("%d", &productID);
                int i = 0;
                for (; i < numProducts; i++) {
                    if (inventory[i].id == productID) {
                        break;
                    }
                }
                if (i == numProducts) {
                    printf("Product not found in inventory!\n");
                    break;
                }
                int newQuantity;
                printf("Enter new product quantity: ");
                scanf("%d", &newQuantity);
                inventory[i].quantity = newQuantity;
                printf("Product quantity updated successfully!\n");
                break;
            }
            case 4: {
                // view inventory
                printf("Inventory:\n");
                printf("%-10s%-20s%-10s\n", "ID", "Name", "Quantity");
                int i = 0;
                for (; i < numProducts; i++) {
                    printf("%-10d%-20s%-10d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
                }
                break;
            }
            case 5: {
                // exit program
                printf("Thank you for using the Warehouse Management System!\n");
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    } while (choice != 5);

    return 0;
}