//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: imaginative
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

void addProduct(Product inventory[], int *count);
void viewInventory(Product inventory[], int count);
void searchProduct(Product inventory[], int count);
void removeProduct(Product inventory[], int *count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    printf("Welcome to the Magical Marketplace Inventory System!\n");

    do {
        printf("\n1. Add a Product\n");
        printf("2. View Inventory\n");
        printf("3. Search for a Product\n");
        printf("4. Remove a Product\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                viewInventory(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                removeProduct(inventory, &count);
                break;
            case 5:
                printf("Exiting the Magical Marketplace. Farewell!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }

    } while (choice != 5);

    return 0;
}

void addProduct(Product inventory[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter the product name: ");
    scanf("%s", newProduct.name);
    printf("Enter the quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter the price: ");
    scanf("%f", &newProduct.price);
    
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product '%s' added successfully!\n", newProduct.name);
}

void viewInventory(Product inventory[], int count) {
    if (count == 0) {
        printf("The inventory is empty! Nothing to display.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    
    printf("--------------------------------------------------\n");
}

void searchProduct(Product inventory[], int count) {
    char name[NAME_LENGTH];
    printf("Enter the product name to search for: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found: %s | Quantity: %d | Price: $%.2f\n",
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("Product '%s' not found in the inventory!\n", name);
}

void removeProduct(Product inventory[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter the product name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < (*count) - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Product '%s' removed successfully!\n", name);
            return;
        }
    }
    
    printf("Product '%s' not found in the inventory!\n", name);
}