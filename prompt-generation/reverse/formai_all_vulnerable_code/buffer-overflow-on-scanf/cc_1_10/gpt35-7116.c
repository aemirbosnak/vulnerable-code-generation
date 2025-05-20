//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold product details
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Function to display all products in inventory
void displayProducts(Product inventory[], int numProducts) {
    printf("Current Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d units - $%.2f each\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to add a new product to inventory
void addProduct(Product inventory[], int *numProducts) {
    Product newProduct;
    printf("Enter product name: ");
    scanf("%[^\n]%*c", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    inventory[*numProducts] = newProduct;
    (*numProducts)++;
    printf("%s successfully added to inventory!\n", newProduct.name);
}

// Function to update quantity of a product in inventory
void updateProductQuantity(Product inventory[], int numProducts) {
    char productName[50];
    printf("Enter the name of the product to update: ");
    scanf("%[^\n]%*c", productName);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(productName, inventory[i].name) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("%s quantity updated to %d\n", inventory[i].name, inventory[i].quantity);
            return;
        }
    }
    printf("%s not found in inventory\n", productName);
}

// Function to update price of a product in inventory
void updateProductPrice(Product inventory[], int numProducts) {
    char productName[50];
    printf("Enter the name of the product to update: ");
    scanf("%[^\n]%*c", productName);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(productName, inventory[i].name) == 0) {
            printf("Enter the new price: ");
            scanf("%f", &inventory[i].price);
            printf("%s price updated to $%.2f\n", inventory[i].name, inventory[i].price);
            return;
        }
    }
    printf("%s not found in inventory\n", productName);
}

int main() {
    // Initialize inventory with 3 products
    Product inventory[10] = {{"Apple", 5, 0.99}, {"Banana", 2, 0.49}, {"Orange", 3, 0.79}};
    int numProducts = 3;
    int choice;
    do {
        printf("\n\n1. Display Inventory\n");
        printf("2. Add Product\n");
        printf("3. Update Product Quantity\n");
        printf("4. Update Product Price\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayProducts(inventory, numProducts);
                break;
            case 2:
                addProduct(inventory, &numProducts);
                break;
            case 3:
                updateProductQuantity(inventory, numProducts);
                break;
            case 4:
                updateProductPrice(inventory, numProducts);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please enter a number from 1 to 5\n");
                break;
        }
    } while (choice != 5);

    return 0;
}