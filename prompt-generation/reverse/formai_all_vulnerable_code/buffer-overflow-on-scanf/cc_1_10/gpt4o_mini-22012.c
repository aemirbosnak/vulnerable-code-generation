//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully! ID: %d\n", newProduct.id);
}

void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    printf("\nInventory List:\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-20s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    char name[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found!\n");
            printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product '%s' not found in inventory.\n", name);
    }
}

void removeProduct() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }
    
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product with ID %d removed successfully.\n", id);
}

void menu() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Remove Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}