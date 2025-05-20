//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addProduct(Warehouse *warehouse, const char *name, int quantity, const char *location) {
    if (warehouse->count < MAX_PRODUCTS) {
        strncpy(warehouse->products[warehouse->count].name, name, MAX_NAME_LENGTH);
        warehouse->products[warehouse->count].quantity = quantity;
        strncpy(warehouse->products[warehouse->count].location, location, MAX_LOCATION_LENGTH);
        warehouse->count++;
        printf("Product '%s' added successfully.\n", name);
    } else {
        printf("Warehouse is full, cannot add more products.\n");
    }
}

void updateProductQuantity(Warehouse *warehouse, const char *name, int newQuantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->products[i].quantity = newQuantity;
            printf("Product '%s' updated to quantity %d.\n", name, newQuantity);
            return;
        }
    }
    printf("Product '%s' not found.\n", name);
}

void searchProduct(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            printf("Product found: %s, Quantity: %d, Location: %s\n",
                   warehouse->products[i].name,
                   warehouse->products[i].quantity,
                   warehouse->products[i].location);
            return;
        }
    }
    printf("Product '%s' not found in the warehouse.\n", name);
}

void displayAllProducts(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }
    printf("Current products in warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf(" - %s: Quantity: %d, Location: %s\n",
               warehouse->products[i].name,
               warehouse->products[i].quantity,
               warehouse->products[i].location);
    }
}

void removeProduct(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->count--;
            printf("Product '%s' removed from the warehouse.\n", name);
            return;
        }
    }
    printf("Product '%s' not found for removal.\n", name);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];

    do {
        printf("\n===== Warehouse Management System =====\n");
        printf("1. Add Product\n");
        printf("2. Update Product Quantity\n");
        printf("3. Search Product\n");
        printf("4. Display All Products\n");
        printf("5. Remove Product\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                getchar(); // clear newline from buffer
                printf("Enter location: ");
                fgets(location, MAX_LOCATION_LENGTH, stdin);
                location[strcspn(location, "\n")] = 0; // Remove newline
                addProduct(&warehouse, name, quantity, location);
                break;
            case 2:
                printf("Enter product name to update: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(&warehouse, name, quantity);
                break;
            case 3:
                printf("Enter product name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                searchProduct(&warehouse, name);
                break;
            case 4:
                displayAllProducts(&warehouse);
                break;
            case 5:
                printf("Enter product name to remove: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                removeProduct(&warehouse, name);
                break;
            case 0:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}