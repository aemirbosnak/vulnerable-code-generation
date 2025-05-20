//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Inventory structure
typedef struct {
    Product *products;
    int size;
} Inventory;

// Add a Product to Inventory
void addProduct(Inventory *inventory) {
    Product product;
    printf("Enter the name of the product: ");
    scanf("%s", &product.name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &product.quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &product.price);
    inventory->products = (Product *)realloc(inventory->products, (inventory->size + 1) * sizeof(Product));
    inventory->products[inventory->size] = product;
    inventory->size++;
    printf("Product added successfully!\n");
}

// Display all the products in the inventory
void displayInventory(Inventory *inventory) {
    int i;
    printf("\nProduct Inventory: \n");
    printf("%-20s %-20s %-20s\n", "Name", "Quantity", "Price");
    for(i = 0; i < inventory->size; i++) {
        printf("%-20s %-20d %-20.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Main function
int main() {
    Inventory inventory;
    inventory.products = NULL;
    inventory.size = 0;
    int choice;
    do {
        printf("\n============== Product Inventory System ==============\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                displayInventory(&inventory);
                break;
            case 3:
                printf("Exiting the program...");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);
    return 0;
}