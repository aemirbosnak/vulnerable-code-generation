//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: visionary
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
    int totalProducts;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->totalProducts = 0;
}

void addProduct(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if (warehouse->totalProducts < MAX_PRODUCTS) {
        warehouse->products[warehouse->totalProducts].id = id;
        strncpy(warehouse->products[warehouse->totalProducts].name, name, MAX_NAME_LENGTH);
        warehouse->products[warehouse->totalProducts].quantity = quantity;
        warehouse->products[warehouse->totalProducts].price = price;
        warehouse->totalProducts++;
    } else {
        printf("Error: Warehouse is full, cannot add more products.\n");
    }
}

void displayProducts(const Warehouse *warehouse) {
    printf("Warehouse Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < warehouse->totalProducts; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n",
               warehouse->products[i].id,
               warehouse->products[i].name,
               warehouse->products[i].quantity,
               warehouse->products[i].price);
    }
}

void updateProductQuantity(Warehouse *warehouse, int id, int newQuantity) {
    for (int i = 0; i < warehouse->totalProducts; i++) {
        if (warehouse->products[i].id == id) {
            warehouse->products[i].quantity = newQuantity;
            printf("Updated product ID %d to new quantity: %d\n", id, newQuantity);
            return;
        }
    }
    printf("Error: Product with ID %d not found.\n", id);
}

void searchProduct(const Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->totalProducts; i++) {
        if (warehouse->products[i].id == id) {
            printf("Product Found: %d, %s, Quantity: %d, Price: %.2f\n",
                   id,
                   warehouse->products[i].name,
                   warehouse->products[i].quantity,
                   warehouse->products[i].price);
            return;
        }
    }
    printf("Error: Product with ID %d not found.\n", id);
}

void deleteProduct(Warehouse *warehouse, int id) {
    int found = 0;
    for (int i = 0; i < warehouse->totalProducts; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->totalProducts - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->totalProducts--;
            printf("Deleted product with ID %d\n", id);
            break;
        }
    }
    if (!found) {
        printf("Error: Product with ID %d not found for deletion.\n", id);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    float price;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product Quantity\n");
        printf("4. Search Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
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
                displayProducts(&warehouse);
                break;
            case 3:
                printf("Enter Product ID to Update: ");
                scanf("%d", &id);
                printf("Enter New Quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(&warehouse, id, quantity);
                break;
            case 4:
                printf("Enter Product ID to Search: ");
                scanf("%d", &id);
                searchProduct(&warehouse, id);
                break;
            case 5:
                printf("Enter Product ID to Delete: ");
                scanf("%d", &id);
                deleteProduct(&warehouse, id);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}