//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct(char *name, int quantity, float price) {
    if (productCount < MAX_PRODUCTS) {
        strcpy(inventory[productCount].name, name);
        inventory[productCount].quantity = quantity;
        inventory[productCount].price = price;
        productCount++;
        printf("Product '%s' added to inventory.\n", name);
    } else {
        printf("Inventory full. Cannot add product '%s'.\n", name);
    }
}

void removeProduct(char *name) {
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product '%s' removed from inventory.\n", name);
            break;
        }
    }
    if (!found) {
        printf("Product '%s' not found in inventory.\n", name);
    }
}

void updateProductQuantity(char *name, int quantity) {
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = quantity;
            printf("Product '%s' quantity updated to %d.\n", name, quantity);
            return;
        }
    }
    printf("Product '%s' not found in inventory.\n", name);
}

void viewInventory() {
    printf("\nCurrent Inventory:\n");
    printf("------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------------------------------------\n");
}

float calculateTotalValue() {
    float totalValue = 0.0;
    for (int i = 0; i < productCount; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    return totalValue;
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    int quantity;
    float price;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product Quantity\n");
        printf("4. View Inventory\n");
        printf("5. Calculate Total Inventory Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                removeProduct(name);
                break;
            case 3:
                printf("Enter product name to update quantity: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(name, quantity);
                break;
            case 4:
                viewInventory();
                break;
            case 5:
                printf("Total inventory value: $%.2f\n", calculateTotalValue());
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}