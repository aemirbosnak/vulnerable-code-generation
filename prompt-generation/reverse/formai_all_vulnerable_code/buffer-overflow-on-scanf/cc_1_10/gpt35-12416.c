//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *numProducts);
void displayInventory(Product *inventory, int numProducts);
void searchProduct(Product *inventory, int numProducts);
void deleteProduct(Product *inventory, int *numProducts);

int main() {
    const int MAX_PRODUCTS = 100;
    int choice, numProducts = 0;
    Product inventory[MAX_PRODUCTS];
    
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                displayInventory(inventory, numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                deleteProduct(inventory, &numProducts);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void addProduct(Product *inventory, int *numProducts) {
    if (*numProducts >= 100) {
        printf("\nInventory full, cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("\nEnter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[*numProducts] = newProduct;
    *numProducts += 1;
    
    printf("\nProduct added successfully!\n");
}

void displayInventory(Product *inventory, int numProducts) {
    if (numProducts == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    
    printf("\nProduct Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < numProducts; i++) {
        printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(Product *inventory, int numProducts) {
    if (numProducts == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    
    char searchName[50];
    printf("\nEnter product name to search: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            printf("\nProduct found!\n");
            printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
            printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    
    printf("\nProduct not found.\n");
}

void deleteProduct(Product *inventory, int *numProducts) {
    if (*numProducts == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    
    char deleteName[50];
    printf("\nEnter product name to delete: ");
    scanf("%s", deleteName);
    
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(deleteName, inventory[i].name) == 0) {
            for (int j = i; j < *numProducts - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            *numProducts -= 1;
            printf("\nProduct deleted successfully!\n");
            return;
        }
    }
    
    printf("\nProduct not found.\n");
}