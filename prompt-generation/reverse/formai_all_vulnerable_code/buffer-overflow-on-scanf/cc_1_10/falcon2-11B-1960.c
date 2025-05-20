//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

void addProduct(struct Product *product) {
    // Function to add a product to the inventory
    printf("Enter product name: ");
    scanf("%s", product->name);
    printf("Enter product price: ");
    scanf("%f", &product->price);
    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);
    printf("Product added successfully!\n");
}

void displayInventory(struct Product *products, int numProducts) {
    // Function to display the inventory
    printf("Product Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - $%.2f (%d units)\n", products[i].name, products[i].price, products[i].quantity);
    }
}

int searchProduct(struct Product *products, int numProducts, char *name) {
    // Function to search for a product in the inventory
    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found: %s\n", products[i].name);
            found = 1;
        }
    }
    return found;
}

int main() {
    struct Product products[10]; // Create an array to hold 10 products

    // Add some products to the inventory
    addProduct(&products[0]);
    addProduct(&products[1]);
    addProduct(&products[2]);

    // Display the inventory
    displayInventory(products, 3);

    // Search for a product in the inventory
    char searchName[50];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    int found = searchProduct(products, 3, searchName);
    if (found == 1) {
        printf("Product found!\n");
    } else {
        printf("Product not found.\n");
    }

    return 0;
}