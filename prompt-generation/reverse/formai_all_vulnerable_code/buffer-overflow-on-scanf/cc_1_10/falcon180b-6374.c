//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_WAREHOUSES 10

typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

typedef struct {
    char name[50];
    int id;
    int capacity;
    Product products[MAX_PRODUCTS];
} Warehouse;

void addProduct(Product* products, int count, Product newProduct) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(products[i].name, newProduct.name) == 0) {
            products[i].quantity += newProduct.quantity;
            return;
        }
    }
    strcpy(products[count].name, newProduct.name);
    products[count].id = newProduct.id;
    products[count].quantity = newProduct.quantity;
    products[count].price = newProduct.price;
    count++;
}

void addWarehouse(Warehouse* warehouses, int count) {
    char name[50];
    printf("Enter warehouse name: ");
    scanf("%s", name);
    strcpy(warehouses[count].name, name);
    warehouses[count].id = count + 1;
    warehouses[count].capacity = 0;
    count++;
}

void displayProducts(Product* products, int count) {
    int i;
    printf("\nProduct List:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void displayWarehouses(Warehouse* warehouses, int count) {
    int i;
    printf("\nWarehouse List:\n");
    printf("ID\tName\tCapacity\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", warehouses[i].id, warehouses[i].name, warehouses[i].capacity);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    Warehouse warehouses[MAX_WAREHOUSES];
    int countProducts = 0, countWarehouses = 0;

    addProduct(products, countProducts, (Product){ "Apple", 1, 100, 1.00 });
    addProduct(products, countProducts, (Product){ "Banana", 2, 200, 0.50 });

    addWarehouse(warehouses, countWarehouses);

    int choice;
    while (1) {
        printf("\n1. Add Product\n2. Add Warehouse\n3. Display Products\n4. Display Warehouses\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, countProducts, (Product){ "", 0, 0, 0.00 });
            break;
        case 2:
            addWarehouse(warehouses, countWarehouses);
            break;
        case 3:
            displayProducts(products, countProducts);
            break;
        case 4:
            displayWarehouses(warehouses, countWarehouses);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}