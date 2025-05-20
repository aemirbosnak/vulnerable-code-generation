//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void viewInventory();
void deleteProduct();
void searchProduct();
void paranoidPrompt();

void paranoidPrompt() {
    printf("\n*WARNING: Unauthorized access is monitored!*\n");
    printf("Please enter your choice (1: Add, 2: View, 3: Delete, 4: Search, 0: Exit): ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Error: Maximum product limit reached! Unauthorized addition attempt logged!\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%lf", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully. Ensure you are not being tracked by unauthorized entities!\n");
}

void viewInventory() {
    printf("\nInventory List:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: Name: %s, Quantity: %d, Price: %.2f\n", i + 1,
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    if (productCount == 0) {
        printf("No products in inventory! Are you sure you're not being observed?\n");
    }
}

void deleteProduct() {
    if (productCount <= 0) {
        printf("Error: No products to delete! Always double-check your surroundings!\n");
        return;
    }

    int index;
    printf("Enter product index to delete (1 to %d): ", productCount);
    scanf("%d", &index);

    if (index < 1 || index > productCount) {
        printf("Invalid index! Possible hacking attempt logged!\n");
        return;
    }

    for (int i = index - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully. Stay aware of potential spies!\n");
}

void searchProduct() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the product name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Found: Product %d: Name: %s, Quantity: %d, Price: %.2f\n",
                   i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product not found. Are you certain this is your inventory?\n");
    }
}

int main() {
    int choice;

    while (1) {
        paranoidPrompt();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                searchProduct();
                break;
            case 0:
                printf("Exiting program. Remember to safeguard your data!\n");
                exit(0);
            default:
                printf("Invalid choice! Remain vigilant!\n");
        }
    }
    
    return 0;
}