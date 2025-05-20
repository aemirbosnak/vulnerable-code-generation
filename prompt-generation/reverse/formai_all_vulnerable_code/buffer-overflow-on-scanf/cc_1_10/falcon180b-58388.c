//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_WAREHOUSES 5

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int categoryId;
} Item;

typedef struct {
    int id;
    char name[50];
} Category;

typedef struct {
    int id;
    char name[50];
    int capacity;
} Warehouse;

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item ID: ");
    scanf("%d", &items[*numItems].id);
    printf("Enter item category ID: ");
    scanf("%d", &items[*numItems].categoryId);
    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void addCategory(Category categories[], int *numCategories) {
    printf("Enter category name: ");
    scanf("%s", categories[*numCategories].name);
    (*numCategories)++;
}

void addWarehouse(Warehouse warehouses[], int *numWarehouses) {
    printf("Enter warehouse name: ");
    scanf("%s", warehouses[*numWarehouses].name);
    printf("Enter warehouse capacity: ");
    scanf("%d", &warehouses[*numWarehouses].capacity);
    (*numWarehouses)++;
}

void displayItem(Item item) {
    printf("Item ID: %d\n", item.id);
    printf("Item Name: %s\n", item.name);
    printf("Item Quantity: %d\n", item.quantity);
    printf("Item Price: %.2f\n", item.price);
    printf("Item Category ID: %d\n", item.categoryId);
}

void displayCategory(Category category) {
    printf("Category ID: %d\n", category.id);
    printf("Category Name: %s\n", category.name);
}

void displayWarehouse(Warehouse warehouse) {
    printf("Warehouse ID: %d\n", warehouse.id);
    printf("Warehouse Name: %s\n", warehouse.name);
    printf("Warehouse Capacity: %d\n", warehouse.capacity);
}

int main() {
    int numItems = 0, numCategories = 0, numWarehouses = 0;
    Item items[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];
    Warehouse warehouses[MAX_WAREHOUSES];

    addCategory(categories, &numCategories);
    addWarehouse(warehouses, &numWarehouses);

    for (int i = 0; i < numCategories; i++) {
        printf("Category %d:\n", i+1);
        displayCategory(categories[i]);
    }

    for (int i = 0; i < numWarehouses; i++) {
        printf("Warehouse %d:\n", i+1);
        displayWarehouse(warehouses[i]);
    }

    while (numItems < MAX_ITEMS) {
        addItem(items, &numItems);
    }

    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", i+1);
        displayItem(items[i]);
    }

    return 0;
}