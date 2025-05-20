//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
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

typedef struct {
    Product products[MAX_PRODUCTS];
    int productCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->productCount = 0;
}

void addProduct(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if (warehouse->productCount >= MAX_PRODUCTS) {
        printf("Warehouse is full. Cannot add more products.\n");
        return;
    }
    
    Product *newProduct = &warehouse->products[warehouse->productCount++];
    newProduct->id = id;
    strncpy(newProduct->name, name, MAX_NAME_LENGTH);
    newProduct->quantity = quantity;
    newProduct->price = price;

    printf("Product '%s' added successfully.\n", newProduct->name);
}

void removeProduct(Warehouse *warehouse, int id) {
    int found = 0;
    
    for (int i = 0; i < warehouse->productCount; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->productCount - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->productCount--;
            printf("Product with ID %d removed successfully.\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void updateProduct(Warehouse *warehouse, int id, int quantity, float price) {
    int found = 0;

    for (int i = 0; i < warehouse->productCount; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            warehouse->products[i].quantity = quantity;
            warehouse->products[i].price = price;
            printf("Product with ID %d updated successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void displayProducts(const Warehouse *warehouse) {
    printf("Current Products in Warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < warehouse->productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
               warehouse->products[i].id,
               warehouse->products[i].name,
               warehouse->products[i].quantity,
               warehouse->products[i].price);
    }
}

void searchProduct(const Warehouse *warehouse, int id) {
    int found = 0;

    for (int i = 0; i < warehouse->productCount; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            printf("Product Found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   warehouse->products[i].id,
                   warehouse->products[i].name,
                   warehouse->products[i].quantity,
                   warehouse->products[i].price);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found in warehouse.\n", id);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    char name[MAX_NAME_LENGTH];
    float price;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Display Products\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                addProduct(&warehouse, id, name, quantity, price);
                break;
            case 2:
                printf("Enter Product ID to Remove: ");
                scanf("%d", &id);
                removeProduct(&warehouse, id);
                break;
            case 3:
                printf("Enter Product ID to Update: ");
                scanf("%d", &id);
                printf("Enter New Quantity: ");
                scanf("%d", &quantity);
                printf("Enter New Price: ");
                scanf("%f", &price);
                updateProduct(&warehouse, id, quantity, price);
                break;
            case 4:
                displayProducts(&warehouse);
                break;
            case 5:
                printf("Enter Product ID to Search: ");
                scanf("%d", &id);
                searchProduct(&warehouse, id);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}