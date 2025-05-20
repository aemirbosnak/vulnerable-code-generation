//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function Prototypes
void addProduct();
void removeProduct();
void displayInventory();
void clearBuffer();

int main() {
    int choice;
    
    printf("Welcome to the Exciting Warehouse Management System!\n");
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting the system... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // Remove newline character

    printf("Enter product code: ");
    fgets(newProduct.code, CODE_LENGTH, stdin);
    newProduct.code[strcspn(newProduct.code, "\n")] = '\0'; // Remove newline character

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    clearBuffer();

    inventory[productCount++] = newProduct;
    printf("Product '%s' added successfully! 🎉\n", newProduct.name);
}

void removeProduct() {
    char code[CODE_LENGTH];
    printf("Enter product code to remove: ");
    fgets(code, CODE_LENGTH, stdin);
    code[strcspn(code, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            // Shift products to fill the gap
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            found = 1;
            printf("Product with code '%s' has been removed! 🚀\n", code);
            break;
        }
    }

    if (!found) {
        printf("Product with code '%s' not found in the inventory! 🙁\n", code);
    }
}

void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty! 📦\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("%-20s %-15s %-10s\n", "Product Name", "Product Code", "Quantity");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < productCount; i++) {
        printf("%-20s %-15s %-10d\n", inventory[i].name, inventory[i].code, inventory[i].quantity);
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}