//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold product details
typedef struct {
    char name[50];
    int id;
    int quantity;
    double price;
} Product;

// Function prototypes
void addProduct(Product *inventory, int *count);
void displayInventory(const Product *inventory, int count);
void searchProduct(const Product *inventory, int count);
void editProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);

int main() {
    Product inventory[100];
    int count = 0;
    int choice;

    printf("Welcome to Sherlock Holmes' Inventory System!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Edit Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                editProduct(inventory, count);
                break;
            case 5:
                deleteProduct(inventory, &count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addProduct(Product *inventory, int *count) {
    printf("Enter product name: ");
    scanf(" %[^\n]s", inventory[*count].name);
    printf("Enter product ID: ");
    scanf("%d", &inventory[*count].id);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter price: ");
    scanf("%lf", &inventory[*count].price);
    
    (*count)++;
    printf("Product added successfully!\n");
}

void displayInventory(const Product *inventory, int count) {
    printf("\nCurrent Inventory:\n");
    printf("-------------------------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Quantity", "Price");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10d $%-9.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(const Product *inventory, int count) {
    int id, found = 0;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Product found: %s, Quantity: %d, Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found in the inventory.\n", id);
    }
}

void editProduct(Product *inventory, int count) {
    int id, found = 0;
    printf("Enter product ID to edit: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Editing product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%lf", &inventory[i].price);
            printf("Product updated successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found in the inventory.\n", id);
    }
}

void deleteProduct(Product *inventory, int *count) {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift left
            }
            (*count)--;
            printf("Product with ID %d has been deleted from the inventory.\n", id);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found in the inventory.\n", id);
    }
}