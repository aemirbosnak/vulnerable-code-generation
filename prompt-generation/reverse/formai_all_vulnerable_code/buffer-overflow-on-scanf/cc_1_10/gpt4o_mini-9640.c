//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. View Inventory\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addProduct(Product *inventory, int *count) {
    if (*count < MAX_PRODUCTS) {
        int id;
        char name[50];
        int quantity;
        float price;

        printf("Enter Product ID: ");
        scanf("%d", &id);
        printf("Enter Product Name: ");
        scanf("%s", name);
        printf("Enter Quantity: ");
        scanf("%d", &quantity);
        printf("Enter Price: ");
        scanf("%f", &price);

        inventory[*count].id = id;
        strcpy(inventory[*count].name, name);
        inventory[*count].quantity = quantity;
        inventory[*count].price = price;
        (*count)++;

        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void updateProduct(Product *inventory, int count) {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Current Name: %s\n", inventory[i].name);
            printf("Enter new Name: ");
            scanf("%s", inventory[i].name);
            printf("Current Quantity: %d\n", inventory[i].quantity);
            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Current Price: %.2f\n", inventory[i].price);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found!\n");
    }
}

void deleteProduct(Product *inventory, int *count) {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found!\n");
    }
}

void viewInventory(Product *inventory, int count) {
    if (count == 0) {
        printf("Inventory is empty!\n");
    } else {
        printf("\nProduct Inventory:\n");
        printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
        printf("----------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                updateProduct(inventory, count);
                break;
            case 3:
                deleteProduct(inventory, &count);
                break;
            case 4:
                viewInventory(inventory, count);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}