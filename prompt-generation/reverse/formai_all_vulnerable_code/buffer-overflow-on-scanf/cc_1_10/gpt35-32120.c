//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold product information
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// function to add a product to the inventory
void addProduct(Product *inventory, int *numProducts) {
    printf("Adding a new product...\n");
    printf("Enter the name of the product: ");
    scanf("%s", inventory[*numProducts].name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[*numProducts].quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &inventory[*numProducts].price);
    (*numProducts)++;
    printf("Product added successfully!\n");
}

// function to update the quantity of a product in the inventory
void updateQuantity(Product *inventory, int numProducts) {
    char productName[50];
    int newQuantity;
    printf("Updating product quantity...\n");
    printf("Enter the name of the product: ");
    scanf("%s", productName);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(productName, inventory[i].name) == 0) {
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

// function to display the entire inventory
void displayInventory(Product *inventory, int numProducts) {
    printf("Product Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // initialize inventory array and number of products to 0
    Product inventory[100];
    int numProducts = 0;

    while (1) {
        // display options to user
        printf("\nChoose an option:\n");
        printf("1. Add a product\n");
        printf("2. Update product quantity\n");
        printf("3. Display inventory\n");
        printf("4. Exit program\n");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                updateQuantity(inventory, numProducts);
                break;
            case 3:
                displayInventory(inventory, numProducts);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}