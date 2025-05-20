//FormAI DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of products the inventory system can handle
#define MAX_PRODUCTS 100

// This struct represents a product in the inventory system
struct Product {
    char name[50];
    int quantity;
    float price;
};

// This struct represents the inventory system itself
struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int numProducts;
};

// This function adds a new product to the inventory system
void addProduct(struct Inventory* inv) {
    // Prompt user for product info
    struct Product newProd;
    printf("Enter the product name: ");
    fgets(newProd.name, 50, stdin);
    newProd.name[strcspn(newProd.name, "\n")] = '\0'; // Remove newline character at end of string
    printf("Enter the product quantity: ");
    scanf("%d", &newProd.quantity);
    printf("Enter the product price: ");
    scanf("%f", &newProd.price);

    // Add the new product to the inventory system
    inv->products[inv->numProducts] = newProd;
    inv->numProducts++;
}

// This function displays all products in the inventory system
void displayProducts(struct Inventory inv) {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < inv.numProducts; i++) {
        printf("Product #%d:\n", i+1);
        printf("Name: %s\n", inv.products[i].name);
        printf("Quantity: %d\n", inv.products[i].quantity);
        printf("Price: $%.2f\n", inv.products[i].price);
    }
    printf("\n");
}

// This function searches for a product by name and returns its index if found (or -1 if not found)
int findProduct(struct Inventory inv, char name[]) {
    for (int i = 0; i < inv.numProducts; i++) {
        if (strcmp(inv.products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// This function removes a product from the inventory system by name
void removeProduct(struct Inventory* inv, char name[]) {
    int index = findProduct(*inv, name);
    if (index == -1) {
        printf("Error: Product not found\n");
        return;
    }
    // Shift all products after the removed one back by one position
    for (int i = index; i < inv->numProducts-1; i++) {
        inv->products[i] = inv->products[i+1];
    }
    inv->numProducts--;
    printf("%s removed from inventory\n", name);
}

int main() {
    struct Inventory inv;
    inv.numProducts = 0;

    // Menu loop
    while (1) {
        printf("Menu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        
        int choice;
        scanf("%d", &choice);
        getchar(); // Remove newline character from input stream 
        
        switch (choice) {
            case 1:
                addProduct(&inv);
                break;
            case 2:
                printf("Enter product name to remove: ");
                char name[50];
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character at end of string
                removeProduct(&inv, name);
                break;
            case 3:
                displayProducts(inv);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}