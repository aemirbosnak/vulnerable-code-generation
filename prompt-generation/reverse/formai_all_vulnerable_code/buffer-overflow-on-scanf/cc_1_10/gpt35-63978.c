//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for products in inventory
typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Product;

// Function prototype
void displayMenu();
void displayInventory(Product products[], int numProducts);
void addProduct(Product products[], int *numProducts);
void removeProduct(Product products[], int *numProducts);
void updateProduct(Product products[], int numProducts, int id);

int main() {
    char choice = '0';
    int numProducts = 0;
    Product products[100];

    while(choice != '5') {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                displayInventory(products, numProducts);
                break;
            case '2':
                addProduct(products, &numProducts);
                break;
            case '3':
                removeProduct(products, &numProducts);
                break;
            case '4':
                // Get product id to update
                printf("Enter product ID to update: ");
                int id;
                scanf("%d", &id);
                updateProduct(products, numProducts, id);
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-5.\n");
                break;
        }
    }
    
    return 0;
}

// Function definitions
void displayMenu() {
    printf("\n=== Warehouse Management System ===\n");
    printf("1. Display Inventory\n");
    printf("2. Add Product\n");
    printf("3. Remove Product\n");
    printf("4. Update Product\n");
    printf("5. Exit\n");
}

void displayInventory(Product products[], int numProducts) {
    printf("\n=== Inventory ===\n");
    printf("ID\tName\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    if(numProducts == 0) {
        printf("Inventory is empty.\n");
    }
}

void addProduct(Product products[], int *numProducts) {
    Product newProduct;
    
    // Get product details from user
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    // Assign product id and add to inventory
    newProduct.id = *numProducts + 1;
    products[*numProducts] = newProduct;
    *numProducts += 1;

    printf("%s added to inventory.\n", newProduct.name);
}

void removeProduct(Product products[], int *numProducts) {
    int removeId;
    int foundId = -1;

    // Get product id to remove
    printf("Enter product ID to remove: ");
    scanf("%d", &removeId);

    // Find product id in inventory
    for(int i = 0; i < *numProducts; i++) {
        if(products[i].id == removeId) {
            foundId = i;
            break;
        }
    }

    // If product is found, remove it from inventory
    if(foundId != -1) {
        printf("%s removed from inventory.\n", products[foundId].name);
        for(int i = foundId; i < *numProducts - 1; i++) {
            products[i] = products[i + 1];
        }
        *numProducts -= 1;
    } else {
        printf("Product not found in inventory.\n");
    }
}

void updateProduct(Product products[], int numProducts, int id) {
    int foundId = -1;

    // Find product id in inventory
    for(int i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            foundId = i;
            break;
        }
    }

    // If product is found, update its details
    if(foundId != -1) {
        printf("\nOld details:\n");
        printf("Name: %s\n", products[foundId].name);
        printf("Quantity: %d\n", products[foundId].quantity);
        printf("Price: %.2f\n", products[foundId].price);

        // Get new product details from user
        printf("\nEnter new details:\n");
        printf("Enter product name: ");
        scanf("%s", products[foundId].name);
        printf("Enter product quantity: ");
        scanf("%d", &products[foundId].quantity);
        printf("Enter product price: ");
        scanf("%f", &products[foundId].price);

        printf("%s updated in inventory.\n", products[foundId].name);

    } else {
        printf("Product not found in inventory.\n");
    }
}